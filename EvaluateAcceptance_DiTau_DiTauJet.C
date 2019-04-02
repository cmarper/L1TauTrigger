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
#include <TGaxis.h>

using namespace std;

void EvaluateAcceptance(TString process, double Threshold_XX, double Threshold_YY, double Threshold_ZZ, bool is0jet, bool is1jet, bool is2jet ){

  TString InputFileName;
  if (process=="ggF") InputFileName = "/data_CMS/cms/mperez/TauTrigger_data/TauTauJet/Ntuple_MC_MiniAOD_GluGluHToTauTau_181210_10_3_X_multipletaus.root";
  else if (process=="VBF") InputFileName = "/data_CMS/cms/mperez/TauTrigger_data/TauTauJet/Ntuple_MC_MiniAOD_VBFHToTauTau_261210_10_3_X_multipletaus.root";
  else if (process=="ttH") InputFileName = "/data_CMS/cms/mperez/TauTrigger_data/2018/MC/NTuple_MC_ttHnonbb_MiniAOD_RunIIAutumn18_2Apr19_multipletaus.root";

  TChain data("TagAndProbe");
  data.Add(InputFileName.Data());

  Int_t       RunNumber = 0;
  ULong64_t   EventNumber = 0;
  Int_t       lumi = 0;

  //offl
  vector<float>   *tauPt = 0;
  vector<float>   *tauEta = 0;
  vector<float>   *tauPhi = 0;

  vector<float>   *jets_px = 0;
  vector<float>   *jets_py = 0;
  vector<float>   *jets_pz = 0;
  vector<float>   *jets_e = 0;

  //online
  vector<float>   *l1tPt = 0;
  vector<float>   *l1tEta = 0;
  vector<float>   *l1tPhi = 0;
  vector<int>     *l1tIso = 0;

  vector<float>   *l1tPtJet = 0;
  vector<float>   *l1tEtaJet = 0;
  vector<float>   *l1tPhiJet = 0;

  TBranch   *b_RunNumber ;
  TBranch   *b_EventNumber ;
  TBranch   *b_lumi ;

  TBranch   *b_tauPt ;
  TBranch   *b_tauEta ;
  TBranch   *b_tauPhi ;

  TBranch   *b_jets_px ;
  TBranch   *b_jets_py ;
  TBranch   *b_jets_pz ;
  TBranch   *b_jets_e ;

  TBranch   *b_l1tPt ;
  TBranch   *b_l1tEta ;
  TBranch   *b_l1tPhi ;
  TBranch   *b_l1tIso ;

  TBranch   *b_l1tPtJet ;
  TBranch   *b_l1tEtaJet ;
  TBranch   *b_l1tPhiJet ;

  TBranch   *b_isMatched ;
  
  data.SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
  data.SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
  data.SetBranchAddress("lumi", &lumi, &b_lumi);

  data.SetBranchAddress("tauPt", &tauPt, &b_tauPt);
  data.SetBranchAddress("tauEta", &tauEta, &b_tauEta);
  data.SetBranchAddress("tauPhi", &tauPhi, &b_tauPhi);

  data.SetBranchAddress("jets_px", &jets_px, &b_jets_px);
  data.SetBranchAddress("jets_py", &jets_py, &b_jets_py);
  data.SetBranchAddress("jets_pz", &jets_pz, &b_jets_pz);
  data.SetBranchAddress("jets_e", &jets_e, &b_jets_e);

  data.SetBranchAddress("l1tPt", &l1tPt, &b_l1tPt);
  data.SetBranchAddress("l1tEta", &l1tEta, &b_l1tEta);
  data.SetBranchAddress("l1tPhi", &l1tPhi, &b_l1tPhi);
  data.SetBranchAddress("l1tIso", &l1tIso, &b_l1tIso);
 
  data.SetBranchAddress("l1tPtJet", &l1tPtJet, &b_l1tPtJet);
  data.SetBranchAddress("l1tEtaJet", &l1tEtaJet, &b_l1tEtaJet);
  data.SetBranchAddress("l1tPhiJet", &l1tPhiJet, &b_l1tPhiJet);

 
  double n_Pass_Offl_DiTau32_0jet = 0.;
  double n_Pass_Offl_DiTau32_1jet = 0.;
  double n_Pass_Offl_DiTau32_2jet = 0.;

  double n_Pass_Offl_DiTauXX_0jet = 0.;
  double n_Pass_Offl_DiTauXX_1jet = 0.;
  double n_Pass_Offl_DiTauXX_2jet = 0.;

  double n_Pass_Offl_DiTauYYJetZZ_1jet = 0.;
  double n_Pass_Offl_DiTauYYJetZZ_2jet = 0.;

  double n_Pass_L1_DiTau32 = 0.;
  double n_Pass_L1_DiTauXX = 0.;
  double n_Pass_L1_DiTauYYJetZZ = 0.;

  double numerator_0jet = 0;
  double numerator_1jet = 0;
  double numerator_2jet = 0;

  double denominator_0jet = 0.;
  double denominator_1jet = 0.;
  double denominator_2jet = 0.;

  double accept_gain_0jet = 0;
  double accept_gain_1jet = 0.;
  double accept_gain_2jet = 0.;

  // cout<<"entries "<<data.GetEntries()<<endl;
  // loop events
  for(UInt_t i = 0 ; i < data.GetEntries() ; ++i){

    data.GetEntry(i);
    //if(i%100000==0) 
    //  cout<<"Entry #"<<i<<endl;

    ///////////////////////////////////////////////
    ////////////////  OFFLINE  ////////////////////
    ///////////////////////////////////////////////

    double Pass_Offl_DiTau32_0jet = false;
    double Pass_Offl_DiTau32_1jet = false;
    double Pass_Offl_DiTau32_2jet = false;

    double Pass_Offl_DiTauXX_0jet = false;
    double Pass_Offl_DiTauXX_1jet = false;
    double Pass_Offl_DiTauXX_2jet = false;

    double Pass_Offl_DiTauYYJetZZ_1jet = false;
    double Pass_Offl_DiTauYYJetZZ_2jet = false;

    double Cuts_Offl_DiTau32_0jet = false;
    double Cuts_Offl_DiTau32_1jet = false;
    double Cuts_Offl_DiTau32_2jet = false;

    double Cuts_Offl_DiTauXX_0jet = false;
    double Cuts_Offl_DiTauXX_1jet = false;
    double Cuts_Offl_DiTauXX_2jet = false;
    
    double Cuts_Offl_DiTauYYJetZZ_1jet = false;
    double Cuts_Offl_DiTauYYJetZZ_2jet = false;

    vector<TLorentzVector> offl_tau_vector;
    offl_tau_vector.clear();
    TLorentzVector OfflTau;
    Int_t n_offl_taus = tauPt->size();
 
    for(Int_t iTau = 0 ; iTau < n_offl_taus ; ++iTau){
      OfflTau.SetPtEtaPhiM(tauPt->at(iTau),tauEta->at(iTau),tauPhi->at(iTau),0.);
      offl_tau_vector.push_back(OfflTau);
    }

    vector<TLorentzVector> offl_jet_vector;
    offl_jet_vector.clear();
    TLorentzVector OfflJet;
    Int_t n_offl_jets = jets_px->size();

    for(Int_t iJet = 0 ; iJet < n_offl_jets ; ++iJet){
      OfflJet.SetPxPyPzE(jets_px->at(iJet),jets_py->at(iJet),jets_pz->at(iJet),jets_e->at(iJet));
      offl_jet_vector.push_back(OfflJet);
    }
    
    vector<TLorentzVector> offl_jet_vector_dR;
    offl_jet_vector_dR.clear();

    //look for jets that are dR>0.5 from tau1 and tau2   
    vector<int> index_offl_jet_tau1;
    vector<int> index_offl_jet_tau2;

    if (n_offl_taus>1 && n_offl_jets>0){
      for(Int_t iJet = 0 ; iJet < n_offl_jets ; ++iJet){
        if(offl_tau_vector.at(0).DeltaR(offl_jet_vector.at(iJet))>0.5) {
          index_offl_jet_tau1.push_back(iJet);
        }
        if(offl_tau_vector.at(1).DeltaR(offl_jet_vector.at(iJet))>0.5) {
          index_offl_jet_tau2.push_back(iJet);
        }
      }
    }

    //look for jets that are dR>0.5 from both taus simultaneously
    int index_offl_jet_taus = -999;  

    if (index_offl_jet_tau1.size()>0 && index_offl_jet_tau2.size()>0) {
      for (UInt_t i = 0; i<index_offl_jet_tau1.size(); ++i){
        for (UInt_t j = 0; j<index_offl_jet_tau2.size(); ++j){    
          if (index_offl_jet_tau1.at(i) == index_offl_jet_tau2.at(j)){
            index_offl_jet_taus = index_offl_jet_tau1.at(i);
            offl_jet_vector_dR.push_back(offl_jet_vector.at(index_offl_jet_tau1.at(i))); 
          } 
        }
      }      
    }
  

    //Cuts DiTau32
    Cuts_Offl_DiTau32_0jet = n_offl_taus>=2
          && offl_tau_vector.at(0).Pt()>=50 && offl_tau_vector.at(1).Pt()>=40
          && offl_tau_vector.at(0).Eta()<=2.1 && offl_tau_vector.at(1).Eta()<=2.1;

    Cuts_Offl_DiTau32_1jet = n_offl_taus>=2 && offl_jet_vector_dR.size()>=1
          && offl_tau_vector.at(0).Pt()>=50 && offl_tau_vector.at(1).Pt()>=40
          && offl_jet_vector_dR.at(0).Pt()>=30
          && offl_tau_vector.at(0).Eta()<=2.1 && offl_tau_vector.at(1).Eta()<=2.1;

    Cuts_Offl_DiTau32_2jet = n_offl_taus>=2 && offl_jet_vector_dR.size()>=2
          && offl_tau_vector.at(0).Pt()>=50 && offl_tau_vector.at(1).Pt()>=40
          && offl_jet_vector_dR.at(0).Pt()>=30 && offl_jet_vector_dR.at(0).Pt()>=30 && offl_jet_vector_dR.at(1).Pt()>=30
          && offl_tau_vector.at(0).Eta()<=2.1 && offl_tau_vector.at(1).Eta()<=2.1;

    //Cuts DiTauXX
    Cuts_Offl_DiTauXX_0jet = n_offl_taus>=2
           && offl_tau_vector.at(0).Pt()>=Threshold_XX+18 && offl_tau_vector.at(1).Pt()>=Threshold_XX+8
           && offl_tau_vector.at(0).Eta()<=2.1 && offl_tau_vector.at(1).Eta()<=2.1;

    Cuts_Offl_DiTauXX_1jet = n_offl_taus>=2 && offl_jet_vector_dR.size()>=1
           && offl_tau_vector.at(0).Pt()>=Threshold_XX+18 && offl_tau_vector.at(1).Pt()>=Threshold_XX+8
           && offl_jet_vector_dR.at(0).Pt()>=30
           && offl_tau_vector.at(0).Eta()<=2.1 && offl_tau_vector.at(1).Eta()<=2.1;

    Cuts_Offl_DiTauXX_2jet = n_offl_taus>=2 && offl_jet_vector_dR.size()>=2
           && offl_tau_vector.at(0).Pt()>=Threshold_XX+18 && offl_tau_vector.at(1).Pt()>=Threshold_XX+8
           && offl_jet_vector_dR.at(0).Pt()>=30 && offl_jet_vector_dR.at(1).Pt()>=30
           && offl_tau_vector.at(0).Eta()<=2.1 && offl_tau_vector.at(1).Eta()<=2.1;

    //Cuts DiTauYYJetZZ
    Cuts_Offl_DiTauYYJetZZ_1jet = n_offl_taus>=2 && offl_jet_vector_dR.size()>=1
           && offl_tau_vector.at(0).Pt()>=Threshold_YY+18 && offl_tau_vector.at(1).Pt()>=Threshold_YY+8
           && offl_jet_vector_dR.at(0).Pt()>=Threshold_ZZ+10
           && offl_tau_vector.at(0).Eta()<=2.1 && offl_tau_vector.at(1).Eta()<=2.1;

    Cuts_Offl_DiTauYYJetZZ_2jet = n_offl_taus>=2 && offl_jet_vector_dR.size()>=2
           && offl_tau_vector.at(0).Pt()>=Threshold_YY+18 && offl_tau_vector.at(1).Pt()>=Threshold_YY+8
           && offl_jet_vector_dR.at(0).Pt()>=30 && offl_jet_vector_dR.at(0).Pt()>=30
           && (offl_jet_vector_dR.at(0).Pt()>=Threshold_ZZ+10 || offl_jet_vector_dR.at(1).Pt()>=Threshold_ZZ+10)
           && offl_tau_vector.at(0).Eta()<=2.1 && offl_tau_vector.at(1).Eta()<=2.1;

    
    if (Cuts_Offl_DiTau32_0jet) {
      Pass_Offl_DiTau32_0jet = true;
      n_Pass_Offl_DiTau32_0jet++;
    }

    if (Cuts_Offl_DiTau32_1jet) {
      Pass_Offl_DiTau32_1jet = true;
      n_Pass_Offl_DiTau32_1jet++;
    }

    if (Cuts_Offl_DiTau32_2jet) {
      Pass_Offl_DiTau32_2jet = true;
      n_Pass_Offl_DiTau32_2jet++;
    }

    if (Cuts_Offl_DiTauXX_0jet) {
      Pass_Offl_DiTauXX_0jet = true;
      n_Pass_Offl_DiTauXX_0jet++;
    }

    if (Cuts_Offl_DiTauXX_1jet) {
      Pass_Offl_DiTauXX_1jet = true;
      n_Pass_Offl_DiTauXX_1jet++;
    }

    if (Cuts_Offl_DiTauXX_2jet) {
      Pass_Offl_DiTauXX_2jet = true;
      n_Pass_Offl_DiTauXX_2jet++;
    }

    if (Cuts_Offl_DiTauYYJetZZ_1jet) {
      Pass_Offl_DiTauYYJetZZ_1jet = true;
      n_Pass_Offl_DiTauYYJetZZ_1jet++;
    }

    if (Cuts_Offl_DiTauYYJetZZ_2jet) {
      Pass_Offl_DiTauYYJetZZ_2jet = true;
      n_Pass_Offl_DiTauYYJetZZ_2jet++;
    }


    ///////////////////////////////////////////////
    ////////////////  ONLINE  /////////////////////
    ///////////////////////////////////////////////

    bool Pass_L1_DiTauXX = false;
    bool Pass_L1_DiTauYYJetZZ = false;
    bool Pass_L1_DiTau32 = false;

    bool Cuts_L1_DiTauXX = false;
    bool Cuts_L1_DiTauYYJetZZ = false;
    bool Cuts_L1_DiTau32 = false;

    vector<TLorentzVector> L1_tau_vector;
    L1_tau_vector.clear();
    TLorentzVector L1Tau;

    vector<TLorentzVector> good_L1_tau_vector;
    good_L1_tau_vector.clear();
    TLorentzVector GoodL1Tau;

    Int_t n_L1_taus = l1tPt->size();
    Int_t n_good_L1_taus = 0;
   
    // all L1 taus
    for(Int_t iTau = 0 ; iTau < n_L1_taus ; ++iTau){
      L1Tau.SetPtEtaPhiM(l1tPt->at(iTau),l1tEta->at(iTau),l1tPhi->at(iTau),0.);
      L1_tau_vector.push_back(L1Tau);
      
      // good L1 taus
      for(Int_t iOffTau = 0 ; iOffTau < n_offl_taus ; ++iOffTau){
        if (l1tPt->at(iTau)>0.5 && (offl_tau_vector.at(iOffTau)).DeltaR(L1Tau)<0.5 && l1tIso->at(iTau)){
          n_good_L1_taus++;
          GoodL1Tau = L1Tau;
          good_L1_tau_vector.push_back(GoodL1Tau);
        }
      }
    }

   
    vector<TLorentzVector> L1_jet_vector;
    L1_jet_vector.clear();
    TLorentzVector L1Jet;

    vector<TLorentzVector> good_L1_jet_vector;
    good_L1_jet_vector.clear();
    TLorentzVector GoodL1Jet;

    Int_t n_L1_jets = l1tPtJet->size();
    Int_t n_good_L1_jets = 0;
   
    // all L1 jets
    for(Int_t iJet = 0 ; iJet < n_L1_jets ; ++iJet){
      L1Jet.SetPtEtaPhiM(l1tPtJet->at(iJet),l1tEtaJet->at(iJet),l1tPhiJet->at(iJet),0.);
      L1_jet_vector.push_back(L1Jet);
      
      // good L1 jets
      for(Int_t iOffJet = 0 ; iOffJet < n_offl_jets ; ++iOffJet){
        if (l1tPtJet->at(iJet)>0.5 && (offl_jet_vector.at(iOffJet)).DeltaR(L1Jet)<0.5){
          n_good_L1_jets++;
          GoodL1Jet = L1Jet;
          good_L1_jet_vector.push_back(GoodL1Jet);
        }
      }
    }


    vector<TLorentzVector> good_L1_jet_vector_dR;
    good_L1_jet_vector_dR.clear();

    //look for jets that are dR>0.5 from tau1 and tau2   
    vector<int> index_good_L1_jet_tau1;
    vector<int> index_good_L1_jet_tau2;

    if (n_good_L1_taus>1 && n_good_L1_jets>0){
      for(Int_t iJet = 0 ; iJet < n_good_L1_jets ; ++iJet){
        if(good_L1_tau_vector.at(0).DeltaR(good_L1_jet_vector.at(iJet))>0.5) {
          index_good_L1_jet_tau1.push_back(iJet);
        }
        if(good_L1_tau_vector.at(1).DeltaR(good_L1_jet_vector.at(iJet))>0.5) {
          index_good_L1_jet_tau2.push_back(iJet);
        }
      }
    }

    //look for jets that are dR>0.5 from both taus simultaneously
    int index_good_L1_jet_taus = -999;  

    if (index_good_L1_jet_tau1.size()>0 && index_good_L1_jet_tau2.size()>0) {
      for (UInt_t i = 0; i<index_good_L1_jet_tau1.size(); ++i){
        for (UInt_t j = 0; j<index_good_L1_jet_tau2.size(); ++j){    
          if (index_good_L1_jet_tau1.at(i) == index_good_L1_jet_tau2.at(j)){
            index_good_L1_jet_taus = index_good_L1_jet_tau1.at(i);
            good_L1_jet_vector_dR.push_back(good_L1_jet_vector.at(index_good_L1_jet_tau1.at(i))); 
          } 
        }
      }      
    }


    Cuts_L1_DiTauXX = n_good_L1_taus>=2
          && good_L1_tau_vector.at(0).Pt()>=Threshold_XX && good_L1_tau_vector.at(1).Pt()>=Threshold_XX
          && good_L1_tau_vector.at(0).Eta()<=2.1 && good_L1_tau_vector.at(1).Eta()<=2.1;

    Cuts_L1_DiTauYYJetZZ = n_good_L1_taus>=2 && good_L1_jet_vector_dR.size()>=1
           && good_L1_tau_vector.at(0).Pt()>=Threshold_YY && good_L1_tau_vector.at(1).Pt()>=Threshold_YY 
           && good_L1_jet_vector.at(0).Pt()>=Threshold_ZZ
           && good_L1_tau_vector.at(0).Eta()<=2.1 && good_L1_tau_vector.at(1).Eta()<=2.1;

    Cuts_L1_DiTau32 = n_good_L1_taus>=2
          && good_L1_tau_vector.at(0).Pt()>=32 && good_L1_tau_vector.at(1).Pt()>=32
          && good_L1_tau_vector.at(0).Eta()<=2.1 && good_L1_tau_vector.at(1).Eta()<=2.1;

    if (Cuts_L1_DiTauXX) {
      Pass_L1_DiTauXX = true;
      n_Pass_L1_DiTauXX++;
    }

    if (Cuts_L1_DiTauYYJetZZ) {
      Pass_L1_DiTauYYJetZZ = true;
      n_Pass_L1_DiTauYYJetZZ++;
    }

    if (Cuts_L1_DiTau32) {
      Pass_L1_DiTau32 = true;
      n_Pass_L1_DiTau32++;
    }

    //////////////////////////////////////////////////
    ////////////////  ACCEPTANCE  ////////////////////
    //////////////////////////////////////////////////

    // numerator 0-jet category
    if ( Cuts_L1_DiTauXX && Pass_Offl_DiTauXX_0jet ) {
      numerator_0jet++;
    }

    // numerator 1-jet category
    if ( (Cuts_L1_DiTauXX && Pass_Offl_DiTauXX_1jet) || (Cuts_L1_DiTauYYJetZZ && Pass_Offl_DiTauYYJetZZ_1jet) ) {
      numerator_1jet++;
    }

    // numerator 2-jet category
    if ( (Cuts_L1_DiTauXX && Pass_Offl_DiTauXX_2jet) || (Cuts_L1_DiTauYYJetZZ && Pass_Offl_DiTauYYJetZZ_2jet) ) {
      numerator_2jet++;
    }

    // denominator 0-jet category
    if ( Cuts_L1_DiTau32 && Cuts_Offl_DiTau32_0jet ) {
      denominator_0jet++;
    }

    // denominator 1-jet category
    if ( Cuts_L1_DiTau32 && Cuts_Offl_DiTau32_1jet ) {
      denominator_1jet++;
    }

    // denominator 2-jet category
    if ( Cuts_L1_DiTau32 && Cuts_Offl_DiTau32_2jet ) {
      denominator_2jet++;
    }
    
  }

  accept_gain_0jet = numerator_0jet/denominator_0jet;
  accept_gain_1jet = numerator_1jet/denominator_1jet;
  accept_gain_2jet = numerator_2jet/denominator_2jet;

  if (is0jet) cout<<"h_XX_YY_AccGain->Fill("<<Threshold_XX<<","<<Threshold_YY<<","<<100*(accept_gain_0jet-1)<<");"<<endl;
  if (is1jet) cout<<"h_XX_YY_AccGain->Fill("<<Threshold_XX<<","<<Threshold_YY<<","<<100*(accept_gain_1jet-1)<<");"<<endl;
  if (is2jet) cout<<"h_XX_YY_AccGain->Fill("<<Threshold_XX<<","<<Threshold_YY<<","<<100*(accept_gain_2jet-1)<<");"<<endl;

}

/*void get_acceptance_0jet_VBF(){

  cout<<"VBF, 0 jet category"<<endl;
  EvaluateAcceptance(true,32,20,164,true,false,false);
  EvaluateAcceptance(true,32,21,164,true,false,false);
  EvaluateAcceptance(true,32,22,164,true,false,false);
  EvaluateAcceptance(true,32,23,150,true,false,false);
  EvaluateAcceptance(true,32,24,134,true,false,false);
  EvaluateAcceptance(true,32,25,126,true,false,false);
  EvaluateAcceptance(true,32,26,118,true,false,false);
  EvaluateAcceptance(true,32,27,118,true,false,false);
  EvaluateAcceptance(true,32,28,118,true,false,false);
  EvaluateAcceptance(true,32,29,100,true,false,false);
  EvaluateAcceptance(true,32,30,92,true,false,false);
  EvaluateAcceptance(true,32,31,52,true,false,false);
  EvaluateAcceptance(true,32,32,20,true,false,false);
  EvaluateAcceptance(true,32,33,20,true,false,false);
  EvaluateAcceptance(true,32,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,33,20,124,true,false,false);
  EvaluateAcceptance(true,33,21,124,true,false,false);
  EvaluateAcceptance(true,33,22,120,true,false,false);
  EvaluateAcceptance(true,33,23,118,true,false,false);
  EvaluateAcceptance(true,33,24,104,true,false,false);
  EvaluateAcceptance(true,33,25,96,true,false,false);
  EvaluateAcceptance(true,33,26,76,true,false,false);
  EvaluateAcceptance(true,33,27,72,true,false,false);
  EvaluateAcceptance(true,33,28,60,true,false,false);
  EvaluateAcceptance(true,33,29,50,true,false,false);
  EvaluateAcceptance(true,33,30,40,true,false,false);
  EvaluateAcceptance(true,33,31,34,true,false,false);
  EvaluateAcceptance(true,33,32,20,true,false,false);
  EvaluateAcceptance(true,33,33,20,true,false,false);
  EvaluateAcceptance(true,33,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,34,20,118,true,false,false);
  EvaluateAcceptance(true,34,21,114,true,false,false);
  EvaluateAcceptance(true,34,22,112,true,false,false);
  EvaluateAcceptance(true,34,23,108,true,false,false);
  EvaluateAcceptance(true,34,24,96,true,false,false);
  EvaluateAcceptance(true,34,25,86,true,false,false);
  EvaluateAcceptance(true,34,26,64,true,false,false);
  EvaluateAcceptance(true,34,27,60,true,false,false);
  EvaluateAcceptance(true,34,28,52,true,false,false);
  EvaluateAcceptance(true,34,29,44,true,false,false);
  EvaluateAcceptance(true,34,30,36,true,false,false);
  EvaluateAcceptance(true,34,31,30,true,false,false);
  EvaluateAcceptance(true,34,32,20,true,false,false);
  EvaluateAcceptance(true,34,33,20,true,false,false);
  EvaluateAcceptance(true,34,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,35,20,110,true,false,false);
  EvaluateAcceptance(true,35,21,108,true,false,false);
  EvaluateAcceptance(true,35,22,104,true,false,false);
  EvaluateAcceptance(true,35,23,100,true,false,false);
  EvaluateAcceptance(true,35,24,90,true,false,false);
  EvaluateAcceptance(true,35,25,76,true,false,false);
  EvaluateAcceptance(true,35,26,58,true,false,false);
  EvaluateAcceptance(true,35,27,52,true,false,false);
  EvaluateAcceptance(true,35,28,46,true,false,false);
  EvaluateAcceptance(true,35,29,38,true,false,false);
  EvaluateAcceptance(true,35,30,32,true,false,false);
  EvaluateAcceptance(true,35,31,28,true,false,false);
  EvaluateAcceptance(true,35,32,20,true,false,false);
  EvaluateAcceptance(true,35,33,20,true,false,false);
  EvaluateAcceptance(true,35,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,36,20,106,true,false,false);
  EvaluateAcceptance(true,36,21,106,true,false,false);
  EvaluateAcceptance(true,36,22,102,true,false,false);
  EvaluateAcceptance(true,36,23,96,true,false,false);
  EvaluateAcceptance(true,36,24,90,true,false,false);
  EvaluateAcceptance(true,36,25,76,true,false,false);
  EvaluateAcceptance(true,36,26,56,true,false,false);
  EvaluateAcceptance(true,36,27,50,true,false,false);
  EvaluateAcceptance(true,36,28,44,true,false,false);
  EvaluateAcceptance(true,36,29,38,true,false,false);
  EvaluateAcceptance(true,36,30,32,true,false,false);
  EvaluateAcceptance(true,36,31,28,true,false,false);
  EvaluateAcceptance(true,36,32,20,true,false,false);
  EvaluateAcceptance(true,36,33,20,true,false,false);
  EvaluateAcceptance(true,36,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,37,20,106,true,false,false);
  EvaluateAcceptance(true,37,21,104,true,false,false);
  EvaluateAcceptance(true,37,22,100,true,false,false);
  EvaluateAcceptance(true,37,23,96,true,false,false);
  EvaluateAcceptance(true,37,24,88,true,false,false);
  EvaluateAcceptance(true,37,25,74,true,false,false);
  EvaluateAcceptance(true,37,26,54,true,false,false);
  EvaluateAcceptance(true,37,27,48,true,false,false);
  EvaluateAcceptance(true,37,28,44,true,false,false);
  EvaluateAcceptance(true,37,29,36,true,false,false);
  EvaluateAcceptance(true,37,30,32,true,false,false);
  EvaluateAcceptance(true,37,31,26,true,false,false);
  EvaluateAcceptance(true,37,32,20,true,false,false);
  EvaluateAcceptance(true,37,33,20,true,false,false);
  EvaluateAcceptance(true,37,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,38,20,104,true,false,false);
  EvaluateAcceptance(true,38,21,100,true,false,false);
  EvaluateAcceptance(true,38,22,96,true,false,false);
  EvaluateAcceptance(true,38,23,92,true,false,false);
  EvaluateAcceptance(true,38,24,84,true,false,false);
  EvaluateAcceptance(true,38,25,70,true,false,false);
  EvaluateAcceptance(true,38,26,52,true,false,false);
  EvaluateAcceptance(true,38,27,46,true,false,false);
  EvaluateAcceptance(true,38,28,42,true,false,false);
  EvaluateAcceptance(true,38,29,34,true,false,false);
  EvaluateAcceptance(true,38,30,30,true,false,false);
  EvaluateAcceptance(true,38,31,26,true,false,false);
  EvaluateAcceptance(true,38,32,20,true,false,false);
  EvaluateAcceptance(true,38,33,20,true,false,false);
  EvaluateAcceptance(true,38,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,39,20,100,true,false,false);
  EvaluateAcceptance(true,39,21,96,true,false,false);
  EvaluateAcceptance(true,39,22,94,true,false,false);
  EvaluateAcceptance(true,39,23,90,true,false,false);
  EvaluateAcceptance(true,39,24,84,true,false,false);
  EvaluateAcceptance(true,39,25,68,true,false,false);
  EvaluateAcceptance(true,39,26,52,true,false,false);
  EvaluateAcceptance(true,39,27,44,true,false,false);
  EvaluateAcceptance(true,39,28,40,true,false,false);
  EvaluateAcceptance(true,39,29,34,true,false,false);
  EvaluateAcceptance(true,39,30,30,true,false,false);
  EvaluateAcceptance(true,39,31,26,true,false,false);
  EvaluateAcceptance(true,39,32,20,true,false,false);
  EvaluateAcceptance(true,39,33,20,true,false,false);
  EvaluateAcceptance(true,39,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,40,20,98,true,false,false);
  EvaluateAcceptance(true,40,21,96,true,false,false);
  EvaluateAcceptance(true,40,22,92,true,false,false);
  EvaluateAcceptance(true,40,23,90,true,false,false);
  EvaluateAcceptance(true,40,24,82,true,false,false);
  EvaluateAcceptance(true,40,25,64,true,false,false);
  EvaluateAcceptance(true,40,26,50,true,false,false);
  EvaluateAcceptance(true,40,27,44,true,false,false);
  EvaluateAcceptance(true,40,28,38,true,false,false);
  EvaluateAcceptance(true,40,29,34,true,false,false);
  EvaluateAcceptance(true,40,30,30,true,false,false);
  EvaluateAcceptance(true,40,31,26,true,false,false);
  EvaluateAcceptance(true,40,32,20,true,false,false);
  EvaluateAcceptance(true,40,33,20,true,false,false);
  EvaluateAcceptance(true,40,34,20,true,false,false);
  cout<<" "<<endl;
}

void get_acceptance_0jet_ggF(){

  cout<<"ggF, 0 jet category"<<endl;
  EvaluateAcceptance(false,32,20,164,true,false,false);
  EvaluateAcceptance(false,32,21,164,true,false,false);
  EvaluateAcceptance(false,32,22,164,true,false,false);
  EvaluateAcceptance(false,32,23,150,true,false,false);
  EvaluateAcceptance(false,32,24,134,true,false,false);
  EvaluateAcceptance(false,32,25,126,true,false,false);
  EvaluateAcceptance(false,32,26,118,true,false,false);
  EvaluateAcceptance(false,32,27,118,true,false,false);
  EvaluateAcceptance(false,32,28,118,true,false,false);
  EvaluateAcceptance(false,32,29,100,true,false,false);
  EvaluateAcceptance(false,32,30,92,true,false,false);
  EvaluateAcceptance(false,32,31,52,true,false,false);
  EvaluateAcceptance(false,32,32,20,true,false,false);
  EvaluateAcceptance(false,32,33,20,true,false,false);
  EvaluateAcceptance(false,32,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance(false,33,20,124,true,false,false);
  EvaluateAcceptance(false,33,21,124,true,false,false);
  EvaluateAcceptance(false,33,22,120,true,false,false);
  EvaluateAcceptance(false,33,23,118,true,false,false);
  EvaluateAcceptance(false,33,24,104,true,false,false);
  EvaluateAcceptance(false,33,25,96,true,false,false);
  EvaluateAcceptance(false,33,26,76,true,false,false);
  EvaluateAcceptance(false,33,27,72,true,false,false);
  EvaluateAcceptance(false,33,28,60,true,false,false);
  EvaluateAcceptance(false,33,29,50,true,false,false);
  EvaluateAcceptance(false,33,30,40,true,false,false);
  EvaluateAcceptance(false,33,31,34,true,false,false);
  EvaluateAcceptance(false,33,32,20,true,false,false);
  EvaluateAcceptance(false,33,33,20,true,false,false);
  EvaluateAcceptance(false,33,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance(false,34,20,118,true,false,false);
  EvaluateAcceptance(false,34,21,114,true,false,false);
  EvaluateAcceptance(false,34,22,112,true,false,false);
  EvaluateAcceptance(false,34,23,108,true,false,false);
  EvaluateAcceptance(false,34,24,96,true,false,false);
  EvaluateAcceptance(false,34,25,86,true,false,false);
  EvaluateAcceptance(false,34,26,64,true,false,false);
  EvaluateAcceptance(false,34,27,60,true,false,false);
  EvaluateAcceptance(false,34,28,52,true,false,false);
  EvaluateAcceptance(false,34,29,44,true,false,false);
  EvaluateAcceptance(false,34,30,36,true,false,false);
  EvaluateAcceptance(false,34,31,30,true,false,false);
  EvaluateAcceptance(false,34,32,20,true,false,false);
  EvaluateAcceptance(false,34,33,20,true,false,false);
  EvaluateAcceptance(false,34,34,20,true,false,false);
  cout<<" "<<endl; 
  EvaluateAcceptance(false,35,20,110,true,false,false);
  EvaluateAcceptance(false,35,21,108,true,false,false);
  EvaluateAcceptance(false,35,22,104,true,false,false);
  EvaluateAcceptance(false,35,23,100,true,false,false);
  EvaluateAcceptance(false,35,24,90,true,false,false);
  EvaluateAcceptance(false,35,25,76,true,false,false);
  EvaluateAcceptance(false,35,26,58,true,false,false);
  EvaluateAcceptance(false,35,27,52,true,false,false);
  EvaluateAcceptance(false,35,28,46,true,false,false);
  EvaluateAcceptance(false,35,29,38,true,false,false);
  EvaluateAcceptance(false,35,30,32,true,false,false);
  EvaluateAcceptance(false,35,31,28,true,false,false);
  EvaluateAcceptance(false,35,32,20,true,false,false);
  EvaluateAcceptance(false,35,33,20,true,false,false);
  EvaluateAcceptance(false,35,34,20,true,false,false);
  cout<<" "<<endl;  
  EvaluateAcceptance(false,36,20,106,true,false,false);
  EvaluateAcceptance(false,36,21,106,true,false,false);
  EvaluateAcceptance(false,36,22,102,true,false,false);
  EvaluateAcceptance(false,36,23,96,true,false,false);
  EvaluateAcceptance(false,36,24,90,true,false,false);
  EvaluateAcceptance(false,36,25,76,true,false,false);
  EvaluateAcceptance(false,36,26,56,true,false,false);
  EvaluateAcceptance(false,36,27,50,true,false,false);
  EvaluateAcceptance(false,36,28,44,true,false,false);
  EvaluateAcceptance(false,36,29,38,true,false,false);
  EvaluateAcceptance(false,36,30,32,true,false,false);
  EvaluateAcceptance(false,36,31,28,true,false,false);
  EvaluateAcceptance(false,36,32,20,true,false,false);
  EvaluateAcceptance(false,36,33,20,true,false,false);
  EvaluateAcceptance(false,36,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance(false,37,20,106,true,false,false);
  EvaluateAcceptance(false,37,21,104,true,false,false);
  EvaluateAcceptance(false,37,22,100,true,false,false);
  EvaluateAcceptance(false,37,23,96,true,false,false);
  EvaluateAcceptance(false,37,24,88,true,false,false);
  EvaluateAcceptance(false,37,25,74,true,false,false);
  EvaluateAcceptance(false,37,26,54,true,false,false);
  EvaluateAcceptance(false,37,27,48,true,false,false);
  EvaluateAcceptance(false,37,28,44,true,false,false);
  EvaluateAcceptance(false,37,29,36,true,false,false);
  EvaluateAcceptance(false,37,30,32,true,false,false);
  EvaluateAcceptance(false,37,31,26,true,false,false);
  EvaluateAcceptance(false,37,32,20,true,false,false);
  EvaluateAcceptance(false,37,33,20,true,false,false);
  EvaluateAcceptance(false,37,34,20,true,false,false);
  cout<<" "<<endl;  
  EvaluateAcceptance(false,38,20,104,true,false,false);
  EvaluateAcceptance(false,38,21,100,true,false,false);
  EvaluateAcceptance(false,38,22,96,true,false,false);
  EvaluateAcceptance(false,38,23,92,true,false,false);
  EvaluateAcceptance(false,38,24,84,true,false,false);
  EvaluateAcceptance(false,38,25,70,true,false,false);
  EvaluateAcceptance(false,38,26,52,true,false,false);
  EvaluateAcceptance(false,38,27,46,true,false,false);
  EvaluateAcceptance(false,38,28,42,true,false,false);
  EvaluateAcceptance(false,38,29,34,true,false,false);
  EvaluateAcceptance(false,38,30,30,true,false,false);
  EvaluateAcceptance(false,38,31,26,true,false,false);
  EvaluateAcceptance(false,38,32,20,true,false,false);
  EvaluateAcceptance(false,38,33,20,true,false,false);
  EvaluateAcceptance(false,38,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance(false,39,20,100,true,false,false);
  EvaluateAcceptance(false,39,21,96,true,false,false);
  EvaluateAcceptance(false,39,22,94,true,false,false);
  EvaluateAcceptance(false,39,23,90,true,false,false);
  EvaluateAcceptance(false,39,24,84,true,false,false);
  EvaluateAcceptance(false,39,25,68,true,false,false);
  EvaluateAcceptance(false,39,26,52,true,false,false);
  EvaluateAcceptance(false,39,27,44,true,false,false);
  EvaluateAcceptance(false,39,28,40,true,false,false);
  EvaluateAcceptance(false,39,29,34,true,false,false);
  EvaluateAcceptance(false,39,30,30,true,false,false);
  EvaluateAcceptance(false,39,31,26,true,false,false);
  EvaluateAcceptance(false,39,32,20,true,false,false);
  EvaluateAcceptance(false,39,33,20,true,false,false);
  EvaluateAcceptance(false,39,34,20,true,false,false);
  cout<<" "<<endl;  
  EvaluateAcceptance(false,40,20,98,true,false,false);
  EvaluateAcceptance(false,40,21,96,true,false,false);
  EvaluateAcceptance(false,40,22,92,true,false,false);
  EvaluateAcceptance(false,40,23,90,true,false,false);
  EvaluateAcceptance(false,40,24,82,true,false,false);
  EvaluateAcceptance(false,40,25,64,true,false,false);
  EvaluateAcceptance(false,40,26,50,true,false,false);
  EvaluateAcceptance(false,40,27,44,true,false,false);
  EvaluateAcceptance(false,40,28,38,true,false,false);
  EvaluateAcceptance(false,40,29,34,true,false,false);
  EvaluateAcceptance(false,40,30,30,true,false,false);
  EvaluateAcceptance(false,40,31,26,true,false,false);
  EvaluateAcceptance(false,40,32,20,true,false,false);
  EvaluateAcceptance(false,40,33,20,true,false,false);
  EvaluateAcceptance(false,40,34,20,true,false,false);
}

void get_acceptance_1jet_VBF(){

  cout<<"VBF, 1 jet category"<<endl;
  EvaluateAcceptance(true,32,20,164,false,true,false);
  EvaluateAcceptance(true,32,21,164,false,true,false);
  EvaluateAcceptance(true,32,22,164,false,true,false);
  EvaluateAcceptance(true,32,23,150,false,true,false);
  EvaluateAcceptance(true,32,24,134,false,true,false);
  EvaluateAcceptance(true,32,25,126,false,true,false);
  EvaluateAcceptance(true,32,26,118,false,true,false);
  EvaluateAcceptance(true,32,27,118,false,true,false);
  EvaluateAcceptance(true,32,28,118,false,true,false);
  EvaluateAcceptance(true,32,29,100,false,true,false);
  EvaluateAcceptance(true,32,30,92,false,true,false);
  EvaluateAcceptance(true,32,31,52,false,true,false);
  EvaluateAcceptance(true,32,32,20,false,true,false);
  EvaluateAcceptance(true,32,33,20,false,true,false);
  EvaluateAcceptance(true,32,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,33,20,124,false,true,false);
  EvaluateAcceptance(true,33,21,124,false,true,false);
  EvaluateAcceptance(true,33,22,120,false,true,false);
  EvaluateAcceptance(true,33,23,118,false,true,false);
  EvaluateAcceptance(true,33,24,104,false,true,false);
  EvaluateAcceptance(true,33,25,96,false,true,false);
  EvaluateAcceptance(true,33,26,76,false,true,false);
  EvaluateAcceptance(true,33,27,72,false,true,false);
  EvaluateAcceptance(true,33,28,60,false,true,false);
  EvaluateAcceptance(true,33,29,50,false,true,false);
  EvaluateAcceptance(true,33,30,40,false,true,false);
  EvaluateAcceptance(true,33,31,34,false,true,false);
  EvaluateAcceptance(true,33,32,20,false,true,false);
  EvaluateAcceptance(true,33,33,20,false,true,false);
  EvaluateAcceptance(true,33,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,34,20,118,false,true,false);
  EvaluateAcceptance(true,34,21,114,false,true,false);
  EvaluateAcceptance(true,34,22,112,false,true,false);
  EvaluateAcceptance(true,34,23,108,false,true,false);
  EvaluateAcceptance(true,34,24,96,false,true,false);
  EvaluateAcceptance(true,34,25,86,false,true,false);
  EvaluateAcceptance(true,34,26,64,false,true,false);
  EvaluateAcceptance(true,34,27,60,false,true,false);
  EvaluateAcceptance(true,34,28,52,false,true,false);
  EvaluateAcceptance(true,34,29,44,false,true,false);
  EvaluateAcceptance(true,34,30,36,false,true,false);
  EvaluateAcceptance(true,34,31,30,false,true,false);
  EvaluateAcceptance(true,34,32,20,false,true,false);
  EvaluateAcceptance(true,34,33,20,false,true,false);
  EvaluateAcceptance(true,34,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,35,20,110,false,true,false);
  EvaluateAcceptance(true,35,21,108,false,true,false);
  EvaluateAcceptance(true,35,22,104,false,true,false);
  EvaluateAcceptance(true,35,23,100,false,true,false);
  EvaluateAcceptance(true,35,24,90,false,true,false);
  EvaluateAcceptance(true,35,25,76,false,true,false);
  EvaluateAcceptance(true,35,26,58,false,true,false);
  EvaluateAcceptance(true,35,27,52,false,true,false);
  EvaluateAcceptance(true,35,28,46,false,true,false);
  EvaluateAcceptance(true,35,29,38,false,true,false);
  EvaluateAcceptance(true,35,30,32,false,true,false);
  EvaluateAcceptance(true,35,31,28,false,true,false);
  EvaluateAcceptance(true,35,32,20,false,true,false);
  EvaluateAcceptance(true,35,33,20,false,true,false);
  EvaluateAcceptance(true,35,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,36,20,106,false,true,false);
  EvaluateAcceptance(true,36,21,106,false,true,false);
  EvaluateAcceptance(true,36,22,102,false,true,false);
  EvaluateAcceptance(true,36,23,96,false,true,false);
  EvaluateAcceptance(true,36,24,90,false,true,false);
  EvaluateAcceptance(true,36,25,76,false,true,false);
  EvaluateAcceptance(true,36,26,56,false,true,false);
  EvaluateAcceptance(true,36,27,50,false,true,false);
  EvaluateAcceptance(true,36,28,44,false,true,false);
  EvaluateAcceptance(true,36,29,38,false,true,false);
  EvaluateAcceptance(true,36,30,32,false,true,false);
  EvaluateAcceptance(true,36,31,28,false,true,false);
  EvaluateAcceptance(true,36,32,20,false,true,false);
  EvaluateAcceptance(true,36,33,20,false,true,false);
  EvaluateAcceptance(true,36,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,37,20,106,false,true,false);
  EvaluateAcceptance(true,37,21,104,false,true,false);
  EvaluateAcceptance(true,37,22,100,false,true,false);
  EvaluateAcceptance(true,37,23,96,false,true,false);
  EvaluateAcceptance(true,37,24,88,false,true,false);
  EvaluateAcceptance(true,37,25,74,false,true,false);
  EvaluateAcceptance(true,37,26,54,false,true,false);
  EvaluateAcceptance(true,37,27,48,false,true,false);
  EvaluateAcceptance(true,37,28,44,false,true,false);
  EvaluateAcceptance(true,37,29,36,false,true,false);
  EvaluateAcceptance(true,37,30,32,false,true,false);
  EvaluateAcceptance(true,37,31,26,false,true,false);
  EvaluateAcceptance(true,37,32,20,false,true,false);
  EvaluateAcceptance(true,37,33,20,false,true,false);
  EvaluateAcceptance(true,37,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,38,20,104,false,true,false);
  EvaluateAcceptance(true,38,21,100,false,true,false);
  EvaluateAcceptance(true,38,22,96,false,true,false);
  EvaluateAcceptance(true,38,23,92,false,true,false);
  EvaluateAcceptance(true,38,24,84,false,true,false);
  EvaluateAcceptance(true,38,25,70,false,true,false);
  EvaluateAcceptance(true,38,26,52,false,true,false);
  EvaluateAcceptance(true,38,27,46,false,true,false);
  EvaluateAcceptance(true,38,28,42,false,true,false);
  EvaluateAcceptance(true,38,29,34,false,true,false);
  EvaluateAcceptance(true,38,30,30,false,true,false);
  EvaluateAcceptance(true,38,31,26,false,true,false);
  EvaluateAcceptance(true,38,32,20,false,true,false);
  EvaluateAcceptance(true,38,33,20,false,true,false);
  EvaluateAcceptance(true,38,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,39,20,100,false,true,false);
  EvaluateAcceptance(true,39,21,96,false,true,false);
  EvaluateAcceptance(true,39,22,94,false,true,false);
  EvaluateAcceptance(true,39,23,90,false,true,false);
  EvaluateAcceptance(true,39,24,84,false,true,false);
  EvaluateAcceptance(true,39,25,68,false,true,false);
  EvaluateAcceptance(true,39,26,52,false,true,false);
  EvaluateAcceptance(true,39,27,44,false,true,false);
  EvaluateAcceptance(true,39,28,40,false,true,false);
  EvaluateAcceptance(true,39,29,34,false,true,false);
  EvaluateAcceptance(true,39,30,30,false,true,false);
  EvaluateAcceptance(true,39,31,26,false,true,false);
  EvaluateAcceptance(true,39,32,20,false,true,false);
  EvaluateAcceptance(true,39,33,20,false,true,false);
  EvaluateAcceptance(true,39,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance(true,40,20,98,false,true,false);
  EvaluateAcceptance(true,40,21,96,false,true,false);
  EvaluateAcceptance(true,40,22,92,false,true,false);
  EvaluateAcceptance(true,40,23,90,false,true,false);
  EvaluateAcceptance(true,40,24,82,false,true,false);
  EvaluateAcceptance(true,40,25,64,false,true,false);
  EvaluateAcceptance(true,40,26,50,false,true,false);
  EvaluateAcceptance(true,40,27,44,false,true,false);
  EvaluateAcceptance(true,40,28,38,false,true,false);
  EvaluateAcceptance(true,40,29,34,false,true,false);
  EvaluateAcceptance(true,40,30,30,false,true,false);
  EvaluateAcceptance(true,40,31,26,false,true,false);
  EvaluateAcceptance(true,40,32,20,false,true,false);
  EvaluateAcceptance(true,40,33,20,false,true,false);
  EvaluateAcceptance(true,40,34,20,false,true,false);
  cout<<" "<<endl;

}

void get_acceptance_1jet_ggF(){

  cout<<"ggF, 1 jet category"<<endl;
  EvaluateAcceptance(false,32,20,164,false,true,false);
  EvaluateAcceptance(false,32,21,164,false,true,false);
  EvaluateAcceptance(false,32,22,164,false,true,false);
  EvaluateAcceptance(false,32,23,150,false,true,false);
  EvaluateAcceptance(false,32,24,134,false,true,false);
  EvaluateAcceptance(false,32,25,126,false,true,false);
  EvaluateAcceptance(false,32,26,118,false,true,false);
  EvaluateAcceptance(false,32,27,118,false,true,false);
  EvaluateAcceptance(false,32,28,118,false,true,false);
  EvaluateAcceptance(false,32,29,100,false,true,false);
  EvaluateAcceptance(false,32,30,92,false,true,false);
  EvaluateAcceptance(false,32,31,52,false,true,false);
  EvaluateAcceptance(false,32,32,20,false,true,false);
  EvaluateAcceptance(false,32,33,20,false,true,false);
  EvaluateAcceptance(false,32,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance(false,33,20,124,false,true,false);
  EvaluateAcceptance(false,33,21,124,false,true,false);
  EvaluateAcceptance(false,33,22,120,false,true,false);
  EvaluateAcceptance(false,33,23,118,false,true,false);
  EvaluateAcceptance(false,33,24,104,false,true,false);
  EvaluateAcceptance(false,33,25,96,false,true,false);
  EvaluateAcceptance(false,33,26,76,false,true,false);
  EvaluateAcceptance(false,33,27,72,false,true,false);
  EvaluateAcceptance(false,33,28,60,false,true,false);
  EvaluateAcceptance(false,33,29,50,false,true,false);
  EvaluateAcceptance(false,33,30,40,false,true,false);
  EvaluateAcceptance(false,33,31,34,false,true,false);
  EvaluateAcceptance(false,33,32,20,false,true,false);
  EvaluateAcceptance(false,33,33,20,false,true,false);
  EvaluateAcceptance(false,33,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance(false,34,20,118,false,true,false);
  EvaluateAcceptance(false,34,21,114,false,true,false);
  EvaluateAcceptance(false,34,22,112,false,true,false);
  EvaluateAcceptance(false,34,23,108,false,true,false);
  EvaluateAcceptance(false,34,24,96,false,true,false);
  EvaluateAcceptance(false,34,25,86,false,true,false);
  EvaluateAcceptance(false,34,26,64,false,true,false);
  EvaluateAcceptance(false,34,27,60,false,true,false);
  EvaluateAcceptance(false,34,28,52,false,true,false);
  EvaluateAcceptance(false,34,29,44,false,true,false);
  EvaluateAcceptance(false,34,30,36,false,true,false);
  EvaluateAcceptance(false,34,31,30,false,true,false);
  EvaluateAcceptance(false,34,32,20,false,true,false);
  EvaluateAcceptance(false,34,33,20,false,true,false);
  EvaluateAcceptance(false,34,34,20,false,true,false);
  cout<<" "<<endl; 
  EvaluateAcceptance(false,35,20,110,false,true,false);
  EvaluateAcceptance(false,35,21,108,false,true,false);
  EvaluateAcceptance(false,35,22,104,false,true,false);
  EvaluateAcceptance(false,35,23,100,false,true,false);
  EvaluateAcceptance(false,35,24,90,false,true,false);
  EvaluateAcceptance(false,35,25,76,false,true,false);
  EvaluateAcceptance(false,35,26,58,false,true,false);
  EvaluateAcceptance(false,35,27,52,false,true,false);
  EvaluateAcceptance(false,35,28,46,false,true,false);
  EvaluateAcceptance(false,35,29,38,false,true,false);
  EvaluateAcceptance(false,35,30,32,false,true,false);
  EvaluateAcceptance(false,35,31,28,false,true,false);
  EvaluateAcceptance(false,35,32,20,false,true,false);
  EvaluateAcceptance(false,35,33,20,false,true,false);
  EvaluateAcceptance(false,35,34,20,false,true,false);
  cout<<" "<<endl;  
  EvaluateAcceptance(false,36,20,106,false,true,false);
  EvaluateAcceptance(false,36,21,106,false,true,false);
  EvaluateAcceptance(false,36,22,102,false,true,false);
  EvaluateAcceptance(false,36,23,96,false,true,false);
  EvaluateAcceptance(false,36,24,90,false,true,false);
  EvaluateAcceptance(false,36,25,76,false,true,false);
  EvaluateAcceptance(false,36,26,56,false,true,false);
  EvaluateAcceptance(false,36,27,50,false,true,false);
  EvaluateAcceptance(false,36,28,44,false,true,false);
  EvaluateAcceptance(false,36,29,38,false,true,false);
  EvaluateAcceptance(false,36,30,32,false,true,false);
  EvaluateAcceptance(false,36,31,28,false,true,false);
  EvaluateAcceptance(false,36,32,20,false,true,false);
  EvaluateAcceptance(false,36,33,20,false,true,false);
  EvaluateAcceptance(false,36,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance(false,37,20,106,false,true,false);
  EvaluateAcceptance(false,37,21,104,false,true,false);
  EvaluateAcceptance(false,37,22,100,false,true,false);
  EvaluateAcceptance(false,37,23,96,false,true,false);
  EvaluateAcceptance(false,37,24,88,false,true,false);
  EvaluateAcceptance(false,37,25,74,false,true,false);
  EvaluateAcceptance(false,37,26,54,false,true,false);
  EvaluateAcceptance(false,37,27,48,false,true,false);
  EvaluateAcceptance(false,37,28,44,false,true,false);
  EvaluateAcceptance(false,37,29,36,false,true,false);
  EvaluateAcceptance(false,37,30,32,false,true,false);
  EvaluateAcceptance(false,37,31,26,false,true,false);
  EvaluateAcceptance(false,37,32,20,false,true,false);
  EvaluateAcceptance(false,37,33,20,false,true,false);
  EvaluateAcceptance(false,37,34,20,false,true,false);
  cout<<" "<<endl;  
  EvaluateAcceptance(false,38,20,104,false,true,false);
  EvaluateAcceptance(false,38,21,100,false,true,false);
  EvaluateAcceptance(false,38,22,96,false,true,false);
  EvaluateAcceptance(false,38,23,92,false,true,false);
  EvaluateAcceptance(false,38,24,84,false,true,false);
  EvaluateAcceptance(false,38,25,70,false,true,false);
  EvaluateAcceptance(false,38,26,52,false,true,false);
  EvaluateAcceptance(false,38,27,46,false,true,false);
  EvaluateAcceptance(false,38,28,42,false,true,false);
  EvaluateAcceptance(false,38,29,34,false,true,false);
  EvaluateAcceptance(false,38,30,30,false,true,false);
  EvaluateAcceptance(false,38,31,26,false,true,false);
  EvaluateAcceptance(false,38,32,20,false,true,false);
  EvaluateAcceptance(false,38,33,20,false,true,false);
  EvaluateAcceptance(false,38,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance(false,39,20,100,false,true,false);
  EvaluateAcceptance(false,39,21,96,false,true,false);
  EvaluateAcceptance(false,39,22,94,false,true,false);
  EvaluateAcceptance(false,39,23,90,false,true,false);
  EvaluateAcceptance(false,39,24,84,false,true,false);
  EvaluateAcceptance(false,39,25,68,false,true,false);
  EvaluateAcceptance(false,39,26,52,false,true,false);
  EvaluateAcceptance(false,39,27,44,false,true,false);
  EvaluateAcceptance(false,39,28,40,false,true,false);
  EvaluateAcceptance(false,39,29,34,false,true,false);
  EvaluateAcceptance(false,39,30,30,false,true,false);
  EvaluateAcceptance(false,39,31,26,false,true,false);
  EvaluateAcceptance(false,39,32,20,false,true,false);
  EvaluateAcceptance(false,39,33,20,false,true,false);
  EvaluateAcceptance(false,39,34,20,false,true,false);
  cout<<" "<<endl;  
  EvaluateAcceptance(false,40,20,98,false,true,false);
  EvaluateAcceptance(false,40,21,96,false,true,false);
  EvaluateAcceptance(false,40,22,92,false,true,false);
  EvaluateAcceptance(false,40,23,90,false,true,false);
  EvaluateAcceptance(false,40,24,82,false,true,false);
  EvaluateAcceptance(false,40,25,64,false,true,false);
  EvaluateAcceptance(false,40,26,50,false,true,false);
  EvaluateAcceptance(false,40,27,44,false,true,false);
  EvaluateAcceptance(false,40,28,38,false,true,false);
  EvaluateAcceptance(false,40,29,34,false,true,false);
  EvaluateAcceptance(false,40,30,30,false,true,false);
  EvaluateAcceptance(false,40,31,26,false,true,false);
  EvaluateAcceptance(false,40,32,20,false,true,false);
  EvaluateAcceptance(false,40,33,20,false,true,false);
  EvaluateAcceptance(false,40,34,20,false,true,false);
}

void get_acceptance_2jet_VBF(){

  cout<<"VBF, 2 jet category"<<endl;
  EvaluateAcceptance(true,32,20,164,false,false,true);
  EvaluateAcceptance(true,32,21,164,false,false,true);
  EvaluateAcceptance(true,32,22,164,false,false,true);
  EvaluateAcceptance(true,32,23,150,false,false,true);
  EvaluateAcceptance(true,32,24,134,false,false,true);
  EvaluateAcceptance(true,32,25,126,false,false,true);
  EvaluateAcceptance(true,32,26,118,false,false,true);
  EvaluateAcceptance(true,32,27,118,false,false,true);
  EvaluateAcceptance(true,32,28,118,false,false,true);
  EvaluateAcceptance(true,32,29,100,false,false,true);
  EvaluateAcceptance(true,32,30,92,false,false,true);
  EvaluateAcceptance(true,32,31,52,false,false,true);
  EvaluateAcceptance(true,32,32,20,false,false,true);
  EvaluateAcceptance(true,32,33,20,false,false,true);
  EvaluateAcceptance(true,32,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance(true,33,20,124,false,false,true);
  EvaluateAcceptance(true,33,21,124,false,false,true);
  EvaluateAcceptance(true,33,22,120,false,false,true);
  EvaluateAcceptance(true,33,23,118,false,false,true);
  EvaluateAcceptance(true,33,24,104,false,false,true);
  EvaluateAcceptance(true,33,25,96,false,false,true);
  EvaluateAcceptance(true,33,26,76,false,false,true);
  EvaluateAcceptance(true,33,27,72,false,false,true);
  EvaluateAcceptance(true,33,28,60,false,false,true);
  EvaluateAcceptance(true,33,29,50,false,false,true);
  EvaluateAcceptance(true,33,30,40,false,false,true);
  EvaluateAcceptance(true,33,31,34,false,false,true);
  EvaluateAcceptance(true,33,32,20,false,false,true);
  EvaluateAcceptance(true,33,33,20,false,false,true);
  EvaluateAcceptance(true,33,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance(true,34,20,118,false,false,true);
  EvaluateAcceptance(true,34,21,114,false,false,true);
  EvaluateAcceptance(true,34,22,112,false,false,true);
  EvaluateAcceptance(true,34,23,108,false,false,true);
  EvaluateAcceptance(true,34,24,96,false,false,true);
  EvaluateAcceptance(true,34,25,86,false,false,true);
  EvaluateAcceptance(true,34,26,64,false,false,true);
  EvaluateAcceptance(true,34,27,60,false,false,true);
  EvaluateAcceptance(true,34,28,52,false,false,true);
  EvaluateAcceptance(true,34,29,44,false,false,true);
  EvaluateAcceptance(true,34,30,36,false,false,true);
  EvaluateAcceptance(true,34,31,30,false,false,true);
  EvaluateAcceptance(true,34,32,20,false,false,true);
  EvaluateAcceptance(true,34,33,20,false,false,true);
  EvaluateAcceptance(true,34,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance(true,35,20,110,false,false,true);
  EvaluateAcceptance(true,35,21,108,false,false,true);
  EvaluateAcceptance(true,35,22,104,false,false,true);
  EvaluateAcceptance(true,35,23,100,false,false,true);
  EvaluateAcceptance(true,35,24,90,false,false,true);
  EvaluateAcceptance(true,35,25,76,false,false,true);
  EvaluateAcceptance(true,35,26,58,false,false,true);
  EvaluateAcceptance(true,35,27,52,false,false,true);
  EvaluateAcceptance(true,35,28,46,false,false,true);
  EvaluateAcceptance(true,35,29,38,false,false,true);
  EvaluateAcceptance(true,35,30,32,false,false,true);
  EvaluateAcceptance(true,35,31,28,false,false,true);
  EvaluateAcceptance(true,35,32,20,false,false,true);
  EvaluateAcceptance(true,35,33,20,false,false,true);
  EvaluateAcceptance(true,35,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance(true,36,20,106,false,false,true);
  EvaluateAcceptance(true,36,21,106,false,false,true);
  EvaluateAcceptance(true,36,22,102,false,false,true);
  EvaluateAcceptance(true,36,23,96,false,false,true);
  EvaluateAcceptance(true,36,24,90,false,false,true);
  EvaluateAcceptance(true,36,25,76,false,false,true);
  EvaluateAcceptance(true,36,26,56,false,false,true);
  EvaluateAcceptance(true,36,27,50,false,false,true);
  EvaluateAcceptance(true,36,28,44,false,false,true);
  EvaluateAcceptance(true,36,29,38,false,false,true);
  EvaluateAcceptance(true,36,30,32,false,false,true);
  EvaluateAcceptance(true,36,31,28,false,false,true);
  EvaluateAcceptance(true,36,32,20,false,false,true);
  EvaluateAcceptance(true,36,33,20,false,false,true);
  EvaluateAcceptance(true,36,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance(true,37,20,106,false,false,true);
  EvaluateAcceptance(true,37,21,104,false,false,true);
  EvaluateAcceptance(true,37,22,100,false,false,true);
  EvaluateAcceptance(true,37,23,96,false,false,true);
  EvaluateAcceptance(true,37,24,88,false,false,true);
  EvaluateAcceptance(true,37,25,74,false,false,true);
  EvaluateAcceptance(true,37,26,54,false,false,true);
  EvaluateAcceptance(true,37,27,48,false,false,true);
  EvaluateAcceptance(true,37,28,44,false,false,true);
  EvaluateAcceptance(true,37,29,36,false,false,true);
  EvaluateAcceptance(true,37,30,32,false,false,true);
  EvaluateAcceptance(true,37,31,26,false,false,true);
  EvaluateAcceptance(true,37,32,20,false,false,true);
  EvaluateAcceptance(true,37,33,20,false,false,true);
  EvaluateAcceptance(true,37,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance(true,38,20,104,false,false,true);
  EvaluateAcceptance(true,38,21,100,false,false,true);
  EvaluateAcceptance(true,38,22,96,false,false,true);
  EvaluateAcceptance(true,38,23,92,false,false,true);
  EvaluateAcceptance(true,38,24,84,false,false,true);
  EvaluateAcceptance(true,38,25,70,false,false,true);
  EvaluateAcceptance(true,38,26,52,false,false,true);
  EvaluateAcceptance(true,38,27,46,false,false,true);
  EvaluateAcceptance(true,38,28,42,false,false,true);
  EvaluateAcceptance(true,38,29,34,false,false,true);
  EvaluateAcceptance(true,38,30,30,false,false,true);
  EvaluateAcceptance(true,38,31,26,false,false,true);
  EvaluateAcceptance(true,38,32,20,false,false,true);
  EvaluateAcceptance(true,38,33,20,false,false,true);
  EvaluateAcceptance(true,38,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance(true,39,20,100,false,false,true);
  EvaluateAcceptance(true,39,21,96,false,false,true);
  EvaluateAcceptance(true,39,22,94,false,false,true);
  EvaluateAcceptance(true,39,23,90,false,false,true);
  EvaluateAcceptance(true,39,24,84,false,false,true);
  EvaluateAcceptance(true,39,25,68,false,false,true);
  EvaluateAcceptance(true,39,26,52,false,false,true);
  EvaluateAcceptance(true,39,27,44,false,false,true);
  EvaluateAcceptance(true,39,28,40,false,false,true);
  EvaluateAcceptance(true,39,29,34,false,false,true);
  EvaluateAcceptance(true,39,30,30,false,false,true);
  EvaluateAcceptance(true,39,31,26,false,false,true);
  EvaluateAcceptance(true,39,32,20,false,false,true);
  EvaluateAcceptance(true,39,33,20,false,false,true);
  EvaluateAcceptance(true,39,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance(true,40,20,98,false,false,true);
  EvaluateAcceptance(true,40,21,96,false,false,true);
  EvaluateAcceptance(true,40,22,92,false,false,true);
  EvaluateAcceptance(true,40,23,90,false,false,true);
  EvaluateAcceptance(true,40,24,82,false,false,true);
  EvaluateAcceptance(true,40,25,64,false,false,true);
  EvaluateAcceptance(true,40,26,50,false,false,true);
  EvaluateAcceptance(true,40,27,44,false,false,true);
  EvaluateAcceptance(true,40,28,38,false,false,true);
  EvaluateAcceptance(true,40,29,34,false,false,true);
  EvaluateAcceptance(true,40,30,30,false,false,true);
  EvaluateAcceptance(true,40,31,26,false,false,true);
  EvaluateAcceptance(true,40,32,20,false,false,true);
  EvaluateAcceptance(true,40,33,20,false,false,true);
  EvaluateAcceptance(true,40,34,20,false,false,true);
  cout<<" "<<endl;

}

void get_acceptance_2jet_ggF(){

  cout<<"ggF, 2 jet category"<<endl;
  EvaluateAcceptance(false,32,20,164,false,false,true);
  EvaluateAcceptance(false,32,21,164,false,false,true);
  EvaluateAcceptance(false,32,22,164,false,false,true);
  EvaluateAcceptance(false,32,23,150,false,false,true);
  EvaluateAcceptance(false,32,24,134,false,false,true);
  EvaluateAcceptance(false,32,25,126,false,false,true);
  EvaluateAcceptance(false,32,26,118,false,false,true);
  EvaluateAcceptance(false,32,27,118,false,false,true);
  EvaluateAcceptance(false,32,28,118,false,false,true);
  EvaluateAcceptance(false,32,29,100,false,false,true);
  EvaluateAcceptance(false,32,30,92,false,false,true);
  EvaluateAcceptance(false,32,31,52,false,false,true);
  EvaluateAcceptance(false,32,32,20,false,false,true);
  EvaluateAcceptance(false,32,33,20,false,false,true);
  EvaluateAcceptance(false,32,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance(false,33,20,124,false,false,true);
  EvaluateAcceptance(false,33,21,124,false,false,true);
  EvaluateAcceptance(false,33,22,120,false,false,true);
  EvaluateAcceptance(false,33,23,118,false,false,true);
  EvaluateAcceptance(false,33,24,104,false,false,true);
  EvaluateAcceptance(false,33,25,96,false,false,true);
  EvaluateAcceptance(false,33,26,76,false,false,true);
  EvaluateAcceptance(false,33,27,72,false,false,true);
  EvaluateAcceptance(false,33,28,60,false,false,true);
  EvaluateAcceptance(false,33,29,50,false,false,true);
  EvaluateAcceptance(false,33,30,40,false,false,true);
  EvaluateAcceptance(false,33,31,34,false,false,true);
  EvaluateAcceptance(false,33,32,20,false,false,true);
  EvaluateAcceptance(false,33,33,20,false,false,true);
  EvaluateAcceptance(false,33,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance(false,34,20,118,false,false,true);
  EvaluateAcceptance(false,34,21,114,false,false,true);
  EvaluateAcceptance(false,34,22,112,false,false,true);
  EvaluateAcceptance(false,34,23,108,false,false,true);
  EvaluateAcceptance(false,34,24,96,false,false,true);
  EvaluateAcceptance(false,34,25,86,false,false,true);
  EvaluateAcceptance(false,34,26,64,false,false,true);
  EvaluateAcceptance(false,34,27,60,false,false,true);
  EvaluateAcceptance(false,34,28,52,false,false,true);
  EvaluateAcceptance(false,34,29,44,false,false,true);
  EvaluateAcceptance(false,34,30,36,false,false,true);
  EvaluateAcceptance(false,34,31,30,false,false,true);
  EvaluateAcceptance(false,34,32,20,false,false,true);
  EvaluateAcceptance(false,34,33,20,false,false,true);
  EvaluateAcceptance(false,34,34,20,false,false,true);
  cout<<" "<<endl; 
  EvaluateAcceptance(false,35,20,110,false,false,true);
  EvaluateAcceptance(false,35,21,108,false,false,true);
  EvaluateAcceptance(false,35,22,104,false,false,true);
  EvaluateAcceptance(false,35,23,100,false,false,true);
  EvaluateAcceptance(false,35,24,90,false,false,true);
  EvaluateAcceptance(false,35,25,76,false,false,true);
  EvaluateAcceptance(false,35,26,58,false,false,true);
  EvaluateAcceptance(false,35,27,52,false,false,true);
  EvaluateAcceptance(false,35,28,46,false,false,true);
  EvaluateAcceptance(false,35,29,38,false,false,true);
  EvaluateAcceptance(false,35,30,32,false,false,true);
  EvaluateAcceptance(false,35,31,28,false,false,true);
  EvaluateAcceptance(false,35,32,20,false,false,true);
  EvaluateAcceptance(false,35,33,20,false,false,true);
  EvaluateAcceptance(false,35,34,20,false,false,true);
  cout<<" "<<endl;  
  EvaluateAcceptance(false,36,20,106,false,false,true);
  EvaluateAcceptance(false,36,21,106,false,false,true);
  EvaluateAcceptance(false,36,22,102,false,false,true);
  EvaluateAcceptance(false,36,23,96,false,false,true);
  EvaluateAcceptance(false,36,24,90,false,false,true);
  EvaluateAcceptance(false,36,25,76,false,false,true);
  EvaluateAcceptance(false,36,26,56,false,false,true);
  EvaluateAcceptance(false,36,27,50,false,false,true);
  EvaluateAcceptance(false,36,28,44,false,false,true);
  EvaluateAcceptance(false,36,29,38,false,false,true);
  EvaluateAcceptance(false,36,30,32,false,false,true);
  EvaluateAcceptance(false,36,31,28,false,false,true);
  EvaluateAcceptance(false,36,32,20,false,false,true);
  EvaluateAcceptance(false,36,33,20,false,false,true);
  EvaluateAcceptance(false,36,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance(false,37,20,106,false,false,true);
  EvaluateAcceptance(false,37,21,104,false,false,true);
  EvaluateAcceptance(false,37,22,100,false,false,true);
  EvaluateAcceptance(false,37,23,96,false,false,true);
  EvaluateAcceptance(false,37,24,88,false,false,true);
  EvaluateAcceptance(false,37,25,74,false,false,true);
  EvaluateAcceptance(false,37,26,54,false,false,true);
  EvaluateAcceptance(false,37,27,48,false,false,true);
  EvaluateAcceptance(false,37,28,44,false,false,true);
  EvaluateAcceptance(false,37,29,36,false,false,true);
  EvaluateAcceptance(false,37,30,32,false,false,true);
  EvaluateAcceptance(false,37,31,26,false,false,true);
  EvaluateAcceptance(false,37,32,20,false,false,true);
  EvaluateAcceptance(false,37,33,20,false,false,true);
  EvaluateAcceptance(false,37,34,20,false,false,true);
  cout<<" "<<endl;  
  EvaluateAcceptance(false,38,20,104,false,false,true);
  EvaluateAcceptance(false,38,21,100,false,false,true);
  EvaluateAcceptance(false,38,22,96,false,false,true);
  EvaluateAcceptance(false,38,23,92,false,false,true);
  EvaluateAcceptance(false,38,24,84,false,false,true);
  EvaluateAcceptance(false,38,25,70,false,false,true);
  EvaluateAcceptance(false,38,26,52,false,false,true);
  EvaluateAcceptance(false,38,27,46,false,false,true);
  EvaluateAcceptance(false,38,28,42,false,false,true);
  EvaluateAcceptance(false,38,29,34,false,false,true);
  EvaluateAcceptance(false,38,30,30,false,false,true);
  EvaluateAcceptance(false,38,31,26,false,false,true);
  EvaluateAcceptance(false,38,32,20,false,false,true);
  EvaluateAcceptance(false,38,33,20,false,false,true);
  EvaluateAcceptance(false,38,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance(false,39,20,100,false,false,true);
  EvaluateAcceptance(false,39,21,96,false,false,true);
  EvaluateAcceptance(false,39,22,94,false,false,true);
  EvaluateAcceptance(false,39,23,90,false,false,true);
  EvaluateAcceptance(false,39,24,84,false,false,true);
  EvaluateAcceptance(false,39,25,68,false,false,true);
  EvaluateAcceptance(false,39,26,52,false,false,true);
  EvaluateAcceptance(false,39,27,44,false,false,true);
  EvaluateAcceptance(false,39,28,40,false,false,true);
  EvaluateAcceptance(false,39,29,34,false,false,true);
  EvaluateAcceptance(false,39,30,30,false,false,true);
  EvaluateAcceptance(false,39,31,26,false,false,true);
  EvaluateAcceptance(false,39,32,20,false,false,true);
  EvaluateAcceptance(false,39,33,20,false,false,true);
  EvaluateAcceptance(false,39,34,20,false,false,true);
  cout<<" "<<endl;  
  EvaluateAcceptance(false,40,20,98,false,false,true);
  EvaluateAcceptance(false,40,21,96,false,false,true);
  EvaluateAcceptance(false,40,22,92,false,false,true);
  EvaluateAcceptance(false,40,23,90,false,false,true);
  EvaluateAcceptance(false,40,24,82,false,false,true);
  EvaluateAcceptance(false,40,25,64,false,false,true);
  EvaluateAcceptance(false,40,26,50,false,false,true);
  EvaluateAcceptance(false,40,27,44,false,false,true);
  EvaluateAcceptance(false,40,28,38,false,false,true);
  EvaluateAcceptance(false,40,29,34,false,false,true);
  EvaluateAcceptance(false,40,30,30,false,false,true);
  EvaluateAcceptance(false,40,31,26,false,false,true);
  EvaluateAcceptance(false,40,32,20,false,false,true);
  EvaluateAcceptance(false,40,33,20,false,false,true);
  EvaluateAcceptance(false,40,34,20,false,false,true);
}*/


void get_acceptance_0jet_ttH(){

  cout<<"ttH, 0 jet category"<<endl;
  EvaluateAcceptance("ttH",32,20,164,true,false,false);
  EvaluateAcceptance("ttH",32,21,164,true,false,false);
  EvaluateAcceptance("ttH",32,22,164,true,false,false);
  EvaluateAcceptance("ttH",32,23,150,true,false,false);
  EvaluateAcceptance("ttH",32,24,134,true,false,false);
  EvaluateAcceptance("ttH",32,25,126,true,false,false);
  EvaluateAcceptance("ttH",32,26,118,true,false,false);
  EvaluateAcceptance("ttH",32,27,118,true,false,false);
  EvaluateAcceptance("ttH",32,28,118,true,false,false);
  EvaluateAcceptance("ttH",32,29,100,true,false,false);
  EvaluateAcceptance("ttH",32,30,92,true,false,false);
  EvaluateAcceptance("ttH",32,31,52,true,false,false);
  EvaluateAcceptance("ttH",32,32,20,true,false,false);
  EvaluateAcceptance("ttH",32,33,20,true,false,false);
  EvaluateAcceptance("ttH",32,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",33,20,124,true,false,false);
  EvaluateAcceptance("ttH",33,21,124,true,false,false);
  EvaluateAcceptance("ttH",33,22,120,true,false,false);
  EvaluateAcceptance("ttH",33,23,118,true,false,false);
  EvaluateAcceptance("ttH",33,24,104,true,false,false);
  EvaluateAcceptance("ttH",33,25,96,true,false,false);
  EvaluateAcceptance("ttH",33,26,76,true,false,false);
  EvaluateAcceptance("ttH",33,27,72,true,false,false);
  EvaluateAcceptance("ttH",33,28,60,true,false,false);
  EvaluateAcceptance("ttH",33,29,50,true,false,false);
  EvaluateAcceptance("ttH",33,30,40,true,false,false);
  EvaluateAcceptance("ttH",33,31,34,true,false,false);
  EvaluateAcceptance("ttH",33,32,20,true,false,false);
  EvaluateAcceptance("ttH",33,33,20,true,false,false);
  EvaluateAcceptance("ttH",33,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",34,20,118,true,false,false);
  EvaluateAcceptance("ttH",34,21,114,true,false,false);
  EvaluateAcceptance("ttH",34,22,112,true,false,false);
  EvaluateAcceptance("ttH",34,23,108,true,false,false);
  EvaluateAcceptance("ttH",34,24,96,true,false,false);
  EvaluateAcceptance("ttH",34,25,86,true,false,false);
  EvaluateAcceptance("ttH",34,26,64,true,false,false);
  EvaluateAcceptance("ttH",34,27,60,true,false,false);
  EvaluateAcceptance("ttH",34,28,52,true,false,false);
  EvaluateAcceptance("ttH",34,29,44,true,false,false);
  EvaluateAcceptance("ttH",34,30,36,true,false,false);
  EvaluateAcceptance("ttH",34,31,30,true,false,false);
  EvaluateAcceptance("ttH",34,32,20,true,false,false);
  EvaluateAcceptance("ttH",34,33,20,true,false,false);
  EvaluateAcceptance("ttH",34,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",35,20,110,true,false,false);
  EvaluateAcceptance("ttH",35,21,108,true,false,false);
  EvaluateAcceptance("ttH",35,22,104,true,false,false);
  EvaluateAcceptance("ttH",35,23,100,true,false,false);
  EvaluateAcceptance("ttH",35,24,90,true,false,false);
  EvaluateAcceptance("ttH",35,25,76,true,false,false);
  EvaluateAcceptance("ttH",35,26,58,true,false,false);
  EvaluateAcceptance("ttH",35,27,52,true,false,false);
  EvaluateAcceptance("ttH",35,28,46,true,false,false);
  EvaluateAcceptance("ttH",35,29,38,true,false,false);
  EvaluateAcceptance("ttH",35,30,32,true,false,false);
  EvaluateAcceptance("ttH",35,31,28,true,false,false);
  EvaluateAcceptance("ttH",35,32,20,true,false,false);
  EvaluateAcceptance("ttH",35,33,20,true,false,false);
  EvaluateAcceptance("ttH",35,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",36,20,106,true,false,false);
  EvaluateAcceptance("ttH",36,21,106,true,false,false);
  EvaluateAcceptance("ttH",36,22,102,true,false,false);
  EvaluateAcceptance("ttH",36,23,96,true,false,false);
  EvaluateAcceptance("ttH",36,24,90,true,false,false);
  EvaluateAcceptance("ttH",36,25,76,true,false,false);
  EvaluateAcceptance("ttH",36,26,56,true,false,false);
  EvaluateAcceptance("ttH",36,27,50,true,false,false);
  EvaluateAcceptance("ttH",36,28,44,true,false,false);
  EvaluateAcceptance("ttH",36,29,38,true,false,false);
  EvaluateAcceptance("ttH",36,30,32,true,false,false);
  EvaluateAcceptance("ttH",36,31,28,true,false,false);
  EvaluateAcceptance("ttH",36,32,20,true,false,false);
  EvaluateAcceptance("ttH",36,33,20,true,false,false);
  EvaluateAcceptance("ttH",36,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",37,20,106,true,false,false);
  EvaluateAcceptance("ttH",37,21,104,true,false,false);
  EvaluateAcceptance("ttH",37,22,100,true,false,false);
  EvaluateAcceptance("ttH",37,23,96,true,false,false);
  EvaluateAcceptance("ttH",37,24,88,true,false,false);
  EvaluateAcceptance("ttH",37,25,74,true,false,false);
  EvaluateAcceptance("ttH",37,26,54,true,false,false);
  EvaluateAcceptance("ttH",37,27,48,true,false,false);
  EvaluateAcceptance("ttH",37,28,44,true,false,false);
  EvaluateAcceptance("ttH",37,29,36,true,false,false);
  EvaluateAcceptance("ttH",37,30,32,true,false,false);
  EvaluateAcceptance("ttH",37,31,26,true,false,false);
  EvaluateAcceptance("ttH",37,32,20,true,false,false);
  EvaluateAcceptance("ttH",37,33,20,true,false,false);
  EvaluateAcceptance("ttH",37,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",38,20,104,true,false,false);
  EvaluateAcceptance("ttH",38,21,100,true,false,false);
  EvaluateAcceptance("ttH",38,22,96,true,false,false);
  EvaluateAcceptance("ttH",38,23,92,true,false,false);
  EvaluateAcceptance("ttH",38,24,84,true,false,false);
  EvaluateAcceptance("ttH",38,25,70,true,false,false);
  EvaluateAcceptance("ttH",38,26,52,true,false,false);
  EvaluateAcceptance("ttH",38,27,46,true,false,false);
  EvaluateAcceptance("ttH",38,28,42,true,false,false);
  EvaluateAcceptance("ttH",38,29,34,true,false,false);
  EvaluateAcceptance("ttH",38,30,30,true,false,false);
  EvaluateAcceptance("ttH",38,31,26,true,false,false);
  EvaluateAcceptance("ttH",38,32,20,true,false,false);
  EvaluateAcceptance("ttH",38,33,20,true,false,false);
  EvaluateAcceptance("ttH",38,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",39,20,100,true,false,false);
  EvaluateAcceptance("ttH",39,21,96,true,false,false);
  EvaluateAcceptance("ttH",39,22,94,true,false,false);
  EvaluateAcceptance("ttH",39,23,90,true,false,false);
  EvaluateAcceptance("ttH",39,24,84,true,false,false);
  EvaluateAcceptance("ttH",39,25,68,true,false,false);
  EvaluateAcceptance("ttH",39,26,52,true,false,false);
  EvaluateAcceptance("ttH",39,27,44,true,false,false);
  EvaluateAcceptance("ttH",39,28,40,true,false,false);
  EvaluateAcceptance("ttH",39,29,34,true,false,false);
  EvaluateAcceptance("ttH",39,30,30,true,false,false);
  EvaluateAcceptance("ttH",39,31,26,true,false,false);
  EvaluateAcceptance("ttH",39,32,20,true,false,false);
  EvaluateAcceptance("ttH",39,33,20,true,false,false);
  EvaluateAcceptance("ttH",39,34,20,true,false,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",40,20,98,true,false,false);
  EvaluateAcceptance("ttH",40,21,96,true,false,false);
  EvaluateAcceptance("ttH",40,22,92,true,false,false);
  EvaluateAcceptance("ttH",40,23,90,true,false,false);
  EvaluateAcceptance("ttH",40,24,82,true,false,false);
  EvaluateAcceptance("ttH",40,25,64,true,false,false);
  EvaluateAcceptance("ttH",40,26,50,true,false,false);
  EvaluateAcceptance("ttH",40,27,44,true,false,false);
  EvaluateAcceptance("ttH",40,28,38,true,false,false);
  EvaluateAcceptance("ttH",40,29,34,true,false,false);
  EvaluateAcceptance("ttH",40,30,30,true,false,false);
  EvaluateAcceptance("ttH",40,31,26,true,false,false);
  EvaluateAcceptance("ttH",40,32,20,true,false,false);
  EvaluateAcceptance("ttH",40,33,20,true,false,false);
  EvaluateAcceptance("ttH",40,34,20,true,false,false);
  cout<<" "<<endl;
}

void get_acceptance_1jet_ttH(){

  cout<<"ttH, 1 jet category"<<endl;
  EvaluateAcceptance("ttH",32,20,164,false,true,false);
  EvaluateAcceptance("ttH",32,21,164,false,true,false);
  EvaluateAcceptance("ttH",32,22,164,false,true,false);
  EvaluateAcceptance("ttH",32,23,150,false,true,false);
  EvaluateAcceptance("ttH",32,24,134,false,true,false);
  EvaluateAcceptance("ttH",32,25,126,false,true,false);
  EvaluateAcceptance("ttH",32,26,118,false,true,false);
  EvaluateAcceptance("ttH",32,27,118,false,true,false);
  EvaluateAcceptance("ttH",32,28,118,false,true,false);
  EvaluateAcceptance("ttH",32,29,100,false,true,false);
  EvaluateAcceptance("ttH",32,30,92,false,true,false);
  EvaluateAcceptance("ttH",32,31,52,false,true,false);
  EvaluateAcceptance("ttH",32,32,20,false,true,false);
  EvaluateAcceptance("ttH",32,33,20,false,true,false);
  EvaluateAcceptance("ttH",32,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",33,20,124,false,true,false);
  EvaluateAcceptance("ttH",33,21,124,false,true,false);
  EvaluateAcceptance("ttH",33,22,120,false,true,false);
  EvaluateAcceptance("ttH",33,23,118,false,true,false);
  EvaluateAcceptance("ttH",33,24,104,false,true,false);
  EvaluateAcceptance("ttH",33,25,96,false,true,false);
  EvaluateAcceptance("ttH",33,26,76,false,true,false);
  EvaluateAcceptance("ttH",33,27,72,false,true,false);
  EvaluateAcceptance("ttH",33,28,60,false,true,false);
  EvaluateAcceptance("ttH",33,29,50,false,true,false);
  EvaluateAcceptance("ttH",33,30,40,false,true,false);
  EvaluateAcceptance("ttH",33,31,34,false,true,false);
  EvaluateAcceptance("ttH",33,32,20,false,true,false);
  EvaluateAcceptance("ttH",33,33,20,false,true,false);
  EvaluateAcceptance("ttH",33,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",34,20,118,false,true,false);
  EvaluateAcceptance("ttH",34,21,114,false,true,false);
  EvaluateAcceptance("ttH",34,22,112,false,true,false);
  EvaluateAcceptance("ttH",34,23,108,false,true,false);
  EvaluateAcceptance("ttH",34,24,96,false,true,false);
  EvaluateAcceptance("ttH",34,25,86,false,true,false);
  EvaluateAcceptance("ttH",34,26,64,false,true,false);
  EvaluateAcceptance("ttH",34,27,60,false,true,false);
  EvaluateAcceptance("ttH",34,28,52,false,true,false);
  EvaluateAcceptance("ttH",34,29,44,false,true,false);
  EvaluateAcceptance("ttH",34,30,36,false,true,false);
  EvaluateAcceptance("ttH",34,31,30,false,true,false);
  EvaluateAcceptance("ttH",34,32,20,false,true,false);
  EvaluateAcceptance("ttH",34,33,20,false,true,false);
  EvaluateAcceptance("ttH",34,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",35,20,110,false,true,false);
  EvaluateAcceptance("ttH",35,21,108,false,true,false);
  EvaluateAcceptance("ttH",35,22,104,false,true,false);
  EvaluateAcceptance("ttH",35,23,100,false,true,false);
  EvaluateAcceptance("ttH",35,24,90,false,true,false);
  EvaluateAcceptance("ttH",35,25,76,false,true,false);
  EvaluateAcceptance("ttH",35,26,58,false,true,false);
  EvaluateAcceptance("ttH",35,27,52,false,true,false);
  EvaluateAcceptance("ttH",35,28,46,false,true,false);
  EvaluateAcceptance("ttH",35,29,38,false,true,false);
  EvaluateAcceptance("ttH",35,30,32,false,true,false);
  EvaluateAcceptance("ttH",35,31,28,false,true,false);
  EvaluateAcceptance("ttH",35,32,20,false,true,false);
  EvaluateAcceptance("ttH",35,33,20,false,true,false);
  EvaluateAcceptance("ttH",35,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",36,20,106,false,true,false);
  EvaluateAcceptance("ttH",36,21,106,false,true,false);
  EvaluateAcceptance("ttH",36,22,102,false,true,false);
  EvaluateAcceptance("ttH",36,23,96,false,true,false);
  EvaluateAcceptance("ttH",36,24,90,false,true,false);
  EvaluateAcceptance("ttH",36,25,76,false,true,false);
  EvaluateAcceptance("ttH",36,26,56,false,true,false);
  EvaluateAcceptance("ttH",36,27,50,false,true,false);
  EvaluateAcceptance("ttH",36,28,44,false,true,false);
  EvaluateAcceptance("ttH",36,29,38,false,true,false);
  EvaluateAcceptance("ttH",36,30,32,false,true,false);
  EvaluateAcceptance("ttH",36,31,28,false,true,false);
  EvaluateAcceptance("ttH",36,32,20,false,true,false);
  EvaluateAcceptance("ttH",36,33,20,false,true,false);
  EvaluateAcceptance("ttH",36,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",37,20,106,false,true,false);
  EvaluateAcceptance("ttH",37,21,104,false,true,false);
  EvaluateAcceptance("ttH",37,22,100,false,true,false);
  EvaluateAcceptance("ttH",37,23,96,false,true,false);
  EvaluateAcceptance("ttH",37,24,88,false,true,false);
  EvaluateAcceptance("ttH",37,25,74,false,true,false);
  EvaluateAcceptance("ttH",37,26,54,false,true,false);
  EvaluateAcceptance("ttH",37,27,48,false,true,false);
  EvaluateAcceptance("ttH",37,28,44,false,true,false);
  EvaluateAcceptance("ttH",37,29,36,false,true,false);
  EvaluateAcceptance("ttH",37,30,32,false,true,false);
  EvaluateAcceptance("ttH",37,31,26,false,true,false);
  EvaluateAcceptance("ttH",37,32,20,false,true,false);
  EvaluateAcceptance("ttH",37,33,20,false,true,false);
  EvaluateAcceptance("ttH",37,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",38,20,104,false,true,false);
  EvaluateAcceptance("ttH",38,21,100,false,true,false);
  EvaluateAcceptance("ttH",38,22,96,false,true,false);
  EvaluateAcceptance("ttH",38,23,92,false,true,false);
  EvaluateAcceptance("ttH",38,24,84,false,true,false);
  EvaluateAcceptance("ttH",38,25,70,false,true,false);
  EvaluateAcceptance("ttH",38,26,52,false,true,false);
  EvaluateAcceptance("ttH",38,27,46,false,true,false);
  EvaluateAcceptance("ttH",38,28,42,false,true,false);
  EvaluateAcceptance("ttH",38,29,34,false,true,false);
  EvaluateAcceptance("ttH",38,30,30,false,true,false);
  EvaluateAcceptance("ttH",38,31,26,false,true,false);
  EvaluateAcceptance("ttH",38,32,20,false,true,false);
  EvaluateAcceptance("ttH",38,33,20,false,true,false);
  EvaluateAcceptance("ttH",38,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",39,20,100,false,true,false);
  EvaluateAcceptance("ttH",39,21,96,false,true,false);
  EvaluateAcceptance("ttH",39,22,94,false,true,false);
  EvaluateAcceptance("ttH",39,23,90,false,true,false);
  EvaluateAcceptance("ttH",39,24,84,false,true,false);
  EvaluateAcceptance("ttH",39,25,68,false,true,false);
  EvaluateAcceptance("ttH",39,26,52,false,true,false);
  EvaluateAcceptance("ttH",39,27,44,false,true,false);
  EvaluateAcceptance("ttH",39,28,40,false,true,false);
  EvaluateAcceptance("ttH",39,29,34,false,true,false);
  EvaluateAcceptance("ttH",39,30,30,false,true,false);
  EvaluateAcceptance("ttH",39,31,26,false,true,false);
  EvaluateAcceptance("ttH",39,32,20,false,true,false);
  EvaluateAcceptance("ttH",39,33,20,false,true,false);
  EvaluateAcceptance("ttH",39,34,20,false,true,false);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",40,20,98,false,true,false);
  EvaluateAcceptance("ttH",40,21,96,false,true,false);
  EvaluateAcceptance("ttH",40,22,92,false,true,false);
  EvaluateAcceptance("ttH",40,23,90,false,true,false);
  EvaluateAcceptance("ttH",40,24,82,false,true,false);
  EvaluateAcceptance("ttH",40,25,64,false,true,false);
  EvaluateAcceptance("ttH",40,26,50,false,true,false);
  EvaluateAcceptance("ttH",40,27,44,false,true,false);
  EvaluateAcceptance("ttH",40,28,38,false,true,false);
  EvaluateAcceptance("ttH",40,29,34,false,true,false);
  EvaluateAcceptance("ttH",40,30,30,false,true,false);
  EvaluateAcceptance("ttH",40,31,26,false,true,false);
  EvaluateAcceptance("ttH",40,32,20,false,true,false);
  EvaluateAcceptance("ttH",40,33,20,false,true,false);
  EvaluateAcceptance("ttH",40,34,20,false,true,false);
  cout<<" "<<endl;
}

void get_acceptance_2jet_ttH(){

  cout<<"ttH, 2 jet category"<<endl;
  EvaluateAcceptance("ttH",32,20,164,false,false,true);
  EvaluateAcceptance("ttH",32,21,164,false,false,true);
  EvaluateAcceptance("ttH",32,22,164,false,false,true);
  EvaluateAcceptance("ttH",32,23,150,false,false,true);
  EvaluateAcceptance("ttH",32,24,134,false,false,true);
  EvaluateAcceptance("ttH",32,25,126,false,false,true);
  EvaluateAcceptance("ttH",32,26,118,false,false,true);
  EvaluateAcceptance("ttH",32,27,118,false,false,true);
  EvaluateAcceptance("ttH",32,28,118,false,false,true);
  EvaluateAcceptance("ttH",32,29,100,false,false,true);
  EvaluateAcceptance("ttH",32,30,92,false,false,true);
  EvaluateAcceptance("ttH",32,31,52,false,false,true);
  EvaluateAcceptance("ttH",32,32,20,false,false,true);
  EvaluateAcceptance("ttH",32,33,20,false,false,true);
  EvaluateAcceptance("ttH",32,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",33,20,124,false,false,true);
  EvaluateAcceptance("ttH",33,21,124,false,false,true);
  EvaluateAcceptance("ttH",33,22,120,false,false,true);
  EvaluateAcceptance("ttH",33,23,118,false,false,true);
  EvaluateAcceptance("ttH",33,24,104,false,false,true);
  EvaluateAcceptance("ttH",33,25,96,false,false,true);
  EvaluateAcceptance("ttH",33,26,76,false,false,true);
  EvaluateAcceptance("ttH",33,27,72,false,false,true);
  EvaluateAcceptance("ttH",33,28,60,false,false,true);
  EvaluateAcceptance("ttH",33,29,50,false,false,true);
  EvaluateAcceptance("ttH",33,30,40,false,false,true);
  EvaluateAcceptance("ttH",33,31,34,false,false,true);
  EvaluateAcceptance("ttH",33,32,20,false,false,true);
  EvaluateAcceptance("ttH",33,33,20,false,false,true);
  EvaluateAcceptance("ttH",33,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",34,20,118,false,false,true);
  EvaluateAcceptance("ttH",34,21,114,false,false,true);
  EvaluateAcceptance("ttH",34,22,112,false,false,true);
  EvaluateAcceptance("ttH",34,23,108,false,false,true);
  EvaluateAcceptance("ttH",34,24,96,false,false,true);
  EvaluateAcceptance("ttH",34,25,86,false,false,true);
  EvaluateAcceptance("ttH",34,26,64,false,false,true);
  EvaluateAcceptance("ttH",34,27,60,false,false,true);
  EvaluateAcceptance("ttH",34,28,52,false,false,true);
  EvaluateAcceptance("ttH",34,29,44,false,false,true);
  EvaluateAcceptance("ttH",34,30,36,false,false,true);
  EvaluateAcceptance("ttH",34,31,30,false,false,true);
  EvaluateAcceptance("ttH",34,32,20,false,false,true);
  EvaluateAcceptance("ttH",34,33,20,false,false,true);
  EvaluateAcceptance("ttH",34,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",35,20,110,false,false,true);
  EvaluateAcceptance("ttH",35,21,108,false,false,true);
  EvaluateAcceptance("ttH",35,22,104,false,false,true);
  EvaluateAcceptance("ttH",35,23,100,false,false,true);
  EvaluateAcceptance("ttH",35,24,90,false,false,true);
  EvaluateAcceptance("ttH",35,25,76,false,false,true);
  EvaluateAcceptance("ttH",35,26,58,false,false,true);
  EvaluateAcceptance("ttH",35,27,52,false,false,true);
  EvaluateAcceptance("ttH",35,28,46,false,false,true);
  EvaluateAcceptance("ttH",35,29,38,false,false,true);
  EvaluateAcceptance("ttH",35,30,32,false,false,true);
  EvaluateAcceptance("ttH",35,31,28,false,false,true);
  EvaluateAcceptance("ttH",35,32,20,false,false,true);
  EvaluateAcceptance("ttH",35,33,20,false,false,true);
  EvaluateAcceptance("ttH",35,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",36,20,106,false,false,true);
  EvaluateAcceptance("ttH",36,21,106,false,false,true);
  EvaluateAcceptance("ttH",36,22,102,false,false,true);
  EvaluateAcceptance("ttH",36,23,96,false,false,true);
  EvaluateAcceptance("ttH",36,24,90,false,false,true);
  EvaluateAcceptance("ttH",36,25,76,false,false,true);
  EvaluateAcceptance("ttH",36,26,56,false,false,true);
  EvaluateAcceptance("ttH",36,27,50,false,false,true);
  EvaluateAcceptance("ttH",36,28,44,false,false,true);
  EvaluateAcceptance("ttH",36,29,38,false,false,true);
  EvaluateAcceptance("ttH",36,30,32,false,false,true);
  EvaluateAcceptance("ttH",36,31,28,false,false,true);
  EvaluateAcceptance("ttH",36,32,20,false,false,true);
  EvaluateAcceptance("ttH",36,33,20,false,false,true);
  EvaluateAcceptance("ttH",36,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",37,20,106,false,false,true);
  EvaluateAcceptance("ttH",37,21,104,false,false,true);
  EvaluateAcceptance("ttH",37,22,100,false,false,true);
  EvaluateAcceptance("ttH",37,23,96,false,false,true);
  EvaluateAcceptance("ttH",37,24,88,false,false,true);
  EvaluateAcceptance("ttH",37,25,74,false,false,true);
  EvaluateAcceptance("ttH",37,26,54,false,false,true);
  EvaluateAcceptance("ttH",37,27,48,false,false,true);
  EvaluateAcceptance("ttH",37,28,44,false,false,true);
  EvaluateAcceptance("ttH",37,29,36,false,false,true);
  EvaluateAcceptance("ttH",37,30,32,false,false,true);
  EvaluateAcceptance("ttH",37,31,26,false,false,true);
  EvaluateAcceptance("ttH",37,32,20,false,false,true);
  EvaluateAcceptance("ttH",37,33,20,false,false,true);
  EvaluateAcceptance("ttH",37,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",38,20,104,false,false,true);
  EvaluateAcceptance("ttH",38,21,100,false,false,true);
  EvaluateAcceptance("ttH",38,22,96,false,false,true);
  EvaluateAcceptance("ttH",38,23,92,false,false,true);
  EvaluateAcceptance("ttH",38,24,84,false,false,true);
  EvaluateAcceptance("ttH",38,25,70,false,false,true);
  EvaluateAcceptance("ttH",38,26,52,false,false,true);
  EvaluateAcceptance("ttH",38,27,46,false,false,true);
  EvaluateAcceptance("ttH",38,28,42,false,false,true);
  EvaluateAcceptance("ttH",38,29,34,false,false,true);
  EvaluateAcceptance("ttH",38,30,30,false,false,true);
  EvaluateAcceptance("ttH",38,31,26,false,false,true);
  EvaluateAcceptance("ttH",38,32,20,false,false,true);
  EvaluateAcceptance("ttH",38,33,20,false,false,true);
  EvaluateAcceptance("ttH",38,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",39,20,100,false,false,true);
  EvaluateAcceptance("ttH",39,21,96,false,false,true);
  EvaluateAcceptance("ttH",39,22,94,false,false,true);
  EvaluateAcceptance("ttH",39,23,90,false,false,true);
  EvaluateAcceptance("ttH",39,24,84,false,false,true);
  EvaluateAcceptance("ttH",39,25,68,false,false,true);
  EvaluateAcceptance("ttH",39,26,52,false,false,true);
  EvaluateAcceptance("ttH",39,27,44,false,false,true);
  EvaluateAcceptance("ttH",39,28,40,false,false,true);
  EvaluateAcceptance("ttH",39,29,34,false,false,true);
  EvaluateAcceptance("ttH",39,30,30,false,false,true);
  EvaluateAcceptance("ttH",39,31,26,false,false,true);
  EvaluateAcceptance("ttH",39,32,20,false,false,true);
  EvaluateAcceptance("ttH",39,33,20,false,false,true);
  EvaluateAcceptance("ttH",39,34,20,false,false,true);
  cout<<" "<<endl;
  EvaluateAcceptance("ttH",40,20,98,false,false,true);
  EvaluateAcceptance("ttH",40,21,96,false,false,true);
  EvaluateAcceptance("ttH",40,22,92,false,false,true);
  EvaluateAcceptance("ttH",40,23,90,false,false,true);
  EvaluateAcceptance("ttH",40,24,82,false,false,true);
  EvaluateAcceptance("ttH",40,25,64,false,false,true);
  EvaluateAcceptance("ttH",40,26,50,false,false,true);
  EvaluateAcceptance("ttH",40,27,44,false,false,true);
  EvaluateAcceptance("ttH",40,28,38,false,false,true);
  EvaluateAcceptance("ttH",40,29,34,false,false,true);
  EvaluateAcceptance("ttH",40,30,30,false,false,true);
  EvaluateAcceptance("ttH",40,31,26,false,false,true);
  EvaluateAcceptance("ttH",40,32,20,false,false,true);
  EvaluateAcceptance("ttH",40,33,20,false,false,true);
  EvaluateAcceptance("ttH",40,34,20,false,false,true);
  cout<<" "<<endl;
}
