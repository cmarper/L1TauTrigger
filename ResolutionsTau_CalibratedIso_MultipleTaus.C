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

using namespace std;

const Int_t NbinsIEta = 4+1;
const Int_t NbinsIEt = 16+1;
const Int_t NbinsnTT = 11+1;//Acceptable LUT Thomas

const Int_t NbinsIEt2 = 32+1;
const Int_t NbinsnTT2 = 32+1;

const Int_t hardcodedIetaBins[NbinsIEta] = {0, 6, 12, 18, 33};
const Int_t hardcodedIetBins[NbinsIEt]    = {0, 18, 23, 27, 31, 35, 39, 43, 47, 53, 59, 65, 73, 82, 95, 120, 255};
const Int_t hardcodedIetBins2[NbinsIEt2]  = {0, 15, 18, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 50, 53, 56, 59, 62, 65, 69, 73, 77, 82, 88, 95, 105, 120, 157, 255};
const Int_t hardcodednTTBins[NbinsnTT] =   {0, 11, 16, 21, 26, 31, 36, 41, 46, 51, 56, 255};//Acceptable LUT Thomas
const Int_t hardcodednTTBins2[NbinsnTT2] = {0, 6, 11, 16, 21, 26, 31, 36, 41, 46, 51, 56, 61, 66, 71, 76, 81, 86, 91, 96, 101, 106, 111, 116, 121, 126, 131, 136, 141, 146, 161, 161, 255};//Acceptable LUT Thomas

// Header file for the classes stored in the TTree if any.
//#include "interface/L1AnalysisRecoTauDataFormat.h"
//#include "interface/L1AnalysisRecoElectronDataFormat.h"
//#include "interface/L1AnalysisRecoMuon2DataFormat.h"
//#include "interface/L1AnalysisL1UpgradeDataFormat.h"
//#include "interface/L1AnalysisL1CaloClusterDataFormat.h"
//#include "interface/L1AnalysisEventDataFormat.h"

Int_t FindBinIEta(Int_t IEta)
{
  for(Int_t i = 0 ; i < NbinsIEta ; ++i)
    {
      if(IEta>=28) return (NbinsIEta-2);
      else if(IEta >= hardcodedIetaBins[i] && IEta < hardcodedIetaBins[i+1]) return i;
    }

  return -1;
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
      if(nTT>=156) return NbinsnTT2-2;
      if(nTT>= hardcodednTTBins2[i] && nTT < hardcodednTTBins2[i+1]) return i;
    }
  return -1;
}

void Acceptance()
{
  TString Name4DFile = "Trees_meanparam/corrections_Trigger_2017_compressedieta_compressedE_hasEM_isMerged_92X_mean.root";
  TFile f_4D(Name4DFile.Data(),"READ");
  TString Name4DHisto_isMerged0 = "LUT_isMerged0_GBRFullLikelihood_Trigger_Stage2_2017_compressedieta_compressediet_hasEM_isMerged_MC_SandeepCristina_MC_VBF";
  TH3F* h_3D_isMerged0 = (TH3F*)f_4D.Get(Name4DHisto_isMerged0.Data());
  TString Name4DHisto_isMerged1 = "LUT_isMerged1_GBRFullLikelihood_Trigger_Stage2_2017_compressedieta_compressediet_hasEM_isMerged_MC_SandeepCristina_MC_VBF";
  TH3F* h_3D_isMerged1 = (TH3F*)f_4D.Get(Name4DHisto_isMerged1.Data());

  std::map<TString,TH3F*> histosIsolation;
  TFile f_Isolation("Trees_meanparam/Iso_LUTs_Options_MC_92X_mean.root");

  for(UInt_t i = 1 ; i < 32 ; ++i)
    {
      TString CurrentNameHisto = "LUT_Progression_";
      ostringstream convert;
      convert << i;
      CurrentNameHisto += convert.str();
      TH3F* current_Histo = (TH3F*)f_Isolation.Get(CurrentNameHisto.Data());
      histosIsolation.insert(make_pair(CurrentNameHisto,current_Histo));
    }  

  TString FileName_in = "Trees_meanparam/Ntuple_MC_Merged_92X_multipletaus_mean.root";
  gStyle->SetOptStat(000000);

  TChain data("Ntuplizer_noTagAndProbe_multipleTaus_TagAndProbe");
  data.Add(FileName_in.Data());
  data.SetMakeClass(1);
  
  Int_t           RunNumber = 0;
  ULong64_t       EventNumber = 0;
  Int_t           lumi = 0;
  vector<float>   *tauPt = 0;
  vector<float>   *tauEta = 0;
  vector<float>   *tauPhi = 0;
  vector<int>     *tauCharge = 0;
  vector<int>     *tauDecayMode = 0;
  bool            hasTriggerMuonType = 0;
  bool            hasTriggerTauType = 0;
  vector<bool>    *isMatched = 0;
  bool            isOS = 0;
  Int_t           foundJet = 0;
  Int_t           Nvtx = 0;
  vector<float>   *l1tPt = 0;
  vector<float>   *l1tEta = 0;
  vector<float>   *l1tPhi = 0;
  vector<int>     *l1tQual = 0;
  vector<int>     *l1tIso = 0;
  vector<float>   *l1tEmuPt = 0 ;
  vector<float>   *l1tEmuEta = 0 ;
  vector<float>   *l1tEmuPhi = 0 ;
  vector<int>     *l1tEmuQual = 0 ;
  vector<int>     *l1tEmuIso = 0 ;
  vector<int>     *l1tEmuNTT = 0 ;
  vector<int>     *l1tEmuHasEM = 0 ;
  vector<int>     *l1tEmuIsMerged = 0 ;
  vector<int>     *l1tEmuTowerIEta = 0 ;
  vector<int>     *l1tEmuTowerIPhi = 0 ;
  vector<int>     *l1tEmuRawEt = 0 ;
  vector<int>     *l1tEmuIsoEt = 0 ;
  
  TBranch        *b_RunNumber;   //!
  TBranch        *b_EventNumber;   //!
  TBranch        *b_lumi;   //!
  TBranch        *b_tauPt;   //!
  TBranch        *b_tauEta;   //!
  TBranch        *b_tauPhi;   //!
  TBranch        *b_tauCharge;   //!
  TBranch        *b_tauDecayMode;   //!
  TBranch        *b_hasTriggerMuonType;   //!
  TBranch        *b_hasTriggerTauType;   //!
  TBranch        *b_isMatched;   //!
  TBranch        *b_isOS;   //!
  TBranch        *b_foundJet;   //!
  TBranch        *b_Nvtx;   //!
  TBranch        *b_l1tPt;   //!
  TBranch        *b_l1tEta;   //!
  TBranch        *b_l1tPhi;   //!
  TBranch        *b_l1tQual;   //!
  TBranch        *b_l1tIso;   //!
  TBranch        *b_l1tEmuPt;   //!
  TBranch        *b_l1tEmuEta;   //!
  TBranch        *b_l1tEmuPhi;   //!
  TBranch        *b_l1tEmuQual;   //!
  TBranch        *b_l1tEmuIso;   //!
  TBranch        *b_l1tEmuNTT;   //!
  TBranch        *b_l1tEmuHasEM;   //!
  TBranch        *b_l1tEmuIsMerged;   //!
  TBranch        *b_l1tEmuTowerIEta;   //!
  TBranch        *b_l1tEmuTowerIPhi;   //!
  TBranch        *b_l1tEmuRawEt;   //!
  TBranch        *b_l1tEmuIsoEt;   //!

  data.SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
  data.SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
  data.SetBranchAddress("lumi", &lumi, &b_lumi);
  data.SetBranchAddress("tauPt", &tauPt, &b_tauPt);
  data.SetBranchAddress("tauEta", &tauEta, &b_tauEta);
  data.SetBranchAddress("tauPhi", &tauPhi, &b_tauPhi);
  data.SetBranchAddress("tauCharge", &tauCharge, &b_tauCharge);
  data.SetBranchAddress("tauDecayMode", &tauDecayMode, &b_tauDecayMode);
  data.SetBranchAddress("hasTriggerMuonType", &hasTriggerMuonType, &b_hasTriggerMuonType);
  data.SetBranchAddress("hasTriggerTauType", &hasTriggerTauType, &b_hasTriggerTauType);
  data.SetBranchAddress("isMatched", &isMatched, &b_isMatched);
  data.SetBranchAddress("isOS", &isOS, &b_isOS);
  data.SetBranchAddress("foundJet", &foundJet, &b_foundJet);
  data.SetBranchAddress("Nvtx", &Nvtx, &b_Nvtx);
  data.SetBranchAddress("l1tPt", &l1tPt, &b_l1tPt);
  data.SetBranchAddress("l1tEta", &l1tEta, &b_l1tEta);
  data.SetBranchAddress("l1tPhi", &l1tPhi, &b_l1tPhi);
  data.SetBranchAddress("l1tQual", &l1tQual, &b_l1tQual);
  data.SetBranchAddress("l1tIso", &l1tIso, &b_l1tIso);
  data.SetBranchAddress("l1tEmuPt", &l1tEmuPt, &b_l1tEmuPt);
  data.SetBranchAddress("l1tEmuEta", &l1tEmuEta, &b_l1tEmuEta);
  data.SetBranchAddress("l1tEmuPhi", &l1tEmuPhi, &b_l1tEmuPhi);
  data.SetBranchAddress("l1tEmuQual", &l1tEmuQual, &b_l1tEmuQual);
  data.SetBranchAddress("l1tEmuIso", &l1tEmuIso, &b_l1tEmuIso);
  data.SetBranchAddress("l1tEmuNTT", &l1tEmuNTT, &b_l1tEmuNTT);
  data.SetBranchAddress("l1tEmuHasEM", &l1tEmuHasEM, &b_l1tEmuHasEM);
  data.SetBranchAddress("l1tEmuIsMerged", &l1tEmuIsMerged, &b_l1tEmuIsMerged);
  data.SetBranchAddress("l1tEmuTowerIEta", &l1tEmuTowerIEta, &b_l1tEmuTowerIEta);
  data.SetBranchAddress("l1tEmuTowerIPhi", &l1tEmuTowerIPhi, &b_l1tEmuTowerIPhi);
  data.SetBranchAddress("l1tEmuRawEt", &l1tEmuRawEt, &b_l1tEmuRawEt);
  data.SetBranchAddress("l1tEmuIsoEt", &l1tEmuIsoEt, &b_l1tEmuIsoEt);
     
  //Double_t binning[17] = {18,20,22,24,26,28,30,32,35,40,45,50,60,70,90,110,210};

  //TH1F* pt = new TH1F("pt","pt",16,binning);
  //TH1F* pt_pass_NoIso = new TH1F("pt_pass_NoIso","pt_pass_NoIso",16,binning);
  //TH1F* pt_pass_Progression_22 = new TH1F("pt_pass_Progression_22","pt_pass_Progression_22",16,binning);
  //TH1F* pt_pass_OR = new TH1F("pt_pass_OR","pt_pass_OR",16,binning);

  TString OutputFileName = "Trees_meanparam/Tree_ForAcceptance_multipletaus_mean.root";
  TFile f(OutputFileName.Data(),"RECREATE");
  TTree outTree("AcceptanceTree","AcceptanceTree");
  
  Int_t           out_RunNumber = 0;
  ULong64_t       out_EventNumber = 0;
  Int_t           out_Lumi = 0; 

  Int_t n_OfflineTau = 0;
  Int_t n_L1Tau = 0;

  vector<float> OfflineTau_pt ;
  vector<float> OfflineTau_eta;
  vector<float> OfflineTau_phi;
  //vector<float> OfflineTau_E  ;

  vector<float> L1Tau_pt       ;
  vector<float> L1Tau_eta      ;
  vector<float> L1Tau_phi      ;
  vector<int>   L1Tau_IEt      ;
  vector<int>   L1Tau_IEta     ;
  vector<int>   L1Tau_nTT      ;
  vector<int>   L1Tau_RawEt    ;
  vector<int>   L1Tau_Iso      ;
  vector<bool>  L1Tau_isMerged ;
  vector<bool>  L1Tau_hasEM    ;

  vector<bool>  OfflineTau_isMatched ;

  vector<bool> L1Tau_passIso_Option1 ;
  vector<bool> L1Tau_passIso_Option2 ;
  vector<bool> L1Tau_passIso_Option3 ;
  vector<bool> L1Tau_passIso_Option4 ;
  vector<bool> L1Tau_passIso_Option5 ;
  vector<bool> L1Tau_passIso_Option6 ;
  vector<bool> L1Tau_passIso_Option7 ;
  vector<bool> L1Tau_passIso_Option8 ;
  vector<bool> L1Tau_passIso_Option9 ;
  vector<bool> L1Tau_passIso_Option10 ;
  vector<bool> L1Tau_passIso_Option11 ;
  vector<bool> L1Tau_passIso_Option12 ;
  vector<bool> L1Tau_passIso_Option13 ;
  vector<bool> L1Tau_passIso_Option14 ;
  vector<bool> L1Tau_passIso_Option15 ;
  vector<bool> L1Tau_passIso_Option16 ;
  vector<bool> L1Tau_passIso_Option17 ;
  vector<bool> L1Tau_passIso_Option18 ;
  vector<bool> L1Tau_passIso_Option19 ;
  vector<bool> L1Tau_passIso_Option20 ;
  vector<bool> L1Tau_passIso_Option21 ;
  vector<bool> L1Tau_passIso_Option22 ;

  outTree.Branch("RunNumber",&out_RunNumber);
  outTree.Branch("EventNumber",&out_EventNumber);
  outTree.Branch("Lumi",&out_Lumi);

  outTree.Branch("n_OfflineTau",&n_OfflineTau,"n_OfflineTau/I");
  outTree.Branch("n_L1Tau",&n_L1Tau,"n_L1Tau/I");

  outTree.Branch("OfflineTau_pt",&OfflineTau_pt);
  outTree.Branch("OfflineTau_eta",&OfflineTau_eta);
  //outTree.Branch("OfflineTau_E",&OfflineTau_E);
  outTree.Branch("OfflineTau_phi",&OfflineTau_phi);

  outTree.Branch("L1Tau_pt",&L1Tau_pt);
  outTree.Branch("L1Tau_eta",&L1Tau_eta);
  outTree.Branch("L1Tau_phi",&L1Tau_phi);
  outTree.Branch("L1Tau_IEt",&L1Tau_IEt);
  outTree.Branch("L1Tau_IEta",&L1Tau_IEta);
  outTree.Branch("L1Tau_isMerged",&L1Tau_isMerged);
  outTree.Branch("L1Tau_hasEM",&L1Tau_hasEM);
  outTree.Branch("L1Tau_Iso",&L1Tau_Iso);
  outTree.Branch("L1Tau_nTT",&L1Tau_nTT);
  outTree.Branch("L1Tau_RawEt",&L1Tau_RawEt);

  outTree.Branch("OfflineTau_isMatched",&OfflineTau_isMatched);

  outTree.Branch("L1Tau_passIso_Option1",&L1Tau_passIso_Option1);
  outTree.Branch("L1Tau_passIso_Option2",&L1Tau_passIso_Option2);
  outTree.Branch("L1Tau_passIso_Option3",&L1Tau_passIso_Option3);
  outTree.Branch("L1Tau_passIso_Option4",&L1Tau_passIso_Option4);
  outTree.Branch("L1Tau_passIso_Option5",&L1Tau_passIso_Option5);
  outTree.Branch("L1Tau_passIso_Option6",&L1Tau_passIso_Option6);
  outTree.Branch("L1Tau_passIso_Option7",&L1Tau_passIso_Option7);
  outTree.Branch("L1Tau_passIso_Option8",&L1Tau_passIso_Option8);
  outTree.Branch("L1Tau_passIso_Option9",&L1Tau_passIso_Option9);
  outTree.Branch("L1Tau_passIso_Option10",&L1Tau_passIso_Option10);
  outTree.Branch("L1Tau_passIso_Option11",&L1Tau_passIso_Option11);
  outTree.Branch("L1Tau_passIso_Option12",&L1Tau_passIso_Option12);
  outTree.Branch("L1Tau_passIso_Option13",&L1Tau_passIso_Option13);
  outTree.Branch("L1Tau_passIso_Option14",&L1Tau_passIso_Option14);
  outTree.Branch("L1Tau_passIso_Option15",&L1Tau_passIso_Option15);
  outTree.Branch("L1Tau_passIso_Option16",&L1Tau_passIso_Option16);
  outTree.Branch("L1Tau_passIso_Option17",&L1Tau_passIso_Option17);
  outTree.Branch("L1Tau_passIso_Option18",&L1Tau_passIso_Option18);
  outTree.Branch("L1Tau_passIso_Option19",&L1Tau_passIso_Option19);
  outTree.Branch("L1Tau_passIso_Option20",&L1Tau_passIso_Option20);
  outTree.Branch("L1Tau_passIso_Option21",&L1Tau_passIso_Option21);
  outTree.Branch("L1Tau_passIso_Option22",&L1Tau_passIso_Option22); 

  //Target 14 kHz,meani,305310
  //Double_t Threshold_NewLayer1_noIso   = 40.51;
  Double_t Threshold_NewLayer1_Option1 = 0;
  Double_t Threshold_NewLayer1_Option2 = 0;
  Double_t Threshold_NewLayer1_Option3 = 0;
  Double_t Threshold_NewLayer1_Option4 = 0;
  Double_t Threshold_NewLayer1_Option5 = 0;
  Double_t Threshold_NewLayer1_Option6 = 0;
  Double_t Threshold_NewLayer1_Option7 = 0;
  Double_t Threshold_NewLayer1_Option8 = 0;
  Double_t Threshold_NewLayer1_Option9 = 0;
  Double_t Threshold_NewLayer1_Option10 = 0;
  Double_t Threshold_NewLayer1_Option11 = 0;
  Double_t Threshold_NewLayer1_Option12 = 0;
  Double_t Threshold_NewLayer1_Option13 = 0;
  Double_t Threshold_NewLayer1_Option14 = 0;
  Double_t Threshold_NewLayer1_Option15 = 0;
  Double_t Threshold_NewLayer1_Option16 = 0;
  Double_t Threshold_NewLayer1_Option17 = 0;
  Double_t Threshold_NewLayer1_Option18 = 0;
  Double_t Threshold_NewLayer1_Option19 = 0;
  Double_t Threshold_NewLayer1_Option20 = 0;
  Double_t Threshold_NewLayer1_Option21 = 0;
  Double_t Threshold_NewLayer1_Option22 = 0;
  //Double_t Threshold_NewLayer1_noIso_unpacked = 41.51;
  //Double_t Threshold_NewLayer1_Iso_unpacked = 28.51;  

  for(int i = 0 ; i < data.GetEntries() ; ++i)
    { 
      //out_EventNumber .clear();
      //out_RunNumber .clear();
      //out_Lumi .clear();

      OfflineTau_pt  .clear();
      OfflineTau_eta .clear();
      OfflineTau_phi .clear();
      //OfflineTau_E   .clear();

      L1Tau_pt         .clear();
      L1Tau_eta        .clear();
      L1Tau_phi        .clear();
      L1Tau_IEt        .clear();
      L1Tau_IEta       .clear();
      L1Tau_nTT        .clear();
      L1Tau_isMerged   .clear();
      L1Tau_hasEM      .clear();
      L1Tau_Iso        .clear();
      L1Tau_RawEt      .clear();

      OfflineTau_isMatched  .clear();

      L1Tau_passIso_Option1  .clear();
      L1Tau_passIso_Option2  .clear();
      L1Tau_passIso_Option3  .clear();
      L1Tau_passIso_Option4  .clear();
      L1Tau_passIso_Option5  .clear();
      L1Tau_passIso_Option6  .clear();
      L1Tau_passIso_Option7  .clear();
      L1Tau_passIso_Option8  .clear();
      L1Tau_passIso_Option9  .clear();
      L1Tau_passIso_Option10  .clear();
      L1Tau_passIso_Option11  .clear();
      L1Tau_passIso_Option12  .clear();
      L1Tau_passIso_Option13  .clear();
      L1Tau_passIso_Option14  .clear();
      L1Tau_passIso_Option15  .clear();
      L1Tau_passIso_Option16  .clear();
      L1Tau_passIso_Option17  .clear();
      L1Tau_passIso_Option18  .clear();
      L1Tau_passIso_Option19  .clear();
      L1Tau_passIso_Option20  .clear();
      L1Tau_passIso_Option21  .clear();
      L1Tau_passIso_Option22  .clear();

      if(i%10000==0) cout<<"entry #"<<i<<"/"<<data.GetEntries()<<endl;
      data.GetEntry(i);

      //loop on reco taus
      n_OfflineTau = 0;
      n_L1Tau = 0;

      for(UInt_t iTau = 0 ; iTau < tauPt->size() ; ++iTau)
      	{ 
	  TLorentzVector RecoTau;
	  RecoTau.SetPtEtaPhiM(tauPt->at(iTau),tauEta->at(iTau),tauPhi->at(iTau),0);

	  if(RecoTau.Pt()<18.) continue;
	  if(fabs(RecoTau.Eta())>2.1) continue;

	  vector < pair<float, int> > L1_matched;
	  const float maxdR = 0.3;
	              
	  for(UInt_t iL1Tau = 0 ; iL1Tau < l1tEmuPt->size() ; ++iL1Tau)
           { 
	      if(fabs(l1tEmuEta->at(iL1Tau))>2.1) continue;

	      TLorentzVector L1Tau;
	      L1Tau.SetPtEtaPhiM(l1tEmuPt->at(iL1Tau),l1tEmuEta->at(iL1Tau),l1tEmuPhi->at(iL1Tau),0.);

	      float dR = RecoTau.DeltaR(L1Tau);
	      if (dR < maxdR)
                {
                   L1_matched.push_back(make_pair(dR, iL1Tau));
                }
            }

	  if (L1_matched.size() > 0) // all for the turn on
            { 
	      sort(L1_matched.begin(), L1_matched.end());
	      int iL1Tau = L1_matched.at(0).second;
	      int L1Tau_CompressedIEta = FindBinIEta(abs(l1tEmuTowerIEta->at(iL1Tau)));
	      int L1Tau_CompressedRawIEt = FindBinIEt(l1tEmuRawEt->at(iL1Tau));
	      int L1Tau_CompressednTT = FindBinnTT(l1tEmuNTT->at(iL1Tau));	      
              
	      float CorrectionFactorMVA4D = 1.;
	      int temp_hasEM = 0;
	      if(l1tEmuHasEM->at(iL1Tau)) temp_hasEM = 1;
	      //if(!l1tEmuIsMerged->at(iL1Tau)) CorrectionFactorMVA4D = h_3D_isMerged0->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,temp_hasEM+1);  
              if(!l1tEmuIsMerged->at(iL1Tau)) CorrectionFactorMVA4D = h_3D_isMerged0->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,temp_hasEM+1);
              else CorrectionFactorMVA4D = h_3D_isMerged0->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,temp_hasEM+1);
	      if(CorrectionFactorMVA4D>=1.3) CorrectionFactorMVA4D=1.3;	      
	      float CurrentCalibratedEt = (float)l1tEmuRawEt->at(iL1Tau)/2.*CorrectionFactorMVA4D;	   

	      TLorentzVector tlvL1Matched;
	      tlvL1Matched.SetPtEtaPhiM(CurrentCalibratedEt,l1tEmuEta->at(iL1Tau),l1tEmuPhi->at(iL1Tau),0.);
              
  	      OfflineTau_pt .push_back(RecoTau.Pt());
	      OfflineTau_eta.push_back(RecoTau.Eta());
	      OfflineTau_phi.push_back(RecoTau.Phi());
	      //OfflineTau_E  .push_back(RecoTau.E());             
 
	      L1Tau_pt      .push_back(CurrentCalibratedEt);
	      // L1Tau_pt      .push_back(tlvL1Matched.Pt());
	      L1Tau_eta     .push_back(tlvL1Matched.Eta());
	      L1Tau_phi     .push_back(tlvL1Matched.Phi());
	      L1Tau_IEt.push_back(l1tEmuRawEt->at(iL1Tau));
	      L1Tau_IEta.push_back(l1tEmuTowerIEta->at(iL1Tau));

	      L1Tau_Iso.push_back(l1tEmuIsoEt->at(iL1Tau));

	      OfflineTau_isMatched.push_back(kTRUE);
               
	      Int_t IsoCut_Progression_1 = histosIsolation["LUT_Progression_1"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_2 = histosIsolation["LUT_Progression_2"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_3 = histosIsolation["LUT_Progression_3"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_4 = histosIsolation["LUT_Progression_4"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_5 = histosIsolation["LUT_Progression_5"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_6 = histosIsolation["LUT_Progression_6"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_7 = histosIsolation["LUT_Progression_7"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_8 = histosIsolation["LUT_Progression_8"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_9 = histosIsolation["LUT_Progression_9"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_10 = histosIsolation["LUT_Progression_10"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_11 = histosIsolation["LUT_Progression_11"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_12 = histosIsolation["LUT_Progression_12"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_13 = histosIsolation["LUT_Progression_13"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_14 = histosIsolation["LUT_Progression_14"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_15 = histosIsolation["LUT_Progression_15"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_16 = histosIsolation["LUT_Progression_16"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_17 = histosIsolation["LUT_Progression_17"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_18 = histosIsolation["LUT_Progression_18"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_19 = histosIsolation["LUT_Progression_19"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_20 = histosIsolation["LUT_Progression_20"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_21 = histosIsolation["LUT_Progression_21"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      Int_t IsoCut_Progression_22 = histosIsolation["LUT_Progression_22"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
	      
              if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_1 && CurrentCalibratedEt>=Threshold_NewLayer1_Option1)
		{
		  L1Tau_passIso_Option1.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_2 && CurrentCalibratedEt>=Threshold_NewLayer1_Option2)
		{
		  L1Tau_passIso_Option2.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_3 && CurrentCalibratedEt>=Threshold_NewLayer1_Option3)
		{
		  L1Tau_passIso_Option3.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_4 && CurrentCalibratedEt>=Threshold_NewLayer1_Option4)
		{
		  L1Tau_passIso_Option4.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_5 && CurrentCalibratedEt>=Threshold_NewLayer1_Option5)
		{
		  L1Tau_passIso_Option5.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_6 && CurrentCalibratedEt>=Threshold_NewLayer1_Option6)
		{
		  L1Tau_passIso_Option6.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_7 && CurrentCalibratedEt>=Threshold_NewLayer1_Option7)
		{
		  L1Tau_passIso_Option7.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_8 && CurrentCalibratedEt>=Threshold_NewLayer1_Option8)
		{
		  L1Tau_passIso_Option8.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_9 && CurrentCalibratedEt>=Threshold_NewLayer1_Option9)
		{
		  L1Tau_passIso_Option9.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_10 && CurrentCalibratedEt>=Threshold_NewLayer1_Option10)
		{
		  L1Tau_passIso_Option10.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_11 && CurrentCalibratedEt>=Threshold_NewLayer1_Option11)
		{
		  L1Tau_passIso_Option11.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_12 && CurrentCalibratedEt>=Threshold_NewLayer1_Option12)
		{
		  L1Tau_passIso_Option12.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_13 && CurrentCalibratedEt>=Threshold_NewLayer1_Option13)
		{
		  L1Tau_passIso_Option13.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_14 && CurrentCalibratedEt>=Threshold_NewLayer1_Option14)
		{
		  L1Tau_passIso_Option14.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_15 && CurrentCalibratedEt>=Threshold_NewLayer1_Option15)
		{
		  L1Tau_passIso_Option15.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_16 && CurrentCalibratedEt>=Threshold_NewLayer1_Option16)
		{
		  L1Tau_passIso_Option16.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_17 && CurrentCalibratedEt>=Threshold_NewLayer1_Option17)
		{
		  L1Tau_passIso_Option17.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_18 && CurrentCalibratedEt>=Threshold_NewLayer1_Option18)
		{
		  L1Tau_passIso_Option18.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_19 && CurrentCalibratedEt>=Threshold_NewLayer1_Option19)
		{
		  L1Tau_passIso_Option19.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_20 && CurrentCalibratedEt>=Threshold_NewLayer1_Option20)
		{
		  L1Tau_passIso_Option20.push_back(true);
		}		  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_21 && CurrentCalibratedEt>=Threshold_NewLayer1_Option21)
		{
		  L1Tau_passIso_Option21.push_back(true);
		}		  	  
	      if(l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_22 && CurrentCalibratedEt>=Threshold_NewLayer1_Option22)
		{
		  L1Tau_passIso_Option22.push_back(true);
		} 
              
	      L1Tau_nTT.push_back(l1tEmuNTT->at(iL1Tau));

	      out_EventNumber = i;

	      L1Tau_hasEM.push_back(l1tEmuHasEM->at(iL1Tau));
	      L1Tau_isMerged.push_back(l1tEmuIsMerged->at(iL1Tau));

	      ++n_OfflineTau;
	      ++n_L1Tau;

	      outTree.Fill();	      
	      
            }
	  else
	    {
	      OfflineTau_pt  .push_back( RecoTau.Pt());
	      OfflineTau_eta .push_back( RecoTau.Eta());
	      OfflineTau_phi .push_back( RecoTau.Phi());
	     // OfflineTau_E   .push_back( RecoTau.E());

	      L1Tau_pt       .push_back( -999.);
	      L1Tau_eta      .push_back( -999.);
	      L1Tau_phi      .push_back( -999.);

	      OfflineTau_isMatched .push_back( kFALSE);

	      L1Tau_passIso_Option1.push_back(kFALSE);
	      L1Tau_passIso_Option2.push_back(kFALSE);
	      L1Tau_passIso_Option3.push_back(kFALSE);
	      L1Tau_passIso_Option4.push_back(kFALSE);
	      L1Tau_passIso_Option5.push_back(kFALSE);
	      L1Tau_passIso_Option6.push_back(kFALSE);
	      L1Tau_passIso_Option7.push_back(kFALSE);
	      L1Tau_passIso_Option8.push_back(kFALSE);
	      L1Tau_passIso_Option9.push_back(kFALSE);
	      L1Tau_passIso_Option10.push_back(kFALSE);
	      L1Tau_passIso_Option11.push_back(kFALSE);
	      L1Tau_passIso_Option12.push_back(kFALSE);
	      L1Tau_passIso_Option13.push_back(kFALSE);
	      L1Tau_passIso_Option14.push_back(kFALSE);
	      L1Tau_passIso_Option15.push_back(kFALSE);
	      L1Tau_passIso_Option16.push_back(kFALSE);
	      L1Tau_passIso_Option17.push_back(kFALSE);
	      L1Tau_passIso_Option18.push_back(kFALSE);
	      L1Tau_passIso_Option19.push_back(kFALSE);
	      L1Tau_passIso_Option20.push_back(kFALSE);
	      L1Tau_passIso_Option21.push_back(kFALSE);
	      L1Tau_passIso_Option22.push_back(kFALSE);
	      
              out_RunNumber = -999;
	      out_EventNumber = -999;
	      out_Lumi = -999;

	      L1Tau_IEt .push_back( -99);
	      L1Tau_IEta .push_back( -99);

	      L1Tau_Iso .push_back( -99);
	      L1Tau_nTT .push_back( -99);

	      L1Tau_hasEM.push_back(kFALSE);
	      L1Tau_isMerged.push_back(kFALSE);

	      ++n_OfflineTau;
	      ++n_L1Tau;
  
	      outTree.Fill();	      
	    }

	  
	}
	  
    }
	  
  outTree.Write();

}
