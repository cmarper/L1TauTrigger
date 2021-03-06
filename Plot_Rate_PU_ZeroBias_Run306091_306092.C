#include <iostream>
#include <sstream>
#include <fstream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <iostream>
#include <TLorentzVector.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TPaveText.h>
#include <TStyle.h>
#include <TROOT.h>
#include <TMultiGraph.h>
#include <TGraphErrors.h>
#include <TPaveStats.h>

using namespace std;

void PlotRate()
{
 float value1;    
 float value2;
 float value3;
 float value4;
 char str[256];
 int nn = 60;//21

 float *PU = new float[nn];
 float *delta_PU = new float[nn];
 float *rate_noIso = new float[nn];
 float *delta_rate_noIso = new float[nn];
 float *rate_Option22 = new float[nn];
 float *delta_rate_Option22 = new float[nn];
 float *rate_Option22_newnTT = new float[nn];
 float *delta_rate_Option22_newnTT = new float[nn];
 float *ratio_Option22 = new float[nn];
 float *delta_ratio_Option22 = new float[nn]; 


 ifstream infile_noIso("rates_PU_306091_mean/good_merged/rate_PU_noIso_run306091and2.txt",ios::in);  
  if(!infile_noIso.is_open()){
     cout << "No inputfile to open!" << endl;
  } 
  
 for (int i = 0; i < nn; i++){
   infile_noIso.getline(str,256);
   sscanf(str, "%f %f %f %f", &value1, &value2, &value3, &value4);
   PU[i] = value1;
   delta_PU[i] = value2;
   rate_noIso[i] = value3;
   delta_rate_noIso[i] = value4;
   //cout << PU[i] << " " << delta_PU[i] << " " << rate_noIso[i] << " " << delta_rate_noIso[i] << endl;
  } 

  ifstream infile_option22("rates_PU_306091_mean/good_merged/rate_PU_Option22_run306091and2.txt",ios::in);
  if(!infile_option22.is_open()){
     cout << "No inputfile to open!" << endl;
  }

 for (int i = 0; i < nn; i++){
   infile_option22.getline(str,256);
   sscanf(str, "%f %f %f %f", &value1, &value2, &value3, &value4);
   PU[i] = value1;
   delta_PU[i] = value2;
   rate_Option22[i] = value3;
   delta_rate_Option22[i] = value4;
  // cout << PU[i] << " " << delta_PU[i] << " " << rate_Option22[i] << " " << delta_rate_Option22[i] << endl;
  }

  ifstream infile_option22_newnTT("rates_PU_306091_mean/good_merged/rate_PU_Option22_run306091and2_newnTT.txt",ios::in);
  if(!infile_option22_newnTT.is_open()){
     cout << "No inputfile to open!" << endl;
  }

 for (int i = 0; i < nn; i++){
   infile_option22_newnTT.getline(str,256);
   sscanf(str, "%f %f %f %f", &value1, &value2, &value3, &value4);
   PU[i] = value1;
   delta_PU[i] = value2;
   rate_Option22_newnTT[i] = value3;
   delta_rate_Option22_newnTT[i] = value4;
  // cout << PU[i] << " " << delta_PU[i] << " " << rate_Option22[i] << " " << delta_rate_Option22[i] << endl;
  }

 for (int i = 0; i < nn; i++){
   ratio_Option22[i] = rate_Option22_newnTT[i]/rate_Option22[i];
  // cout << ratio_Option22[i];
  // delta_ratio_Option22[i] = ratio_Option22[i]*(delta_rate_Option22[i]/rate_Option22[i] + delta_rate_Option22_newnTT[i]/rate_Option22_newnTT[i]);
   delta_ratio_Option22[i] = 0;
   //cout << " " << delta_ratio_Option22[i] << endl;
  }
 
 gStyle->SetOptFit(0);
 TCanvas *c1 = new TCanvas("c1","multigraph",700,750);
 c1->SetGrid();

 TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
 pad1->SetBottomMargin(0.0); // Upper and lower plot are joined
 pad1->Draw();             // Draw the upper pad: pad1
 pad1->SetGrid();
 pad1->cd();               // pad1 becomes the current pad
  
 TMultiGraph *mg = new TMultiGraph();
 
 TGraphErrors *gr_noIso = new TGraphErrors(nn,PU,rate_noIso,delta_PU,delta_rate_noIso);
 gr_noIso->SetMarkerColor(kBlue);
 gr_noIso->SetMarkerStyle(21);
 gr_noIso->Fit("pol1","q");
 gr_noIso->GetFunction("pol1")->SetLineColor(kBlue);
 gr_noIso->GetFunction("pol1")->SetLineWidth(2);
 gr_noIso->GetFunction("pol1")->SetLineStyle(2);
 //mg->Add(gr_noIso);

 TGraphErrors *gr_option22 = new TGraphErrors(nn,PU,rate_Option22,delta_PU,delta_rate_Option22);
 gr_option22->SetMarkerColor(kRed);
 //gr_option22->SetLineColor(kRed);
 gr_option22->SetMarkerStyle(21);
 //gr_option22->Fit("pol2","q");
 //gr_option22->GetFunction("pol2")->SetLineColor(kRed);
 //gr_option22->GetFunction("pol2")->SetLineWidth(2);
 //gr_option22->GetFunction("pol2")->SetLineStyle(2);
 mg->Add(gr_option22);
 
 TGraphErrors *gr_option22_newnTT = new TGraphErrors(nn,PU,rate_Option22_newnTT,delta_PU,delta_rate_Option22_newnTT);
 gr_option22_newnTT->SetMarkerColor(kGreen+1);
 //gr_option22_newnTT->SetLineColor(kGreen+1);
 gr_option22_newnTT->SetMarkerStyle(21);
 //gr_option22_newnTT->Fit("pol2","q");
 //gr_option22_newnTT->GetFunction("pol2")->SetLineColor(kGreen+1);
 //gr_option22_newnTT->GetFunction("pol2")->SetLineWidth(2);
 //gr_option22_newnTT->GetFunction("pol2")->SetLineStyle(2);
 mg->Add(gr_option22_newnTT);

 mg->Draw("ap");

 mg->GetXaxis()->SetTitle("PU");
 mg->GetYaxis()->SetTitle("Di-#tau rate [kHz]");
 mg->GetXaxis()->SetLimits(27,80);
 mg->GetYaxis()->SetRangeUser(0.001,25);
 gPad->Modified();
 gPad->Update();
  
 TPaveText* texl = new TPaveText(0.16,0.87,0.95,0.99,"NDC");
 texl->AddText("CMS Internal, #sqrt{s}=13 TeV, Runs #306091 and #306092");
 texl->SetTextSize(0.04);
 texl->SetFillStyle(0);
 texl->SetBorderSize(0);
 texl->Draw("same");
 
 TLegend *leg = new TLegend(0.12,0.68,0.48,0.87);
 leg->SetBorderSize(0);
 leg->SetTextSize(0.03);
 leg->SetFillColor(kWhite);
 leg->SetHeader("#splitline{Linearly scaled to 2.0E34}{E_{T}^{L1}(#tau) > 32 GeV}");
 leg->AddEntry((TObject*)0," ","");
 //leg->AddEntry(gr_noIso, "Di-#tau no-iso","AP");
 //leg->AddEntry(gr_option22, "Di-#tau iso, old nTT (Option 22)","AP");
 leg->AddEntry(gr_option22_newnTT, "Di-#tau iso (Option 22), new nTT","AP");
 leg->AddEntry(gr_option22, "Di-#tau iso (Option 22), old nTT","AP");
 leg->Draw("same");

 c1->cd();

 TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
 pad2->SetTopMargin(0);
 //pad2->SetLeftMargin(0.15);
 pad2->SetBottomMargin(0.30);
 pad2->Draw();
 pad2->SetGrid();
 pad2->cd();

 TLine line4(27., 1., 80., 1.);
 // TLine line3(0., 1., 40., 1.);
 line4.SetLineColor(kBlue);
 line4.SetLineStyle(2);
 line4.SetLineWidth(3);
 line4.Draw();

 TGraphErrors *gr_ratio22 = new TGraphErrors(nn,PU,ratio_Option22,delta_PU,delta_ratio_Option22);
 gr_ratio22->SetMarkerColor(kBlack);
 gr_ratio22->SetMarkerStyle(21);
 gr_ratio22->Draw();

 gr_ratio22->GetXaxis()->SetLabelSize(0.095);
 gr_ratio22->GetYaxis()->SetLabelSize(0.095);
 gr_ratio22->GetYaxis()->SetRangeUser(0.9,1.29);
 gr_ratio22->GetXaxis()->SetLimits(27,80);
 gr_ratio22->GetXaxis()->SetTitleSize(0.095);
 gr_ratio22->GetYaxis()->SetTitleSize(0.095);
 gr_ratio22->GetYaxis()->SetTitleOffset(0.5);
 gr_ratio22->SetTitle("");
 gr_ratio22->GetYaxis()->SetTitle("new nTT / old nTT");
 gr_ratio22->GetXaxis()->SetTitle("<PU>");

 c1->Update();

 //TLine line4(27., 1., 80., 1.);
 // TLine line3(0., 1., 40., 1.);
 //line4.SetLineColor(kBlue);
 //line4.SetLineStyle(2);
 //line4.SetLineWidth(3);
 line4.Draw();
// gPad->Modified();
// gPad->Update();

// c1->Modified();
 c1->Update();

/* 
 TPaveStats* sb1=(TPaveStats*)(gr_noIso->GetListOfFunctions()->FindObject("stats"));
 sb1->SetX1NDC(.2);
 sb1->SetX2NDC(.4);
 sb1->SetY1NDC(.7);
 sb1->SetY2NDC(.9);
 sb1->SetTextColor(kBlue);
 gPad->Modified();

 TPaveStats* sb2=(TPaveStats*)(gr_option22->GetListOfFunctions()->FindObject("stats"));
 sb2->SetX1NDC(.2);
 sb2->SetX2NDC(.4);
 sb2->SetY1NDC(.7);
 sb2->SetY2NDC(.9);
 sb2->SetTextColor(kRed);
 gPad->Modified();
*/
  
 c1->SaveAs("rates_PU_306091_mean/plot_rate_PU_withnewnTT_306091_306092.png","png");
 c1->SaveAs("rates_PU_306091_mean/plot_rate_PU_withnewnTT_306091_306092.pdf","pdf");

 return;
}
