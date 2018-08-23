{
  bool Draw_Options = kTRUE;
  

  gStyle->SetOptStat(000000);
  TFile f("./Trees_modeparam/histos_rate_Run305310_92X_mode_Unpacked.root","READ");
  TH1F* rate_NewLayer1_noIso_unpacked   = (TH1F*)f.Get("rate_noCut_DiTau");
  TH1F* rate_NewLayer1_Iso_unpacked     = (TH1F*)f.Get("rate_Iso_DiTau");

  TString CanvasName = "./Plots_modeparam/Comparison_Rate_DiTau_Iso_Run305310_Unpacked";
  TString CanvasNamePdf = CanvasName ;
  CanvasNamePdf += ".pdf";

  TCanvas c(CanvasName.Data(),CanvasName.Data(),650,600);
  c.SetLeftMargin(0.15);
  c.SetGrid();
  c.SetLogy();

  TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
  pad1->SetBottomMargin(0); // Upper and lower plot are joined
  pad1->SetLeftMargin(0.15);
  pad1->SetGridx();         // Vertical grid
  pad1->SetGridy();         // Vertical grid
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();               // pad1 becomes the current pad
  pad1->SetLogy();

  rate_NewLayer1_noIso_unpacked->SetTitle("");
  rate_NewLayer1_noIso_unpacked->GetXaxis()->SetRangeUser(20.,60.);
  rate_NewLayer1_noIso_unpacked->GetYaxis()->SetTitle("Rate [kHz]");
  rate_NewLayer1_noIso_unpacked->SetLineColor(kRed);
  rate_NewLayer1_noIso_unpacked->SetLineWidth(3);
  rate_NewLayer1_noIso_unpacked->Draw();

  rate_NewLayer1_Iso_unpacked->SetLineColor(kBlue);
  rate_NewLayer1_Iso_unpacked->SetLineWidth(3);
  rate_NewLayer1_Iso_unpacked->Draw("same");

  TPaveText* texl = new TPaveText(0.20,0.87,0.90,0.99,"NDC");
  texl->AddText("CMS Internal, #sqrt{s}=13 TeV, Run #305310 (PU ~ 57)");
  // texl->AddText("CMS Internal, #sqrt{s}=13 TeV, Run #277069 (2064 bunches), 81<lumi<300");

  texl->SetTextSize(0.04);
  texl->SetFillStyle(0);
  texl->SetBorderSize(0);
  texl->Draw("same");

  TLegend* leg = new TLegend(0.55,0.51,0.89,0.81);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetHeader("Linearly scaled to 2.0E34");
  leg->AddEntry(rate_NewLayer1_noIso_unpacked,"#bf{Di-#tau no-iso, unpacked}","L");  
  leg->AddEntry(rate_NewLayer1_Iso_unpacked,"#bf{Di-#tau iso, unpacked}","L");

  TLine line(0., 18., 120., 18.);
  line.SetLineColor(kRed);
  line.SetLineWidth(4);
  line.SetLineStyle(2);
  // line.Draw("same");

  leg->Draw("same");

  c.cd();

  TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
  pad2->SetTopMargin(0);
  pad2->SetLeftMargin(0.15);
  pad2->SetBottomMargin(0.30);
  // pad2->SetBottomMargin(0.25);//was here

  pad2->SetGridx(); // vertical grid
  pad2->Draw();
  pad2->cd();       // pad2 becomes the current pad

  //TH1F* ratioPlot22 = (TH1F*)rate_NewLayer1_noIso->Clone("ratioPlot");
  //ratioPlot22->Divide(rate_NewLayer1_Option22);
  //ratioPlot22->SetLineColor(kRed);
  //ratioPlot22->Draw();
   
  //cout << "rate" << rate_NewLayer1_Option22 << endl;
  /*
  TH1F* ratioPlot_nonIso = (TH1F*)rate_NewLayer1_SK1616_noIso->Clone("ratioPlot_nonIso");
  ratioPlot_nonIso->Divide(rate_NewLayer1_noIso);
  ratioPlot_nonIso->Draw("same");

  TH1F* ratioPlot_Option15 = (TH1F*)rate_NewLayer1_Option15->Clone("ratioPlot_Option15");
  ratioPlot_Option15->Divide(rate_OldLayer1);
  ratioPlot_Option15->Draw("same");

  TH1F* ratioPlot_SK1616 = (TH1F*)rate_NewLayer1_SK1616->Clone("ratioPlot_SK1616");
  ratioPlot_SK1616->Divide(rate_OldLayer1);
  ratioPlot_SK1616->Draw("same");

  TH1F* ratioPlot_Option21 = (TH1F*)rate_NewLayer1_Option21->Clone("ratioPlot_Option21");
  ratioPlot_Option21->Divide(rate_OldLayer1);
  ratioPlot_Option21->Draw("same");
  */
  
  //ratioPlot->GetXaxis()->SetLabelSize(0.09);
  //ratioPlot->GetYaxis()->SetLabelSize(0.09);

  //ratioPlot->GetYaxis()->SetTitleSize(0.09);
  //ratioPlot->SetTitle("");
  // ratioPlot->GetXaxis()->SetRangeUser(20.,100.);
  //ratioPlot->GetXaxis()->SetRangeUser(20.,60.);
  // ratioPlot->GetXaxis()->SetRangeUser(0.,40.);
  //ratioPlot->GetYaxis()->SetRangeUser(0.,22.);
  //ratioPlot->GetYaxis()->SetTitle("No-iso/iso(Option)");
  //ratioPlot->GetXaxis()->SetTitle("E_{T}^{L1} threshold [GeV]");
  // ratioPlot->GetXaxis()->SetTitleOffset(1.3);
  //ratioPlot->GetXaxis()->SetTitleSize(0.11);
  // ratioPlot->GetYaxis()->SetTitle("New/Currently online");
  //ratioPlot->GetYaxis()->SetTitleOffset(0.5);

  // TLine line2(20., 1., 100., 1.);
  //TLine line2(20., 1., 60., 1.);
  // TLine line2(0., 1., 40., 1.);
  //line2.SetLineColor(kGreen);
  //line2.SetLineStyle(2);
  //line2.Draw("same");

  
  c.SaveAs(CanvasNamePdf.Data());

    //find first threshold giving < 10 kHz.
  Double_t Target = 8.5;
  // Double_t Target = 14.*1.8/2.0;
  //Double_t Target = 14.;

  Double_t Threshold_NewLayer1_noIso_unpacked = 0.;
  Double_t Threshold_NewLayer1_Iso_unpacked = 0.;
   
  for(UInt_t i = 1 ; i <= rate_NewLayer1_noIso_unpacked->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_noIso_unpacked->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_noIso_unpacked = rate_NewLayer1_noIso_unpacked->GetBinLowEdge(i);
  	  break;
  	}
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Iso_unpacked->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Iso_unpacked->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Iso_unpacked = rate_NewLayer1_Iso_unpacked->GetBinLowEdge(i);
  	  break;
  	}
    }
 

  // cout<<"Double_t Threshold_Layer1_Option21 = "<<Threshold_Layer1_Option21-0.49<<";"<<endl;

  cout<<"Double_t Threshold_NewLayer1_noIso_unpacked   = "<<Threshold_NewLayer1_noIso_unpacked-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Iso_unpacked   = "<<Threshold_NewLayer1_Iso_unpacked-0.49<<";"<<endl;

  cout<<endl;
  
  cout<<"TString Threshold_NewLayer1_noIso_unpacked = \""<<Threshold_NewLayer1_noIso_unpacked<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Iso_unpacked = \""<<Threshold_NewLayer1_Iso_unpacked<<"\";"<<endl;  
  
}
