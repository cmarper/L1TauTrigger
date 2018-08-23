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

void EvaluateAcceptance(TString InputFileName = "Trees_modeparam/Tree_ForAcceptance_multipletaus_mode.root")
{
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

  Int_t           out_RunNumber = 0;
  ULong64_t       out_EventNumber = 0;
  Int_t           out_Lumi = 0;

  vector<float>   *out_OfflineTau_pt = 0;
  vector<float>   *out_OfflineTau_eta = 0;
  vector<float>   *out_OfflineTau_phi = 0;

  vector<float>   *out_L1Tau_pt = 0;
  vector<float>   *out_L1Tau_eta = 0;
  vector<float>   *out_L1Tau_phi = 0;
  vector<int>     *out_L1Tau_IEt = 0;
  vector<int>     *out_L1Tau_IEta = 0;
  vector<bool>    *out_L1Tau_isMerged = 0;
  vector<bool>    *out_L1Tau_hasEM = 0;
  vector<int>     *out_L1Tau_Iso = 0;
  vector<int>     *out_L1Tau_nTT = 0;
  vector<int>     *out_L1Tau_RawEt = 0;
  vector<bool>    *out_OfflineTau_isMatched = 0;

  vector<bool>    *out_L1Tau_passIso_Option1 = 0;
  vector<bool>    *out_L1Tau_passIso_Option2 = 0;
  vector<bool>    *out_L1Tau_passIso_Option3 = 0;
  vector<bool>    *out_L1Tau_passIso_Option4 = 0;
  vector<bool>    *out_L1Tau_passIso_Option5 = 0;
  vector<bool>    *out_L1Tau_passIso_Option6 = 0;
  vector<bool>    *out_L1Tau_passIso_Option7 = 0;
  vector<bool>    *out_L1Tau_passIso_Option8 = 0;
  vector<bool>    *out_L1Tau_passIso_Option9 = 0;
  vector<bool>    *out_L1Tau_passIso_Option10 = 0;
  vector<bool>    *out_L1Tau_passIso_Option11 = 0;
  vector<bool>    *out_L1Tau_passIso_Option12 = 0;
  vector<bool>    *out_L1Tau_passIso_Option13 = 0;
  vector<bool>    *out_L1Tau_passIso_Option14 = 0;
  vector<bool>    *out_L1Tau_passIso_Option15 = 0;
  vector<bool>    *out_L1Tau_passIso_Option16 = 0;
  vector<bool>    *out_L1Tau_passIso_Option17 = 0;
  vector<bool>    *out_L1Tau_passIso_Option18 = 0;
  vector<bool>    *out_L1Tau_passIso_Option19 = 0;
  vector<bool>    *out_L1Tau_passIso_Option20 = 0;
  vector<bool>    *out_L1Tau_passIso_Option21 = 0;
  vector<bool>    *out_L1Tau_passIso_Option22 = 0;
  
  TString OutputFileName = "Trees_modeparam/AcceptanceResults_mode.root";

  TFile f(OutputFileName.Data(),"RECREATE");
  TTree outTree("AcceptanceTree","AcceptanceTree");  
  
  outTree.Branch("EventNumber",&out_EventNumber);
  outTree.Branch("RunNumber",&out_RunNumber);
  outTree.Branch("Lumi",&out_Lumi);
  outTree.Branch("OfflineTau_pt",  &out_OfflineTau_pt);
  outTree.Branch("OfflineTau_eta", &out_OfflineTau_eta);
  outTree.Branch("OfflineTau_phi", &out_OfflineTau_phi);
  outTree.Branch("L1Tau_pt",  &out_L1Tau_pt);
  outTree.Branch("L1Tau_eta", &out_L1Tau_eta);
  outTree.Branch("L1Tau_phi", &out_L1Tau_phi);
  outTree.Branch("L1Tau_nTT", &out_L1Tau_nTT);
  outTree.Branch("L1Tau_hasEM", &out_L1Tau_hasEM);
  outTree.Branch("L1Tau_isMerged", &out_L1Tau_isMerged);
  outTree.Branch("L1Tau_IEta", &out_L1Tau_IEta);
  outTree.Branch("L1Tau_RawEt", &out_L1Tau_RawEt);
  outTree.Branch("L1Tau_Iso", &out_L1Tau_Iso);
  outTree.Branch("OfflineTau_isMatched", &out_OfflineTau_isMatched);//needs to be filled
  outTree.Branch("L1Tau_passIso_Option1", &out_L1Tau_passIso_Option1);
  outTree.Branch("L1Tau_passIso_Option2", &out_L1Tau_passIso_Option2);
  outTree.Branch("L1Tau_passIso_Option3", &out_L1Tau_passIso_Option3);
  outTree.Branch("L1Tau_passIso_Option4", &out_L1Tau_passIso_Option4);
  outTree.Branch("L1Tau_passIso_Option5", &out_L1Tau_passIso_Option5);
  outTree.Branch("L1Tau_passIso_Option6", &out_L1Tau_passIso_Option6);
  outTree.Branch("L1Tau_passIso_Option7", &out_L1Tau_passIso_Option7);
  outTree.Branch("L1Tau_passIso_Option8", &out_L1Tau_passIso_Option8);
  outTree.Branch("L1Tau_passIso_Option9", &out_L1Tau_passIso_Option9);
  outTree.Branch("L1Tau_passIso_Option10", &out_L1Tau_passIso_Option10);
  outTree.Branch("L1Tau_passIso_Option11", &out_L1Tau_passIso_Option11);
  outTree.Branch("L1Tau_passIso_Option12", &out_L1Tau_passIso_Option12);
  outTree.Branch("L1Tau_passIso_Option13", &out_L1Tau_passIso_Option13);
  outTree.Branch("L1Tau_passIso_Option14", &out_L1Tau_passIso_Option14);
  outTree.Branch("L1Tau_passIso_Option15", &out_L1Tau_passIso_Option15);
  outTree.Branch("L1Tau_passIso_Option16", &out_L1Tau_passIso_Option16);
  outTree.Branch("L1Tau_passIso_Option17", &out_L1Tau_passIso_Option17);
  outTree.Branch("L1Tau_passIso_Option18", &out_L1Tau_passIso_Option18);
  outTree.Branch("L1Tau_passIso_Option19", &out_L1Tau_passIso_Option19);
  outTree.Branch("L1Tau_passIso_Option20", &out_L1Tau_passIso_Option20);
  outTree.Branch("L1Tau_passIso_Option21", &out_L1Tau_passIso_Option21);
  outTree.Branch("L1Tau_passIso_Option22", &out_L1Tau_passIso_Option22);
  
  TH1F* all_offline = new TH1F("all_offline","all_offline",1,0,1);
  TH1F* pass_offline_L1_DoubleIsoTau30er = new TH1F("pass_offline_L1_DoubleIsoTau30er","pass_offline_L1_DoubleIsoTau30er",1,0,1);
  //TH1F* pass_offline_L1_DoubleIsoTau30er_Option22 = new TH1F("pass_offline_L1_DoubleIsoTau30er_Option22","pass_offline_L1_DoubleIsoTau30er_Option22",1,0,1);

  UInt_t CurrentEventNumber = 0;
  
  // loop events
  for(UInt_t i = 0 ; i < data.GetEntries() ; ++i)
    {
      data.GetEntry(i);
      // cout<<"EventNumber = "<<<<endl;
      if(EventNumber==CurrentEventNumber) continue;
      CurrentEventNumber = EventNumber;
      if(i%100000==0) cout<<"Entry #"<<i<<endl;

      Bool_t PassOffline = kFALSE;

      vector<TLorentzVector> tau_vector;
      tau_vector.clear();
      TLorentzVector Tau;

      //loop offline taus 
      for(UInt_t iTau = 0 ; iTau < OfflineTau_pt->size() ; ++iTau)
       {
	  //TLorentzVector Tau;
          Tau.SetPtEtaPhiM(OfflineTau_pt->at(iTau),OfflineTau_eta->at(iTau),OfflineTau_phi->at(iTau),0.);
	  if(Tau.Pt()<40.) continue;
	  tau_vector.push_back(Tau);
       }
      
       if(tau_vector.size()<2) continue;
       PassOffline = kTRUE;
      
       //cout<<"good offline event:"<<endl;
       //cout<<"    tau1Pt   = "<<tau_vector.at(0).Pt()<<endl;
       //cout<<"    tau2Pt   = "<<tau_vector.at(1).Pt()<<endl;
      
       all_offline->Fill(0.5);

       Bool_t PassL1 = kFALSE;
       Bool_t PassL1_Option22 = kFALSE;

       if(OfflineTau_isMatched==0) continue;

       //loop L1 taus
       TLorentzVector GoodL1Tau;
       GoodL1Tau.SetPtEtaPhiM(0,0,0,0);
       for(UInt_t iL1Tau = 0 ; iL1Tau < L1Tau_pt->size() ; ++iL1Tau)
	 { 
	   if(L1Tau_pt->at(iL1Tau)<0.5) continue;
	   if(fabs(L1Tau_eta->at(iL1Tau))>2.1) continue;
          // if(!L1Tau_passIso_Option22->at(iL1Tau)) continue; 
           
           TLorentzVector L1Tau;
	   L1Tau.SetPtEtaPhiM(L1Tau_pt->at(iL1Tau),L1Tau_eta->at(iL1Tau),L1Tau_phi->at(iL1Tau),0.);
	   if(L1Tau.Pt()<30) continue;
	   if(Tau.DeltaR(L1Tau)<0.5) continue;
           if(!L1Tau_passIso_Option22->at(iL1Tau)) continue;           
           GoodL1Tau = L1Tau; break;
	 }

       if(GoodL1Tau.Pt()<30.) continue;
       PassL1 = kTRUE;

       if(PassL1 && PassOffline) pass_offline_L1_DoubleIsoTau30er->Fill(0.5);   
    }

  all_offline->Write();
  pass_offline_L1_DoubleIsoTau30er->Write();
  
  float numerator = pass_offline_L1_DoubleIsoTau30er->GetEntries();
  float denominator = all_offline->GetEntries();
  cout << numerator << "/" << denominator << endl;
  float acceptance = numerator/denominator;
  cout << "Acceptance: " << acceptance*100 <<"%" << endl;
}
