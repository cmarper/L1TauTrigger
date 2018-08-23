{
  TString FileNameOut = "./Trees_meanparam/turnOns_92X_mean_EGTau";
  FileNameOut += ".root";
  TFile f_Stage2(FileNameOut.Data(),"READ");

  //TCanvas c1 = new TCanvas("c1","graph",10,20,200,400);
  
  TGraph* eff_Stage2_iso_noIso = (TGraph*)f_Stage2.Get("divide_pt_pass_noIso_by_pt");
  TGraph* eff_Stage2_iso_Option1 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option1_by_pt");
  TGraph* eff_Stage2_iso_Option2 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option2_by_pt");
  TGraph* eff_Stage2_iso_Option3 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option3_by_pt");
  TGraph* eff_Stage2_iso_Option4 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option4_by_pt");
  TGraph* eff_Stage2_iso_Option5 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option5_by_pt");
  TGraph* eff_Stage2_iso_Option6 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option6_by_pt");
  TGraph* eff_Stage2_iso_Option7 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option7_by_pt");
  TGraph* eff_Stage2_iso_Option8 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option8_by_pt");
  TGraph* eff_Stage2_iso_Option9 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option9_by_pt");
  TGraph* eff_Stage2_iso_Option10 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option10_by_pt");
  TGraph* eff_Stage2_iso_Option11 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option11_by_pt");
  TGraph* eff_Stage2_iso_Option12 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option12_by_pt");
  TGraph* eff_Stage2_iso_Option13 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option13_by_pt");
  TGraph* eff_Stage2_iso_Option14 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option14_by_pt");
  TGraph* eff_Stage2_iso_Option15 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option15_by_pt");
  TGraph* eff_Stage2_iso_Option16 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option16_by_pt");
  TGraph* eff_Stage2_iso_Option17 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option17_by_pt");
  TGraph* eff_Stage2_iso_Option18 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option18_by_pt");
  TGraph* eff_Stage2_iso_Option19 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option19_by_pt");
  TGraph* eff_Stage2_iso_Option20 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option20_by_pt");
  TGraph* eff_Stage2_iso_Option21 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option21_by_pt");
  TGraph* eff_Stage2_iso_Option22 = (TGraph*)f_Stage2.Get("divide_pt_pass_Option22_by_pt");

  //29 GeV index 5
  //100 GeV index 14
  
  //int n = eff_Stage2_iso_noIso->GetN();
  //double *x = eff_Stage2_iso_noIso->GetX();
  //cout <<  x[5] << " "  << x[14] << endl; 
  
  cout << "NoIso : " << eff_Stage2_iso_noIso->Integral(5,14) << endl;
  cout << "Option1: " << eff_Stage2_iso_Option1->Integral(5,14) << endl;
  cout << "Option2: " << eff_Stage2_iso_Option2->Integral(5,14) << endl;
  cout << "Option3: " << eff_Stage2_iso_Option3->Integral(5,14) << endl;
  cout << "Option4: " << eff_Stage2_iso_Option4->Integral(5,14) << endl;
  cout << "Option8: " << eff_Stage2_iso_Option8->Integral(5,14) << endl;
  cout << "Option22: " << eff_Stage2_iso_Option22->Integral(5,14) << endl;
 
}
