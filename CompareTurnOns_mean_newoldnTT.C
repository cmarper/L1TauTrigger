{
  TString FileNameOut_mean = "/data_CMS/cms/mperez/TauTrigger_data/2018isolation92X/turnOns_92X_newLayer1_newLayer2_oldnTT_2017isoLUT";
  FileNameOut_mean += ".root";
  TString FileNameOut_mean_newnTT = "/data_CMS/cms/mperez/TauTrigger_data/2018isolation92X/turnOns_92X_newLayer1_newLayer2_newnTT";
  FileNameOut_mean_newnTT += ".root";

  //mean old nTT
  TString Threshold_NewLayer1_noIso_mean = "39";
  TString Threshold_NewLayer1_Option22_mean = "30";

  //mean new nTT
  TString Threshold_NewLayer1_noIso_mean_newnTT = "39";
  TString Threshold_NewLayer1_Option22_mean_newnTT = "30";
  TString Threshold_NewLayer1_Option8_mean_newnTT = "28"; 
 
  TFile f_Stage2_mean(FileNameOut_mean.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_noIso_mean = (TGraphAsymmErrors*)f_Stage2_mean.Get("divide_pt_pass_noIso_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_mean = (TGraphAsymmErrors*)f_Stage2_mean.Get("divide_pt_pass_Option22_by_pt");
  
  TFile f_Stage2_mean_newnTT(FileNameOut_mean_newnTT.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_noIso_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_noIso_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option1_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option1_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option2_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option2_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option3_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option3_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option4_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option4_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option5_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option5_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option6_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option6_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option7_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option7_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option8_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option8_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option9_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option9_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option10_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option10_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option11_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option11_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option12_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option12_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option13_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option13_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option14_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option14_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option15_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option15_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option16_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option16_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option17_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option17_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option18_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option18_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option19_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option19_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option20_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option20_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option21_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option21_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_mean_newnTT = (TGraphAsymmErrors*)f_Stage2_mean_newnTT.Get("divide_pt_pass_Option22_by_pt");
 
  eff_Stage2_iso_noIso_mean->SetLineWidth(2);
  eff_Stage2_iso_Option22_mean->SetLineWidth(2);
  eff_Stage2_iso_noIso_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option1_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option2_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option3_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option4_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option5_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option6_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option7_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option8_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option9_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option10_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option11_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option12_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option13_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option14_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option15_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option16_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option17_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option18_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option19_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option20_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option21_mean_newnTT->SetLineWidth(2);
  eff_Stage2_iso_Option22_mean_newnTT->SetLineWidth(2);

  eff_Stage2_iso_noIso_mean->SetLineColor(kBlack);
  eff_Stage2_iso_Option22_mean->SetLineColor(kBlue);
  eff_Stage2_iso_noIso_mean_newnTT->SetLineColor(kMagenta);
  eff_Stage2_iso_Option1_mean_newnTT->SetLineColor(1);
  eff_Stage2_iso_Option2_mean_newnTT->SetLineColor(2);
  eff_Stage2_iso_Option3_mean_newnTT->SetLineColor(3);
  eff_Stage2_iso_Option4_mean_newnTT->SetLineColor(4);
  eff_Stage2_iso_Option5_mean_newnTT->SetLineColor(5);
  eff_Stage2_iso_Option6_mean_newnTT->SetLineColor(6);
  eff_Stage2_iso_Option7_mean_newnTT->SetLineColor(7);
  eff_Stage2_iso_Option8_mean_newnTT->SetLineColor(8);
  eff_Stage2_iso_Option9_mean_newnTT->SetLineColor(9);
  eff_Stage2_iso_Option10_mean_newnTT->SetLineColor(11);
  eff_Stage2_iso_Option11_mean_newnTT->SetLineColor(kRed);
  eff_Stage2_iso_Option12_mean_newnTT->SetLineColor(kBlack);
  eff_Stage2_iso_Option13_mean_newnTT->SetLineColor(1);
  eff_Stage2_iso_Option14_mean_newnTT->SetLineColor(2);
  eff_Stage2_iso_Option15_mean_newnTT->SetLineColor(3);
  eff_Stage2_iso_Option16_mean_newnTT->SetLineColor(4);
  eff_Stage2_iso_Option17_mean_newnTT->SetLineColor(5);
  eff_Stage2_iso_Option18_mean_newnTT->SetLineColor(6);
  eff_Stage2_iso_Option19_mean_newnTT->SetLineColor(7);
  eff_Stage2_iso_Option20_mean_newnTT->SetLineColor(8);
  eff_Stage2_iso_Option21_mean_newnTT->SetLineColor(9);
  eff_Stage2_iso_Option22_mean_newnTT->SetLineColor(11);

  TMultiGraph *mgbest = new TMultiGraph();
  //mgbest->Add(eff_Stage2_iso_noIso_mean,"l");
  mgbest->Add(eff_Stage2_iso_Option22_mean,"l");
  //mgbest->Add(eff_Stage2_iso_noIso_mean_newnTT,"l");
  /*mgbest->Add(eff_Stage2_iso_Option1_mean_newnTT,"l");
  */mgbest->Add(eff_Stage2_iso_Option2_mean_newnTT,"l");
  /*mgbest->Add(eff_Stage2_iso_Option3_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option4_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option5_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option6_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option7_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option8_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option9_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option10_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option11_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option12_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option13_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option14_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option15_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option16_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option17_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option18_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option19_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option20_mean_newnTT,"l");
  mgbest->Add(eff_Stage2_iso_Option21_mean_newnTT,"l");
  */mgbest->Add(eff_Stage2_iso_Option22_mean_newnTT,"l");

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
  legbest->SetTextSize(0.02);
  legbest->SetBorderSize(0);
  //legbest->AddEntry(eff_Stage2_iso_noIso_mean ,"non-isolated (E_{T}^{L1}#geq "+Threshold_NewLayer1_noIso_mean+" GeV)","L");
 // legbest->AddEntry(eff_Stage2_iso_noIso_mean_newnTT ,"no-iso, new nTT (E_{T}^{L1}#geq "+Threshold_NewLayer1_noIso_mean_newnTT+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_mean,"isolated (Option 22), 2017 iso LUT (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22_mean+" GeV)","L");
  //legbest->AddEntry(eff_Stage2_iso_Option22_mean_newnTT,"isolated (Option 22), new nTT iso LUT (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22_mean_newnTT+" GeV)","L");
  //legbest->AddEntry(eff_Stage2_iso_Option8_mean_newnTT,"isolated (Option 8), new nTT iso LUT (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option8_mean_newnTT+" GeV)","L");
  /*  legbest->AddEntry(eff_Stage2_iso_Option1_mean_newnTT,"1","L");
  */legbest->AddEntry(eff_Stage2_iso_Option2_mean_newnTT,"2","L");
  /*legbest->AddEntry(eff_Stage2_iso_Option3_mean_newnTT,"3","L");
  legbest->AddEntry(eff_Stage2_iso_Option4_mean_newnTT,"4","L");
  legbest->AddEntry(eff_Stage2_iso_Option5_mean_newnTT,"5","L");
  legbest->AddEntry(eff_Stage2_iso_Option6_mean_newnTT,"6","L");
  legbest->AddEntry(eff_Stage2_iso_Option7_mean_newnTT,"7","L");
  legbest->AddEntry(eff_Stage2_iso_Option8_mean_newnTT,"8","L");
  legbest->AddEntry(eff_Stage2_iso_Option9_mean_newnTT,"9","L");
  legbest->AddEntry(eff_Stage2_iso_Option10_mean_newnTT,"10","L");
  legbest->AddEntry(eff_Stage2_iso_Option11_mean_newnTT,"11","L");
  legbest->AddEntry(eff_Stage2_iso_Option12_mean_newnTT,"12","L");
  legbest->AddEntry(eff_Stage2_iso_Option13_mean_newnTT,"13","L");
  legbest->AddEntry(eff_Stage2_iso_Option14_mean_newnTT,"14","L");
  legbest->AddEntry(eff_Stage2_iso_Option15_mean_newnTT,"15","L");
  legbest->AddEntry(eff_Stage2_iso_Option16_mean_newnTT,"16","L");
  legbest->AddEntry(eff_Stage2_iso_Option17_mean_newnTT,"17","L");
  legbest->AddEntry(eff_Stage2_iso_Option18_mean_newnTT,"18","L");
  legbest->AddEntry(eff_Stage2_iso_Option19_mean_newnTT,"19","L");
  legbest->AddEntry(eff_Stage2_iso_Option20_mean_newnTT,"20","L");
  legbest->AddEntry(eff_Stage2_iso_Option21_mean_newnTT,"21","L");
*/  legbest->AddEntry(eff_Stage2_iso_Option22_mean_newnTT,"22","L");


  legbest->Draw("same");

  texl->Draw("same");

  TString PlotNamesOutbest = "/data_CMS/cms/mperez/TauTrigger_data/2018isolation92X/TurnOns_92X_oldnewnTT";
  TString PlotNamesOutPdfbest = PlotNamesOutbest;
  PlotNamesOutPdfbest += ".pdf";
  TString PlotNamesOutRootbest = PlotNamesOutbest;
  PlotNamesOutRootbest += ".root";
  cbest.SaveAs(PlotNamesOutPdfbest.Data());
  cbest.SaveAs(PlotNamesOutRootbest.Data());

}
