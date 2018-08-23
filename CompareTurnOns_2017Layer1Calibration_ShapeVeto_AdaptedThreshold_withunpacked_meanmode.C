{
  TString FileNameOut_emulated_mode = "./Trees_modeparam/turnOns_March2017Layer1Calibration_ShapeVeto_92X_mode";
  FileNameOut_emulated_mode += ".root";
  TString FileNameOut_emulated_mean = "./Trees_meanparam/turnOns_March2017Layer1Calibration_ShapeVeto_92X_mean";
  FileNameOut_emulated_mean += ".root";
  TString FileNameOut_unpacked = "./Trees_unpacked/turnOns_March2017Layer1Calibration_ShapeVeto_92X_Unpacked";
  FileNameOut_unpacked += ".root";

  //mean
  
  TString Threshold_NewLayer1_noIso_mean = "41";
  /*
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
  */
  TString Threshold_NewLayer1_Option22_mean = "28"; 
  TString Threshold_NewLayer1_noIso_unpacked = "42";
  TString Threshold_NewLayer1_Iso_unpacked = "29";  
  
  //mode
   
  TString Threshold_NewLayer1_noIso_mode = "41";
  /*
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
  */
  TString Threshold_NewLayer1_Option22_mode = "27";
  //TString Threshold_NewLayer1_noIso_unpacked = "42";
  //TString Threshold_NewLayer1_Iso_unpacked = "29";
  
  TFile f_Stage2_emulated_mode(FileNameOut_emulated_mode.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_noIso_mode = (TGraphAsymmErrors*)f_Stage2_emulated_mode.Get("divide_pt_pass_noIso_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_mode = (TGraphAsymmErrors*)f_Stage2_emulated_mode.Get("divide_pt_pass_Option22_by_pt");
  
  TFile f_Stage2_emulated_mean(FileNameOut_emulated_mean.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_noIso_mean = (TGraphAsymmErrors*)f_Stage2_emulated_mean.Get("divide_pt_pass_noIso_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_mean = (TGraphAsymmErrors*)f_Stage2_emulated_mean.Get("divide_pt_pass_Option22_by_pt");
  
  TFile f_Stage2_unpacked(FileNameOut_unpacked.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_noIso_unpacked = (TGraphAsymmErrors*)f_Stage2_unpacked.Get("divide_pt_pass_noIso_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_unpacked = (TGraphAsymmErrors*)f_Stage2_unpacked.Get("divide_pt_pass_Option22_by_pt");
  
  eff_Stage2_iso_noIso_mean->SetLineWidth(2);
  eff_Stage2_iso_Option22_mean->SetLineWidth(2);
  eff_Stage2_iso_noIso_mode->SetLineWidth(2);
  eff_Stage2_iso_Option22_mode->SetLineWidth(2);
  eff_Stage2_iso_noIso_unpacked->SetLineWidth(2);
  eff_Stage2_iso_Option22_unpacked->SetLineWidth(2);

  eff_Stage2_iso_noIso_mean->SetLineColor(kGreen-7);
  eff_Stage2_iso_Option22_mean->SetLineColor(kGreen+1);
  eff_Stage2_iso_noIso_mode->SetLineColor(kRed-9);
  eff_Stage2_iso_Option22_mode->SetLineColor(kRed+1);
  eff_Stage2_iso_noIso_unpacked->SetLineColor(kBlue-9);
  eff_Stage2_iso_Option22_unpacked->SetLineColor(kBlue+1);
 
  TMultiGraph *mgbest = new TMultiGraph();
  mgbest->Add(eff_Stage2_iso_noIso_mean,"l");
  mgbest->Add(eff_Stage2_iso_Option22_mean,"l");
  mgbest->Add(eff_Stage2_iso_noIso_mode,"l");
  mgbest->Add(eff_Stage2_iso_Option22_mode,"l");
  mgbest->Add(eff_Stage2_iso_noIso_unpacked,"l");
  mgbest->Add(eff_Stage2_iso_Option22_unpacked,"l");

  TCanvas cbest("turnOns_newbest","turnOns_newbest",800,800);
  cbest.SetGrid();
  mgbest->Draw("same");
  mgbest->GetXaxis()->SetLabelSize(0.025);
  mgbest->GetYaxis()->SetLabelSize(0.025);
  mgbest->GetXaxis()->SetTitle("p_{T}^{offl} [GeV]");
  mgbest->GetXaxis()->SetTitleOffset(1.1);
  mgbest->GetXaxis()->SetRangeUser(18.,90.);
  mgbest->GetYaxis()->SetTitleOffset(1.4);
  mgbest->GetYaxis()->SetTitle("Single-#tau efficiency");
  mgbest->SetTitle("");
  
  TPaveText* texl = new TPaveText(0.2,0.87,0.93,0.99,"NDC");
  texl->AddText("CMS Internal, #sqrt{s}=13 TeV, MC VBF H #rightarrow #tau#tau (PU 28-62)");
  texl->SetTextSize(0.03);
  texl->SetFillStyle(0);
  texl->SetBorderSize(0);
  texl->Draw("same");
  
  TLegend* legbest = new TLegend(0.4,0.15,0.90,0.35);
  legbest->SetTextSize(0.023);
  legbest->SetBorderSize(0);
  legbest->AddEntry(eff_Stage2_iso_noIso_unpacked ,"no-iso, old param. (E_{T}^{L1}#geq "+Threshold_NewLayer1_noIso_unpacked +" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_noIso_mode ,"no-iso, mode (E_{T}^{L1}#geq "+Threshold_NewLayer1_noIso_mode+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_noIso_mean ,"no-iso, mean (E_{T}^{L1}#geq "+Threshold_NewLayer1_noIso_mean+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_unpacked,"iso Option 22, old param. (E_{T}^{L1}#geq "+Threshold_NewLayer1_Iso_unpacked+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_mode,"iso Option 22, mode (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22_mode+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_mean,"iso Option 22, mean (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22_mean+" GeV)","L");
  legbest->Draw("same");

  texl->Draw("same");

  TString PlotNamesOutbest = "PlotIsolation/TurnOns_2017_22_modemean_withunpacked";
  TString PlotNamesOutPdfbest = PlotNamesOutbest;
  PlotNamesOutPdfbest += ".pdf";
  TString PlotNamesOutRootbest = PlotNamesOutbest;
  PlotNamesOutRootbest += ".root";
  cbest.SaveAs(PlotNamesOutPdfbest.Data());
  cbest.SaveAs(PlotNamesOutRootbest.Data());

}
