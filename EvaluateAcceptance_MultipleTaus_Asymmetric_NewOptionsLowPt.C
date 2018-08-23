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
#include <vector>

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

void EvaluateAcceptance(Int_t Option = 22, Int_t Thr_leading = 28, Int_t Thr_subleading = 28)
{
  std::map<TString,TH3F*> histosIsolation;
  TFile f_Isolation("../Trees_meanparam/Iso_LUTs_Options_MC_92X_mean_NewOptionsLowPt.root");

  for(UInt_t i = 1 ; i < 32 ; ++i)
    {
      TString CurrentNameHisto = "LUT_Progression_";
      ostringstream convert;
      convert << i;
      CurrentNameHisto += convert.str();
      TH3F* current_Histo = (TH3F*)f_Isolation.Get(CurrentNameHisto.Data());
      histosIsolation.insert(make_pair(CurrentNameHisto,current_Histo));
    }

  TString InputFileName = "../Trees_meanparam/Tree_ForAcceptance_multipletaus_mean.root";
  TChain data("AcceptanceTree");
  data.Add(InputFileName.Data());

  Int_t           RunNumber = 0;
  ULong64_t       EventNumber = 0;
  Int_t           Lumi = 0;

  vector<float>   *OfflineTau_pt = 0;
  vector<float>   *OfflineTau_eta = 0;
  vector<float>   *OfflineTau_phi = 0;

  vector<float>   *L1Tau_pt = 0;
  vector<float>   *L1Tau_eta = 0;
  vector<float>   *L1Tau_phi = 0;
  vector<int>     *L1Tau_IEt = 0;
  vector<int>     *L1Tau_IEta = 0;
  vector<bool>    *L1Tau_isMerged = 0;
  vector<bool>    *L1Tau_hasEM = 0;
  vector<int>     *L1Tau_Iso = 0;
  vector<int>     *L1Tau_nTT = 0;
  vector<int>     *L1Tau_RawEt = 0;
  vector<bool>    *OfflineTau_isMatched = 0; 
  
  vector<bool>    *L1Tau_passIso_Option1 = 0;
  vector<bool>    *L1Tau_passIso_Option2 = 0;
  vector<bool>    *L1Tau_passIso_Option3 = 0;
  vector<bool>    *L1Tau_passIso_Option4 = 0;
  vector<bool>    *L1Tau_passIso_Option5 = 0;
  vector<bool>    *L1Tau_passIso_Option6 = 0;
  vector<bool>    *L1Tau_passIso_Option7 = 0;
  vector<bool>    *L1Tau_passIso_Option8 = 0;
  vector<bool>    *L1Tau_passIso_Option9 = 0;
  vector<bool>    *L1Tau_passIso_Option10 = 0;
  vector<bool>    *L1Tau_passIso_Option11 = 0;
  vector<bool>    *L1Tau_passIso_Option12 = 0;
  vector<bool>    *L1Tau_passIso_Option13 = 0;
  vector<bool>    *L1Tau_passIso_Option14 = 0;
  vector<bool>    *L1Tau_passIso_Option15 = 0;
  vector<bool>    *L1Tau_passIso_Option16 = 0;
  vector<bool>    *L1Tau_passIso_Option17 = 0;
  vector<bool>    *L1Tau_passIso_Option18 = 0;
  vector<bool>    *L1Tau_passIso_Option19 = 0;
  vector<bool>    *L1Tau_passIso_Option20 = 0;
  vector<bool>    *L1Tau_passIso_Option21 = 0;
  vector<bool>    *L1Tau_passIso_Option22 = 0;

  TBranch   *b_RunNumber ;
  TBranch   *b_EventNumber ;
  TBranch   *b_Lumi ;
  TBranch   *b_OfflineTau_pt ;
  TBranch   *b_OfflineTau_eta ;
  TBranch   *b_OfflineTau_phi ;

  TBranch   *b_L1Tau_pt ;
  TBranch   *b_L1Tau_eta ;
  TBranch   *b_L1Tau_phi ;
  TBranch   *b_L1Tau_IEt ;
  TBranch   *b_L1Tau_IEta ;
  TBranch   *b_L1Tau_isMerged ;
  TBranch   *b_L1Tau_hasEM ;
  TBranch   *b_L1Tau_Iso ;
  TBranch   *b_L1Tau_nTT ;
  TBranch   *b_L1Tau_RawEt ;
  TBranch   *b_OfflineTau_isMatched ;

  TBranch   *b_L1Tau_passIso_Option1 ;
  TBranch   *b_L1Tau_passIso_Option2 ;
  TBranch   *b_L1Tau_passIso_Option3 ;
  TBranch   *b_L1Tau_passIso_Option4 ;
  TBranch   *b_L1Tau_passIso_Option5 ;
  TBranch   *b_L1Tau_passIso_Option6 ;
  TBranch   *b_L1Tau_passIso_Option7 ;
  TBranch   *b_L1Tau_passIso_Option8 ;
  TBranch   *b_L1Tau_passIso_Option9 ;
  TBranch   *b_L1Tau_passIso_Option10 ;
  TBranch   *b_L1Tau_passIso_Option11 ;
  TBranch   *b_L1Tau_passIso_Option12 ;
  TBranch   *b_L1Tau_passIso_Option13 ;
  TBranch   *b_L1Tau_passIso_Option14 ;
  TBranch   *b_L1Tau_passIso_Option15 ;
  TBranch   *b_L1Tau_passIso_Option16 ;
  TBranch   *b_L1Tau_passIso_Option17 ;
  TBranch   *b_L1Tau_passIso_Option18 ;
  TBranch   *b_L1Tau_passIso_Option19 ;
  TBranch   *b_L1Tau_passIso_Option20 ;
  TBranch   *b_L1Tau_passIso_Option21 ;
  TBranch   *b_L1Tau_passIso_Option22 ;
  
  data.SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
  data.SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
  data.SetBranchAddress("Lumi", &Lumi, &b_Lumi);
  data.SetBranchAddress("OfflineTau_pt", &OfflineTau_pt, &b_OfflineTau_pt);
  data.SetBranchAddress("OfflineTau_eta", &OfflineTau_eta, &b_OfflineTau_eta);
  data.SetBranchAddress("OfflineTau_phi", &OfflineTau_phi, &b_OfflineTau_phi);

  data.SetBranchAddress("L1Tau_pt", &L1Tau_pt, &b_L1Tau_pt);
  data.SetBranchAddress("L1Tau_eta", &L1Tau_eta, &b_L1Tau_eta);
  data.SetBranchAddress("L1Tau_phi", &L1Tau_phi, &b_L1Tau_phi);
  data.SetBranchAddress("L1Tau_IEt", &L1Tau_IEt, &b_L1Tau_IEt);
  data.SetBranchAddress("L1Tau_IEta", &L1Tau_IEta, &b_L1Tau_IEta);
  data.SetBranchAddress("L1Tau_isMerged", &L1Tau_isMerged, &b_L1Tau_isMerged);
  data.SetBranchAddress("L1Tau_hasEM", &L1Tau_hasEM, &b_L1Tau_hasEM);
  data.SetBranchAddress("L1Tau_Iso", &L1Tau_Iso, &b_L1Tau_Iso);
  data.SetBranchAddress("L1Tau_nTT", &L1Tau_nTT, &b_L1Tau_nTT);
  data.SetBranchAddress("L1Tau_RawEt", &L1Tau_RawEt, &b_L1Tau_RawEt);
  data.SetBranchAddress("OfflineTau_isMatched", &OfflineTau_isMatched, &b_OfflineTau_isMatched);
  
  data.SetBranchAddress("L1Tau_passIso_Option1", &L1Tau_passIso_Option1, &b_L1Tau_passIso_Option1);
  data.SetBranchAddress("L1Tau_passIso_Option2", &L1Tau_passIso_Option2, &b_L1Tau_passIso_Option2);
  data.SetBranchAddress("L1Tau_passIso_Option3", &L1Tau_passIso_Option3, &b_L1Tau_passIso_Option3);
  data.SetBranchAddress("L1Tau_passIso_Option4", &L1Tau_passIso_Option4, &b_L1Tau_passIso_Option4);
  data.SetBranchAddress("L1Tau_passIso_Option5", &L1Tau_passIso_Option5, &b_L1Tau_passIso_Option5);
  data.SetBranchAddress("L1Tau_passIso_Option6", &L1Tau_passIso_Option6, &b_L1Tau_passIso_Option6);
  data.SetBranchAddress("L1Tau_passIso_Option7", &L1Tau_passIso_Option7, &b_L1Tau_passIso_Option7);
  data.SetBranchAddress("L1Tau_passIso_Option8", &L1Tau_passIso_Option8, &b_L1Tau_passIso_Option8);
  data.SetBranchAddress("L1Tau_passIso_Option9", &L1Tau_passIso_Option9, &b_L1Tau_passIso_Option9);
  data.SetBranchAddress("L1Tau_passIso_Option10", &L1Tau_passIso_Option10, &b_L1Tau_passIso_Option10);
  data.SetBranchAddress("L1Tau_passIso_Option11", &L1Tau_passIso_Option11, &b_L1Tau_passIso_Option11);
  data.SetBranchAddress("L1Tau_passIso_Option12", &L1Tau_passIso_Option12, &b_L1Tau_passIso_Option12);
  data.SetBranchAddress("L1Tau_passIso_Option13", &L1Tau_passIso_Option13, &b_L1Tau_passIso_Option13);
  data.SetBranchAddress("L1Tau_passIso_Option14", &L1Tau_passIso_Option14, &b_L1Tau_passIso_Option14);
  data.SetBranchAddress("L1Tau_passIso_Option15", &L1Tau_passIso_Option15, &b_L1Tau_passIso_Option15);
  data.SetBranchAddress("L1Tau_passIso_Option16", &L1Tau_passIso_Option16, &b_L1Tau_passIso_Option16);
  data.SetBranchAddress("L1Tau_passIso_Option17", &L1Tau_passIso_Option17, &b_L1Tau_passIso_Option17);
  data.SetBranchAddress("L1Tau_passIso_Option18", &L1Tau_passIso_Option18, &b_L1Tau_passIso_Option18);
  data.SetBranchAddress("L1Tau_passIso_Option19", &L1Tau_passIso_Option19, &b_L1Tau_passIso_Option19);
  data.SetBranchAddress("L1Tau_passIso_Option20", &L1Tau_passIso_Option20, &b_L1Tau_passIso_Option20);
  data.SetBranchAddress("L1Tau_passIso_Option21", &L1Tau_passIso_Option21, &b_L1Tau_passIso_Option21);
  data.SetBranchAddress("L1Tau_passIso_Option22", &L1Tau_passIso_Option22, &b_L1Tau_passIso_Option22);
 
  double denominator = 0;
  double numerator = 0;
/*  
  TH1F *pt_Offline_leading = new TH1F("pt_offline_leading","pt_offline_leading",50,0,150);
  TH1F *pt_Offline_subleading = new TH1F("pt_offline_subleading","pt_offline_subleading",50,0,150);
  TH1F *pt_L1_noIso_leading = new TH1F("pt_L1_noIso_leading","pt_L1_noIso_leading",50,0,150);
  TH1F *pt_L1_noIso_subleading = new TH1F("pt_L1_noIso_subleading","pt_L1_noIso_subleading",50,0,150);
  TH1F *pt_L1_Option_leading = new TH1F("pt_L1_Option_leading","pt_L1_Option_leading",50,0,150);
  TH1F *pt_L1_Option_subleading = new TH1F("pt_L1_Option_subleading","pt_L1_Option_subleading",50,0,150); 
*/ 
  // loop events
  for(UInt_t i = 0 ;  i < data.GetEntries() ; ++i)// i < data.GetEntries()
  {
    data.GetEntry(i);
    if(i%100000==0) cout<<"Entry #"<<i<<endl;

    std::vector<Int_t> Index_TausOFF;
    Index_TausOFF.push_back(-1); Index_TausOFF.push_back(-1);
    std::vector<Float_t> pt_TausOFF;
    pt_TausOFF.push_back(-99.); pt_TausOFF.push_back(-99.);
    std::vector<Float_t> eta_TausOFF;
    eta_TausOFF.push_back(-99.); eta_TausOFF.push_back(-99.);
    std::vector<Float_t> phi_TausOFF;
    phi_TausOFF.push_back(-99.); phi_TausOFF.push_back(-99.);
    
    Bool_t PassOffline = kFALSE;

    // **** LOOP OFFLINE TAUS **** //
    for(UInt_t iTauOFF = 0 ; iTauOFF < OfflineTau_pt->size() ; ++iTauOFF)
    { 
      if(OfflineTau_isMatched==0) continue;

      if(OfflineTau_pt->at(iTauOFF)>=pt_TausOFF.at(0) )
      {
        Index_TausOFF.at(1)=Index_TausOFF.at(0);
        pt_TausOFF.at(1)=pt_TausOFF.at(0);
        eta_TausOFF.at(1)=eta_TausOFF.at(0);
        phi_TausOFF.at(1)=phi_TausOFF.at(0);
        Index_TausOFF.at(0)=iTauOFF;
        pt_TausOFF.at(0)=OfflineTau_pt->at(iTauOFF);
        eta_TausOFF.at(0)=OfflineTau_eta->at(iTauOFF);
        phi_TausOFF.at(0)=OfflineTau_phi->at(iTauOFF);
      }
      else if(OfflineTau_pt->at(iTauOFF)>=pt_TausOFF.at(1))
      {
        Index_TausOFF.at(1)=iTauOFF;
        pt_TausOFF.at(1)=OfflineTau_pt->at(iTauOFF);
        eta_TausOFF.at(1)=OfflineTau_eta->at(iTauOFF);
        phi_TausOFF.at(1)=OfflineTau_phi->at(iTauOFF);
      }
    }
    
    TLorentzVector OfflTau0;
    TLorentzVector OfflTau1;
    
    if(Index_TausOFF.at(0)>=0 && Index_TausOFF.at(1)>=0)
    { 
      OfflTau0.SetPtEtaPhiM(pt_TausOFF.at(0),eta_TausOFF.at(0),phi_TausOFF.at(0),0.);
      OfflTau1.SetPtEtaPhiM(pt_TausOFF.at(1),eta_TausOFF.at(1),phi_TausOFF.at(1),0.);
      
      //pt_Offline_leading->Fill(pt_TausOFF.at(0));
      //pt_Offline_subleading->Fill(pt_TausOFF.at(1)); 
      
      if((pt_TausOFF.at(0) > 20) && (pt_TausOFF.at(1) > 20)){ denominator++; };
     
      if(pt_TausOFF.at(0) < Thr_leading+5) continue;
      if(pt_TausOFF.at(1) < Thr_subleading+5) continue;

      PassOffline = kTRUE;
    }

    if(!PassOffline) continue;

    std::vector<Int_t> Index_Taus_Progression;
    Index_Taus_Progression.push_back(-1); Index_Taus_Progression.push_back(-1);
    std::vector<Float_t> pt_Taus_Progression;
    pt_Taus_Progression.push_back(-99.); pt_Taus_Progression.push_back(-99.);
    std::vector<Float_t> eta_Taus_Progression;
    eta_Taus_Progression.push_back(-99.); eta_Taus_Progression.push_back(-99.);
    std::vector<Float_t> phi_Taus_Progression;
    phi_Taus_Progression.push_back(-99.); phi_Taus_Progression.push_back(-99.);
    
    // **** LOOP L1 TAUS ***** //
    for(UInt_t iL1Tau = 0 ; iL1Tau < L1Tau_pt->size() ; ++iL1Tau)
    { 
      int L1Tau_CompressedIEta = FindBinIEta(abs(L1Tau_IEta->at(iL1Tau)));
      int L1Tau_CompressedRawIEt = FindBinIEt(L1Tau_IEt->at(iL1Tau));
      int L1Tau_CompressednTT = FindBinnTT(L1Tau_nTT->at(iL1Tau));
      
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
      Int_t IsoCut_Progression_23 = histosIsolation["LUT_Progression_23"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);
      Int_t IsoCut_Progression_24 = histosIsolation["LUT_Progression_24"]->GetBinContent(L1Tau_CompressedIEta+1,L1Tau_CompressedRawIEt+1,L1Tau_CompressednTT+1);   
      
      if ( (Option == 1) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_1) ) continue; 
      if ( (Option == 2) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_2) ) continue;
      if ( (Option == 3) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_3) ) continue;
      if ( (Option == 4) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_4) ) continue;
      if ( (Option == 5) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_5) ) continue;
      if ( (Option == 6) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_6) ) continue;
      if ( (Option == 7) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_7) ) continue;
      if ( (Option == 8) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_8) ) continue;
      if ( (Option == 9) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_9) ) continue;
      if ( (Option == 10) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_10) ) continue;
      if ( (Option == 11) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_11) ) continue;
      if ( (Option == 12) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_12) ) continue;
      if ( (Option == 13) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_13) ) continue;
      if ( (Option == 14) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_14) ) continue;
      if ( (Option == 15) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_15) ) continue;
      if ( (Option == 16) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_16) ) continue; 
      if ( (Option == 17) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_17) ) continue;
      if ( (Option == 18) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_18) ) continue;
      if ( (Option == 19) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_19) ) continue;
      if ( (Option == 20) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_20) ) continue;
      if ( (Option == 21) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_21) ) continue; 
      if ( (Option == 22) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_22) ) continue;     
      if ( (Option == 23) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_23) ) continue;
      if ( (Option == 24) && (L1Tau_Iso->at(iL1Tau)>=IsoCut_Progression_24) ) continue;

      /* if( (Option == 1) && (!L1Tau_passIso_Option1)) continue;
      if( (Option == 2) && (!L1Tau_passIso_Option2)) continue;
      if( (Option == 3) && (!L1Tau_passIso_Option3)) continue;
      if( (Option == 4) && (!L1Tau_passIso_Option4)) continue;
      if( (Option == 5) && (!L1Tau_passIso_Option5)) continue;
      if( (Option == 6) && (!L1Tau_passIso_Option6)) continue;
      if( (Option == 7) && (!L1Tau_passIso_Option7)) continue;
      if( (Option == 8) && (!L1Tau_passIso_Option8)) continue;
      if( (Option == 9) && (!L1Tau_passIso_Option9)) continue;
      if( (Option == 10) && (!L1Tau_passIso_Option10)) continue;
      if( (Option == 11) && (!L1Tau_passIso_Option11)) continue;
      if( (Option == 12) && (!L1Tau_passIso_Option12)) continue;
      if( (Option == 13) && (!L1Tau_passIso_Option13)) continue;
      if( (Option == 14) && (!L1Tau_passIso_Option14)) continue;
      if( (Option == 15) && (!L1Tau_passIso_Option15)) continue;
      if( (Option == 16) && (!L1Tau_passIso_Option16)) continue;
      if( (Option == 17) && (!L1Tau_passIso_Option17)) continue;
      if( (Option == 18) && (!L1Tau_passIso_Option18)) continue;
      if( (Option == 19) && (!L1Tau_passIso_Option19)) continue;
      if( (Option == 20) && (!L1Tau_passIso_Option20)) continue;
      if( (Option == 21) && (!L1Tau_passIso_Option21)) continue;
      if( (Option == 22) && (!L1Tau_passIso_Option22)) continue;    
     */ 
      if(L1Tau_pt->at(iL1Tau)>=pt_Taus_Progression.at(0))
        {
          Index_Taus_Progression.at(1)=Index_Taus_Progression.at(0);
          pt_Taus_Progression.at(1)=pt_Taus_Progression.at(0);
          eta_Taus_Progression.at(1)=eta_Taus_Progression.at(0);
          phi_Taus_Progression.at(1)=phi_Taus_Progression.at(0);
          Index_Taus_Progression.at(0)=iL1Tau;
          pt_Taus_Progression.at(0)=L1Tau_pt->at(iL1Tau);
          eta_Taus_Progression.at(0)=L1Tau_eta->at(iL1Tau);
          phi_Taus_Progression.at(0)=L1Tau_phi->at(iL1Tau);
        }
      else if(L1Tau_pt->at(iL1Tau)>=pt_Taus_Progression.at(1))
        {
          Index_Taus_Progression.at(1)=iL1Tau;
          pt_Taus_Progression.at(1)=L1Tau_pt->at(iL1Tau);
          eta_Taus_Progression.at(1)=L1Tau_eta->at(iL1Tau);
          phi_Taus_Progression.at(1)=L1Tau_phi->at(iL1Tau);
        }
    }

    TLorentzVector L1Tau0;
    TLorentzVector L1Tau1;
    TLorentzVector L1Tau0_noIso;
    TLorentzVector L1Tau1_noIso;
    
    if(Index_Taus_Progression.at(0)>=0 && Index_Taus_Progression.at(1)>=0)
    { 
      L1Tau0.SetPtEtaPhiM(pt_Taus_Progression.at(0),eta_Taus_Progression.at(0),phi_Taus_Progression.at(0),0.);
      L1Tau1.SetPtEtaPhiM(pt_Taus_Progression.at(1),eta_Taus_Progression.at(1),phi_Taus_Progression.at(1),0.);
      
      if(OfflTau0.DeltaR(L1Tau0)>0.5) continue;
      if(OfflTau1.DeltaR(L1Tau1)>0.5) continue;

      //pt_L1_Option_leading->Fill(pt_Taus_Progression.at(0));
      //pt_L1_Option_subleading->Fill(pt_Taus_Progression.at(1));
      
      if(pt_Taus_Progression.at(0) < Thr_leading) continue;
      if(pt_Taus_Progression.at(1) < Thr_subleading) continue;
      
      numerator++;
    }
  }
 
  cout << "Option " << Option << endl;
  cout << "L1 thr (" << Thr_leading << ", " << Thr_subleading << ")" << endl; 
  cout << "num: " << numerator << ", den: " << denominator << endl;
  double acceptance = numerator/denominator;
  cout << "Acceptance = " << acceptance << endl;
  
/*  TPaveText* texl = new TPaveText(0.18,0.87,0.93,0.99,"NDC");
  texl->AddText("CMS Internal, #sqrt{s}=13 TeV, MC VBF H #rightarrow #tau#tau (PU 28-62)");
  texl->SetTextSize(0.03);
  texl->SetFillStyle(0);
  texl->SetBorderSize(0);
  texl->Draw("same");

  gStyle->SetOptStat(0);

  TCanvas *c1 = new TCanvas("c1","c1",1200,600);
  c1->Divide(2,1);
  c1->cd(1);
  c1->SetGrid();
 
  pt_Offline_subleading->SetLineColor(kRed);
  pt_Offline_subleading->SetFillColor(kRed);
  pt_Offline_subleading->SetFillStyle(3004);
  pt_Offline_subleading->Draw();
  pt_Offline_subleading->SetFillStyle(3004);
  pt_Offline_subleading->SetTitle("");
  pt_Offline_subleading->GetXaxis()->SetTitle("p^{#tau}_{T} offline [GeV]");
  pt_Offline_subleading->GetYaxis()->SetTitle("a. u.");
  pt_Offline_subleading->GetYaxis()->SetTitleOffset(1.6);
  
  pt_Offline_leading->SetLineColor(kBlue);
  pt_Offline_leading->SetFillColor(kBlue);
  pt_Offline_leading->SetFillStyle(3005);
  pt_Offline_leading->Draw("same");

  TLegend *leg = new TLegend(0.62,0.68,0.85,0.87);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.03);
  leg->SetFillColor(kWhite);
  leg->SetHeader("#bf{Offline}");
  leg->AddEntry(pt_Offline_leading, "Leading #tau","f");
  leg->AddEntry(pt_Offline_subleading, "Subleading #tau","f");
  leg->Draw("same");

  texl->Draw("same");

  c1->cd(2);
  pt_L1_noIso_subleading->SetFillStyle(3004);
  pt_L1_noIso_subleading->SetLineColor(kRed);
  pt_L1_noIso_subleading->SetFillColor(kRed);
  pt_L1_noIso_subleading->Draw();
  pt_L1_noIso_subleading->SetTitle("");
  pt_L1_noIso_subleading->GetXaxis()->SetTitle("p^{#tau}_{T} L1 [GeV]");
  pt_L1_noIso_subleading->GetYaxis()->SetTitle("a. u. ");
  pt_L1_noIso_subleading->GetYaxis()->SetTitleOffset(1.6);
  
  pt_L1_noIso_leading->SetLineColor(kBlue);
  pt_L1_noIso_leading->SetFillStyle(3005);
  pt_L1_noIso_leading->SetFillColor(kBlue);
  pt_L1_noIso_leading->Draw("same");
  
  TLegend *leg2 = new TLegend(0.62,0.68,0.85,0.87);
  leg2->SetBorderSize(0);
  leg2->SetTextSize(0.03);
  leg2->SetFillColor(kWhite);
  leg2->SetHeader("#bf{L1 #tau no-iso}");
  leg2->AddEntry(pt_Offline_leading, "Leading #tau","f");
  leg2->AddEntry(pt_Offline_subleading, "Subleading #tau","f");
  leg2->Draw("same");

  texl->Draw("same");

  c1->SaveAs("ptdistribution_noiso.pdf","pdf"); 
*/ 
  return;  

}
