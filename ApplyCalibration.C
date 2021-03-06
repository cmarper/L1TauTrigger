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

const Int_t NbinsIEta = 4+1;
const Int_t NbinsIEt = 16+1;
const Int_t NbinsnTT = 11+1;//Acceptable LUT Thomas

const Int_t NbinsIEt2 = 32+1;
const Int_t NbinsnTT2 = 32+1;

const Int_t hardcodedIetaBins[NbinsIEta] = {0, 6, 12, 18, 33};
const Int_t hardcodedIetBins[NbinsIEt]    = {0, 23, 27, 31, 35, 39, 43, 47, 53, 59, 65, 73, 82, 95, 120, 157, 255};
const Int_t hardcodedIetBins2[NbinsIEt2]  = {0, 15, 18, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 50, 53, 56, 59, 62, 65, 69, 73, 77, 82, 88, 95, 105, 120, 157, 255};
const Double_t hardcodedIetBins2double[NbinsIEt2]  = {0, 15, 18, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 50, 53, 56, 59, 62, 65, 69, 73, 77, 82, 88, 95, 105, 120, 157, 255};

const Int_t hardcodednTTBins[NbinsnTT] =   {0, 26, 31, 36, 41, 46, 51, 56, 61, 66, 76, 255};//Acceptable LUT Thomas
// const Int_t hardcodednTTBins[NbinsnTT] =   {0, 11, 16, 21, 26, 31, 36, 41, 46, 51, 56, 255};//Acceptable LUT Thomas
const Int_t hardcodednTTBins2[NbinsnTT2] = {0, 6, 11, 16, 21, 26, 31, 36, 41, 46, 51, 56, 61, 66, 71, 76, 81, 86, 91, 96, 101, 106, 111, 116, 121, 126, 131, 136, 141, 146, 161, 161, 255};//Acceptable LUT Thomas

bool CheckBit (short int number, int bitpos)
{
  bool res = number & (1 << bitpos);
  return res;
}

void SetBit (short int& number, int bitpos, bool val)
{
  // int isTrue = (CheckBit(number, bitpos) ? 1 : 0);
    
  // //number ^= (-isTrue ^ number) & (1 << bitpos);
  // //return;

  // number = (number & ~(1<<bitpos)) | (isTrue<<bitpos);

  if (val)
    number |= (1 << bitpos);
  else
    number &= ~(1 << bitpos);
}

// vertically flip a shape
short int reflectShape (short int shape)
{
  short int newshape = 0;
  map<int, int> remap;
  remap[0] = 3;
  remap[1] = 2;
  remap[2] = 1;
  remap[3] = 0;
  remap[4] = 6;
  remap[5] = 5;
  remap[6] = 4;


  for (int i = 0; i < 7; i++)
    {
      bool val = CheckBit(shape, i);
      SetBit (newshape, remap[i], val) ;
    }
  return newshape;
}

short int symmShape(short int shape)
{
  // truncate to first 7 bits
  shape &= 127; // first 7 bits

  int N_n = 0;
  int N_s = 0;
  int N_n_c = 0;
  int N_s_c = 0;
  int N_n_dx = 0;
  int N_s_dx = 0;

  if (CheckBit(shape, 0))
    {
      N_n++;
      N_n_c++;
    }

  if (CheckBit(shape, 1))
    {
      N_n++;
      N_n_c++;
    }

  if (CheckBit(shape, 2))
    {
      N_s++;
      N_s_c++;
    }

  if (CheckBit(shape, 3))
    {
      N_s++;
      N_s_c++;
    }

  if (CheckBit(shape, 4))
    {
      N_n++;
      N_n_dx++;
    }

  if (CheckBit(shape, 6))
    {
      N_s++;
      N_s_dx++;
    }

  ////////////

  if (N_n > N_s) return shape;
  if (N_n < N_s) return reflectShape(shape);
  if (N_n == N_s)
    {
      if (N_n_c > N_s_c) return shape;
      if (N_n_c < N_s_c) return reflectShape(shape);
      if (N_n_c == N_s_c)
	{
	  if (N_n_dx >= N_s_dx) return shape;
	  else return reflectShape(shape);
	}
    }

  cout << "I should not arrive here!!!" << endl;
  return shape;
}

// will encode the shape in a new short int mapped as:
// ## this is in the format:
// # D
// #BC
// #AX
// #bc
// # d
// so that vertical reflectionn == shape vertical flip
short int encodeSymm (short int shape, map<int, int>& remap)
{
  short int symm = 0;
  for (int i = 0; i < 7; i++)
    {
      if (CheckBit(shape, i))
	SetBit (symm, remap[i], true);
    }
  return symm;
}

// vertically flip the shape
short int reflect (short int shape)
{
  short int shRev = 0;
  int numbits = 7;
  for (int i = 0; i < numbits; i++)
    {
      if ((shape >> i) & 1)
	{
	  shRev += (1 << (numbits-1-i));
	}
    }
  // shRev = sum(1<<(numbits-1-i) for i in range(numbits) if sh1>>i&1)
  return shRev;
}

// this is ensured to give only symm shapes
short int getSymmShape (short int shape, map<int, int>& remap)
{
  shape &= 127; // first 7 bits
  short int symmForm = encodeSymm (shape, remap);
  short int reflected = reflect (symmForm);

  // return the one having the lowest value!
  return (symmForm < reflected ? symmForm : reflected);
}


Int_t FindBinIEt(Int_t IEt)
{
  for(UInt_t i = 0 ; i < NbinsIEt2-1 ; ++i)
    {
      if(IEt>=157) return NbinsIEt2-2;
      if(IEt>= hardcodedIetBins2[i] && IEt < hardcodedIetBins2[i+1]) return i;
    }
  return -1;
}

Int_t FindBinnTT(Int_t nTT)
{
  for(UInt_t i = 0 ; i < NbinsnTT2-1 ; ++i)
    {
      if(nTT>=161) return NbinsnTT2-2;
      if(nTT>= hardcodednTTBins2[i] && nTT < hardcodednTTBins2[i+1]) return i;
    }
  return -1;
}

Int_t FindBinCorrespondenceIEt(Int_t IEt_fine)
{
  for(UInt_t i = 0 ; i < NbinsIEt-1 ; ++i)
    {
      if(IEt_fine>=157) return NbinsIEt-2;
      // if(IEt_fine>=120) return NbinsIEt-2;
      if(IEt_fine>= hardcodedIetBins[i] && IEt_fine < hardcodedIetBins[i+1]) return i;
    }
  return -1;
}

Int_t FindBinCorrespondencenTT(Int_t nTT_fine)
{
  for(UInt_t i = 0 ; i < NbinsnTT-1 ; ++i)
    {
      if(nTT_fine>=76) return NbinsnTT-2;
      // if(nTT_fine>=106) return NbinsnTT-2;
      // if(nTT_fine>=56) return NbinsnTT-2;
      if(nTT_fine>= hardcodednTTBins[i] && nTT_fine < hardcodednTTBins[i+1]) return i;
    }
  return -1;
}

void ApplyCalibration(TString InputFileName = "/data_CMS/cms/mperez/TauTrigger_data/2018isolation92X/outputForCalibration_compressed_Ntuple_MC_92X_v1_1_newLayer1.root")
{

  TFile f_shapes("/home/llr/cms/cadamuro/Tau_ShapeVeto/CMSSW_8_0_10/src/L1Trigger/L1TNtuples/ShapeVeto/shapes_signal.root");
  // TH2F* shapes_vs_pt = (TH2F*)f_shapes.Get("hShapes_vs_pt");
  // shapes_vs_pt->Clear();
  TH2F* shapes_vs_eta = (TH2F*)f_shapes.Get("hShapes_vs_eta");
  shapes_vs_eta->Clear();
  TH1F* shapes_1D = (TH1F*) f_shapes.Get("hShapes_gt30_merg");
  shapes_1D->Clear();

  TH2F* shapes_vs_pt = new TH2F("shapes_vs_pt","shapes_vs_pt",128,0,128,NbinsIEt2-1,hardcodedIetBins2double);
  shapes_vs_pt->Clear();  

  TH2F* isolation_vs_pt = new TH2F("isolation_vs_pt","isolation_vs_pt",100,0,100,NbinsIEt2-1,hardcodedIetBins2double);
  // TH2F* isolation_vs_pt = new TH2F("isolation_vs_pt","isolation_vs_pt",100,0.,100.,200,0.,200.);
  isolation_vs_pt->Clear();

  const UInt_t nIsolation = 101;
  const Double_t isolationBins[nIsolation] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
 
  const UInt_t nShapes = 129;
  const Double_t shapesBins[nShapes] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128};
 
  TH3F* shapes_vs_isolation_vs_pt = new TH3F("shapes_vs_isolation_vs_pt","shapes_vs_isolation_vs_pt",nShapes-1,shapesBins,nIsolation-1,isolationBins,NbinsIEt2-1,hardcodedIetBins2double);
  shapes_vs_isolation_vs_pt->Clear();


    TFile f_histos("/data_CMS/cms/mperez/TauTrigger_data/2018isolation92X/corrections_Trigger_2018_compressedieta_compressedE_hasEM_isMerged_MC_VBF_180409_newLayer2calibs.root","READ");
  TH3F* h_LUT_isMerged0 = (TH3F*)f_histos.Get("LUT_isMerged0_GBRFullLikelihood_Trigger_Stage2_2018_compressedieta_compressedE_hasEM_isMerged_MC_VBF_180409");
  TH3F* h_LUT_isMerged1 = (TH3F*)f_histos.Get("LUT_isMerged1_GBRFullLikelihood_Trigger_Stage2_2018_compressedieta_compressedE_hasEM_isMerged_MC_VBF_180409");

  TFile f_in(InputFileName.Data(),"READ");
  TTree* inTree = (TTree*)f_in.Get("outTreeForCalibration");

  Int_t           L1Tau_IEta;
  Int_t           L1Tau_hasEM;
  Float_t         Target;
  Int_t           L1Tau_IEt;
  Int_t           L1Tau_RawIEt;
  Int_t           EventNumber;
  Int_t           RunNumber;
  Int_t           Nvtx;
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
  inTree->SetBranchAddress("Nvtx", &Nvtx);
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

  TString OutputFileName = "/data_CMS/cms/mperez/TauTrigger_data/2018isolation92X/calibratedOutput_Ntuple_MC_92X_newLayer1_newLayer2_oldnTT.root";

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
  Int_t           out_Nvtx;
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
  outTree.Branch("Nvtx", &out_Nvtx, "Nvtx/I");
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

  map<int, int> remap;
  remap[0] = 6 ;
  remap[1] = 5 ;
  remap[2] = 1 ;
  remap[3] = 0 ;
  remap[4] = 4 ;
  remap[5] = 3 ;
  remap[6] = 2 ;

  // pt in 20-30
  vector<int> veto_set_20 = {0,4,99,8,20};
  // pt in 30-40
  vector<int> veto_set_30 = {127, 119, 99, 111, 103, 23, 55, 20, 31, 27, 63, 107, 19, 51, 28};
  // pt in 40-50
  vector<int> veto_set_40 = {127, 119, 99, 103, 20, 111, 23, 19, 27, 4, 55};

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
      out_Nvtx = Nvtx;
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

      // out_L1Tau_PassShapeVeto = true;
      // if (out_L1Tau_IEt > 20 && out_L1Tau_IEt < 30)
      //   {
      //     out_L1Tau_PassShapeVeto = (find(veto_set_20.begin(), veto_set_20.end(), symmShape) == veto_set_20.end() ? true : false);
      //   }
      // else if (out_L1Tau_IEt > 30 && out_L1Tau_IEt < 40)
      //   {
      //     out_L1Tau_PassShapeVeto = (find(veto_set_30.begin(), veto_set_30.end(), symmShape) == veto_set_30.end() ? true : false);
      //   }
      // else if (out_L1Tau_IEt > 40 && out_L1Tau_IEt < 50)
      //   {
      //     out_L1Tau_PassShapeVeto = (find(veto_set_40.begin(), veto_set_40.end(), symmShape) == veto_set_40.end() ? true : false);
      //   }
      // else out_L1Tau_PassShapeVeto = true;

      for(Int_t ie = 0 ; ie < NbinsIEt ; ++ie)
	{
	  if(L1Tau_IEt>=255)
	    {
	      out_supercompressedE = NbinsIEt-2;
	      break;
	    }
	  else if(L1Tau_IEt >= hardcodedIetBins[ie] && L1Tau_IEt < hardcodedIetBins[ie+1])
	    {
	      out_supercompressedE = ie;
	      break;
	    }
	}

      for(Int_t inTT = 0 ; inTT < NbinsnTT ; ++inTT)
	{
	  if(L1Tau_nTT>=255)
	    {
	      out_supercompressednTT = NbinsnTT-2;
	      break;
	    }
	  else if(L1Tau_nTT >= hardcodednTTBins[inTT] && L1Tau_nTT < hardcodednTTBins[inTT+1])
	    {
	      out_supercompressednTT = inTT;
	      break;
	    }
	}

      /*
	cout<<"L1Tau_IEta = "<<L1Tau_IEta<<endl;
	cout<<"L1Tau_IEt/2. = "<<L1Tau_IEt/2.<<endl;
	// cout<<"L1Tau_IEt/2. = "<<L1Tau_IEt/2.<<endl;
	cout<<"OfflineTau_pt = "<<OfflineTau_pt<<endl;
	cout<<"Target = "<<out_Target<<endl;
	cout<<"h_LUT_isMerged0->GetBinContent(abs(compressedieta)+1,compressedE+1,L1Tau_hasEM+1) = "<<h_LUT_isMerged0->GetBinContent(abs(compressedieta)+1,compressedE+1,L1Tau_hasEM+1)<<endl;
	cout<<"-----"<<endl;
      */

      // cout<<"abs(compressedieta) = "<<abs(compressedieta)<<endl;
      // cout<<"compressedE = "<<compressedE<<endl;
      // cout<<"L1Tau_hasEM = "<<L1Tau_hasEM<<endl;
      // cout<<"h_LUT_isMerged0->GetBinContent(abs(compressedieta)+1,compressedE+1,L1Tau_hasEM+1) = "<<h_LUT_isMerged0->GetBinContent(abs(compressedieta)+1,compressedE+1,L1Tau_hasEM+1)<<endl;

      if(!out_L1Tau_isMerged)
	{
	  out_L1Tau_CalibConstant = h_LUT_isMerged0->GetBinContent(abs(compressedieta)+1,compressedE+1,L1Tau_hasEM+1);
	  if(out_L1Tau_CalibConstant>1.3) out_L1Tau_CalibConstant = 1.3;
	  // if(out_L1Tau_CalibConstant>1.7) out_L1Tau_CalibConstant = 1.7;
	  out_L1Tau_CalibPt = out_L1Tau_CalibConstant*L1Tau_IEt/2.;
	}
      else
	{
	  out_L1Tau_CalibConstant = h_LUT_isMerged1->GetBinContent(abs(compressedieta)+1,compressedE+1,L1Tau_hasEM+1);
	  if(out_L1Tau_CalibConstant>1.3) out_L1Tau_CalibConstant = 1.3;
	  // if(out_L1Tau_CalibConstant>1.7) out_L1Tau_CalibConstant = 1.7;
	  out_L1Tau_CalibPt = out_L1Tau_CalibConstant*L1Tau_IEt/2.;
	}


      // if(out_L1Tau_CalibPt<20.) cout<<"hello"<<endl;

      out_L1Tau_Qual = L1Tau_Qual;
      short int symmShape = getSymmShape (L1Tau_Qual, remap);

      //cout<<(L1Tau_Qual&=127)<<endl;
      
      out_L1Tau_PassShapeVeto = true;

      shapes_vs_pt->Fill(symmShape,out_L1Tau_IEt);
      // shapes_vs_pt->Fill(symmShape,out_L1Tau_IEt/2.);
      shapes_vs_eta->Fill(symmShape,out_L1Tau_IEta);
      isolation_vs_pt->Fill(L1Tau_Iso,out_L1Tau_IEt);
      shapes_vs_isolation_vs_pt->Fill(symmShape,L1Tau_Iso,out_L1Tau_IEt);
      // isolation_vs_pt->Fill(L1Tau_Iso,out_L1Tau_IEt/2.);

      if(out_L1Tau_IEt/2.>=30.) shapes_1D->Fill(symmShape);

      if (out_L1Tau_CalibPt >= 20 && out_L1Tau_CalibPt < 30)
        {
          out_L1Tau_PassShapeVeto = (find(veto_set_20.begin(), veto_set_20.end(), symmShape) == veto_set_20.end() ? true : false);
        }
      else if (out_L1Tau_CalibPt >= 30 && out_L1Tau_CalibPt < 40)
        {
          out_L1Tau_PassShapeVeto = (find(veto_set_30.begin(), veto_set_30.end(), symmShape) == veto_set_30.end() ? true : false);
        }
      else if (out_L1Tau_CalibPt >= 40 && out_L1Tau_CalibPt < 50)
        {
          out_L1Tau_PassShapeVeto = (find(veto_set_40.begin(), veto_set_40.end(), symmShape) == veto_set_40.end() ? true : false);
        }
      else out_L1Tau_PassShapeVeto = true;      

      outTree.Fill();

    }

  outTree.Write();

  TFile f_out_shapes("signal_shapes_forTraining_fine_binning_dummy_19_10_17.root","RECREATE");
  // TFile f_out_shapes("signal_shapes_forTraining.root","RECREATE");
  shapes_vs_pt->Write("shapes_vs_pt");
  isolation_vs_pt->Write("isolation_vs_pt");
  shapes_vs_isolation_vs_pt->Write("shapes_vs_isolation_vs_pt");
  shapes_vs_eta->Write("shapes_vs_eta");
  shapes_1D->Write("hShapes_gt30_merg");

}
