{
  TString FileNameOut_er2p1 = "../Trees_etarestriction/turnOns_MC_92X_mean_er2p1_thr28";
  FileNameOut_er2p1 += ".root";
  TString FileNameOut_er2p2 = "../Trees_etarestriction/turnOns_MC_92X_mean_er2p2_thr29";
  FileNameOut_er2p2 += ".root";

   
  TString Threshold_NewLayer1_Option22_er2p1 = "28";
  TString Threshold_NewLayer1_Option22_er2p2 = "29"; 
 
  TFile f_Option22_er2p1(FileNameOut_er2p1.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_er2p1 = (TGraphAsymmErrors*)f_Option22_er2p1.Get("divide_pt_pass_Option22_by_pt");
 
  TFile f_Option22_er2p2(FileNameOut_er2p2.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_er2p2 = (TGraphAsymmErrors*)f_Option22_er2p2.Get("divide_pt_pass_Option22_by_pt");
  
  eff_Stage2_iso_Option22_er2p1->SetLineWidth(2);
  eff_Stage2_iso_Option22_er2p2->SetLineWidth(2);
 
  eff_Stage2_iso_Option22_er2p1->SetLineColor(kRed+1);
  eff_Stage2_iso_Option22_er2p2->SetLineColor(kMagenta+1);
  
  TMultiGraph *mgbest = new TMultiGraph();
  mgbest->Add(eff_Stage2_iso_Option22_er2p1,"l");
  mgbest->Add(eff_Stage2_iso_Option22_er2p2,"l");

  TCanvas cbest("turnOns_newbest","turnOns_newbest",800,800);
  cbest.SetGrid();
  mgbest->Draw("same");
  mgbest->GetXaxis()->SetLabelSize(0.025);
  mgbest->GetYaxis()->SetLabelSize(0.025);
  mgbest->GetXaxis()->SetTitle("p_{T}^{offl} [GeV]");
  mgbest->GetXaxis()->SetTitleOffset(1.1);
  mgbest->GetXaxis()->SetRangeUser(20.,100.);
  mgbest->GetYaxis()->SetTitleOffset(1.43);
  mgbest->GetYaxis()->SetTitle("Single-#tau Efficiency");
  mgbest->SetTitle("");

  TPaveText* texl = new TPaveText(0.2,0.87,0.93,0.99,"NDC");
  texl->AddText("CMS Internal, #sqrt{s}=13 TeV, MC VBF H #rightarrow #tau#tau (PU 28-62)");
  texl->SetTextSize(0.03);
  texl->SetFillStyle(0);
  texl->SetBorderSize(0);
  texl->Draw("same");

  TLegend* legbest = new TLegend(0.47,0.18,0.8,0.33);
  legbest->SetTextSize(0.023);
  legbest->SetBorderSize(0);
  legbest->AddEntry(eff_Stage2_iso_Option22_er2p1,"TT28, er2p1 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22_er2p1+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_er2p2,"TT28, er2p2 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22_er2p2+" GeV)","L");
  legbest->Draw("same");

  texl->Draw("same");

  TString PlotNamesOutbest = "../PlotIsolation/TurnOns_etarestriction";
  TString PlotNamesOutPdfbest = PlotNamesOutbest;
  PlotNamesOutPdfbest += ".pdf";
  TString PlotNamesOutRootbest = PlotNamesOutbest;
  PlotNamesOutRootbest += ".root";
  cbest.SaveAs(PlotNamesOutPdfbest.Data());
  cbest.SaveAs(PlotNamesOutRootbest.Data());

}
