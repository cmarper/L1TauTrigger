{
  bool Draw_Options = kTRUE;
  

  gStyle->SetOptStat(000000);
  //TFile f_mode("./Trees_modeparam/histos_rate_Run305310_92X_mode.root","READ");
  TFile f_mean("./Trees_modeparam/histos_rate_Run305310_92X_mode.root","READ");
  //TFile f_unpacked("./Trees_unpacked/histos_rate_Run305310_92X_Unpacked.root","READ");  

  //TH1F* rate_NewLayer1_noIso_mode   = (TH1F*)f_mode.Get("rate_noCut_DiTau");    
  TH1F* rate_NewLayer1_noIso_mean   = (TH1F*)f_mean.Get("rate_noCut_DiTau");
  //TH1F* rate_NewLayer1_Option22_mode = (TH1F*)f_mode.Get("rate_DiTau_Progression_22");
  TH1F* rate_NewLayer1_Option1_mean = (TH1F*)f_mean.Get("rate_DiTau_Progression_1");
  TH1F* rate_NewLayer1_Option8_mean = (TH1F*)f_mean.Get("rate_DiTau_Progression_8");
  TH1F* rate_NewLayer1_Option15_mean = (TH1F*)f_mean.Get("rate_DiTau_Progression_15");
  TH1F* rate_NewLayer1_Option22_mean = (TH1F*)f_mean.Get("rate_DiTau_Progression_22");
  //TH1F* rate_NewLayer1_noIso_unpacked   = (TH1F*)f_unpacked.Get("rate_noCut_DiTau");
  //TH1F* rate_NewLayer1_Iso_unpacked     = (TH1F*)f_unpacked.Get("rate_Iso_DiTau");

  //TString CanvasName = "./Trees/Comparison_Rate_DiTau_Iso_Run305310";
  TString CanvasName = "./PlotIsolation/PlotRate/Comparison_Rate_DiTau_Iso_Run305310_92X_mode";
  TString CanvasNamePdf = CanvasName ;
  CanvasNamePdf += ".pdf";

  TCanvas c(CanvasName.Data(),CanvasName.Data(),650,600);
  c.SetLeftMargin(0.15);
  c.SetGrid();
  c.SetLogy();

  TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
  pad1->SetBottomMargin(0.05); // Upper and lower plot are joined
  pad1->SetLeftMargin(0.15);
  pad1->SetGridx();         // Vertical grid
  pad1->SetGridy();         // Vertical grid
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();               // pad1 becomes the current pad
  pad1->SetLogy();

  rate_NewLayer1_noIso_mean->SetTitle("");
  rate_NewLayer1_noIso_mean->GetXaxis()->SetRangeUser(20.,60.);
  rate_NewLayer1_noIso_mean->GetYaxis()->SetTitle("Di-#tau rate [kHz]");
  
  //rate_NewLayer1_noIso_unpacked->SetLineColor(kBlue-9);
  //rate_NewLayer1_noIso_unpacked->SetLineWidth(3);
  //rate_NewLayer1_noIso_unpacked->SetLineStyle(2);
  //rate_NewLayer1_noIso_unpacked->Draw();

  //rate_NewLayer1_noIso_mode->SetLineWidth(3);
  //rate_NewLayer1_noIso->SetLineStyle(2);
  //rate_NewLayer1_noIso_mode->SetLineColor(kRed-9);
  //rate_NewLayer1_noIso_mode->Draw("same");
  
  rate_NewLayer1_noIso_mean->SetLineWidth(3);
  //rate_NewLayer1_noIso->SetLineStyle(2);
  rate_NewLayer1_noIso_mean->SetLineColor(kBlack);
  rate_NewLayer1_noIso_mean->Draw();
  
  //rate_NewLayer1_Iso_unpacked->SetLineColor(kBlue+1);
  //rate_NewLayer1_Iso_unpacked->SetLineWidth(3);
  //rate_NewLayer1_Iso_unpacked->SetLineStyle(9);
  //rate_NewLayer1_Iso_unpacked->Draw("same");  

  rate_NewLayer1_Option1_mean->SetLineColor(kMagenta);
  rate_NewLayer1_Option1_mean->SetLineWidth(3);
  //rate_NewLayer1_Option22->SetLineStyle(9);
  rate_NewLayer1_Option1_mean->Draw("same");
  
  rate_NewLayer1_Option8_mean->SetLineColor(kGreen);
  rate_NewLayer1_Option8_mean->SetLineWidth(3);
  //rate_NewLayer1_Option22->SetLineStyle(9);
  rate_NewLayer1_Option8_mean->Draw("same");
  
  rate_NewLayer1_Option15_mean->SetLineColor(kOrange);
  rate_NewLayer1_Option15_mean->SetLineWidth(3);
  //rate_NewLayer1_Option22->SetLineStyle(9);
  rate_NewLayer1_Option15_mean->Draw("same");
 
  rate_NewLayer1_Option22_mean->SetLineColor(kRed+1);
  rate_NewLayer1_Option22_mean->SetLineWidth(3);
  //rate_NewLayer1_Option22->SetLineStyle(9);
  rate_NewLayer1_Option22_mean->Draw("same");

  //rate_NewLayer1_Option22_mean->SetLineColor(kGreen+1);
  //rate_NewLayer1_Option22_mean->SetLineWidth(3);
  //rate_NewLayer1_Option22->SetLineStyle(9);
  //rate_NewLayer1_Option22_mean->Draw("same");
   
  TPaveText* texl = new TPaveText(0.30,0.87,0.95,0.99,"NDC");
  texl->AddText("CMS Internal, #sqrt{s}=13 TeV, Run #305310 (PU ~ 57)");
  // texl->AddText("CMS Internal, #sqrt{s}=13 TeV, Run #277069 (2064 bunches), 81<lumi<300");

  texl->SetTextSize(0.04);
  texl->SetFillStyle(0);
  texl->SetBorderSize(0);
  texl->Draw("same");

  TLegend* leg = new TLegend(0.47,0.45,0.89,0.86);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.03);
  leg->SetHeader("#splitline{Linearly scaled to 2.0E34}{caloStage2Params_2017_v1_10_mode_inconsistent}");
  //leg->AddEntry(rate_NewLayer1_noIso,"Di-#tau no-iso","L");
  //leg->AddEntry(rate_NewLayer1_Option8 ,"#bf{Di-#tau iso (Option 8)  - 2017 Layer-1}","L");
  //leg->AddEntry(rate_NewLayer1_noIso_unpacked,"Di-#tau no-iso, old param.","L");
  //leg->AddEntry(rate_NewLayer1_noIso_mode,"Di-#tau no-iso, mode","L");
  leg->AddEntry(rate_NewLayer1_noIso_mean,"Di-#tau no-iso","L");
  //leg->AddEntry(rate_NewLayer1_Iso_unpacked,"Di-#tau iso (Option 22), old param,","L");
  //leg->AddEntry(rate_NewLayer1_noIso,"Di-#tau no-iso, reemulated","L");
  //leg->AddEntry(rate_NewLayer1_Option1,"Di-#tau iso (Option 1)","L");
  //leg->AddEntry(rate_NewLayer1_Option2,"Di-#tau iso (Option 2)","L");
  //leg->AddEntry(rate_NewLayer1_Option8,"Di-#tau iso (Option 8)","L");
  //leg->AddEntry(rate_NewLayer1_Option15,"Di-#tau iso (Option 15)","L");
  //leg->AddEntry(rate_NewLayer1_Option22_mode,"Di-#tau iso (Option 22), mode","L");
  leg->AddEntry(rate_NewLayer1_Option1_mean,"Di-#tau iso (Option 1)","L");
  leg->AddEntry(rate_NewLayer1_Option8_mean,"Di-#tau iso (Option 8)","L");
  leg->AddEntry(rate_NewLayer1_Option15_mean,"Di-#tau iso (Option 15)","L");
  leg->AddEntry(rate_NewLayer1_Option22_mean,"Di-#tau iso (Option 22)","L");

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

  //TH1F* ratioPlot22_mode = (TH1F*)rate_NewLayer1_noIso_mode->Clone("ratioPlot");
  //ratioPlot22_mode->Divide(rate_NewLayer1_Option22_mode);
  //ratioPlot22_mode->SetLineColor(kGreen+1);
  //ratioPlot22_mode->Draw();
  
  TH1F* ratioPlot1_mean = (TH1F*)rate_NewLayer1_noIso_mean->Clone("ratioPlot");
  ratioPlot1_mean->Divide(rate_NewLayer1_Option1_mean);
  ratioPlot1_mean->SetLineColor(kMagenta);
  ratioPlot1_mean->Draw();
  
  TH1F* ratioPlot8_mean = (TH1F*)rate_NewLayer1_noIso_mean->Clone("ratioPlot");
  ratioPlot8_mean->Divide(rate_NewLayer1_Option8_mean);
  ratioPlot8_mean->SetLineColor(kGreen);
  ratioPlot8_mean->Draw("same");

  TH1F* ratioPlot15_mean = (TH1F*)rate_NewLayer1_noIso_mean->Clone("ratioPlot");
  ratioPlot15_mean->Divide(rate_NewLayer1_Option15_mean);
  ratioPlot15_mean->SetLineColor(kOrange);
  ratioPlot15_mean->Draw("same");
  
  TH1F* ratioPlot22_mean = (TH1F*)rate_NewLayer1_noIso_mean->Clone("ratioPlot");
  ratioPlot22_mean->Divide(rate_NewLayer1_Option22_mean);
  ratioPlot22_mean->SetLineColor(kRed+1);
  ratioPlot22_mean->Draw("same");

  //TH1F* ratioPlot22_unpacked = (TH1F*)rate_NewLayer1_noIso_unpacked->Clone("ratioPlot");
  //ratioPlot22_unpacked->Divide(rate_NewLayer1_Iso_unpacked);
  //ratioPlot22_unpacked->SetLineColor(kBlue+1);
  //ratioPlot22_unpacked->Draw("same");
  ratioPlot->GetXaxis()->SetLabelSize(0.09);
  ratioPlot->GetYaxis()->SetLabelSize(0.09);

  ratioPlot->GetYaxis()->SetTitleSize(0.09);
  ratioPlot->SetTitle("");
  // ratioPlot->GetXaxis()->SetRangeUser(20.,100.);
  ratioPlot->GetXaxis()->SetRangeUser(20.,60.);
  // ratioPlot->GetXaxis()->SetRangeUser(0.,40.);
  ratioPlot->GetYaxis()->SetRangeUser(0.75,24.5);
  ratioPlot->GetYaxis()->SetTitle("No-iso/iso(Option)");
  ratioPlot->GetXaxis()->SetTitle("E_{T}^{L1}(#tau) threshold [GeV]");
  // ratioPlot->GetXaxis()->SetTitleOffset(1.3);
  ratioPlot->GetXaxis()->SetTitleSize(0.11);
  ratioPlot->GetYaxis()->SetNdivisions(6);
 //ratioPlot->GetYaxis()->SetTitleSize(0.07);
  // ratioPlot->GetYaxis()->SetTitle("New/Currently online");
  ratioPlot->GetYaxis()->SetTitleOffset(0.5);

  // TLine line2(20., 1., 100., 1.);
  TLine line2(20., 1., 60., 1.);
  // TLine line2(0., 1., 40., 1.);
  line2.SetLineColor(kGreen);
  line2.SetLineStyle(2);
  line2.Draw("same");

  
  c.SaveAs(CanvasNamePdf.Data());

  //find first threshold giving < 10 kHz.
  Double_t Target = 14.;
  // Double_t Target = 14.*1.8/2.0;
  // Double_t Target = 14.;

  Double_t Threshold_NewLayer1_noIso = 0.;
  Double_t Threshold_NewLayer1_Option1 = 0.;
  Double_t Threshold_NewLayer1_Option2 = 0.;
  Double_t Threshold_NewLayer1_Option3 = 0.;
  Double_t Threshold_NewLayer1_Option4 = 0.;
  Double_t Threshold_NewLayer1_Option5 = 0.;
  Double_t Threshold_NewLayer1_Option6 = 0.;
  Double_t Threshold_NewLayer1_Option7 = 0.;
  Double_t Threshold_NewLayer1_Option8 = 0.;
  Double_t Threshold_NewLayer1_Option9 = 0.;
  Double_t Threshold_NewLayer1_Option10 = 0.;
  Double_t Threshold_NewLayer1_Option11 = 0.;
  Double_t Threshold_NewLayer1_Option12 = 0.;
  Double_t Threshold_NewLayer1_Option13 = 0.;
  Double_t Threshold_NewLayer1_Option14 = 0.;
  Double_t Threshold_NewLayer1_Option15 = 0.;
  Double_t Threshold_NewLayer1_Option16 = 0.;
  Double_t Threshold_NewLayer1_Option17 = 0.;
  Double_t Threshold_NewLayer1_Option18 = 0.;
  Double_t Threshold_NewLayer1_Option19 = 0.;
  Double_t Threshold_NewLayer1_Option20 = 0.;
  Double_t Threshold_NewLayer1_Option21 = 0.;
  Double_t Threshold_NewLayer1_Option22 = 0.;
  Double_t Threshold_NewLayer1_noIso_unpacked = 0.;
  Double_t Threshold_NewLayer1_Iso_unpacked = 0.;
   
  for(UInt_t i = 1 ; i <= rate_NewLayer1_noIso_mean->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_noIso_mean->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_noIso = rate_NewLayer1_noIso_mean->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option1_mean->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option1_mean->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option1 = rate_NewLayer1_Option1_mean->GetBinLowEdge(i);
  	  break;
  	}
    }
  /*
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option2->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option2->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option2 = rate_NewLayer1_Option2->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option3->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option3->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option3 = rate_NewLayer1_Option3->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option4->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option4->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option4 = rate_NewLayer1_Option4->GetBinLowEdge(i);
  	  break;
  	}
    }
    
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option5->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option5->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option5 = rate_NewLayer1_Option5->GetBinLowEdge(i);
  	  break;
  	}
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option6->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option6->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option6 = rate_NewLayer1_Option6->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option7->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option7->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option7 = rate_NewLayer1_Option7->GetBinLowEdge(i);
  	  break;
  	}
    }
  */
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option8_mean->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option8_mean->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option8 = rate_NewLayer1_Option8_mean->GetBinLowEdge(i);
  	  break;
  	}
    }
  /*
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option9->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option9->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option9 = rate_NewLayer1_Option9->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option10->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option10->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option10 = rate_NewLayer1_Option10->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option11->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option11->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option11 = rate_NewLayer1_Option11->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option12->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option12->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option12 = rate_NewLayer1_Option12->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option13->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option13->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option13 = rate_NewLayer1_Option13->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option14->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option14->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option14 = rate_NewLayer1_Option14->GetBinLowEdge(i);
  	  break;
  	}
    }
  */
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option15_mean->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option15_mean->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option15 = rate_NewLayer1_Option15_mean->GetBinLowEdge(i);
  	  break;
  	}
    }
  /*
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option16->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option16->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option16 = rate_NewLayer1_Option16->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option17->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option17->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option17 = rate_NewLayer1_Option17->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option18->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option18->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option18 = rate_NewLayer1_Option18->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option19->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option19->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option19 = rate_NewLayer1_Option19->GetBinLowEdge(i);
  	  break;
  	}
    }
  
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option20->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option20->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option20 = rate_NewLayer1_Option20->GetBinLowEdge(i);
  	  break;
  	}
    }

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option21->GetNbinsX() ; ++i)
    {
      // cout<<"rate_NewLayer1_Option21->GetBinContent(i) = "<<rate_NewLayer1_Option21->GetBinContent(i)<<endl;
      if(rate_NewLayer1_Option21->GetBinContent(i)<=Target)
      	{
      	  Threshold_NewLayer1_Option21 = rate_NewLayer1_Option21->GetBinLowEdge(i);
      	  break;
      	}
    }
  */
  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option22_mean->GetNbinsX() ; ++i)
    {
      // cout<<"rate_NewLayer1_Option22->GetBinContent(i) = "<<rate_NewLayer1_Option22->GetBinContent(i)<<endl;
      if(rate_NewLayer1_Option22_mean->GetBinContent(i)<=Target)
      	{
      	  Threshold_NewLayer1_Option22 = rate_NewLayer1_Option22_mean->GetBinLowEdge(i);
      	  break;
      	}
    }
  /*
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

   */
  // cout<<"Double_t Threshold_Layer1_Option21 = "<<Threshold_Layer1_Option21-0.49<<";"<<endl;

  cout<<"Double_t Threshold_NewLayer1_noIso   = "<<Threshold_NewLayer1_noIso-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option1 = "<<Threshold_NewLayer1_Option1-0.49<<";"<<endl;
  /*
  cout<<"Double_t Threshold_NewLayer1_Option2 = "<<Threshold_NewLayer1_Option2-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option3 = "<<Threshold_NewLayer1_Option3-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option4 = "<<Threshold_NewLayer1_Option4-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option5 = "<<Threshold_NewLayer1_Option5-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option6 = "<<Threshold_NewLayer1_Option6-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option7 = "<<Threshold_NewLayer1_Option7-0.49<<";"<<endl;
  */
  cout<<"Double_t Threshold_NewLayer1_Option8 = "<<Threshold_NewLayer1_Option8-0.49<<";"<<endl;
  /*
  cout<<"Double_t Threshold_NewLayer1_Option9 = "<<Threshold_NewLayer1_Option9-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option10 = "<<Threshold_NewLayer1_Option10-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option11 = "<<Threshold_NewLayer1_Option11-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option12 = "<<Threshold_NewLayer1_Option12-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option13 = "<<Threshold_NewLayer1_Option13-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option14 = "<<Threshold_NewLayer1_Option14-0.49<<";"<<endl;
  */
  cout<<"Double_t Threshold_NewLayer1_Option15 = "<<Threshold_NewLayer1_Option15-0.49<<";"<<endl;
  /*
  cout<<"Double_t Threshold_NewLayer1_Option16 = "<<Threshold_NewLayer1_Option16-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option17 = "<<Threshold_NewLayer1_Option17-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option18 = "<<Threshold_NewLayer1_Option18-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option19 = "<<Threshold_NewLayer1_Option19-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option20 = "<<Threshold_NewLayer1_Option20-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option21 = "<<Threshold_NewLayer1_Option21-0.49<<";"<<endl;
  */
  cout<<"Double_t Threshold_NewLayer1_Option22 = "<<Threshold_NewLayer1_Option22-0.49<<";"<<endl;
  //cout<<"Double_t Threshold_NewLayer1_noIso_unpacked = "<<Threshold_NewLayer1_noIso_unpacked-0.49<<";"<<endl;
  //cout<<"Double_t Threshold_NewLayer1_Iso_unpacked = "<<Threshold_NewLayer1_Iso_unpacked-0.49<<";"<<endl;

  cout<<endl;
  // cout<<"TString Threshold_Layer1_Option21 = \""<<Threshold_Layer1_Option21<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option1 = \""<<Threshold_NewLayer1_Option1<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option2 = \""<<Threshold_NewLayer1_Option2<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option3 = \""<<Threshold_NewLayer1_Option3<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option4 = \""<<Threshold_NewLayer1_Option4<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option5 = \""<<Threshold_NewLayer1_Option5<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option6 = \""<<Threshold_NewLayer1_Option6<<"\";"<<endl;
  // `cout<<"TString Threshold_NewLayer1_Option7 = \""<<Threshold_NewLayer1_Option7<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option8 = \""<<Threshold_NewLayer1_Option8<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option9 = \""<<Threshold_NewLayer1_Option9<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option10 = \""<<Threshold_NewLayer1_Option10<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option11 = \""<<Threshold_NewLayer1_Option11<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option12 = \""<<Threshold_NewLayer1_Option12<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option13 = \""<<Threshold_NewLayer1_Option13<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option14 = \""<<Threshold_NewLayer1_Option14<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option15 = \""<<Threshold_NewLayer1_Option15<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option16 = \""<<Threshold_NewLayer1_Option16<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option17 = \""<<Threshold_NewLayer1_Option17<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option18 = \""<<Threshold_NewLayer1_Option18<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option19 = \""<<Threshold_NewLayer1_Option19<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option20 = \""<<Threshold_NewLayer1_Option20<<"\";"<<endl;
  // cout<<"TString Threshold_NewLayer1_Option21 = \""<<Threshold_NewLayer1_Option21<<"\";"<<endl;
  // cout<<endl;
  // // cout<<"Rate for Layer-1 Option 21 DoubleIsoTau33er = "<<rate_OldLayer1->GetBinContent(rate_OldLayer1->FindBin(33.))<<endl;;
  cout<<"TString Threshold_NewLayer1_noIso = \""<<Threshold_NewLayer1_noIso<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option1 = \""<<Threshold_NewLayer1_Option1<<"\";"<<endl;
  /*cout<<"TString Threshold_NewLayer1_Option2 = \""<<Threshold_NewLayer1_Option2<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option3 = \""<<Threshold_NewLayer1_Option3<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option4 = \""<<Threshold_NewLayer1_Option4<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option5 = \""<<Threshold_NewLayer1_Option5<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option6 = \""<<Threshold_NewLayer1_Option6<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option7 = \""<<Threshold_NewLayer1_Option7<<"\";"<<endl;
  */
  cout<<"TString Threshold_NewLayer1_Option8 = \""<<Threshold_NewLayer1_Option8<<"\";"<<endl;
  /*cout<<"TString Threshold_NewLayer1_Option9 = \""<<Threshold_NewLayer1_Option9<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option10 = \""<<Threshold_NewLayer1_Option10<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option11 = \""<<Threshold_NewLayer1_Option11<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option12 = \""<<Threshold_NewLayer1_Option12<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option13 = \""<<Threshold_NewLayer1_Option13<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option14 = \""<<Threshold_NewLayer1_Option13<<"\";"<<endl;
  */
  cout<<"TString Threshold_NewLayer1_Option15 = \""<<Threshold_NewLayer1_Option15<<"\";"<<endl;
  /*cout<<"TString Threshold_NewLayer1_Option16 = \""<<Threshold_NewLayer1_Option16<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option17 = \""<<Threshold_NewLayer1_Option17<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option18 = \""<<Threshold_NewLayer1_Option18<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option19 = \""<<Threshold_NewLayer1_Option19<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option20 = \""<<Threshold_NewLayer1_Option20<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option21 = \""<<Threshold_NewLayer1_Option21<<"\";"<<endl;
  */
  cout<<"TString Threshold_NewLayer1_Option22 = \""<<Threshold_NewLayer1_Option22<<"\";"<<endl;
  //cout<<"TString Threshold_NewLayer1_noIso_unpacked = \""<<Threshold_NewLayer1_noIso_unpacked<<"\";"<<endl;
  //cout<<"TString Threshold_NewLayer1_Iso_unpacked = \""<<Threshold_NewLayer1_Iso_unpacked<<"\";"<<endl;

  /*
  Double_t Threshold_NewLayer1_Option5_SK1616 = 0.;

  for(UInt_t i = 1 ; i <= rate_NewLayer1_SK1616->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_SK1616->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option5_SK1616 = rate_NewLayer1_SK1616->GetBinLowEdge(i);
  	  break;
  	}
    }
  */
  //cout<<"Double_t Threshold_NewLayer1_Option5_SK1616 = "<<Threshold_NewLayer1_Option5_SK1616-0.49<<";"<<endl;
  //cout<<"TString Threshold_NewLayer1_Option5_SK1616 = \""<<Threshold_NewLayer1_Option5_SK1616<<"\";"<<endl;
  

  /*
  //barrel-endcaps rates
  TString CanvasName2 = "Comparison_Rate_DiTau_Iso_Layer1_Option21_vs_NewLayer1_vs_SK1616_Option5_277069_EE_EB_OlivierFlatWP";
  TString CanvasNamePdf2 = CanvasName2 ;
  CanvasNamePdf2 += ".pdf";

  TCanvas c2(CanvasName2.Data(),CanvasName2.Data(),650,600);
  c2.SetLeftMargin(0.15);
  c2.SetGrid();
  c2.SetLogy();

  TPad *pad1_2 = new TPad("pad1_2", "pad1_2", 0, 0.3, 1, 1.0);
  pad1_2->SetBottomMargin(0); // Upper and lower plot are joined
  pad1_2->SetLeftMargin(0.15);
  pad1_2->SetGridx();         // Vertical grid
  pad1_2->SetGridy();         // Vertical grid
  pad1_2->Draw();             // Draw the upper pad: pad1_2
  pad1_2->cd();               // pad1_2 becomes the current pad
  pad1_2->SetLogy();

  rate_OldLayer1_barrel->SetTitle("");
  rate_OldLayer1_barrel->GetXaxis()->SetRangeUser(20.,60.);
  rate_OldLayer1_barrel->GetYaxis()->SetTitle("Rate [kHz]");
  
  rate_OldLayer1_barrel->SetLineWidth(3);
  rate_OldLayer1_barrel->SetLineColor(kGreen);
  rate_OldLayer1_barrel->Draw();

  rate_NewLayer1_Option21_barrel->SetLineWidth(3);
  rate_NewLayer1_Option21_barrel->SetLineColor(kOrange);
  rate_NewLayer1_Option21_barrel->Draw("same");

  rate_OldLayer1_endcaps->SetLineWidth(3);
  rate_OldLayer1_endcaps->SetLineColor(kRed);
  rate_OldLayer1_endcaps->Draw("same");

  rate_NewLayer1_Option21_endcaps->SetLineWidth(3);
  rate_NewLayer1_Option21_endcaps->SetLineColor(kMagenta);
  rate_NewLayer1_Option21_endcaps->Draw("same");

  TPaveText* texl2 = new TPaveText(0.20,0.87,0.90,0.99,"NDC");
  texl2->AddText("CMS Internal, #sqrt{s}=13 TeV, Run #277069 (2064 bunches), 81<lumi<300");

  texl2->SetTextSize(0.04);
  texl2->SetFillStyle(0);
  texl2->SetBorderSize(0);
  texl2->Draw("same");

  TLegend* leg2 = new TLegend(0.40,0.61,0.89,0.81);
  leg2->SetBorderSize(0);
  leg2->SetHeader("Scaled to 1.15E34");
  leg2->AddEntry(rate_OldLayer1_barrel,"#bf{Di-#tau with isolation - Old Layer-1 Option 21 - barrel}","L");
  leg2->AddEntry(rate_NewLayer1_Option21_barrel,"#bf{Di-#tau with isolation - New Layer-1 Option 21 - barrel}","L");
  leg2->AddEntry(rate_OldLayer1_endcaps,"#bf{Di-#tau with isolation - Old Layer-1 Option 21 - endcaps}","L");
  leg2->AddEntry(rate_NewLayer1_Option21_endcaps,"#bf{Di-#tau with isolation - New Layer-1 Option 21 - endcaps}","L");
  //leg->AddEntry(rate_NewLayer1_Option21,"#bf{Di-#tau with isolation - New Layer-1 Option 21}","L");


  TLine line3(0., 18., 120., 18.);
  line3.SetLineColor(kRed);
  line3.SetLineWidth(4);
  line3.SetLineStyle(2);
  //line.Draw("same");

  leg2->Draw("same");

  c2.cd();

  TPad *pad2_2 = new TPad("pad2_2", "pad2_2", 0, 0.05, 1, 0.3);
  pad2_2->SetTopMargin(0);
  pad2_2->SetLeftMargin(0.15);
  pad2_2->SetBottomMargin(0.25);
  pad2_2->SetGridx(); // vertical grid
  pad2_2->Draw();
  pad2_2->cd();       // pad2_2 becomes the current pad
  
  TH1F* ratioPlot2 = (TH1F*)rate_NewLayer1_Option21_barrel->Clone("ratioPlot2");
  ratioPlot2->Divide(rate_OldLayer1_barrel);
  ratioPlot2->Draw();

  ratioPlot2->GetXaxis()->SetLabelSize(0.09);
  ratioPlot2->GetYaxis()->SetLabelSize(0.09);

  ratioPlot2->GetYaxis()->SetTitleSize(0.09);
  ratioPlot2->SetTitle("");
  ratioPlot2->GetXaxis()->SetRangeUser(20.,60.);
  ratioPlot2->GetYaxis()->SetRangeUser(0.5,1.5);
  ratioPlot2->GetYaxis()->SetTitle("New/Old");
  ratioPlot2->GetYaxis()->SetTitleOffset(0.5);

  TH1F* ratioPlot3 = (TH1F*)rate_NewLayer1_Option21_endcaps->Clone("ratioPlot3");
  ratioPlot3->Divide(rate_OldLayer1_endcaps);
  ratioPlot3->Draw("same");

  TLine line4(20., 1., 60., 1.);
  // TLine line3(0., 1., 40., 1.);
  line4.SetLineColor(kBlack);
  line4.SetLineStyle(2);
  line4.Draw("same");


  c2.SaveAs(CanvasNamePdf2.Data());
  */
  
}
