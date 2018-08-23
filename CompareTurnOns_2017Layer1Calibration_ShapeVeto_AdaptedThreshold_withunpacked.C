{
  TString FileNameOut_emulated = "./Trees_modeparam/turnOns_March2017Layer1Calibration_ShapeVeto_92X_mode";
  FileNameOut_emulated += ".root";
  TString FileNameOut_unpacked = "./Trees_unpacked/turnOns_March2017Layer1Calibration_ShapeVeto_92X_Unpacked";
  FileNameOut_unpacked += ".root";

  //mean
  /*
  TString Threshold_NewLayer1_noIso = "41";
  TString Threshold_NewLayer1_Option1 = "21";
  TString Threshold_NewLayer1_Option2 = "28";
  TString Threshold_NewLayer1_Option3 = "30";
  TString Threshold_NewLayer1_Option4 = "32";
  TString Threshold_NewLayer1_Option5 = "34";
  TString Threshold_NewLayer1_Option6 = "39";
  TString Threshold_NewLayer1_Option7 = "39";
  TString Threshold_NewLayer1_Option8 = "26";
  TString Threshold_NewLayer1_Option9 = "40";
  TString Threshold_NewLayer1_Option10 = "40";
  TString Threshold_NewLayer1_Option11 = "40";
  TString Threshold_NewLayer1_Option12 = "41";
  TString Threshold_NewLayer1_Option13 = "41";
  TString Threshold_NewLayer1_Option14 = "41";
  TString Threshold_NewLayer1_Option15 = "34";
  TString Threshold_NewLayer1_Option16 = "41";
  TString Threshold_NewLayer1_Option17 = "41";
  TString Threshold_NewLayer1_Option18 = "41";
  TString Threshold_NewLayer1_Option19 = "41";
  TString Threshold_NewLayer1_Option20 = "41";
  TString Threshold_NewLayer1_Option21 = "36";
  TString Threshold_NewLayer1_Option22 = "28"; 
  TString Threshold_NewLayer1_noIso_unpacked = "42";
  TString Threshold_NewLayer1_Iso_unpacked = "29";  
  */
  //mode
   
  TString Threshold_NewLayer1_noIso = "41";
  TString Threshold_NewLayer1_Option1 = "18";
  TString Threshold_NewLayer1_Option2 = "24";
  TString Threshold_NewLayer1_Option3 = "27";
  TString Threshold_NewLayer1_Option4 = "28";
  TString Threshold_NewLayer1_Option5 = "31";
  TString Threshold_NewLayer1_Option6 = "37";
  TString Threshold_NewLayer1_Option7 = "37";
  TString Threshold_NewLayer1_Option8 = "24";
  TString Threshold_NewLayer1_Option9 = "38";
  TString Threshold_NewLayer1_Option10 = "38";
  TString Threshold_NewLayer1_Option11 = "38";
  TString Threshold_NewLayer1_Option12 = "40";
  TString Threshold_NewLayer1_Option13 = "40";
  TString Threshold_NewLayer1_Option14 = "40";
  TString Threshold_NewLayer1_Option15 = "32";
  TString Threshold_NewLayer1_Option16 = "41";
  TString Threshold_NewLayer1_Option17 = "41";
  TString Threshold_NewLayer1_Option18 = "40";
  TString Threshold_NewLayer1_Option19 = "40";
  TString Threshold_NewLayer1_Option20 = "40";
  TString Threshold_NewLayer1_Option21 = "34";
  TString Threshold_NewLayer1_Option22 = "27";
  TString Threshold_NewLayer1_noIso_unpacked = "42";
  TString Threshold_NewLayer1_Iso_unpacked = "29";
  
  TFile f_Stage2_emulated(FileNameOut_emulated.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_noIso = (TGraphAsymmErrors*)f_Stage2_emulated.Get("divide_pt_pass_noIso_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option22 = (TGraphAsymmErrors*)f_Stage2_emulated.Get("divide_pt_pass_Option22_by_pt");
  
  TFile f_Stage2_unpacked(FileNameOut_unpacked.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_noIso_unpacked = (TGraphAsymmErrors*)f_Stage2_unpacked.Get("divide_pt_pass_noIso_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_unpacked = (TGraphAsymmErrors*)f_Stage2_unpacked.Get("divide_pt_pass_Option22_by_pt");
  
  eff_Stage2_iso_noIso->SetLineWidth(2);
  eff_Stage2_iso_Option22->SetLineWidth(2);
  eff_Stage2_iso_noIso_unpacked->SetLineWidth(2);
  eff_Stage2_iso_Option22_unpacked->SetLineWidth(2);

  eff_Stage2_iso_noIso->SetLineColor(kRed-9);
  eff_Stage2_iso_Option22->SetLineColor(kRed+1);
  eff_Stage2_iso_noIso_unpacked->SetLineColor(kBlue-9);
  eff_Stage2_iso_Option22_unpacked->SetLineColor(kBlue+1);
 
  TMultiGraph *mgbest = new TMultiGraph();
  mgbest->Add(eff_Stage2_iso_noIso,"l");
  mgbest->Add(eff_Stage2_iso_Option22,"l");
  mgbest->Add(eff_Stage2_iso_noIso_unpacked,"l");
  mgbest->Add(eff_Stage2_iso_Option22_unpacked,"l");

  TCanvas cbest("turnOns_newbest","turnOns_newbest",800,800);
  cbest.SetGrid();
  mgbest->Draw("same");
  mgbest->GetXaxis()->SetLabelSize(0.025);
  mgbest->GetYaxis()->SetLabelSize(0.025);
  mgbest->GetXaxis()->SetTitle("p_{T}^{offl} [GeV]");
  mgbest->GetXaxis()->SetTitleOffset(1.1);
  mgbest->GetXaxis()->SetRangeUser(18.,100.);
  mgbest->GetYaxis()->SetTitleOffset(1.43);
  mgbest->GetYaxis()->SetTitle("Single-#tau Efficiency");
  mgbest->SetTitle("");

  TLegend* legbest = new TLegend(0.35,0.18,0.8,0.33);
  legbest->SetTextSize(0.023);
  legbest->SetBorderSize(0);
  legbest->AddEntry(eff_Stage2_iso_noIso_unpacked ,"2017 no-iso, unpacked (E_{T}^{L1}#geq "+Threshold_NewLayer1_noIso_unpacked +" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_noIso ,"2017 no-iso, reemulated (E_{T}^{L1}#geq "+Threshold_NewLayer1_noIso +" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_unpacked,"2017 iso Option 22, unpacked (E_{T}^{L1}#geq "+Threshold_NewLayer1_Iso_unpacked+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option22,"2017 iso Option 22, reemulated (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22+" GeV)","L");
  legbest->Draw("same");

  texl->Draw("same");

  TString PlotNamesOutbest = "PlotIsolation/TurnOns_2017_22_mode_withunpacked";
  TString PlotNamesOutPdfbest = PlotNamesOutbest;
  PlotNamesOutPdfbest += ".pdf";
  TString PlotNamesOutRootbest = PlotNamesOutbest;
  PlotNamesOutRootbest += ".root";
  cbest.SaveAs(PlotNamesOutPdfbest.Data());
  cbest.SaveAs(PlotNamesOutRootbest.Data());

}
