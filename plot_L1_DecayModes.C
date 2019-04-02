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
#include "Helpers.C"
#include <TSystem.h>
#include <TLatex.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TStyle.h>


void plothisto (  TString var, double bins, double xmin, double xmax, TString axislabel, TString filename, bool drawnorm ){

  vector<TString> infiles;
  //infiles.push_back("/data_CMS/cms/mperez/TauTrigger_data/2018/MC/reemulated/outputForCalibration_NTuple_MC_VBFHTauTau_RunIIAutumn18_12Mar19.root");
  infiles.push_back("/data_CMS/cms/mperez/TauTrigger_data/2017/MC/reemulated/outputForCalibration_NTuple_MC_VBFHTauTau_RunIIFall17_12Mar19.root");
 
  vector<TH1F*> histograms;
  histograms.push_back(single_plot(infiles,"outTreeForCalibration",var,"OfflineTau_decayMode==0", bins,xmin,xmax));
  histograms.push_back(single_plot(infiles,"outTreeForCalibration",var,"OfflineTau_decayMode==1", bins,xmin,xmax));
  histograms.push_back(single_plot(infiles,"outTreeForCalibration",var,"OfflineTau_decayMode==10",bins,xmin,xmax));

  TCanvas* c=new TCanvas("c","c",650,600);
  c->SetLeftMargin(0.12);
  c->SetGridx();
  c->SetGridy();

  gStyle->SetOptStat(0);  

  double ymax = 0.1;

  histograms[1]->SetTitle(" ");
  histograms[1]->GetXaxis()->SetTitle(axislabel);
  if(drawnorm) histograms[1]->GetYaxis()->SetTitle("Normalized events");
  else if(!drawnorm) histograms[1]->GetYaxis()->SetTitle("Events");
  histograms[1]->GetXaxis()->SetRangeUser(xmin,xmax);
  histograms[1]->GetYaxis()->SetTitleOffset(1.5);
  histograms[1]->GetXaxis()->SetTitleOffset(1.2);
  histograms[1]->SetLineWidth(2);
  histograms[1]->SetFillColor(0);
  histograms[1]->SetLineColor(kRed);
  histograms[1]->SetFillColor(0);

  TLegend* leg=new TLegend(0.68,0.6,0.83,0.75);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.035);
  leg->SetFillColor(0);
  leg->AddEntry(histograms[0],"1prong");
  leg->AddEntry(histograms[1],"1prong+#pi^{0}");
  leg->AddEntry(histograms[2],"3prongs");

  histograms[0]->SetLineWidth(2);
  histograms[0]->SetFillColor(0);
  histograms[0]->SetLineColor(kBlue);
  histograms[0]->SetFillColor(0);

  histograms[2]->SetLineWidth(2);
  histograms[2]->SetFillColor(0);
  histograms[2]->SetLineColor(kGreen);
  histograms[2]->SetFillColor(0);


  if(drawnorm) histograms[1]->DrawNormalized();
  else if(!drawnorm) histograms[1]->Draw();
    
  if(drawnorm) histograms[0]->DrawNormalized("same");
  else if(!drawnorm) histograms[0]->Draw("same");

  if(drawnorm) histograms[2]->DrawNormalized("same");
  else if(!drawnorm) histograms[2]->Draw("same");

  
  leg->Draw("same");

  TLatex tex;
  tex.SetTextSize(0.035);
  tex.DrawLatexNDC(0.13,0.91,"CMS #bf{#it{Preliminary}}");
  //tex.DrawLatexNDC(0.67,0.91,"Simulation 2018");
  tex.DrawLatexNDC(0.67,0.91,"Simulation 2017");
  tex.DrawLatexNDC(0.57,0.81,"VBF H#rightarrow#tau#tau, PU=28-62");

  if(drawnorm) {
    c->SaveAs("plots_norm/pdf/"+filename+"_norm.pdf");
    c->SaveAs("plots_norm/png/"+filename+"_norm.png");
  }

  if(!drawnorm) {
    c->SaveAs("plots/pdf/"+filename+".pdf");
    c->SaveAs("plots/png/"+filename+".png");
  }

  return;

}

void test(){

  //plothisto("L1Tau_IsoEt/2",40,0,40,"L1 iso. E_{T} [GeV]","l1tEmuIsoEt_decayModes_MC2018",true);
  plothisto("L1Tau_IsoEt/2",40,0,40,"L1 iso. E_{T} [GeV]","l1tEmuIsoEt_decayModes_MC2017",true);

}