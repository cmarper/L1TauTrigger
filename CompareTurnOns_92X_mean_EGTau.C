{
  TString FileNameOut = "./Trees_meanparam/turnOns_92X_mean_EGTau";
  FileNameOut += ".root";
  //mean
  TString Threshold_NewLayer1_noIso = "38";
  TString Threshold_NewLayer1_Option1 = "21";
  TString Threshold_NewLayer1_Option2 = "28";
  TString Threshold_NewLayer1_Option3 = "29";
  TString Threshold_NewLayer1_Option4 = "29";
  TString Threshold_NewLayer1_Option5 = "32";
  TString Threshold_NewLayer1_Option6 = "35";
  TString Threshold_NewLayer1_Option7 = "35";
  TString Threshold_NewLayer1_Option8 = "26";
  TString Threshold_NewLayer1_Option9 = "35";
  TString Threshold_NewLayer1_Option10 = "35";
  TString Threshold_NewLayer1_Option11 = "37";
  TString Threshold_NewLayer1_Option12 = "38";
  TString Threshold_NewLayer1_Option13 = "38";
  TString Threshold_NewLayer1_Option14 = "38";
  TString Threshold_NewLayer1_Option15 = "34";
  TString Threshold_NewLayer1_Option16 = "38";
  TString Threshold_NewLayer1_Option17 = "38";
  TString Threshold_NewLayer1_Option18 = "38";
  TString Threshold_NewLayer1_Option19 = "38";
  TString Threshold_NewLayer1_Option20 = "38";
  TString Threshold_NewLayer1_Option21 = "34";
  TString Threshold_NewLayer1_Option22 = "27"; 

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

  TGraph* eff_Stage2_iso_noIso_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_noIso_by_pt");
  TGraph* eff_Stage2_iso_Option1_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option1_by_pt");
  TGraph* eff_Stage2_iso_Option2_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option2_by_pt");
  TGraph* eff_Stage2_iso_Option3_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option3_by_pt");
  TGraph* eff_Stage2_iso_Option4_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option4_by_pt");
  TGraph* eff_Stage2_iso_Option5_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option5_by_pt");
  TGraph* eff_Stage2_iso_Option6_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option6_by_pt");
  TGraph* eff_Stage2_iso_Option7_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option7_by_pt");
  TGraph* eff_Stage2_iso_Option8_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option8_by_pt");
  TGraph* eff_Stage2_iso_Option9_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option9_by_pt");
  TGraph* eff_Stage2_iso_Option10_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option10_by_pt");
  TGraph* eff_Stage2_iso_Option11_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option11_by_pt");
  TGraph* eff_Stage2_iso_Option12_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option12_by_pt");
  TGraph* eff_Stage2_iso_Option13_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option13_by_pt");
  TGraph* eff_Stage2_iso_Option14_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option14_by_pt");
  TGraph* eff_Stage2_iso_Option15_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option15_by_pt");
  TGraph* eff_Stage2_iso_Option16_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option16_by_pt");
  TGraph* eff_Stage2_iso_Option17_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option17_by_pt");
  TGraph* eff_Stage2_iso_Option18_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option18_by_pt");
  TGraph* eff_Stage2_iso_Option19_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option19_by_pt");
  TGraph* eff_Stage2_iso_Option20_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option20_by_pt");
  TGraph* eff_Stage2_iso_Option21_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option21_by_pt");
  TGraph* eff_Stage2_iso_Option22_graph = (TGraph*)f_Stage2.Get("divide_pt_pass_Option22_by_pt");
  
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
  eff_Stage2_iso_Option1->SetLineColor(kMagenta);
  eff_Stage2_iso_Option2->SetLineColor(kCyan);
  eff_Stage2_iso_Option3->SetLineColor(kOrange);
  eff_Stage2_iso_Option4->SetLineColor(kBlue);
  eff_Stage2_iso_Option5->SetLineColor(kGreen);
  eff_Stage2_iso_Option6->SetLineColor(kOrange);
  eff_Stage2_iso_Option7->SetLineColor(kRed);
  eff_Stage2_iso_Option8->SetLineColor(kGreen+2);
  eff_Stage2_iso_Option9->SetLineColor(kCyan);
  eff_Stage2_iso_Option10->SetLineColor(kGreen);
  eff_Stage2_iso_Option11->SetLineColor(kOrange);
  eff_Stage2_iso_Option12->SetLineColor(kRed);
  eff_Stage2_iso_Option13->SetLineColor(kBlue+2);
  eff_Stage2_iso_Option14->SetLineColor(kBlue);
  eff_Stage2_iso_Option15->SetLineColor(kOrange);
  eff_Stage2_iso_Option16->SetLineColor(kMagenta+2);
  eff_Stage2_iso_Option17->SetLineColor(kOrange);
  eff_Stage2_iso_Option18->SetLineColor(kRed);
  eff_Stage2_iso_Option19->SetLineColor(kBlue+2);
  eff_Stage2_iso_Option20->SetLineColor(kBlue);
  eff_Stage2_iso_Option21->SetLineColor(kGreen);
  eff_Stage2_iso_Option22->SetLineColor(kRed);
 
  TMultiGraph *mgbest = new TMultiGraph();
  mgbest->Add(eff_Stage2_iso_noIso,"l");
  mgbest->Add(eff_Stage2_iso_Option1,"l");
  mgbest->Add(eff_Stage2_iso_Option2,"l");
  mgbest->Add(eff_Stage2_iso_Option3,"l");
  mgbest->Add(eff_Stage2_iso_Option4,"l");
  mgbest->Add(eff_Stage2_iso_Option8,"l");
  mgbest->Add(eff_Stage2_iso_Option22,"l");
 
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

  TPaveText* texl = new TPaveText(0.2,0.87,0.93,0.99,"NDC");
  texl->AddText("CMS Internal, #sqrt{s}=13 TeV, MC VBF H #rightarrow #tau#tau (PU 28-62)");
  texl->SetTextSize(0.03);
  texl->SetFillStyle(0);
  texl->SetBorderSize(0);
  texl->Draw("same");

  TLegend* legbest = new TLegend(0.45,0.15,0.85,0.45);
  legbest->SetTextSize(0.027);
  legbest->SetBorderSize(0);
  legbest->AddEntry(eff_Stage2_iso_noIso ,"no-iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_noIso +" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option1,"iso Option 1 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option1+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option2,"iso Option 2 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option2+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option3,"iso Option 3 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option3+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option4,"iso Option 4 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option4+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option8,"iso Option 8 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option8+" GeV)","L");
  //legbest->AddEntry(eff_Stage2_iso_Option15,"#bf{2017 iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option15+" GeV) - Option 15}","L");
  legbest->AddEntry(eff_Stage2_iso_Option22,"iso Option 22(E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22+" GeV)","L");
  legbest->Draw("same");

  //texl->Draw("same");

  TString PlotNamesOutbest = "PlotIsolation/TurnOns_92X_mean_EG_goodoptions";
  TString PlotNamesOutPdfbest = PlotNamesOutbest;
  PlotNamesOutPdfbest += ".pdf";
  TString PlotNamesOutRootbest = PlotNamesOutbest;
  PlotNamesOutRootbest += ".root";
  cbest.SaveAs(PlotNamesOutPdfbest.Data());
  cbest.SaveAs(PlotNamesOutRootbest.Data());
  
  cout << "noIso (0,100) " << eff_Stage2_iso_noIso_graph->Integral(0,14) << endl;
  cout << "opt.1 (0,100) " << eff_Stage2_iso_Option1_graph->Integral(0,14) << endl;
  cout << "opt.2 (0,100) " << eff_Stage2_iso_Option2_graph->Integral(0,14) << endl;
  cout << "opt.3 (0,100) " << eff_Stage2_iso_Option3_graph->Integral(0,14) << endl;
  cout << "opt.4 (0,100) " << eff_Stage2_iso_Option4_graph->Integral(0,14) << endl;
  cout << "opt.8 (0,100) " << eff_Stage2_iso_Option8_graph->Integral(0,14) << endl;
  cout << "opt.22 (0,100) " << eff_Stage2_iso_Option22_graph->Integral(0,14) << endl;
 
  cout << "noIso (30,100) " << eff_Stage2_iso_noIso_graph->Integral(6,14) << endl;
  cout << "opt.1 (30,100) " << eff_Stage2_iso_Option1_graph->Integral(6,14) << endl;
  cout << "opt.2 (30,100) " << eff_Stage2_iso_Option2_graph->Integral(6,14) << endl;
  cout << "opt.3 (30,100) " << eff_Stage2_iso_Option3_graph->Integral(6,14) << endl;
  cout << "opt.4 (30,100) " << eff_Stage2_iso_Option4_graph->Integral(6,14) << endl;
  cout << "opt.8 (30,100) " << eff_Stage2_iso_Option8_graph->Integral(6,14) << endl;
  cout << "opt.22 (30,100) " << eff_Stage2_iso_Option22_graph->Integral(6,14) << endl;
}
