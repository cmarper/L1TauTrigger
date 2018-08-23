{
  bool Draw_Options = kTRUE;
  

  gStyle->SetOptStat(000000);
  TFile f_TT25_er2p1("../Trees_TTrestriction/histos_rate_Run305310_92X_mean_TT25_er2p1.root","READ");
  TFile f_TT25_er2p2("../Trees_TTrestriction/histos_rate_Run305310_92X_mean_TT25_er2p2.root","READ");
  TFile f_TT28_er2p1("../Trees_TTrestriction/histos_rate_Run305310_92X_mean_TT28_er2p1.root","READ");
  TFile f_TT28_er2p2("../Trees_TTrestriction/histos_rate_Run305310_92X_mean_TT28_er2p2.root","READ");

  TH1F* rate_NewLayer1_Option22_TT25_er2p1 = (TH1F*)f_TT25_er2p1.Get("rate_DiTau_Progression_22");
  TH1F* rate_NewLayer1_Option22_TT25_er2p2 = (TH1F*)f_TT25_er2p2.Get("rate_DiTau_Progression_22");
  TH1F* rate_NewLayer1_Option22_TT28_er2p1 = (TH1F*)f_TT28_er2p1.Get("rate_DiTau_Progression_22");
  TH1F* rate_NewLayer1_Option22_TT28_er2p2 = (TH1F*)f_TT28_er2p2.Get("rate_DiTau_Progression_22");
 
  //TString CanvasName = "./Trees/Comparison_Rate_DiTau_Iso_Run305310";
  TString CanvasName = "../PlotIsolation/PlotRate/Comparison_Rate_DiTau_Iso_Run305310_92X_mean_etarestriction28";
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

  rate_NewLayer1_Option22_TT28_er2p1->SetTitle("");
  rate_NewLayer1_Option22_TT28_er2p1->GetXaxis()->SetRangeUser(20.,50.);
  rate_NewLayer1_Option22_TT28_er2p1->GetYaxis()->SetTitle("Di-#tau rate [kHz]");
  
  rate_NewLayer1_Option22_TT25_er2p1->SetLineColor(kBlue);
  rate_NewLayer1_Option22_TT25_er2p1->SetLineWidth(2);
  //rate_NewLayer1_Option22_TT25_er2p1->Draw();

  rate_NewLayer1_Option22_TT25_er2p2->SetLineWidth(2);
  rate_NewLayer1_Option22_TT25_er2p2->SetLineColor(kGreen+2);
  //rate_NewLayer1_Option22_TT25_er2p2->Draw("same");
  
  rate_NewLayer1_Option22_TT28_er2p1->SetLineWidth(2);
  rate_NewLayer1_Option22_TT28_er2p1->SetLineColor(kRed);
  rate_NewLayer1_Option22_TT28_er2p1->Draw();
  
  rate_NewLayer1_Option22_TT28_er2p2->SetLineColor(kMagenta+1);
  rate_NewLayer1_Option22_TT28_er2p2->SetLineWidth(2);
  rate_NewLayer1_Option22_TT28_er2p2->Draw("same");  

  TPaveText* texl = new TPaveText(0.30,0.87,0.95,0.99,"NDC");
  texl->AddText("CMS Internal, #sqrt{s}=13 TeV, Run #305310 (PU ~ 57)");
  texl->SetTextSize(0.04);
  texl->SetFillStyle(0);
  texl->SetBorderSize(0);
  texl->Draw("same");

  TLegend* leg = new TLegend(0.6,0.51,0.89,0.81);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetHeader("Linearly scaled to 2.0E34");
  //leg->AddEntry(rate_NewLayer1_Option22_TT25_er2p1,"TT25, er2p1","L");
  leg->AddEntry(rate_NewLayer1_Option22_TT28_er2p1,"TT28, er2p1","L");
  //leg->AddEntry(rate_NewLayer1_Option22_TT25_er2p2,"TT25, er2p2","L");
  leg->AddEntry(rate_NewLayer1_Option22_TT28_er2p2,"TT28, er2p2","L");

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

  TH1F* ratioPlotTT25 = (TH1F*)rate_NewLayer1_Option22_TT25_er2p2->Clone("ratioPlot25");
  ratioPlotTT25->Divide(rate_NewLayer1_Option22_TT25_er2p1);
  ratioPlotTT25->SetLineColor(kBlack);
  ratioPlotTT25->Draw();

  //TH1F* ratioPlotTT28 = (TH1F*)rate_NewLayer1_Option22_TT28_er2p2->Clone("ratioPlot28");
  //ratioPlotTT28->Divide(rate_NewLayer1_Option22_TT28_er2p1);
  //ratioPlotTT28->SetLineColor(kRed+1);
  //ratioPlotTT28->Draw("same");

  ratioPlot25->GetXaxis()->SetLabelSize(0.09);
  ratioPlot25->GetYaxis()->SetLabelSize(0.09);

  ratioPlot25->GetYaxis()->SetTitleSize(0.09);
  ratioPlot25->SetTitle("");
  // ratioPlot->GetXaxis()->SetRangeUser(20.,100.);
  ratioPlot25->GetXaxis()->SetRangeUser(20.,50.);
  ratioPlot25->GetYaxis()->SetRangeUser(0.981,1.29);
  ratioPlot25->GetYaxis()->SetTitle("er2p2 / er2p1  ");
  ratioPlot25->GetXaxis()->SetTitle("E_{T}^{L1}(#tau) threshold [GeV]");
  // ratioPlot->GetXaxis()->SetTitleOffset(1.3);
  ratioPlot25->GetXaxis()->SetTitleSize(0.11);
  // ratioPlot->GetYaxis()->SetTitle("New/Currently online");
  ratioPlot25->GetYaxis()->SetTitleOffset(0.5);

  // TLine line2(20., 1., 100., 1.);
  TLine line2(20., 1., 60., 1.);
  // TLine line2(0., 1., 40., 1.);
  line2.SetLineColor(kGreen);
  line2.SetLineStyle(2);
  //line2.Draw("same");

  
  c.SaveAs(CanvasNamePdf.Data());





    //find first threshold giving < 10 kHz.
  Double_t Target = 14.;

  Double_t Threshold_NewLayer1_Option22_TT25_er2p1 = 0.;
  Double_t Threshold_NewLayer1_Option22_TT25_er2p2 = 0.;
  Double_t Threshold_NewLayer1_Option22_TT28_er2p1 = 0.;
  Double_t Threshold_NewLayer1_Option22_TT28_er2p2 = 0.;

  for(UInt_t i = 1 ; i <= rate_NewLayer1_Option22_TT25_er2p1->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option22_TT25_er2p1->GetBinContent(i)<=Target)
  	{
  	  Threshold_NewLayer1_Option22_TT25_er2p1 = rate_NewLayer1_Option22_TT25_er2p1->GetBinLowEdge(i);
  	  break;
  	}
    }
 
   for(UInt_t i = 1 ; i <= rate_NewLayer1_Option22_TT25_er2p2->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option22_TT25_er2p2->GetBinContent(i)<=Target)
        {
          Threshold_NewLayer1_Option22_TT25_er2p2 = rate_NewLayer1_Option22_TT25_er2p2->GetBinLowEdge(i);
          break;
        }
    }  

   for(UInt_t i = 1 ; i <= rate_NewLayer1_Option22_TT28_er2p1->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option22_TT28_er2p1->GetBinContent(i)<=Target)
        {
          Threshold_NewLayer1_Option22_TT28_er2p1 = rate_NewLayer1_Option22_TT28_er2p1->GetBinLowEdge(i);
          break;
        }
    }
  
   for(UInt_t i = 1 ; i <= rate_NewLayer1_Option22_TT28_er2p2->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option22_TT28_er2p2->GetBinContent(i)<=Target)
        {
          Threshold_NewLayer1_Option22_TT28_er2p2 = rate_NewLayer1_Option22_TT28_er2p2->GetBinLowEdge(i);
          break;
        }
    }
  

  cout<<"Double_t Threshold_NewLayer1_Option22_TT25_er2p1 = "<<Threshold_NewLayer1_Option22_TT25_er2p1-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option22_TT25_er2p2 = "<<Threshold_NewLayer1_Option22_TT25_er2p2-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option22_TT28_er2p1 = "<<Threshold_NewLayer1_Option22_TT28_er2p1-0.49<<";"<<endl;
  cout<<"Double_t Threshold_NewLayer1_Option22_TT28_er2p2 = "<<Threshold_NewLayer1_Option22_TT28_er2p2-0.49<<";"<<endl;
  cout<<endl;
  cout<<"TString Threshold_NewLayer1_Option22_TT25_er2p1 = \""<<Threshold_NewLayer1_Option22_TT25_er2p1<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option22_TT25_er2p2 = \""<<Threshold_NewLayer1_Option22_TT25_er2p2<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option22_TT28_er2p1 = \""<<Threshold_NewLayer1_Option22_TT28_er2p1<<"\";"<<endl;
  cout<<"TString Threshold_NewLayer1_Option22_TT28_er2p2 = \""<<Threshold_NewLayer1_Option22_TT28_er2p2<<"\";"<<endl;
  
}
