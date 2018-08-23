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
#include <sstream>
#include <TBranchElement.h>
#include <fstream>
#include <TGraphAsymmErrors.h>
#include <stdio.h>
#include <math.h>
#include "ApplyCalibration.C"

using namespace std;

void ComputeAcceptance(TString InputFileName = "./Trees_meanparam/calibratedOutput_Ntuple_MC_92X_mean.root")
{
  std::map<TString,TH3F*> histosIsolation;
  TFile f_Isolation("./Trees_meanparam/Iso_LUTs_Options_MC_92X_mean.root");

  for(UInt_t i = 0 ; i < 101 ; ++i)
    {
      TString CurrentNameHisto = "LUT_WP";
      ostringstream convert;
      convert << i;
      CurrentNameHisto += convert.str();
      TH3F* current_Histo = (TH3F*)f_Isolation.Get(CurrentNameHisto.Data());
      histosIsolation.insert(make_pair(CurrentNameHisto,current_Histo));
    }  

  for(UInt_t i = 1 ; i < 23 ; ++i)
    {
      TString CurrentNameHisto = "LUT_Progression_";
      ostringstream convert;
      convert << i;
      CurrentNameHisto += convert.str();
      TH3F* current_Histo = (TH3F*)f_Isolation.Get(CurrentNameHisto.Data());
      histosIsolation.insert(make_pair(CurrentNameHisto,current_Histo));
    }  

  TFile f(InputFileName.Data(),"READ");
  TTree* inTree = (TTree*)f.Get("outTreeForCalibration");

  Int_t           in_L1Tau_IEta;
  Int_t           in_compressedsortedshape;
  Int_t           in_L1Tau_hasEM;
  Float_t         in_Target;
  Int_t           in_L1Tau_IEt;
  Int_t           in_L1Tau_RawIEt;
  Int_t           in_EventNumber;
  Int_t           in_RunNumber;
  Int_t           in_L1Tau_nTT;
  Float_t         in_L1Tau_pt;
  Float_t         in_L1Tau_CalibPt;
  Float_t         in_OfflineTau_pt;
  Int_t           in_compressedieta;
  Int_t           in_compressedE;
  Int_t           in_L1Tau_Iso;
  Int_t           in_compressednTT;
  Int_t           in_OfflineTau_isMatched;
  Int_t           in_L1Tau_isMerged;
  Int_t           in_compressedshape;
  Int_t           in_supercompressedE;
  Int_t           in_supercompressednTT;
  Int_t           in_L1Tau_Qual;
  Bool_t          in_L1Tau_PassShapeVeto;
  Bool_t          L1Tau_PassShapeVeto_0p6_10_50;
  Bool_t          L1Tau_PassShapeVeto_0p5_20_45;
  Bool_t          L1Tau_PassShapeVeto_0p2_25_60;
  Bool_t          L1Tau_PassShapeVeto_0p2_20_100;

  inTree->SetBranchAddress("L1Tau_IEta", &in_L1Tau_IEta);
  inTree->SetBranchAddress("compressedsortedshape", &in_compressedsortedshape);
  inTree->SetBranchAddress("L1Tau_hasEM", &in_L1Tau_hasEM);
  inTree->SetBranchAddress("Target", &in_Target);
  inTree->SetBranchAddress("L1Tau_IEt", &in_L1Tau_IEt);
  inTree->SetBranchAddress("L1Tau_RawIEt", &in_L1Tau_RawIEt);
  inTree->SetBranchAddress("EventNumber", &in_EventNumber);
  inTree->SetBranchAddress("RunNumber", &in_RunNumber);
  inTree->SetBranchAddress("L1Tau_nTT", &in_L1Tau_nTT);
  inTree->SetBranchAddress("L1Tau_pt", &in_L1Tau_pt);
  inTree->SetBranchAddress("L1Tau_CalibPt", &in_L1Tau_CalibPt);
  inTree->SetBranchAddress("OfflineTau_pt", &in_OfflineTau_pt);
  inTree->SetBranchAddress("compressedieta", &in_compressedieta);
  inTree->SetBranchAddress("compressedE", &in_compressedE);
  inTree->SetBranchAddress("L1Tau_Iso", &in_L1Tau_Iso);
  inTree->SetBranchAddress("compressednTT", &in_compressednTT);
  inTree->SetBranchAddress("OfflineTau_isMatched", &in_OfflineTau_isMatched);
  inTree->SetBranchAddress("L1Tau_isMerged", &in_L1Tau_isMerged);
  inTree->SetBranchAddress("compressedshape", &in_compressedshape);
  inTree->SetBranchAddress("supercompressedE", &in_supercompressedE);
  inTree->SetBranchAddress("supercompressednTT", &in_supercompressednTT);
  inTree->SetBranchAddress("L1Tau_PassShapeVeto", &in_L1Tau_PassShapeVeto);
  inTree->SetBranchAddress("L1Tau_Qual",&in_L1Tau_Qual);

  //Double_t binning[22] = {18,20,22,24,26,28,30,32,35,40,45,50,60,70,90,110,210,350,500,700,1000,2000};
  TH1F* denominator =  new TH1F("denominator","denominator",125,0,250);
  TH1F* numerator_noIso   = new TH1F("numerator_noIso"  ,"numerator_noIso"  ,125,0,250);
  TH1F* numerator_Option1   = new TH1F("numerator_Option1"  ,"numerator_Option1"  ,125,0,250);
  TH1F* numerator_Option2   = new TH1F("numerator_Option2"  ,"numerator_Option2"  ,125,0,250);
  TH1F* numerator_Option3   = new TH1F("numerator_Option3"  ,"numerator_Option3"  ,125,0,250);
  TH1F* numerator_Option4   = new TH1F("numerator_Option4"  ,"numerator_Option4"  ,125,0,250);
  TH1F* numerator_Option5   = new TH1F("numerator_Option5"  ,"numerator_Option5"  ,125,0,250);
  TH1F* numerator_Option6   = new TH1F("numerator_Option6"  ,"numerator_Option6"  ,125,0,250);
  TH1F* numerator_Option7   = new TH1F("numerator_Option7"  ,"numerator_Option7"  ,125,0,250);
  TH1F* numerator_Option8   = new TH1F("numerator_Option8"  ,"numerator_Option8"  ,125,0,250);
  TH1F* numerator_Option9   = new TH1F("numerator_Option9"  ,"numerator_Option9"  ,125,0,250);
  TH1F* numerator_Option10  = new TH1F("numerator_Option10" ,"numerator_Option10" ,125,0,250);
  TH1F* numerator_Option11  = new TH1F("numerator_Option11" ,"numerator_Option11" ,125,0,250);
  TH1F* numerator_Option12  = new TH1F("numerator_Option12" ,"numerator_Option12" ,125,0,250);
  TH1F* numerator_Option13  = new TH1F("numerator_Option13" ,"numerator_Option13" ,125,0,250);
  TH1F* numerator_Option14  = new TH1F("numerator_Option14" ,"numerator_Option14" ,125,0,250);
  TH1F* numerator_Option15  = new TH1F("numerator_Option15" ,"numerator_Option15" ,125,0,250);
  TH1F* numerator_Option16  = new TH1F("numerator_Option16" ,"numerator_Option16" ,125,0,250);
  TH1F* numerator_Option17  = new TH1F("numerator_Option17" ,"numerator_Option17" ,125,0,250);
  TH1F* numerator_Option18  = new TH1F("numerator_Option18" ,"numerator_Option18" ,125,0,250);
  TH1F* numerator_Option19  = new TH1F("numerator_Option19" ,"numerator_Option19" ,125,0,250);
  TH1F* numerator_Option20  = new TH1F("numerator_Option20" ,"numerator_Option20" ,125,0,250);
  TH1F* numerator_Option21  = new TH1F("numerator_Option21" ,"numerator_Option21" ,125,0,250);
  TH1F* numerator_Option22  = new TH1F("numerator_Option22" ,"numerator_Option22" ,125,0,250);

  Double_t Threshold_NewLayer1_noIso   = 37.51;
  Double_t Threshold_NewLayer1_Option1 = 20.51;
  Double_t Threshold_NewLayer1_Option2 = 27.51;
  Double_t Threshold_NewLayer1_Option3 = 28.51;
  Double_t Threshold_NewLayer1_Option4 = 28.51;
  Double_t Threshold_NewLayer1_Option5 = 31.51;
  Double_t Threshold_NewLayer1_Option6 = 34.51;
  Double_t Threshold_NewLayer1_Option7 = 34.51;
  Double_t Threshold_NewLayer1_Option8 = 25.51;
  Double_t Threshold_NewLayer1_Option9 = 34.51;
  Double_t Threshold_NewLayer1_Option10 = 34.51;
  Double_t Threshold_NewLayer1_Option11 = 36.51;
  Double_t Threshold_NewLayer1_Option12 = 37.51;
  Double_t Threshold_NewLayer1_Option13 = 37.51;
  Double_t Threshold_NewLayer1_Option14 = 37.51;
  Double_t Threshold_NewLayer1_Option15 = 33.51;
  Double_t Threshold_NewLayer1_Option16 = 37.51;
  Double_t Threshold_NewLayer1_Option17 = 37.51;
  Double_t Threshold_NewLayer1_Option18 = 37.51;
  Double_t Threshold_NewLayer1_Option19 = 37.51;
  Double_t Threshold_NewLayer1_Option20 = 37.51;
  Double_t Threshold_NewLayer1_Option21 = 33.51;
  Double_t Threshold_NewLayer1_Option22 = 26.51;
   
  map<int, int> remap;
  remap[0] = 6 ;
  remap[1] = 5 ;
  remap[2] = 1 ;
  remap[3] = 0 ;
  remap[4] = 4 ;
  remap[5] = 3 ;
  remap[6] = 2 ;
  
  for(UInt_t i = 0 ; i < inTree->GetEntries() ; ++i)
    {
      inTree->GetEntry(i);
     // if (inOfflineTau_eta < 2.1) continue;
      if (in_OfflineTau_pt >= 30) denominator->Fill(in_OfflineTau_pt);

      Int_t Cut_L1Tau_Iso_Option1   = histosIsolation["LUT_Progression_1"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option2   = histosIsolation["LUT_Progression_2"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option3   = histosIsolation["LUT_Progression_3"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option4   = histosIsolation["LUT_Progression_4"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option5   = histosIsolation["LUT_Progression_5"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option6   = histosIsolation["LUT_Progression_6"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option7   = histosIsolation["LUT_Progression_7"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option8   = histosIsolation["LUT_Progression_8"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option9   = histosIsolation["LUT_Progression_9"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option10  = histosIsolation["LUT_Progression_10"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option11  = histosIsolation["LUT_Progression_11"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option12  = histosIsolation["LUT_Progression_12"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option13  = histosIsolation["LUT_Progression_13"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option14  = histosIsolation["LUT_Progression_14"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option15  = histosIsolation["LUT_Progression_15"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option16  = histosIsolation["LUT_Progression_16"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option17  = histosIsolation["LUT_Progression_17"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option18  = histosIsolation["LUT_Progression_18"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option19  = histosIsolation["LUT_Progression_19"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option20  = histosIsolation["LUT_Progression_20"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option21  = histosIsolation["LUT_Progression_21"] ->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
      Int_t Cut_L1Tau_Iso_Option22  = histosIsolation["LUT_Progression_22"]->GetBinContent(in_compressedieta+1,in_compressedE+1,in_compressednTT+1);
	
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_noIso && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_noIso->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option1 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option1 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option1->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option2 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option2 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option2->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option3 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option3 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option3->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option4 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option4 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option4->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option5 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option5 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option5->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option6 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option6 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option6->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option7 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option7 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option7->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option8 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option8 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option8->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option9 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option9 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option9->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option10 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option10 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option10->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option11 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option11 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option11->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option12 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option12 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option12->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option13 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option13 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option13->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option14 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option14 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option14->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option15 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option15 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option15->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option16 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option16 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option16->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option17 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option17 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option17->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option18 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option18 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option18->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option19 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option19 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option19->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option20 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option20 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option20->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option21 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option21 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option21->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option22 && in_L1Tau_Iso<=Cut_L1Tau_Iso_Option22 && in_OfflineTau_pt >= 30 && in_OfflineTau_isMatched) numerator_Option22->Fill(in_OfflineTau_pt);
      
    }
  double sumDen = 0;
  double sumNum_noIso = 0; 
  double sumNum_Option1 = 0; 
  double sumNum_Option2 = 0;
  double sumNum_Option3 = 0; 
  double sumNum_Option4 = 0; 
  double sumNum_Option8 = 0; 
  double sumNum_Option22 = 0;
  
  for(Int_t bin = 1 ; bin < numerator_noIso->GetNbinsX() ; ++bin)
   {
     if(denominator->GetXaxis()->GetBinLowEdge(bin)>=30.) sumDen += denominator->GetBinContent(bin);
     if(numerator_noIso->GetXaxis()->GetBinLowEdge(bin)>=30.) sumNum_noIso += numerator_noIso->GetBinContent(bin);
     if(numerator_Option1->GetXaxis()->GetBinLowEdge(bin)>=30.) sumNum_Option1 += numerator_Option1->GetBinContent(bin);
     if(numerator_Option2->GetXaxis()->GetBinLowEdge(bin)>=30.) sumNum_Option2 += numerator_Option2->GetBinContent(bin);
     if(numerator_Option3->GetXaxis()->GetBinLowEdge(bin)>=30.) sumNum_Option3 += numerator_Option3->GetBinContent(bin);
     if(numerator_Option4->GetXaxis()->GetBinLowEdge(bin)>=30.) sumNum_Option4 += numerator_Option4->GetBinContent(bin);
     if(numerator_Option8->GetXaxis()->GetBinLowEdge(bin)>=30.) sumNum_Option8 += numerator_Option8->GetBinContent(bin);
     if(numerator_Option22->GetXaxis()->GetBinLowEdge(bin)>=30.) sumNum_Option22 += numerator_Option22->GetBinContent(bin);
   }

  double acceptance_noIso = sumNum_noIso/sumDen;
  double acceptance_Option1 = sumNum_Option1/sumDen;
  double acceptance_Option2 = sumNum_Option2/sumDen;
  double acceptance_Option3 = sumNum_Option3/sumDen;
  double acceptance_Option4 = sumNum_Option4/sumDen;
  double acceptance_Option8 = sumNum_Option8/sumDen;
  double acceptance_Option22 = sumNum_Option22/sumDen;

  cout << "No Iso: " << acceptance_noIso*100 << "%" << endl;
  cout << "Option 1: " << acceptance_Option1*100 << "%" << endl;
  cout << "Option 2: " << acceptance_Option2*100 << "%" << endl;
  cout << "Option 3: " << acceptance_Option3*100 << "%" << endl;
  cout << "Option 4: " << acceptance_Option4*100 << "%" << endl;
  cout << "Option 8: " << acceptance_Option8*100 << "%" << endl;
  cout << "Option 22: " << acceptance_Option22*100 << "%" <<  endl;

  gStyle->SetOptStat(000000);

  TFile *acceptance = new TFile("Trees_meanparam/pt_acceptance_mean.root","RECREATE");
 
  TCanvas c1("c1","c1",800,800);
  c1.SetGrid();
 
  denominator->SetLineWidth(2);
  denominator->SetLineColor(kGray+2); 
  denominator->GetXaxis()->SetLabelSize(0.025);
  denominator->GetYaxis()->SetLabelSize(0.025);
  denominator->GetXaxis()->SetTitle("p_{T}^{offl} [GeV]");
  denominator->GetYaxis()->SetTitle("a. u.");
  denominator->SetTitle(" ");
  denominator->Draw();
  numerator_noIso->SetLineWidth(2);
  numerator_noIso->SetLineColor(kBlack);
  numerator_noIso->Draw("same");
  numerator_Option1->SetLineWidth(2);
  numerator_Option1->SetLineColor(kMagenta);
  numerator_Option1->Draw("same");
  numerator_Option2->SetLineWidth(2);
  numerator_Option2->SetLineColor(kCyan);
  numerator_Option2->Draw("same");
  numerator_Option3->SetLineWidth(2);
  numerator_Option3->SetLineColor(kOrange);
  numerator_Option3->Draw("same");
  numerator_Option4->SetLineWidth(2);
  numerator_Option4->SetLineColor(kBlue);
  numerator_Option4->Draw("same");
  numerator_Option8->SetLineWidth(2);
  numerator_Option8->SetLineColor(kGreen+2);
  numerator_Option8->Draw("same");
  numerator_Option22->SetLineWidth(2);
  numerator_Option22->SetLineColor(kRed);
  numerator_Option22->Draw("same");

  TLegend* leg1 = new TLegend(0.60,0.18,0.85,0.43);
  leg1->SetBorderSize(0);
  leg1->AddEntry(denominator ,"all offline","L");
  leg1->AddEntry(numerator_noIso ,"no iso","L");
  leg1->AddEntry(numerator_Option1,"Option 1","L");
  leg1->AddEntry(numerator_Option2,"Option 2","L");
  leg1->AddEntry(numerator_Option3,"Option 3","L");
  leg1->AddEntry(numerator_Option4,"Option 4","L");
  leg1->AddEntry(numerator_Option8,"Option 8","L");
  leg1->AddEntry(numerator_Option22,"Option 22","L");
  leg1->Draw("same");
  
  c1.SaveAs("PlotIsolation/pT_options.pdf");
  
  denominator->Write();
  numerator_noIso->Write();
  numerator_Option1->Write();
  numerator_Option2->Write();
  numerator_Option3->Write();
  numerator_Option4->Write();
  numerator_Option8->Write();
  numerator_Option22->Write();
}

