{
  gStyle->SetOptStat(0);

  TString FileNameOut_oldnTT = "./Trees_meanparam/Eiso_PU_306091_mean";
  FileNameOut_oldnTT += ".root";
  TString FileNameOut_newnTT = "./Trees_meanparam/Eiso_PU_306091_mean_newnTT";
  FileNameOut_newnTT += ".root";

  TFile f_oldnTT(FileNameOut_oldnTT.Data(),"READ");
  TH2I* h2Eiso_nTT_oldnTT = (TH2I*)f_oldnTT.Get("Eiso_nTT");
  TH2I* h2Eiso_compressednTT_oldnTT = (TH2I*)f_oldnTT.Get("Eiso_compressednTT");
  TH2I* h2Eiso_supercompressednTT_oldnTT = (TH2I*)f_oldnTT.Get("Eiso_supercompressednTT");
  
  TFile f_newnTT(FileNameOut_newnTT.Data(),"READ");
  TH2I* h2Eiso_nTT_newnTT = (TH2I*)f_newnTT.Get("Eiso_nTT");
  TH2I* h2Eiso_compressednTT_newnTT = (TH2I*)f_newnTT.Get("Eiso_compressednTT");
  TH2I* h2Eiso_supercompressednTT_newnTT = (TH2I*)f_newnTT.Get("Eiso_supercompressednTT");
  
  TCanvas cnTT("cnTT","cnTT",600,600);
  cnTT.SetRightMargin(0.15);
  cnTT.SetLogz();

  h2Eiso_nTT_oldnTT->Draw("COLZ");
  h2Eiso_nTT_oldnTT->GetXaxis()->SetLabelSize(0.025);
  h2Eiso_nTT_oldnTT->GetYaxis()->SetLabelSize(0.025);
  h2Eiso_nTT_oldnTT->GetXaxis()->SetTitle("nTT");
  h2Eiso_nTT_oldnTT->GetXaxis()->SetTitleOffset(1.1);
  //mgbest->GetXaxis()->SetRangeUser(18.,90.);
  h2Eiso_nTT_oldnTT->GetYaxis()->SetTitleOffset(1.4);
  h2Eiso_nTT_oldnTT->GetYaxis()->SetTitle("E^{#tau}_{T,iso}");
  h2Eiso_nTT_oldnTT->SetTitle("");
 
  TCanvas cscompnTT("cscompnTT","cscompnTT",1200,600);
  //cscompnTT.SetRightMargin(0.15);
  //cscompnTT.SetLogz();

  cscompnTT.Divide(2,1);

  cscompnTT.cd(1);
  cscompnTT.SetRightMargin(0.15);
  cscompnTT.SetLogz();

  h2Eiso_supercompressednTT_oldnTT->Draw("COLZ");
  h2Eiso_supercompressednTT_oldnTT->GetXaxis()->SetLabelSize(0.025);
  h2Eiso_supercompressednTT_oldnTT->GetYaxis()->SetLabelSize(0.025);
  h2Eiso_supercompressednTT_oldnTT->GetXaxis()->SetTitle("supercompressed inTT");
  h2Eiso_supercompressednTT_oldnTT->GetXaxis()->SetTitleOffset(1.1);
  //mgbest->GetXaxis()->SetRangeUser(18.,90.);
  h2Eiso_supercompressednTT_oldnTT->GetYaxis()->SetTitleOffset(1.4);
  h2Eiso_supercompressednTT_oldnTT->GetYaxis()->SetTitle("E^{#tau}_{T,iso}");
  h2Eiso_supercompressednTT_oldnTT->SetTitle("old nTT"); 
  
  cscompnTT.cd(2);
  cscompnTT.SetRightMargin(0.15);
  cscompnTT.SetLogz();
  h2Eiso_supercompressednTT_newnTT->Draw("COLZ");
  h2Eiso_supercompressednTT_newnTT->GetXaxis()->SetLabelSize(0.025);
  h2Eiso_supercompressednTT_newnTT->GetYaxis()->SetLabelSize(0.025);
  h2Eiso_supercompressednTT_newnTT->GetXaxis()->SetTitle("supercompressed inTT");
  h2Eiso_supercompressednTT_newnTT->GetXaxis()->SetTitleOffset(1.1);
  //mgbest->GetXaxis()->SetRangeUser(18.,90.);
  h2Eiso_supercompressednTT_newnTT->GetYaxis()->SetTitleOffset(1.4);
  h2Eiso_supercompressednTT_newnTT->GetYaxis()->SetTitle("E^{#tau}_{T,iso}");
  h2Eiso_supercompressednTT_newnTT->SetTitle("new nTT");
  
  TPaveText* texl = new TPaveText(0.2,0.87,0.93,0.99,"NDC");
  texl->AddText("CMS Internal, #sqrt{s}=13 TeV, Run #306091");
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
*/
  TString PlotNamesOutnTT = "PlotEisonTT/Eiso_nTT_306091_mean";
  TString PlotNamesOutPdfnTT = PlotNamesOutnTT;
  PlotNamesOutPdfnTT += ".pdf";
  TString PlotNamesOutRootnTT = PlotNamesOutnTT;
  PlotNamesOutRootnTT += ".root";
  cnTT.SaveAs(PlotNamesOutPdfnTT.Data());
  cnTT.SaveAs(PlotNamesOutRootnTT.Data());

  TString PlotNamesOutscompnTT = "PlotEisonTT/Eiso_supercompressednTT_306091_mean";
  TString PlotNamesOutPdfscompnTT = PlotNamesOutscompnTT;
  PlotNamesOutPdfscompnTT += ".pdf";
  TString PlotNamesOutRootscompnTT = PlotNamesOutscompnTT;
  PlotNamesOutRootscompnTT += ".root";
  cscompnTT.SaveAs(PlotNamesOutPdfscompnTT.Data());
  cscompnTT.SaveAs(PlotNamesOutRootscompnTT.Data());
}
