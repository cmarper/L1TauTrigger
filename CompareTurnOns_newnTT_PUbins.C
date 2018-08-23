{
  TString FileNameOut_0030 = "/data_CMS/cms/mperez/TauTrigger_data/2018CalibIsolation/turnOns_92X_v1_8_4_130518_witnNvtx_PU_0_to_30";
  FileNameOut_0030 += ".root";
  TString FileNameOut_3040 = "/data_CMS/cms/mperez/TauTrigger_data/2018CalibIsolation/turnOns_92X_v1_8_4_130518_witnNvtx_PU_30_to_40";
  FileNameOut_3040 += ".root";
  TString FileNameOut_4050 = "/data_CMS/cms/mperez/TauTrigger_data/2018CalibIsolation/turnOns_92X_v1_8_4_130518_witnNvtx_PU_40_to_50";
  FileNameOut_4050 += ".root";
  TString FileNameOut_5070 = "/data_CMS/cms/mperez/TauTrigger_data/2018CalibIsolation/turnOns_92X_v1_8_4_130518_witnNvtx_PU_50_to_70";
  FileNameOut_5070 += ".root";

  //mean old nTT
  TString Threshold_NewLayer1_Option22_mean = "30";

  TFile f_Stage2_0030(FileNameOut_0030.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_0030 = (TGraphAsymmErrors*)f_Stage2_0030.Get("divide_pt_pass_Option22_by_pt");
  
  TFile f_Stage2_3040(FileNameOut_3040.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_3040 = (TGraphAsymmErrors*)f_Stage2_3040.Get("divide_pt_pass_Option22_by_pt");

  TFile f_Stage2_4050(FileNameOut_4050.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_4050 = (TGraphAsymmErrors*)f_Stage2_4050.Get("divide_pt_pass_Option22_by_pt");

  TFile f_Stage2_5070(FileNameOut_5070.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_5070 = (TGraphAsymmErrors*)f_Stage2_5070.Get("divide_pt_pass_Option22_by_pt");

  eff_Stage2_iso_Option22_0030->SetLineWidth(1);
  eff_Stage2_iso_Option22_3040->SetLineWidth(1); 
  eff_Stage2_iso_Option22_4050->SetLineWidth(1); 
  eff_Stage2_iso_Option22_5070->SetLineWidth(1);

  eff_Stage2_iso_Option22_0030->SetLineColor(kBlack);
  eff_Stage2_iso_Option22_3040->SetLineColor(kBlue);
  eff_Stage2_iso_Option22_4050->SetLineColor(kRed);
  eff_Stage2_iso_Option22_5070->SetLineColor(kGreen+2);

  TMultiGraph *mgbest = new TMultiGraph();
  mgbest->Add(eff_Stage2_iso_Option22_0030,"l");
  mgbest->Add(eff_Stage2_iso_Option22_3040,"l");
  mgbest->Add(eff_Stage2_iso_Option22_4050,"l");
  mgbest->Add(eff_Stage2_iso_Option22_5070,"l");

  TCanvas cbest("turnOns_newbest","turnOns_newbest",800,800);
  cbest.SetGrid();
  mgbest->Draw("same");
  mgbest->GetXaxis()->SetLabelSize(0.025);
  mgbest->GetYaxis()->SetLabelSize(0.025);
  mgbest->GetXaxis()->SetTitle("p_{T}^{offl} [GeV]");
  mgbest->GetXaxis()->SetTitleOffset(1.1);
  mgbest->GetXaxis()->SetRangeUser(18.,100.);
  mgbest->GetYaxis()->SetTitleOffset(1.4);
  mgbest->GetYaxis()->SetTitle("Single-#tau efficiency");
  mgbest->SetTitle("");

  TPaveText* texl = new TPaveText(0.2,0.86,0.93,0.98,"NDC");
  texl->AddText("CMS Internal, #sqrt{s}=13 TeV, MC VBF H #rightarrow #tau#tau (PU 28-62)");
  texl->SetTextSize(0.03);
  texl->SetFillStyle(0);
  texl->SetBorderSize(0);
  texl->Draw("same");

  TLegend* legbest = new TLegend(0.33,0.18,0.87,0.3);
  legbest->SetTextSize(0.023);
  legbest->SetBorderSize(0);
  legbest->AddEntry(eff_Stage2_iso_Option22_0030 ,"iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22_mean+" GeV), PU < 30","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_3040 ,"iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22_mean+" GeV), 30 < PU < 40","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_4050 ,"iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22_mean+" GeV), 40 < PU < 50","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_5070 ,"iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22_mean+" GeV), PU > 50","L");

  legbest->Draw("same");

  texl->Draw("same");

  TString PlotNamesOutbest = "/data_CMS/cms/mperez/TauTrigger_data/2018CalibIsolation/TurnOns_92X_v1_8_4_130518_Opt22_newnTT_PUbins";
  TString PlotNamesOutPdfbest = PlotNamesOutbest;
  PlotNamesOutPdfbest += ".pdf";
  TString PlotNamesOutRootbest = PlotNamesOutbest;
  PlotNamesOutRootbest += ".root";
  cbest.SaveAs(PlotNamesOutPdfbest.Data());
  cbest.SaveAs(PlotNamesOutRootbest.Data());

}
