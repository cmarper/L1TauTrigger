{
  bool Draw_Options = kTRUE;
  
  gStyle->SetOptStat(000000);
  TFile f_mean("../Trees_meanparam/histos_rate_DiTauasymetric_Run305310_92X_mean.root","READ");

  TH2F* rate_NewLayer1_noIso_mean   = (TH2F*)f_mean.Get("rate_noCut_DiTau");
  TH2F* rate_NewLayer1_Option15_mean = (TH2F*)f_mean.Get("rate_DiTau_Progression_1");

  TString CanvasName = "../PlotIsolation/PlotRate/Comparison_Rate_DiTau_Asymmetric_Run305310_92X_mean_Option1";
  TString CanvasNamePdf = CanvasName ;
  CanvasNamePdf += ".pdf";

  TCanvas c(CanvasName.Data(),CanvasName.Data(),650,600);
  c.SetRightMargin(0.15);
  c.SetGrid();

  TPaveText* texl = new TPaveText(0.12,0.87,0.9,0.99,"NDC");
  texl->AddText("CMS Internal, #sqrt{s}=13 TeV, Run #305310 (PU ~ 57)");
  texl->SetTextSize(0.035);
  texl->SetFillStyle(0);
  texl->SetBorderSize(0);
  
  TPaveText* tex2 = new TPaveText(0.12,0.84,0.35,0.87,"NDC");
  tex2->AddText("#splitline{Linearly scaled to 2.0E34}{Iso Option 1}");
  tex2->SetTextSize(0.025);
  tex2->SetFillStyle(0);
  tex2->SetBorderSize(0);

  TPaveText* tex7kHz = new TPaveText(0.13,0.59,0.2,0.69,"NDC");
  tex7kHz->AddText("7 kHz");
  tex7kHz->SetTextSize(0.03);
  tex7kHz->SetFillStyle(0);
  tex7kHz->SetBorderSize(0);
  tex7kHz->SetTextColor(2);

  TPaveText* tex9kHz = new TPaveText(0.13,0.40,0.2,0.50,"NDC");
  tex9kHz->AddText("9 kHz");
  tex9kHz->SetTextSize(0.03);
  tex9kHz->SetFillStyle(0);
  tex9kHz->SetBorderSize(0);
  tex9kHz->SetTextColor(8);
  
  TPaveText* tex14kHz = new TPaveText(0.13,0.11,0.2,0.21,"NDC");
  tex14kHz->AddText("14 kHz");
  tex14kHz->SetTextSize(0.03);
  tex14kHz->SetFillStyle(0);
  tex14kHz->SetBorderSize(0);
  tex14kHz->SetTextColor(6);

  TPaveText* tex25kHz = new TPaveText(0.13,0.17,0.2,0.27,"NDC");
  tex25kHz->AddText("25 kHz");
  tex25kHz->SetTextSize(0.03);
  tex25kHz->SetFillStyle(0);
  tex25kHz->SetBorderSize(0);
  tex25kHz->SetTextColor(4);

  Double_t contours[4];
  contours[0] = 7;
  contours[1] = 9;
  contours[2] = 14;
  contours[3] = 25;
  Int_t colors_15[4];
  colors_15[0] = 2;
  colors_15[1] = 8;
  colors_15[2] = 6;
  colors_15[3] = 4;
 
  gStyle->SetPalette(1,colors_15); 
  TH2F *hcontours_Option15 = (TH2F*) rate_NewLayer1_Option15_mean->Clone();
  hcontours_Option15->SetFillColor(0);
  hcontours_Option15->SetContour(4,contours);
  gStyle->SetPalette(4,colors_15);
  hcontours_Option15->SetLineWidth(2);
  hcontours_Option15->Draw("cont1 list");//cont1 for line plot!
  hcontours_Option15->SetTitle("");
  hcontours_Option15->GetXaxis()->SetRangeUser(20.,60.);
  hcontours_Option15->GetYaxis()->SetRangeUser(20.,60.);
  hcontours_Option15->GetXaxis()->SetTitle("Leading #tau E_{T} threshold [GeV]");
  hcontours_Option15->GetYaxis()->SetTitle("Sub-leading #tau E_{T} threshold [GeV]");
  gPad->Update();
  
  gROOT->Reset();
  texl->Draw("same");
  tex2->Draw("same");
  tex7kHz->Draw("same");
  tex9kHz->Draw("same");
  tex14kHz->Draw("same");
  //tex25kHz->Draw("same");
  
  //TLegend* leg = new TLegend(0.5,0.77,0.75,0.86);
  //leg->SetBorderSize(0);
  //leg->SetTextSize(0.03);
  //leg->AddEntry((TObject*)0,"Linearly scaled to 2.0E34","");
  //leg->AddEntry((TObject*)0,"Iso Option 22","");
  //leg->AddEntry((TObject*)0,"caloStage2Params_2017_v1_10_mean_inconsistent","");
  //leg->Draw("same");
  
  TMarker* sym7 = new TMarker(48,48,20);
  sym7->SetMarkerSize(1.5);
  sym7->SetMarkerColor(2);
  sym7->Draw("same");
  
  TMarker* sym9 = new TMarker(37,37,20);
  sym9->SetMarkerSize(1.5);
  sym9->SetMarkerColor(8);
  sym9->Draw("same");

  TMarker* sym9a = new TMarker(40,36,22);
  sym9a->SetMarkerSize(1.7);
  sym9a->SetMarkerColor(8);
  sym9a->Draw("same");

  TMarker* sym9b = new TMarker(44,35,21);
  sym9b->SetMarkerSize(1.5);
  sym9b->SetMarkerColor(8);
  sym9b->Draw("same");

  TMarker* sym9c = new TMarker(46,29,23);
  sym9c->SetMarkerSize(1.7);
  sym9c->SetMarkerColor(8);
  sym9c->Draw("same");

  TMarker* sym9d = new TMarker(48,28,33);
  sym9d->SetMarkerSize(2);
  sym9d->SetMarkerColor(8);
  sym9d->Draw("same");

  TMarker* sym9e = new TMarker(50,23,34);
  sym9e->SetMarkerSize(1.7);
  sym9e->SetMarkerColor(8);
  sym9e->Draw("same");

  TMarker* sym9f = new TMarker(52,22,29);
  sym9f->SetMarkerSize(2);
  sym9f->SetMarkerColor(8);
  sym9f->Draw("same");
  
  TMarker* sym14 = new TMarker(21,21,20);
  sym14->SetMarkerSize(1.5);
  sym14->SetMarkerColor(6);
  sym14->Draw("same");

  TMarker* sym25 = new TMarker(27,27,20);
  sym25->SetMarkerSize(1.5);
  sym25->SetMarkerColor(4);
  //sym25->Draw("same");

  TLegend* leg = new TLegend(0.32,0.68,0.52,0.85);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.025);
  leg->SetHeader("#bf{Symmetric di-tau}");
  leg->AddEntry(sym7,"7 kHz: (48,48) GeV","p");
  leg->AddEntry(sym9,"9 kHz: (43,43) GeV","p");
  leg->AddEntry(sym14,"14 kHz: (34,34) GeV","p");
  //leg->AddEntry(sym25,"25 kHz: (27,27) GeV","p");
  
  TLegend* leg2 = new TLegend(0.57,0.68,0.82,0.88);
  leg2->SetBorderSize(0);
  leg2->SetTextSize(0.025);
  leg2->SetHeader("#bf{Asymmetric di-tau, 9 kHz}");
  leg2->AddEntry(sym9a,"(40,36) GeV","p");
  leg2->AddEntry(sym9b,"(44,35) GeV","p");
  leg2->AddEntry(sym9c,"(46,29) GeV","p");
  leg2->AddEntry(sym9d,"(48,28) GeV","p");
  leg2->AddEntry(sym9e,"(50,23) GeV","p");
  leg2->AddEntry(sym9f,"(52,22) GeV","p");
  //leg2->AddEntry(sym9e,"(50,24) GeV","p");

  //leg->AddEntry((TObject*)0,"caloStage2Params_2017_v1_10_mean_inconsistent","");
  
  leg->Draw("same");
  leg2->Draw("same");

  c.SaveAs("../PlotIsolation/PlotRate/Rate_tau_asym_305310_Option1_9kHz.pdf","pdf");
  
  /*TH2F *hcontours_noIso = (TH2F*) rate_NewLayer1_noIso_mean->Clone();
  hcontours_noIso->SetFillColor(0);
 // hcontours_noIso->SetContour(1,contours);
  hcontours_noIso->UseCurrentStyle();
  //hcontours_noIso->SetContourLevel(1,14);
  //gStyle->SetPalette(1,colors_noIso);
  gPad->Update();
  hcontours_noIso->SetLineWidth(2);
 // hcontours_noIso->Draw("cont1 same");
  hcontours_noIso->SetLineColor(kRed);
  gPad->Update();
  */

/*
  TObjArray *conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
  TList* contLevel = NULL;
  TGraph* curv     = NULL;
 // TGraph* gc       = NULL; 
  Int_t TotalConts = 0;

  if (conts == NULL){
      printf("*** No Contours Were Extracted!\n");
      TotalConts = 0;
      return 0;
   }
  
  TotalConts = conts->GetSize();
  cout << TotalConts << endl;
  for(i = 0; i < TotalConts; i++){
      contLevel = (TList*)conts->At(i);
      printf("Contour %d has %d Graphs\n", i, contLevel->GetSize());
      //nGraphs += contLevel->GetSize();
   }

  curv = (TGraph*)contLevel->Second();  
  cout << "x=28, y=" << curv->Eval(28);
*/ 
  //find first threshold giving < 10 kHz.
  Double_t Target = 9;
   
  for(UInt_t j = 1 ; j <= rate_NewLayer1_Option15_mean->GetNbinsY() ; ++j)
  {
    for(UInt_t i = 1 ; i <= rate_NewLayer1_Option15_mean->GetNbinsX() ; ++i)
    {
      if(rate_NewLayer1_Option15_mean->GetBinContent(i,j)<=Target){
        if(rate_NewLayer1_Option15_mean->GetXaxis()->GetBinLowEdge(i) == 54){
  	//  if(rate_NewLayer1_Option15_mean->GetXaxis()->GetBinLowEdge(i) == rate_NewLayer1_Option15_mean->GetYaxis()->GetBinLowEdge(j)){
           cout << "Thr 1 " << rate_NewLayer1_Option15_mean->GetXaxis()->GetBinLowEdge(i) << " " ;
  	   cout << "Thr 2 " << rate_NewLayer1_Option15_mean->GetYaxis()->GetBinLowEdge(j) << endl;
           break;
           }
       //break;
       }  
    }
  }

}

