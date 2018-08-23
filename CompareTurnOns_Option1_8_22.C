{
  TString FileNameOut_low = "./Trees_meanparam/turnOns_Option1_8_22_mean_lowcut";
  FileNameOut_low += ".root";
  
  TString FileNameOut_sym = "./Trees_meanparam/turnOns_Optio22_mean_symcut";
  FileNameOut_sym += ".root";

   //mean
 
  TString Threshold_NewLayer1_Option1_low = "28"; 
  TString Threshold_NewLayer1_Option8_low = "23";
  TString Threshold_NewLayer1_Option22_low = "24"; 
  TString Threshold_NewLayer1_Option22_sym = "32";
  
  TFile f_Stage2_low(FileNameOut_low.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_Option1_low = (TGraphAsymmErrors*)f_Stage2_low.Get("divide_pt_pass_Option1_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option8_low = (TGraphAsymmErrors*)f_Stage2_low.Get("divide_pt_pass_Option8_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_low = (TGraphAsymmErrors*)f_Stage2_low.Get("divide_pt_pass_Option22_by_pt");

  TFile f_Stage2_sym(FileNameOut_sym.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_sym = (TGraphAsymmErrors*)f_Stage2_sym.Get("divide_pt_pass_Option22_by_pt");

  eff_Stage2_iso_Option1_low->SetLineWidth(2);
  eff_Stage2_iso_Option8_low->SetLineWidth(2);
  eff_Stage2_iso_Option22_low->SetLineWidth(2);
  eff_Stage2_iso_Option22_sym->SetLineWidth(2);
 
  eff_Stage2_iso_Option1_low->SetLineColor(2); 
  eff_Stage2_iso_Option8_low->SetLineColor(4);
  eff_Stage2_iso_Option22_low->SetLineColor(6);
  eff_Stage2_iso_Option22_sym->SetLineColor(8);

  TMultiGraph *mgbest = new TMultiGraph();
  mgbest->Add(eff_Stage2_iso_Option1_low,"l");
  mgbest->Add(eff_Stage2_iso_Option8_low,"l");
  mgbest->Add(eff_Stage2_iso_Option22_low,"l");
  mgbest->Add(eff_Stage2_iso_Option22_sym,"l");

  TCanvas cbest("turnOns_newbest","turnOns_newbest",800,800);
  cbest.SetGrid();
  mgbest->Draw("same");
  mgbest->GetXaxis()->SetLabelSize(0.025);
  mgbest->GetYaxis()->SetLabelSize(0.025);
  mgbest->GetXaxis()->SetTitle("p_{T}^{offl} [GeV]");
  mgbest->GetXaxis()->SetTitleOffset(1.1);
  mgbest->GetXaxis()->SetRangeUser(15.,100.);
  mgbest->GetYaxis()->SetTitleOffset(1.4);
  mgbest->GetYaxis()->SetTitle("Single-#tau efficiency");
  mgbest->SetTitle("");

  TPaveText* texl = new TPaveText(0.2,0.87,0.93,0.99,"NDC");
  texl->AddText("CMS Internal, #sqrt{s}=13 TeV, MC VBF H #rightarrow #tau#tau (PU 28-62)");
  texl->SetTextSize(0.03);
  texl->SetFillStyle(0);
  texl->SetBorderSize(0);
  texl->Draw("same");

  TLegend* legbest = new TLegend(0.4,0.2,0.90,0.35);
  legbest->SetBorderSize(0);
  legbest->SetTextSize(0.023);
  legbest->AddEntry(eff_Stage2_iso_Option1_low,"iso Option 1 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option1_low+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option8_low,"iso Option 8 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option8_low+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_low,"iso Option 22 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22_low+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_sym,"iso Option 22 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22_sym+" GeV)","L");

  legbest->Draw("same");

  texl->Draw("same");
 
  TString PlotNamesOutbest = "PlotIsolation/TurnOns_Option8_22_mean_lowsym";
  TString PlotNamesOutPdfbest = PlotNamesOutbest;
  PlotNamesOutPdfbest += ".pdf";
  TString PlotNamesOutRootbest = PlotNamesOutbest;
  PlotNamesOutRootbest += ".root";
  cbest.SaveAs(PlotNamesOutPdfbest.Data());
  cbest.SaveAs(PlotNamesOutRootbest.Data());

}
