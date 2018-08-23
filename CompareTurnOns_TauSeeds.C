{
  TString FileNameOut_2GeV = "../Trees_TauSeeds/turnOns_MC_92X_mean_seed2GeV_highstats_31GeVthr";
  FileNameOut_2GeV += ".root";
  TString FileNameOut_4GeV = "../Trees_TauSeeds/turnOns_MC_92X_mean_seed4GeV_highstats_31GeVthr";
  FileNameOut_4GeV += ".root";
  TString FileNameOut_6GeV = "../Trees_TauSeeds/turnOns_MC_92X_mean_seed6GeV_highstats_31GeVthr";
  FileNameOut_6GeV += ".root";
  TString FileNameOut_8GeV = "../Trees_TauSeeds/turnOns_MC_92X_mean_seed8GeV_highstats_31GeVthr";
  FileNameOut_8GeV += ".root";


   
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
  TString Threshold_NewLayer1_Option22 = "31";
  TString Threshold_NewLayer1_noIso_unpacked = "42";
  TString Threshold_NewLayer1_Iso_unpacked = "29";
  
  TFile f_Option22_2GeV(FileNameOut_2GeV.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_2GeV = (TGraphAsymmErrors*)f_Option22_2GeV.Get("divide_pt_pass_Option22_by_pt");
 
  TFile f_Option22_4GeV(FileNameOut_4GeV.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_4GeV = (TGraphAsymmErrors*)f_Option22_4GeV.Get("divide_pt_pass_Option22_by_pt"); 
  
  TFile f_Option22_6GeV(FileNameOut_6GeV.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_6GeV = (TGraphAsymmErrors*)f_Option22_6GeV.Get("divide_pt_pass_Option22_by_pt");

  TFile f_Option22_8GeV(FileNameOut_8GeV.Data(),"READ");
  TGraphAsymmErrors* eff_Stage2_iso_Option22_8GeV = (TGraphAsymmErrors*)f_Option22_8GeV.Get("divide_pt_pass_Option22_by_pt");

  eff_Stage2_iso_Option22_2GeV->SetLineWidth(2);
  eff_Stage2_iso_Option22_4GeV->SetLineWidth(2);
  eff_Stage2_iso_Option22_6GeV->SetLineWidth(2);
  eff_Stage2_iso_Option22_8GeV->SetLineWidth(2);
 
  eff_Stage2_iso_Option22_2GeV->SetLineColor(kRed+1);
  eff_Stage2_iso_Option22_4GeV->SetLineColor(kBlue+1);
  eff_Stage2_iso_Option22_6GeV->SetLineColor(kGreen+1);
  eff_Stage2_iso_Option22_8GeV->SetLineColor(kOrange+1);
  
  TMultiGraph *mgbest = new TMultiGraph();
  mgbest->Add(eff_Stage2_iso_Option22_2GeV,"l");
  mgbest->Add(eff_Stage2_iso_Option22_4GeV,"l");
  mgbest->Add(eff_Stage2_iso_Option22_6GeV,"l");
  mgbest->Add(eff_Stage2_iso_Option22_8GeV,"l");

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

  TLegend* legbest = new TLegend(0.27,0.18,0.8,0.33);
  legbest->SetTextSize(0.023);
  legbest->SetBorderSize(0);
  legbest->AddEntry(eff_Stage2_iso_Option22_2GeV,"Seed 2 GeV, iso Option 22, reemulated (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_4GeV,"Seed 4 GeV, iso Option 22, reemulated (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_6GeV,"Seed 6 GeV, iso Option 22, reemulated (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22+" GeV)","L");
  legbest->AddEntry(eff_Stage2_iso_Option22_8GeV,"Seed 8 GeV, iso Option 22, reemulated (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22+" GeV)","L");
  legbest->Draw("same");

  texl->Draw("same");

  TString PlotNamesOutbest = "../PlotIsolation/TurnOns_TauSeeds_thr31GeV";
  TString PlotNamesOutPdfbest = PlotNamesOutbest;
  PlotNamesOutPdfbest += ".pdf";
  TString PlotNamesOutRootbest = PlotNamesOutbest;
  PlotNamesOutRootbest += ".root";
  cbest.SaveAs(PlotNamesOutPdfbest.Data());
  cbest.SaveAs(PlotNamesOutRootbest.Data());

}
