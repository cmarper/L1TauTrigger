{
  TString FileNameOut = "./Trees_meanparam/turnOns_thr21_mean";
  FileNameOut += ".root";
  //mean
  
  TString Threshold_NewLayer1_noIso = "21";
  TString Threshold_NewLayer1_Option1 = "21";
  TString Threshold_NewLayer1_Option2 = "21";
  TString Threshold_NewLayer1_Option3 = "21";
  TString Threshold_NewLayer1_Option4 = "21";
  TString Threshold_NewLayer1_Option5 = "21";
  TString Threshold_NewLayer1_Option6 = "21";
  TString Threshold_NewLayer1_Option7 = "21";
  TString Threshold_NewLayer1_Option8 = "21";
  TString Threshold_NewLayer1_Option9 = "21";
  TString Threshold_NewLayer1_Option10 = "21";
  TString Threshold_NewLayer1_Option11 = "21";
  TString Threshold_NewLayer1_Option12 = "21";
  TString Threshold_NewLayer1_Option13 = "21";
  TString Threshold_NewLayer1_Option14 = "21";
  TString Threshold_NewLayer1_Option15 = "21";
  TString Threshold_NewLayer1_Option16 = "21";
  TString Threshold_NewLayer1_Option17 = "21";
  TString Threshold_NewLayer1_Option18 = "21";
  TString Threshold_NewLayer1_Option19 = "21";
  TString Threshold_NewLayer1_Option20 = "21";
  TString Threshold_NewLayer1_Option21 = "21";
  TString Threshold_NewLayer1_Option22 = "21"; 
  

  //mode 
  /*TString Threshold_NewLayer1_noIso = "41";
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
*/
  TFile f_Stage2(FileNameOut.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_noIso = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_noIso_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option1 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option1_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option2 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option2_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option3 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option3_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option4 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option4_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option5 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option5_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option6 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option6_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option7 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option7_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option8 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option8_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option9 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option9_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option10 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option10_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option11 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option11_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option12 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option12_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option13 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option13_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option14 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option14_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option15 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option15_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option16 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option16_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option17 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option17_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option18 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option18_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option19 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option19_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option20 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option20_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option21 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option21_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option22 = (TGraphAsymmErrors*)f_Stage2.Get("divide_pt_pass_Option22_by_pt");

  eff_Stage2_iso_noIso->SetLineWidth(2);
  eff_Stage2_iso_Option1->SetLineWidth(2);
  eff_Stage2_iso_Option2->SetLineWidth(2);
  eff_Stage2_iso_Option3->SetLineWidth(2);
  eff_Stage2_iso_Option4->SetLineWidth(2);
  eff_Stage2_iso_Option5->SetLineWidth(2);
  eff_Stage2_iso_Option6->SetLineWidth(2);
  eff_Stage2_iso_Option7->SetLineWidth(2);
  eff_Stage2_iso_Option8->SetLineWidth(2);
  eff_Stage2_iso_Option9->SetLineWidth(2);
  eff_Stage2_iso_Option10->SetLineWidth(2);
  eff_Stage2_iso_Option11->SetLineWidth(2);
  eff_Stage2_iso_Option12->SetLineWidth(2);
  eff_Stage2_iso_Option13->SetLineWidth(2);
  eff_Stage2_iso_Option14->SetLineWidth(2);
  eff_Stage2_iso_Option15->SetLineWidth(2);
  eff_Stage2_iso_Option16->SetLineWidth(2);
  eff_Stage2_iso_Option17->SetLineWidth(2);
  eff_Stage2_iso_Option18->SetLineWidth(2);
  eff_Stage2_iso_Option19->SetLineWidth(2);
  eff_Stage2_iso_Option20->SetLineWidth(2);
  eff_Stage2_iso_Option21->SetLineWidth(2);
  eff_Stage2_iso_Option22->SetLineWidth(2);

  eff_Stage2_iso_noIso->SetLineColor(kBlack);
  eff_Stage2_iso_Option1->SetLineColor(11);
  eff_Stage2_iso_Option2->SetLineColor(2);
  eff_Stage2_iso_Option3->SetLineColor(3);
  eff_Stage2_iso_Option4->SetLineColor(4);
  eff_Stage2_iso_Option5->SetLineColor(5);
  eff_Stage2_iso_Option6->SetLineColor(6);
  eff_Stage2_iso_Option7->SetLineColor(7);
  eff_Stage2_iso_Option8->SetLineColor(94);
  eff_Stage2_iso_Option9->SetLineColor(30);
  eff_Stage2_iso_Option10->SetLineColor(28);
  eff_Stage2_iso_Option11->SetLineColor(1);
  eff_Stage2_iso_Option12->SetLineColor(2);
  eff_Stage2_iso_Option13->SetLineColor(3);
  eff_Stage2_iso_Option14->SetLineColor(4);
  eff_Stage2_iso_Option15->SetLineColor(5);
  eff_Stage2_iso_Option16->SetLineColor(6);
  eff_Stage2_iso_Option17->SetLineColor(7);
  eff_Stage2_iso_Option18->SetLineColor(94);
  eff_Stage2_iso_Option19->SetLineColor(30);
  eff_Stage2_iso_Option20->SetLineColor(28);
  eff_Stage2_iso_Option21->SetLineColor(51);
  eff_Stage2_iso_Option22->SetLineColor(8);
 
/*
  TMultiGraph *mgbest = new TMultiGraph();
  mgbest->Add(eff_Stage2_iso_noIso,"l");
  mgbest->Add(eff_Stage2_iso_Option1,"l");
  //mgbest->Add(eff_Stage2_iso_Option2,"l");
  mgbest->Add(eff_Stage2_iso_Option8,"l");
  mgbest->Add(eff_Stage2_iso_Option15,"l");
  mgbest->Add(eff_Stage2_iso_Option22,"l");
 */

  TMultiGraph *mgbest = new TMultiGraph();
  //mgbest->Add(eff_Stage2_iso_noIso,"l");
  mgbest->Add(eff_Stage2_iso_Option10,"l");
  mgbest->Add(eff_Stage2_iso_Option11,"l");
  mgbest->Add(eff_Stage2_iso_Option12,"l");
  mgbest->Add(eff_Stage2_iso_Option13,"l");
  mgbest->Add(eff_Stage2_iso_Option14,"l");
  mgbest->Add(eff_Stage2_iso_Option15,"l");
  mgbest->Add(eff_Stage2_iso_Option16,"l");
  mgbest->Add(eff_Stage2_iso_Option17,"l");
  mgbest->Add(eff_Stage2_iso_Option18,"l");
  mgbest->Add(eff_Stage2_iso_Option19,"l");
  mgbest->Add(eff_Stage2_iso_Option20,"l");
  mgbest->Add(eff_Stage2_iso_Option21,"l");
  mgbest->Add(eff_Stage2_iso_Option22,"l");
  
  TCanvas cbest("turnOns_newbest","turnOns_newbest",800,800);
  cbest.SetGrid();
  mgbest->Draw("same");
  mgbest->GetXaxis()->SetLabelSize(0.025);
  mgbest->GetYaxis()->SetLabelSize(0.025);
  mgbest->GetXaxis()->SetTitle("p_{T}^{offl} [GeV]");
  mgbest->GetXaxis()->SetTitleOffset(1.1);
  mgbest->GetXaxis()->SetRangeUser(8.,100.);
  mgbest->GetYaxis()->SetTitleOffset(1.4);
  mgbest->GetYaxis()->SetTitle("Single-#tau efficiency");
  mgbest->SetTitle("");

  TPaveText* texl = new TPaveText(0.2,0.87,0.93,0.99,"NDC");
  texl->AddText("CMS Internal, #sqrt{s}=13 TeV, MC VBF H #rightarrow #tau#tau (PU 28-62)");
  texl->SetTextSize(0.03);
  texl->SetFillStyle(0);
  texl->SetBorderSize(0);
  texl->Draw("same");

  TLegend* legbest = new TLegend(0.5,0.15,0.90,0.5);
  legbest->SetBorderSize(0);
  //legbest->SetHeader("caloStage2Params_2017_v1_10_mean_inconsistent");
  legbest->SetTextSize(0.023);
  //legbest->AddEntry(eff_Stage2_iso_noIso ,"no-iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_noIso +" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option10,"iso Option 10 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option1+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option11,"iso Option 11 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option2+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option12,"iso Option 12 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option3+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option13,"iso Option 13 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option4+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option14,"iso Option 14 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option5+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option15,"iso Option 15 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option6+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option16,"iso Option 16 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option7+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option17,"iso Option 17 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option8+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option18,"iso Option 18 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option9+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option19,"iso Option 19 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option10+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option20,"iso Option 20 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option10+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option21,"iso Option 21 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option10+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option22,"iso Option 22 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option10+" GeV)","L");

  legbest->Draw("same");

  texl->Draw("same");
 
  TString PlotNamesOutbest = "PlotIsolation/TurnOns_groupsecond_mean_thr21";
  TString PlotNamesOutPdfbest = PlotNamesOutbest;
  PlotNamesOutPdfbest += ".pdf";
  TString PlotNamesOutRootbest = PlotNamesOutbest;
  PlotNamesOutRootbest += ".root";
  cbest.SaveAs(PlotNamesOutPdfbest.Data());
  cbest.SaveAs(PlotNamesOutRootbest.Data());

}
