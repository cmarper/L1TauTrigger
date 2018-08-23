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

void ApplyIsolationForTurnOns(TString InputFileName = "Trees_modeparam/calibratedOutput_Ntuple_MC_92X_mode_Unpacked.root", Bool_t nTTRange = kTRUE)
{
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
  //inTree->SetBranchAddress("L1Tau_PassShapeVeto_0p6_10_50",&in_L1Tau_PassShapeVeto_0p6_10_50);

  Double_t binning[22] = {18,20,22,24,26,28,30,32,35,40,45,50,60,70,90,110,210,350,500,700,1000,2000};
  TH1F* pt = new TH1F("pt","pt",21,binning);
  TH1F* pt_pass_noIso   = new TH1F("pt_pass_noIso"  ,"pt_pass_noIso"  ,21,binning);
  TH1F* pt_pass_Option22  = new TH1F("pt_pass_Option22" ,"pt_pass_Option22" ,21,binning);

  Double_t Threshold_NewLayer1_noIso = 41.51;
  Double_t Threshold_NewLayer1_Option22 = 28.51;
  
  for(UInt_t i = 0 ; i < inTree->GetEntries() ; ++i)
    {
      inTree->GetEntry(i);
      if(in_L1Tau_nTT<60 && nTTRange) continue;

      pt->Fill(in_OfflineTau_pt);
	
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_noIso) pt_pass_noIso->Fill(in_OfflineTau_pt);
      if(in_L1Tau_CalibPt>=Threshold_NewLayer1_Option22 && in_L1Tau_Iso>0) pt_pass_Option22->Fill(in_OfflineTau_pt);
         
    }

  TString FileNameOut = "Trees_modeparam/turnOns_March2017Layer1Calibration_ShapeVeto_92X_mode_Unpacked";
  // TString FileNameOut = "turnOns_2017Layer1Calibration";
  if(nTTRange) FileNameOut += "_nTTRange";
  FileNameOut += ".root";

  TFile turnOns(FileNameOut.Data(),"RECREATE");

  TGraphAsymmErrors* turnOn_noIso = new TGraphAsymmErrors(pt_pass_noIso,pt,"cp");
  turnOn_noIso->Write();

  TGraphAsymmErrors* turnOn_Option22 = new TGraphAsymmErrors(pt_pass_Option22,pt,"cp");
  turnOn_Option22->Write();
}
