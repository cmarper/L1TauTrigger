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

using namespace std;

void ApplyCalibration(TString InputFileName = "Trees_modeparam/outputForCalibration_Ntuple_MC_92X_mode_Unpacked.root")
{
  TFile f_in(InputFileName.Data(),"READ");
  TTree* inTree = (TTree*)f_in.Get("outTreeForCalibration");

  Int_t           L1Tau_IEta;
  Int_t           L1Tau_hasEM;
  Float_t         Target;
  Int_t           L1Tau_IEt;
  Int_t           L1Tau_RawIEt;
  Int_t           EventNumber;
  Int_t           RunNumber;
  Int_t           L1Tau_nTT;
  Float_t         L1Tau_pt;
  Float_t         OfflineTau_pt;
  Float_t         OfflineTau_eta;
  Int_t           L1Tau_Iso;
  Int_t           OfflineTau_isMatched;
  Int_t           L1Tau_isMerged;
  Int_t           compressedshape;
  Int_t           compressedsortedshape;
  Int_t           compressedieta;
  Int_t           compressedE;
  Int_t           compressednTT;
  Int_t           supercompressedE;
  Int_t           supercompressednTT;
  Int_t           L1Tau_Qual;

  inTree->SetBranchAddress("L1Tau_IEta", &L1Tau_IEta);
  inTree->SetBranchAddress("compressedsortedshape", &compressedsortedshape);
  inTree->SetBranchAddress("L1Tau_hasEM", &L1Tau_hasEM);
  inTree->SetBranchAddress("Target", &Target);
  inTree->SetBranchAddress("L1Tau_IEt", &L1Tau_IEt);
  inTree->SetBranchAddress("L1Tau_RawIEt", &L1Tau_RawIEt);
  inTree->SetBranchAddress("EventNumber", &EventNumber);
  inTree->SetBranchAddress("RunNumber", &RunNumber);
  inTree->SetBranchAddress("L1Tau_nTT", &L1Tau_nTT);
  inTree->SetBranchAddress("L1Tau_pt", &L1Tau_pt);
  inTree->SetBranchAddress("OfflineTau_pt", &OfflineTau_pt);
  inTree->SetBranchAddress("OfflineTau_eta", &OfflineTau_eta);
  inTree->SetBranchAddress("compressedieta", &compressedieta);
  inTree->SetBranchAddress("compressedE", &compressedE);
  inTree->SetBranchAddress("L1Tau_Iso", &L1Tau_Iso);
  inTree->SetBranchAddress("compressednTT", &compressednTT);
  inTree->SetBranchAddress("OfflineTau_isMatched", &OfflineTau_isMatched);
  inTree->SetBranchAddress("L1Tau_isMerged", &L1Tau_isMerged);
  inTree->SetBranchAddress("compressedshape", &compressedshape);
  inTree->SetBranchAddress("L1Tau_Qual",&L1Tau_Qual);
  // inTree->SetBranchAddress("supercompressedE", &supercompressedE);
  // inTree->SetBranchAddress("supercompressednTT", &supercompressednTT);

  TString OutputFileName = "Trees_modeparam/calibratedOutput_Ntuple_MC_92X_mode_Unpacked.root";

  TFile f(OutputFileName.Data(),"RECREATE");
  TTree outTree("outTreeForCalibration","outTreeForCalibration");  

  Int_t           out_L1Tau_IEta;
  Int_t           out_compressedsortedshape;
  Int_t           out_L1Tau_hasEM;
  Float_t         out_Target;
  Int_t           out_L1Tau_IEt;
  Int_t           out_L1Tau_RawIEt;
  Int_t           out_EventNumber;
  Int_t           out_RunNumber;
  Int_t           out_L1Tau_nTT;
  Float_t         out_L1Tau_pt;
  Float_t         out_L1Tau_CalibPt;
  Float_t         out_OfflineTau_pt;
  Float_t         out_OfflineTau_eta;
  Int_t           out_compressedieta;
  Int_t           out_compressedE;
  Int_t           out_L1Tau_Iso;
  Int_t           out_compressednTT;
  Int_t           out_OfflineTau_isMatched;
  Int_t           out_L1Tau_isMerged;
  Int_t           out_compressedshape;
  Int_t           out_supercompressedE;
  Int_t           out_supercompressednTT;
  Int_t           out_L1Tau_Qual;
  Bool_t          out_L1Tau_PassShapeVeto;
  Float_t         out_L1Tau_CalibConstant;

  outTree.Branch("L1Tau_IEta", &out_L1Tau_IEta,"L1Tau_IEta/I");
  outTree.Branch("compressedsortedshape", &out_compressedsortedshape,"compressedsortedshape/I");
  outTree.Branch("L1Tau_hasEM", &L1Tau_hasEM, "L1Tau_hasEM/I");
  outTree.Branch("Target", &out_Target, "Target/F");
  outTree.Branch("L1Tau_IEt", &out_L1Tau_IEt, "L1Tau_IEt/I");
  outTree.Branch("L1Tau_RawIEt", &out_L1Tau_RawIEt, "L1Tau_RawIEt/I");
  outTree.Branch("EventNumber", &out_EventNumber, "EventNumber/I");
  outTree.Branch("RunNumber", &out_RunNumber, "RunNumber/I");
  outTree.Branch("L1Tau_nTT", &out_L1Tau_nTT, "L1Tau/I");
  outTree.Branch("L1Tau_pt", &out_L1Tau_pt, "L1Tau_pt/F");
  outTree.Branch("L1Tau_CalibPt", &out_L1Tau_CalibPt, "L1Tau_CalibPt/F");
  outTree.Branch("L1Tau_CalibConstant", &out_L1Tau_CalibConstant, "L1Tau_CalibConstant/F");
  outTree.Branch("OfflineTau_pt", &out_OfflineTau_pt, "OfflineTau_pt/F");
  outTree.Branch("OfflineTau_eta", &out_OfflineTau_eta, "OfflineTau_eta/F");
  outTree.Branch("compressedieta", &out_compressedieta, "compressedieta/I");
  outTree.Branch("compressedE", &out_compressedE, "compressedE/I");
  outTree.Branch("L1Tau_Iso", &out_L1Tau_Iso, "L1Tau_Iso/I");
  outTree.Branch("compressednTT", &out_compressednTT, "compressednTT/I");
  outTree.Branch("OfflineTau_isMatched", &out_OfflineTau_isMatched, "OfflineTau_isMatched/I");
  outTree.Branch("L1Tau_isMerged", &out_L1Tau_isMerged, "L1Tau_isMerged/I");
  outTree.Branch("compressedshape", &out_compressedshape, "compressedshape/I");
  outTree.Branch("supercompressedE", &out_supercompressedE, "supercompressedE/I");
  outTree.Branch("supercompressednTT", &out_supercompressednTT, "supercompressednTT/I");
  outTree.Branch("L1Tau_PassShapeVeto",&out_L1Tau_PassShapeVeto, "out_L1Tau_PassShapeVeto/O");
  outTree.Branch("L1Tau_Qual",&out_L1Tau_Qual, "out_L1Tau_Qual/I");

  for(UInt_t i = 0 ; i < inTree->GetEntries() ; ++i)
    {
      inTree->GetEntry(i);
      if(i%10000==0) cout<<"Entry #"<<i<<endl;

      out_L1Tau_IEta = abs(L1Tau_IEta);
      out_compressedsortedshape = compressedsortedshape;
      out_L1Tau_hasEM = L1Tau_hasEM;
      out_Target = Target;
      out_L1Tau_IEt = L1Tau_IEt;
      out_L1Tau_RawIEt = L1Tau_RawIEt;
      out_EventNumber = EventNumber;
      out_RunNumber = RunNumber;
      out_L1Tau_nTT = L1Tau_nTT;
      out_L1Tau_pt = L1Tau_pt;
      out_OfflineTau_pt = OfflineTau_pt;
      out_OfflineTau_eta = OfflineTau_eta;
      out_compressedieta = abs(compressedieta);
      out_compressedE = compressedE;
      out_L1Tau_Iso = L1Tau_Iso;
      out_compressednTT = compressednTT;
      out_OfflineTau_isMatched = OfflineTau_isMatched;
      out_L1Tau_isMerged = L1Tau_isMerged;
      out_compressedshape = compressedshape;
      
      out_L1Tau_CalibConstant = 1.;
      out_L1Tau_CalibPt = L1Tau_pt;

      out_L1Tau_Qual = L1Tau_Qual;

      outTree.Fill();

    }

  outTree.Write();

}
