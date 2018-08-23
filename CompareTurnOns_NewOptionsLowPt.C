{
  TString FileNameOut_low = "../Trees_meanparam/turnOns_mean_NewOptionsLowPt";
  FileNameOut_low += ".root";
  
  TString FileNameOut_sym = "../Trees_meanparam/turnOns_Optio22_mean_symcut";
  FileNameOut_sym += ".root";

   //mean
 
  TString Threshold_NewLayer1_Option1_low = "28"; 
  TString Threshold_NewLayer1_Option8_low = "23";
  TString Threshold_NewLayer1_Option22_low = "24"; 
  TString Threshold_NewLayer1_Option23_low = "26";
  TString Threshold_NewLayer1_Option24_low = "25";

  TString Threshold_NewLayer1_Option22_sym = "32";
  
  TFile f_Stage2_low(FileNameOut_low.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_Option1_low = (TGraphAsymmErrors*)f_Stage2_low.Get("divide_pt_pass_Option1_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option8_low = (TGraphAsymmErrors*)f_Stage2_low.Get("divide_pt_pass_Option8_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_low = (TGraphAsymmErrors*)f_Stage2_low.Get("divide_pt_pass_Option22_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option23_low = (TGraphAsymmErrors*)f_Stage2_low.Get("divide_pt_pass_Option23_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option24_low = (TGraphAsymmErrors*)f_Stage2_low.Get("divide_pt_pass_Option24_by_pt");
   
  double accepOpt8 = 0.234;
  double accepOpt22 = 0.25;
  double accepOpt23 = 0.209;
  double accepOpt24 = 0.197;

  //cout << "Option 1: " << eff_Stage2_iso_Option1_low->Eval(28) << endl;
  cout << "Option 8 eff: " << eff_Stage2_iso_Option1_low->Eval(23) << ", Eff x acc: " << accepOpt8*eff_Stage2_iso_Option1_low->Eval(23) << endl;
  cout << "Option 22 eff: " << eff_Stage2_iso_Option1_low->Eval(24) << ", Eff x acc: " << accepOpt22*eff_Stage2_iso_Option22_low->Eval(24) << endl;
  cout << "Option 23 eff: " << eff_Stage2_iso_Option1_low->Eval(26) << ", Eff x acc: " << accepOpt23*eff_Stage2_iso_Option23_low->Eval(26) << endl;
  cout << "Option 24 eff: " << eff_Stage2_iso_Option1_low->Eval(25) << ", Eff x acc: " << accepOpt24*eff_Stage2_iso_Option24_low->Eval(25) <<endl; 

  TFile f_Stage2_sym(FileNameOut_sym.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_sym = (TGraphAsymmErrors*)f_Stage2_sym.Get("divide_pt_pass_Option22_by_pt");

  eff_Stage2_iso_Option1_low->SetLineWidth(2);
  eff_Stage2_iso_Option8_low->SetLineWidth(2);
  eff_Stage2_iso_Option22_low->SetLineWidth(2);
  eff_Stage2_iso_Option23_low->SetLineWidth(2);
  eff_Stage2_iso_Option24_low->SetLineWidth(2);
  eff_Stage2_iso_Option22_sym->SetLineWidth(2);
 
  eff_Stage2_iso_Option1_low->SetLineColor(2); 
  eff_Stage2_iso_Option8_low->SetLineColor(2);
  eff_Stage2_iso_Option22_low->SetLineColor(4);
  eff_Stage2_iso_Option23_low->SetLineColor(6);
  eff_Stage2_iso_Option24_low->SetLineColor(8);
  eff_Stage2_iso_Option22_sym->SetLineColor(1);

  TMultiGraph *mgbest = new TMultiGraph();
  //mgbest->Add(eff_Stage2_iso_Option1_low,"l");
  mgbest->Add(eff_Stage2_iso_Option8_low,"l");
  mgbest->Add(eff_Stage2_iso_Option22_low,"l");
  mgbest->Add(eff_Stage2_iso_Option23_low,"l");
  mgbest->Add(eff_Stage2_iso_Option24_low,"l");
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

  TLegend* legbest = new TLegend(0.5,0.15,0.90,0.4);
  legbest->SetBorderSize(0);
  legbest->SetTextSize(0.023);
  //legbest->AddEntry(eff_Stage2_iso_Option1_low,"iso Option 1 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option1_low+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option8_low,"iso Option 8 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option8_low+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_low,"iso Option 22 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22_low+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option23_low,"iso Option 23 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option23_low+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option24_low,"iso Option 24 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option24_low+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_sym,"iso Option 22 (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22_sym+" GeV)","L");

  legbest->Draw("same");

  texl->Draw("same");
 
  TString PlotNamesOutbest = "../PlotIsolation/TurnOns_Option8_22_mean_lowsym";
  TString PlotNamesOutPdfbest = PlotNamesOutbest;
  PlotNamesOutPdfbest += ".pdf";
  TString PlotNamesOutRootbest = PlotNamesOutbest;
  PlotNamesOutRootbest += ".root";
  cbest.SaveAs(PlotNamesOutPdfbest.Data());
  cbest.SaveAs(PlotNamesOutRootbest.Data());

}
