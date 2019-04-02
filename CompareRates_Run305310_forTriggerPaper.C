#include <TFile.h>
#include <TGraph.h>
#include <TTree.h>
#include <TString.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TH1D.h>
#include <TH2F.h>
#include <TH3F.h>
#include <iostream>
#include <TLegend.h>
#include <TBranch.h>
#include <TClonesArray.h>
#include <TChain.h>
#include <TMath.h>
#include <TF1.h>
#include <TF2.h>
#include <TSystem.h>
#include <TLatex.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TGaxis.h>
#include <TPaveStats.h>
#include <TAxis.h>
#include <TStyle.h>
#include <TBox.h>

void Plot_rate(){

  TFile f_unpacked("/data_CMS/cms/mperez/TauTrigger/CMSSW_9_2_10/src/TauTagAndProbe/TauTagAndProbe/test//Trees_unpacked/histos_rate_Run305310_92X_Unpacked.root","READ");  

  TH1F* rate_noIso_unpacked = (TH1F*)f_unpacked.Get("rate_noCut_DiTau");
  TH1F* rate_Iso_unpacked   = (TH1F*)f_unpacked.Get("rate_Iso_DiTau");

  TString CanvasName = "./Rate_DiTau_run305310_forTriggerPaper";
  TString CanvasNamePdf = CanvasName ;
  CanvasNamePdf += ".pdf";

  TCanvas c(CanvasName.Data(),CanvasName.Data(),650,650);
  c.SetLeftMargin(0.11);
  c.SetGrid();
  c.SetLogy();

  gStyle->SetOptStat(000000);

  rate_noIso_unpacked->SetTitle("");
  rate_noIso_unpacked->GetXaxis()->SetRangeUser(20.,70.);
  rate_noIso_unpacked->GetYaxis()->SetTitle("L1 double-#tau rate [kHz]");
  rate_noIso_unpacked->GetXaxis()->SetTitle("E^{L1 #tau}_{T} threshold [GeV]");
  rate_noIso_unpacked->GetXaxis()->SetTitleOffset(1.2);
  rate_noIso_unpacked->GetYaxis()->SetTitleOffset(1.2);
  
  rate_noIso_unpacked->SetLineColor(kBlue);
  rate_noIso_unpacked->SetLineWidth(3);
  rate_noIso_unpacked->Draw();

  rate_noIso_unpacked->SetLineColor(kRed);
  rate_Iso_unpacked->SetLineWidth(3);
  rate_Iso_unpacked->Draw("same");  

  //TLatex* texla = new TLatex(20,2800,"#scale[1.2]{CMS} #scale[1.2]{#font[50]{Preliminary}}");
  TLatex* texla = new TLatex(20,2800,"#scale[1.2]{CMS}");
  texla->SetTextAlign(11);
  texla->SetTextSize(0.035);
  texla->Draw("same");

  TLatex* texlb = new TLatex(70,2800,"#scale[1.2]{#font[40]{139 pb^{-1} (13 TeV)}}");
  texlb->SetTextAlign(31);
  texlb->SetTextSize(0.035);
  texlb->Draw("same");

  TBox *box1 = new TBox(45.1,450,69,1900);
  box1->SetFillColor(0);
  box1->SetLineColor(0);
  box1->Draw("same");

  TLatex* texlc = new TLatex(68,1400,"#font[40]{2017 Data}");
  texlc->SetTextAlign(31);
  texlc->SetTextSize(0.035);
  texlc->Draw("same");

  TLatex* texld = new TLatex(68,920,"#font[40]{ZeroBias <PU> = 55}");
  texld->SetTextAlign(31);
  texld->SetTextSize(0.035);
  texld->Draw("same");

  TLatex* texle = new TLatex(68,600,"#font[40]{Linearly scaled to 2.0E34}");
  texle->SetTextAlign(31);
  texle->SetTextSize(0.035);
  texle->Draw("same");

  TLegend* leg = new TLegend(0.57,0.55,0.85,0.65);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.035);
  leg->AddEntry(rate_noIso_unpacked,"Non-isolated #tau's","L");
  leg->AddEntry(rate_Iso_unpacked,"Isolated #tau's","L");

  leg->Draw("same");

  c.cd();
  c.SaveAs(CanvasNamePdf.Data());

}
