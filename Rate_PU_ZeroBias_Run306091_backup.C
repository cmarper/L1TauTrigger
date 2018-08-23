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
#include "ApplyCalibration.C"
#include <map>
#include <stdio.h>

using namespace std;

void Rate()
{ 
  // *** PU PER LS FILE ***
  ifstream PUFile("PU_LS_run306091.txt");
  std::map<Int_t,Float_t> PU_per_LS;
  std::string str; 
  
  while (std::getline(PUFile, str))
    { TString temp(str);
      int pos_space = temp.First(" ");
      TString LS_str(temp,pos_space);
     // cout<<LS_str<<endl;
      TString Replacing = LS_str ;
      Replacing += " ";
      temp.ReplaceAll(Replacing.Data(),"");
      TString PU_str = temp;
      //cout<<PU_str<<endl;
      std::istringstream ss_LS(LS_str.Data());
      Int_t LS ;
      ss_LS >> LS;
      std::istringstream ss_PU(PU_str.Data());
      Float_t PU ;
      ss_PU >> PU;
      int PU_floor = floor(PU);     
      PU_per_LS.insert(std::pair<Int_t,Int_t>(LS , PU_floor ));
    }
  
  // *** ISO OPTIONS FILE ***
  std::map<TString,TH3F*> histosIsolation;
  TFile f_Isolation("/home/llr/cms/mperez/TauTrigger/CMSSW_9_2_10/src/TauTagAndProbe/TauTagAndProbe/test/Trees_meanparam/Iso_LUTs_Options_MC_92X_mean.root","READ");

  for(UInt_t i = 1 ; i < 23 ; ++i)
    {
      TString CurrentNameHisto = "LUT_Progression_";
      ostringstream convert;
      convert << i;
      CurrentNameHisto += convert.str();
      TH3F* current_Histo = (TH3F*)f_Isolation.Get(CurrentNameHisto.Data());
      histosIsolation.insert(make_pair(CurrentNameHisto,current_Histo));
    }  

  // *** NTUPLES ***
  TString FileName_in = "/home/llr/cms/mperez/TauTrigger/CMSSW_9_2_10/src/TauTagAndProbe/TauTagAndProbe/test/Trees_meanparam/calibratedOutput_Ntuple_ZeroBias_Run306091_92X_mean.root";
  TFile f_in(FileName_in.Data(),"READ");
  TTree* inTree = (TTree*)f_in.Get("outTreeForCalibration");

  Int_t       in_EventNumber =  0;
  Int_t           in_RunNumber =  0;
  Int_t           in_lumi =  0;
  vector<float>   *in_l1tEmuPt =  0;
  vector<float>   *in_l1tEmuEta =  0;
  vector<float>   *in_l1tEmuPhi =  0;
  vector<int>     *in_l1tEmuQual =  0;
  vector<int>     *in_l1tEmuNTT =  0;
  vector<int>     *in_l1tEmuHasEM =  0;
  vector<int>     *in_l1tEmuIsMerged =  0;
  vector<int>     *in_l1tEmuTowerIEta =  0;
  vector<int>     *in_l1tEmuTowerIPhi =  0;
  vector<int>     *in_l1tEmuRawEt =  0;
  vector<int>     *in_l1tEmuIsoEt =  0;
  vector<int>     *in_compressedieta =  0;
  vector<int>     *in_compressedE =  0;
  vector<int>     *in_compressednTT =  0;
  vector<int>     *in_supercompressedE =  0;
  vector<int>     *in_supercompressednTT =  0;
  vector<float>   *in_CalibPt =  0;
  vector<Bool_t>  *in_L1Tau_PassShapeVeto = 0;

  inTree->SetBranchAddress("EventNumber", &in_EventNumber);
  inTree->SetBranchAddress("RunNumber", &in_RunNumber);
  inTree->SetBranchAddress("lumi", &in_lumi);
  inTree->SetBranchAddress("L1Tau_pt",&in_l1tEmuPt);
  inTree->SetBranchAddress("L1Tau_eta",&in_l1tEmuEta);
  inTree->SetBranchAddress("L1Tau_phi",&in_l1tEmuPhi);
  inTree->SetBranchAddress("L1Tau_Qual",&in_l1tEmuQual);
  inTree->SetBranchAddress("L1Tau_nTT",&in_l1tEmuNTT);
  inTree->SetBranchAddress("L1Tau_hasEM",&in_l1tEmuHasEM);
  inTree->SetBranchAddress("L1Tau_isMerged",&in_l1tEmuIsMerged);
  inTree->SetBranchAddress("L1Tau_IEt",&in_l1tEmuRawEt);
  inTree->SetBranchAddress("L1Tau_Iso",&in_l1tEmuIsoEt);
  inTree->SetBranchAddress("L1Tau_IEta",&in_l1tEmuTowerIEta);
  inTree->SetBranchAddress("L1Tau_IPhi",&in_l1tEmuTowerIPhi);
  inTree->SetBranchAddress("compressedieta",&in_compressedieta);
  inTree->SetBranchAddress("compressedE",&in_compressedE);
  inTree->SetBranchAddress("compressednTT",&in_compressednTT);
  inTree->SetBranchAddress("supercompressedE",&in_supercompressedE);
  inTree->SetBranchAddress("supercompressednTT",&in_supercompressednTT);
  inTree->SetBranchAddress("L1Tau_CalibPt",&in_CalibPt);
  inTree->SetBranchAddress("L1Tau_PassShapeVeto",&in_L1Tau_PassShapeVeto);
/*
  TH3F* rate_PU_DiTau_noIso = new TH3F("rate_PU_DiTau_noIso","rate_PU_DiTau_noIso",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_1 = new TH3F("rate_PU_DiTau_Progression_1","rate_PU_DiTau_Progression_1",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_2 = new TH3F("rate_PU_DiTau_Progression_2","rate_PU_DiTau_Progression_2",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_3 = new TH3F("rate_PU_DiTau_Progression_3","rate_PU_DiTau_Progression_3",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_4 = new TH3F("rate_PU_DiTau_Progression_4","rate_PU_DiTau_Progression_4",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_5 = new TH3F("rate_PU_DiTau_Progression_5","rate_PU_DiTau_Progression_5",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_6 = new TH3F("rate_PU_DiTau_Progression_6","rate_PU_DiTau_Progression_6",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_7 = new TH3F("rate_PU_DiTau_Progression_7","rate_PU_DiTau_Progression_7",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_8 = new TH3F("rate_PU_DiTau_Progression_8","rate_PU_DiTau_Progression_8",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_9 = new TH3F("rate_PU_DiTau_Progression_9","rate_PU_DiTau_Progression_9",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_10 = new TH3F("rate_PU_DiTau_Progression_10","rate_PU_DiTau_Progression_10",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_11 = new TH3F("rate_PU_DiTau_Progression_11","rate_PU_DiTau_Progression_11",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_12 = new TH3F("rate_PU_DiTau_Progression_12","rate_PU_DiTau_Progression_12",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_13 = new TH3F("rate_PU_DiTau_Progression_13","rate_PU_DiTau_Progression_13",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_14 = new TH3F("rate_PU_DiTau_Progression_14","rate_PU_DiTau_Progression_14",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_15 = new TH3F("rate_PU_DiTau_Progression_15","rate_PU_DiTau_Progression_15",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_16 = new TH3F("rate_PU_DiTau_Progression_16","rate_PU_DiTau_Progression_16",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_17 = new TH3F("rate_PU_DiTau_Progression_17","rate_PU_DiTau_Progression_17",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_18 = new TH3F("rate_PU_DiTau_Progression_18","rate_PU_DiTau_Progression_18",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_19 = new TH3F("rate_PU_DiTau_Progression_19","rate_PU_DiTau_Progression_19",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_20 = new TH3F("rate_PU_DiTau_Progression_20","rate_PU_DiTau_Progression_20",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_21 = new TH3F("rate_PU_DiTau_Progression_21","rate_PU_DiTau_Progression_21",620,0,620,80,0,80,100,0,100);
  TH3F* rate_PU_DiTau_Progression_22 = new TH3F("rate_PU_DiTau_Progression_22","rate_PU_DiTau_Progression_22",620,0,620,80,0,80,100,0,100);
*/
  TH2F* h2_rate_PU_DiTau_noIso = new TH2F("h2_rate_PU_DiTau_noIso","h2_rate_PU_DiTau_noIso",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_1 = new TH2F("h2_rate_PU_DiTau_Progression_1","h2_rate_PU_DiTau_Progression_1",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_2 = new TH2F("h2_rate_PU_DiTau_Progression_2","h2_rate_PU_DiTau_Progression_2",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_3 = new TH2F("h2_rate_PU_DiTau_Progression_3","h2_rate_PU_DiTau_Progression_3",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_4 = new TH2F("h2_rate_PU_DiTau_Progression_4","h2_rate_PU_DiTau_Progression_4",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_5 = new TH2F("h2_rate_PU_DiTau_Progression_5","h2_rate_PU_DiTau_Progression_5",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_6 = new TH2F("h2_rate_PU_DiTau_Progression_6","h2_rate_PU_DiTau_Progression_6",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_7 = new TH2F("h2_rate_PU_DiTau_Progression_7","h2_rate_PU_DiTau_Progression_7",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_8 = new TH2F("h2_rate_PU_DiTau_Progression_8","h2_rate_PU_DiTau_Progression_8",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_9 = new TH2F("h2_rate_PU_DiTau_Progression_9","h2_rate_PU_DiTau_Progression_9",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_10 = new TH2F("h2_rate_PU_DiTau_Progression_10","h2_rate_PU_DiTau_Progression_10",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_11 = new TH2F("h2_rate_PU_DiTau_Progression_11","h2_rate_PU_DiTau_Progression_11",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_12 = new TH2F("h2_rate_PU_DiTau_Progression_12","h2_rate_PU_DiTau_Progression_12",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_13 = new TH2F("h2_rate_PU_DiTau_Progression_13","h2_rate_PU_DiTau_Progression_13",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_14 = new TH2F("h2_rate_PU_DiTau_Progression_14","h2_rate_PU_DiTau_Progression_14",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_15 = new TH2F("h2_rate_PU_DiTau_Progression_15","h2_rate_PU_DiTau_Progression_15",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_16 = new TH2F("h2_rate_PU_DiTau_Progression_16","h2_rate_PU_DiTau_Progression_16",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_17 = new TH2F("h2_rate_PU_DiTau_Progression_17","h2_rate_PU_DiTau_Progression_17",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_18 = new TH2F("h2_rate_PU_DiTau_Progression_18","h2_rate_PU_DiTau_Progression_18",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_19 = new TH2F("h2_rate_PU_DiTau_Progression_19","h2_rate_PU_DiTau_Progression_19",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_20 = new TH2F("h2_rate_PU_DiTau_Progression_20","h2_rate_PU_DiTau_Progression_20",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_21 = new TH2F("h2_rate_PU_DiTau_Progression_21","h2_rate_PU_DiTau_Progression_21",80,0,80,100,0,100);
  TH2F* h2_rate_PU_DiTau_Progression_22 = new TH2F("h2_rate_PU_DiTau_Progression_22","h2_rate_PU_DiTau_Progression_22",80,0,80,100,0,100);

   
  // run 305310 
  // float nb = 1866.;
  // float thisLumiRun = 1.46E34;
  // float scaleToLumi = 2.00E34;
  // float scale = 0.001*(nb*11245.6)*scaleToLumi/thisLumiRun;
  
  //run 306091
  float nb = 1868.;
  float thisLumiRun = 1.50E34;
  float scaleToLumi = 2.00E34;
  float scale = 0.001*(nb*11245.6)*scaleToLumi/thisLumiRun;
  
  Float_t weight = 1.;
  
  // ***LOOP THROUGH PU***  
  //for (Int_t iLS = 45; iLS < 600 ; iLS++){
  for (Int_t iPU = 50; iPU < 70; iPU+=2){
  cout<< "PU = "<< iPU <<endl;
  
  float Denominator = 0;
  float nn_IsoInf = 0;
  float nn_Progression_1 = 0; 
  float nn_Progression_2 = 0;
  float nn_Progression_3 = 0;
  float nn_Progression_4 = 0;
  float nn_Progression_5 = 0;
  float nn_Progression_6 = 0;
  float nn_Progression_7 = 0;
  float nn_Progression_8 = 0;
  float nn_Progression_9 = 0;
  float nn_Progression_10 = 0;
  float nn_Progression_11 = 0;
  float nn_Progression_12 = 0;
  float nn_Progression_13 = 0;
  float nn_Progression_14 = 0;
  float nn_Progression_15 = 0;
  float nn_Progression_16 = 0;
  float nn_Progression_17 = 0;
  float nn_Progression_18 = 0;
  float nn_Progression_19 = 0;
  float nn_Progression_20 = 0;
  float nn_Progression_21 = 0;
  float nn_Progression_22 = 0;
 
  // ***LOOP THROUGH EVENTS***
  for(UInt_t i = 0 ; i < inTree->GetEntries() ; ++i)
    { 
      inTree->GetEntry(i);
     // if(i%10000==0) cout<<"Entry #"<<i<<endl; 
      
      if(PU_per_LS[in_lumi] == iPU || PU_per_LS[in_lumi] == iPU+1){
      //if(PU_per_LS.find(in_lumi)==PU_per_LS.end()) continue;
      //cout << PU_per_LS[in_lumi] << endl;
      
      ++Denominator;

      std::vector<Int_t> Index_Taus_IsoInf;
      Index_Taus_IsoInf.push_back(-1); Index_Taus_IsoInf.push_back(-1);
      std::vector<Float_t> pt_Taus_IsoInf;
      pt_Taus_IsoInf.push_back(-99.); pt_Taus_IsoInf.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_1;
      Index_Taus_Progression_1.push_back(-1); Index_Taus_Progression_1.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_1;
      pt_Taus_Progression_1.push_back(-99.); pt_Taus_Progression_1.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_2;
      Index_Taus_Progression_2.push_back(-1); Index_Taus_Progression_2.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_2;
      pt_Taus_Progression_2.push_back(-99.); pt_Taus_Progression_2.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_3;
      Index_Taus_Progression_3.push_back(-1); Index_Taus_Progression_3.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_3;
      pt_Taus_Progression_3.push_back(-99.); pt_Taus_Progression_3.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_4;
      Index_Taus_Progression_4.push_back(-1); Index_Taus_Progression_4.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_4;
      pt_Taus_Progression_4.push_back(-99.); pt_Taus_Progression_4.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_5;
      Index_Taus_Progression_5.push_back(-1); Index_Taus_Progression_5.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_5;
      pt_Taus_Progression_5.push_back(-99.); pt_Taus_Progression_5.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_6;
      Index_Taus_Progression_6.push_back(-1); Index_Taus_Progression_6.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_6;
      pt_Taus_Progression_6.push_back(-99.); pt_Taus_Progression_6.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_7;
      Index_Taus_Progression_7.push_back(-1); Index_Taus_Progression_7.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_7;
      pt_Taus_Progression_7.push_back(-99.); pt_Taus_Progression_7.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_8;
      Index_Taus_Progression_8.push_back(-1); Index_Taus_Progression_8.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_8;
      pt_Taus_Progression_8.push_back(-99.); pt_Taus_Progression_8.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_9;
      Index_Taus_Progression_9.push_back(-1); Index_Taus_Progression_9.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_9;
      pt_Taus_Progression_9.push_back(-99.); pt_Taus_Progression_9.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_10;
      Index_Taus_Progression_10.push_back(-1); Index_Taus_Progression_10.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_10;
      pt_Taus_Progression_10.push_back(-99.); pt_Taus_Progression_10.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_11;
      Index_Taus_Progression_11.push_back(-1); Index_Taus_Progression_11.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_11;
      pt_Taus_Progression_11.push_back(-99.); pt_Taus_Progression_11.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_12;
      Index_Taus_Progression_12.push_back(-1); Index_Taus_Progression_12.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_12;
      pt_Taus_Progression_12.push_back(-99.); pt_Taus_Progression_12.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_13;
      Index_Taus_Progression_13.push_back(-1); Index_Taus_Progression_13.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_13;
      pt_Taus_Progression_13.push_back(-99.); pt_Taus_Progression_13.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_14;
      Index_Taus_Progression_14.push_back(-1); Index_Taus_Progression_14.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_14;
      pt_Taus_Progression_14.push_back(-99.); pt_Taus_Progression_14.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_15;
      Index_Taus_Progression_15.push_back(-1); Index_Taus_Progression_15.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_15;
      pt_Taus_Progression_15.push_back(-99.); pt_Taus_Progression_15.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_16;
      Index_Taus_Progression_16.push_back(-1); Index_Taus_Progression_16.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_16;
      pt_Taus_Progression_16.push_back(-99.); pt_Taus_Progression_16.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_17;
      Index_Taus_Progression_17.push_back(-1); Index_Taus_Progression_17.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_17;
      pt_Taus_Progression_17.push_back(-99.); pt_Taus_Progression_17.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_18;
      Index_Taus_Progression_18.push_back(-1); Index_Taus_Progression_18.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_18;
      pt_Taus_Progression_18.push_back(-99.); pt_Taus_Progression_18.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_19;
      Index_Taus_Progression_19.push_back(-1); Index_Taus_Progression_19.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_19;
      pt_Taus_Progression_19.push_back(-99.); pt_Taus_Progression_19.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_20;
      Index_Taus_Progression_20.push_back(-1); Index_Taus_Progression_20.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_20;
      pt_Taus_Progression_20.push_back(-99.); pt_Taus_Progression_20.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_21;
      Index_Taus_Progression_21.push_back(-1); Index_Taus_Progression_21.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_21;
      pt_Taus_Progression_21.push_back(-99.); pt_Taus_Progression_21.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_22;
      Index_Taus_Progression_22.push_back(-1); Index_Taus_Progression_22.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_22;
      pt_Taus_Progression_22.push_back(-99.); pt_Taus_Progression_22.push_back(-99.);

      for(UInt_t iL1Tau = 0 ; iL1Tau < in_CalibPt->size() ; ++iL1Tau)
	{
	 // if(fabs(in_l1tEmuEta->at(iL1Tau))>2.1) continue;
         // if(in_CalibPt->at(iL1Tau)<32) continue; 

	  TString Result_Progression_1 = "LUT_Progression_1";
	  Int_t IsoCut_Progression_1 = histosIsolation[Result_Progression_1]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
           
	  TString Result_Progression_2 = "LUT_Progression_2";
	  Int_t IsoCut_Progression_2 = histosIsolation[Result_Progression_2]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_3 = "LUT_Progression_3";
	  Int_t IsoCut_Progression_3 = histosIsolation[Result_Progression_3]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_4 = "LUT_Progression_4";
	  Int_t IsoCut_Progression_4 = histosIsolation[Result_Progression_4]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_5 = "LUT_Progression_5";
	  Int_t IsoCut_Progression_5 = histosIsolation[Result_Progression_5]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_6 = "LUT_Progression_6";
	  Int_t IsoCut_Progression_6 = histosIsolation[Result_Progression_6]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_7 = "LUT_Progression_7";
	  Int_t IsoCut_Progression_7 = histosIsolation[Result_Progression_7]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_8 = "LUT_Progression_8";
	  Int_t IsoCut_Progression_8 = histosIsolation[Result_Progression_8]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_9 = "LUT_Progression_9";
	  Int_t IsoCut_Progression_9 = histosIsolation[Result_Progression_9]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_10 = "LUT_Progression_10";
	  Int_t IsoCut_Progression_10 = histosIsolation[Result_Progression_10]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_11 = "LUT_Progression_11";
	  Int_t IsoCut_Progression_11 = histosIsolation[Result_Progression_11]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_12 = "LUT_Progression_12";
	  Int_t IsoCut_Progression_12 = histosIsolation[Result_Progression_12]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_13 = "LUT_Progression_13";
	  Int_t IsoCut_Progression_13 = histosIsolation[Result_Progression_13]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_14 = "LUT_Progression_14";
	  Int_t IsoCut_Progression_14 = histosIsolation[Result_Progression_14]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_15 = "LUT_Progression_15";
	  Int_t IsoCut_Progression_15 = histosIsolation[Result_Progression_15]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_16 = "LUT_Progression_16";
	  Int_t IsoCut_Progression_16 = histosIsolation[Result_Progression_16]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_17 = "LUT_Progression_17";
	  Int_t IsoCut_Progression_17 = histosIsolation[Result_Progression_17]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_18 = "LUT_Progression_18";
	  Int_t IsoCut_Progression_18 = histosIsolation[Result_Progression_18]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_19 = "LUT_Progression_19";
	  Int_t IsoCut_Progression_19 = histosIsolation[Result_Progression_19]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_20 = "LUT_Progression_20";
	  Int_t IsoCut_Progression_20 = histosIsolation[Result_Progression_20]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  TString Result_Progression_21 = "LUT_Progression_21";
	  Int_t IsoCut_Progression_21 = histosIsolation[Result_Progression_21]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	
          TString Result_Progression_22 = "LUT_Progression_22";
	  Int_t IsoCut_Progression_22 = histosIsolation[Result_Progression_22]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

	  //DiTau trigger
	  if(fabs(in_l1tEmuEta->at(iL1Tau))>2.1) continue;
          if(in_CalibPt->at(iL1Tau)<32) continue;

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_IsoInf.at(0))
	    {
	      Index_Taus_IsoInf.at(1)=Index_Taus_IsoInf.at(0);
	      pt_Taus_IsoInf.at(1)=pt_Taus_IsoInf.at(0);
	      Index_Taus_IsoInf.at(0)=iL1Tau;
	      pt_Taus_IsoInf.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_IsoInf.at(1))
	    {
	      Index_Taus_IsoInf.at(1)=iL1Tau;
	      pt_Taus_IsoInf.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_1.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_1)
	    {
	      Index_Taus_Progression_1.at(1)=Index_Taus_Progression_1.at(0);
	      pt_Taus_Progression_1.at(1)=pt_Taus_Progression_1.at(0);
	      Index_Taus_Progression_1.at(0)=iL1Tau;
	      pt_Taus_Progression_1.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_1.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_1)
	    {
	      Index_Taus_Progression_1.at(1)=iL1Tau;
	      pt_Taus_Progression_1.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_2.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_2)
	    {
	      Index_Taus_Progression_2.at(1)=Index_Taus_Progression_2.at(0);
	      pt_Taus_Progression_2.at(1)=pt_Taus_Progression_2.at(0);
	      Index_Taus_Progression_2.at(0)=iL1Tau;
	      pt_Taus_Progression_2.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_2.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_2)
	    {
	      Index_Taus_Progression_2.at(1)=iL1Tau;
	      pt_Taus_Progression_2.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_3.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_3)
	    {
	      Index_Taus_Progression_3.at(1)=Index_Taus_Progression_3.at(0);
	      pt_Taus_Progression_3.at(1)=pt_Taus_Progression_3.at(0);
	      Index_Taus_Progression_3.at(0)=iL1Tau;
	      pt_Taus_Progression_3.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_3.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_3)
	    {
	      Index_Taus_Progression_3.at(1)=iL1Tau;
	      pt_Taus_Progression_3.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_4.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_4)
	    {
	      Index_Taus_Progression_4.at(1)=Index_Taus_Progression_4.at(0);
	      pt_Taus_Progression_4.at(1)=pt_Taus_Progression_4.at(0);
	      Index_Taus_Progression_4.at(0)=iL1Tau;
	      pt_Taus_Progression_4.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_4.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_4)
	    {
	      Index_Taus_Progression_4.at(1)=iL1Tau;
	      pt_Taus_Progression_4.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_5.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_5)
	    {
	      Index_Taus_Progression_5.at(1)=Index_Taus_Progression_5.at(0);
	      pt_Taus_Progression_5.at(1)=pt_Taus_Progression_5.at(0);
	      Index_Taus_Progression_5.at(0)=iL1Tau;
	      pt_Taus_Progression_5.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_5.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_5)
	    {
	      Index_Taus_Progression_5.at(1)=iL1Tau;
	      pt_Taus_Progression_5.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_6.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_6)
	    {
	      Index_Taus_Progression_6.at(1)=Index_Taus_Progression_6.at(0);
	      pt_Taus_Progression_6.at(1)=pt_Taus_Progression_6.at(0);
	      Index_Taus_Progression_6.at(0)=iL1Tau;
	      pt_Taus_Progression_6.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_6.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_6)
	    {
	      Index_Taus_Progression_6.at(1)=iL1Tau;
	      pt_Taus_Progression_6.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_7.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_7)
	    {
	      Index_Taus_Progression_7.at(1)=Index_Taus_Progression_7.at(0);
	      pt_Taus_Progression_7.at(1)=pt_Taus_Progression_7.at(0);
	      Index_Taus_Progression_7.at(0)=iL1Tau;
	      pt_Taus_Progression_7.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_7.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_7)
	    {
	      Index_Taus_Progression_7.at(1)=iL1Tau;
	      pt_Taus_Progression_7.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_8.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_8)
	    {
	      Index_Taus_Progression_8.at(1)=Index_Taus_Progression_8.at(0);
	      pt_Taus_Progression_8.at(1)=pt_Taus_Progression_8.at(0);
	      Index_Taus_Progression_8.at(0)=iL1Tau;
	      pt_Taus_Progression_8.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_8.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_8)
	    {
	      Index_Taus_Progression_8.at(1)=iL1Tau;
	      pt_Taus_Progression_8.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_9.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_9)
	    {
	      Index_Taus_Progression_9.at(1)=Index_Taus_Progression_9.at(0);
	      pt_Taus_Progression_9.at(1)=pt_Taus_Progression_9.at(0);
	      Index_Taus_Progression_9.at(0)=iL1Tau;
	      pt_Taus_Progression_9.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_9.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_9)
	    {
	      Index_Taus_Progression_9.at(1)=iL1Tau;
	      pt_Taus_Progression_9.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_10.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_10)
	    {
	      Index_Taus_Progression_10.at(1)=Index_Taus_Progression_10.at(0);
	      pt_Taus_Progression_10.at(1)=pt_Taus_Progression_10.at(0);
	      Index_Taus_Progression_10.at(0)=iL1Tau;
	      pt_Taus_Progression_10.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_10.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_10)
	    {
	      Index_Taus_Progression_10.at(1)=iL1Tau;
	      pt_Taus_Progression_10.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_11.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_11)
	    {
	      Index_Taus_Progression_11.at(1)=Index_Taus_Progression_11.at(0);
	      pt_Taus_Progression_11.at(1)=pt_Taus_Progression_11.at(0);
	      Index_Taus_Progression_11.at(0)=iL1Tau;
	      pt_Taus_Progression_11.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_11.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_11)
	    {
	      Index_Taus_Progression_11.at(1)=iL1Tau;
	      pt_Taus_Progression_11.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_12.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_12)
	    {
	      Index_Taus_Progression_12.at(1)=Index_Taus_Progression_12.at(0);
	      pt_Taus_Progression_12.at(1)=pt_Taus_Progression_12.at(0);
	      Index_Taus_Progression_12.at(0)=iL1Tau;
	      pt_Taus_Progression_12.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_12.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_12)
	    {
	      Index_Taus_Progression_12.at(1)=iL1Tau;
	      pt_Taus_Progression_12.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_13.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_13)
	    {
	      Index_Taus_Progression_13.at(1)=Index_Taus_Progression_13.at(0);
	      pt_Taus_Progression_13.at(1)=pt_Taus_Progression_13.at(0);
	      Index_Taus_Progression_13.at(0)=iL1Tau;
	      pt_Taus_Progression_13.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_13.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_13)
	    {
	      Index_Taus_Progression_13.at(1)=iL1Tau;
	      pt_Taus_Progression_13.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_14.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_14)
	    {
	      Index_Taus_Progression_14.at(1)=Index_Taus_Progression_14.at(0);
	      pt_Taus_Progression_14.at(1)=pt_Taus_Progression_14.at(0);
	      Index_Taus_Progression_14.at(0)=iL1Tau;
	      pt_Taus_Progression_14.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_14.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_14)
	    {
	      Index_Taus_Progression_14.at(1)=iL1Tau;
	      pt_Taus_Progression_14.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_15.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_15)
	    {
	      Index_Taus_Progression_15.at(1)=Index_Taus_Progression_15.at(0);
	      pt_Taus_Progression_15.at(1)=pt_Taus_Progression_15.at(0);
	      Index_Taus_Progression_15.at(0)=iL1Tau;
	      pt_Taus_Progression_15.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_15.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_15)
	    {
	      Index_Taus_Progression_15.at(1)=iL1Tau;
	      pt_Taus_Progression_15.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_16.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_16)
	    {
	      Index_Taus_Progression_16.at(1)=Index_Taus_Progression_16.at(0);
	      pt_Taus_Progression_16.at(1)=pt_Taus_Progression_16.at(0);
	      Index_Taus_Progression_16.at(0)=iL1Tau;
	      pt_Taus_Progression_16.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_16.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_16)
	    {
	      Index_Taus_Progression_16.at(1)=iL1Tau;
	      pt_Taus_Progression_16.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_17.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_17)
	    {
	      Index_Taus_Progression_17.at(1)=Index_Taus_Progression_17.at(0);
	      pt_Taus_Progression_17.at(1)=pt_Taus_Progression_17.at(0);
	      Index_Taus_Progression_17.at(0)=iL1Tau;
	      pt_Taus_Progression_17.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_17.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_17)
	    {
	      Index_Taus_Progression_17.at(1)=iL1Tau;
	      pt_Taus_Progression_17.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_18.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_18)
	    {
	      Index_Taus_Progression_18.at(1)=Index_Taus_Progression_18.at(0);
	      pt_Taus_Progression_18.at(1)=pt_Taus_Progression_18.at(0);
	      Index_Taus_Progression_18.at(0)=iL1Tau;
	      pt_Taus_Progression_18.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_18.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_18)
	    {
	      Index_Taus_Progression_18.at(1)=iL1Tau;
	      pt_Taus_Progression_18.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_19.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_19)
	    {
	      Index_Taus_Progression_19.at(1)=Index_Taus_Progression_19.at(0);
	      pt_Taus_Progression_19.at(1)=pt_Taus_Progression_19.at(0);
	      Index_Taus_Progression_19.at(0)=iL1Tau;
	      pt_Taus_Progression_19.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_19.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_19)
	    {
	      Index_Taus_Progression_19.at(1)=iL1Tau;
	      pt_Taus_Progression_19.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_20.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_20)
	    {
	      Index_Taus_Progression_20.at(1)=Index_Taus_Progression_20.at(0);
	      pt_Taus_Progression_20.at(1)=pt_Taus_Progression_20.at(0);
	      Index_Taus_Progression_20.at(0)=iL1Tau;
	      pt_Taus_Progression_20.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_20.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_20)
	    {
	      Index_Taus_Progression_20.at(1)=iL1Tau;
	      pt_Taus_Progression_20.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_21.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_21)
	    {
	      Index_Taus_Progression_21.at(1)=Index_Taus_Progression_21.at(0);
	      pt_Taus_Progression_21.at(1)=pt_Taus_Progression_21.at(0);
	      Index_Taus_Progression_21.at(0)=iL1Tau;
	      pt_Taus_Progression_21.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_21.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_21)
	    {
	      Index_Taus_Progression_21.at(1)=iL1Tau;
	      pt_Taus_Progression_21.at(1)=in_CalibPt->at(iL1Tau);
	    }

	  if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_22.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_22)
	    {
	      Index_Taus_Progression_22.at(1)=Index_Taus_Progression_22.at(0);
	      pt_Taus_Progression_22.at(1)=pt_Taus_Progression_22.at(0);
	      Index_Taus_Progression_22.at(0)=iL1Tau;
	      pt_Taus_Progression_22.at(0)=in_CalibPt->at(iL1Tau);
	    }
	  else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_22.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_22)
	    {
	      Index_Taus_Progression_22.at(1)=iL1Tau;
	      pt_Taus_Progression_22.at(1)=in_CalibPt->at(iL1Tau);
	    }
	}
      
   
      if(Index_Taus_IsoInf.at(0)>=0 && Index_Taus_IsoInf.at(1)>=0)
	{
           nn_IsoInf++;
	}
      if(Index_Taus_Progression_1.at(0)>=0 && Index_Taus_Progression_1.at(1)>=0)
	{
	  nn_Progression_1++;
        }
      if(Index_Taus_Progression_2.at(0)>=0 && Index_Taus_Progression_2.at(1)>=0)
	{
	  nn_Progression_2++;
	}
      if(Index_Taus_Progression_3.at(0)>=0 && Index_Taus_Progression_3.at(1)>=0)
	{
	  nn_Progression_3++;
	}
      if(Index_Taus_Progression_4.at(0)>=0 && Index_Taus_Progression_4.at(1)>=0)
	{
	 nn_Progression_4++; 
	}
      if(Index_Taus_Progression_5.at(0)>=0 && Index_Taus_Progression_5.at(1)>=0)
	{
	 nn_Progression_5++; 
	}
      if(Index_Taus_Progression_6.at(0)>=0 && Index_Taus_Progression_6.at(1)>=0)
	{
	 nn_Progression_6++; 
	}
      if(Index_Taus_Progression_7.at(0)>=0 && Index_Taus_Progression_7.at(1)>=0)
	{
	 nn_Progression_7++; 
	}
      if(Index_Taus_Progression_8.at(0)>=0 && Index_Taus_Progression_8.at(1)>=0)
	{
	 nn_Progression_8++; 
	}
      if(Index_Taus_Progression_9.at(0)>=0 && Index_Taus_Progression_9.at(1)>=0)
	{
	 nn_Progression_9++; 
	}
      if(Index_Taus_Progression_10.at(0)>=0 && Index_Taus_Progression_10.at(1)>=0)
	{
	 nn_Progression_10++; 
	}
      if(Index_Taus_Progression_11.at(0)>=0 && Index_Taus_Progression_11.at(1)>=0)
	{
	 nn_Progression_11++; 
	}
      if(Index_Taus_Progression_12.at(0)>=0 && Index_Taus_Progression_12.at(1)>=0)
	{
	 nn_Progression_12++; 
	}
      if(Index_Taus_Progression_13.at(0)>=0 && Index_Taus_Progression_13.at(1)>=0)
	{
	 nn_Progression_13++; 
	}
      if(Index_Taus_Progression_14.at(0)>=0 && Index_Taus_Progression_14.at(1)>=0)
	{
	 nn_Progression_14++; 
	}
      if(Index_Taus_Progression_15.at(0)>=0 && Index_Taus_Progression_15.at(1)>=0)
	{
	 nn_Progression_15++;
	}
      if(Index_Taus_Progression_16.at(0)>=0 && Index_Taus_Progression_16.at(1)>=0)
	{
	 nn_Progression_16++; 
	}
      if(Index_Taus_Progression_17.at(0)>=0 && Index_Taus_Progression_17.at(1)>=0)
	{
	 nn_Progression_17++; 
	}
      if(Index_Taus_Progression_18.at(0)>=0 && Index_Taus_Progression_18.at(1)>=0)
	{
	 nn_Progression_18++;
	}
      if(Index_Taus_Progression_19.at(0)>=0 && Index_Taus_Progression_19.at(1)>=0)
	{
	 nn_Progression_19++; 
	}
      if(Index_Taus_Progression_20.at(0)>=0 && Index_Taus_Progression_20.at(1)>=0)
	{
	 nn_Progression_20++; 
	}
      if(Index_Taus_Progression_21.at(0)>=0 && Index_Taus_Progression_21.at(1)>=0)
	{
	 nn_Progression_21++;
	}
      if(Index_Taus_Progression_22.at(0)>=0 && Index_Taus_Progression_22.at(1)>=0)
	{
	 nn_Progression_22++; 
	}
     }//end if
  }//end of loop through entries
 
  //cout << "den" << Denominator << endl;
  //cout << "scale " << scale << endl;
  //cout << "nn IsoInf " << nn_IsoInf << endl;
  //cout << "rate IsoInf " << (nn_IsoInf/Denominator)*scale << endl;
  //cout << "nn 22 " << nn_Progression_22 << endl;
  //cout << "rate 22 " << nn_Progression_22/Denominator*scale << endl; 
  //cout<<"Denominator = "<<Denominator<<endl;

/*
  rate_PU_DiTau_noIso->Fill(iLS,PU_per_LS[iLS],(nn_IsoInf/Denominator)*scale);
  rate_PU_DiTau_Progression_1->Fill(iLS,PU_per_LS[iLS],(nn_Progression_1/Denominator)*scale);
  rate_PU_DiTau_Progression_2->Fill(iLS,PU_per_LS[iLS],(nn_Progression_2/Denominator)*scale);
  rate_PU_DiTau_Progression_3->Fill(iLS,PU_per_LS[iLS],(nn_Progression_3/Denominator)*scale);
  rate_PU_DiTau_Progression_4->Fill(iLS,PU_per_LS[iLS],(nn_Progression_4/Denominator)*scale);
  rate_PU_DiTau_Progression_5->Fill(iLS,PU_per_LS[iLS],(nn_Progression_5/Denominator)*scale);
  rate_PU_DiTau_Progression_6->Fill(iLS,PU_per_LS[iLS],(nn_Progression_6/Denominator)*scale);
  rate_PU_DiTau_Progression_7->Fill(iLS,PU_per_LS[iLS],(nn_Progression_7/Denominator)*scale);
  rate_PU_DiTau_Progression_8->Fill(iLS,PU_per_LS[iLS],(nn_Progression_8/Denominator)*scale);
  rate_PU_DiTau_Progression_9->Fill(iLS,PU_per_LS[iLS],(nn_Progression_9/Denominator)*scale);
  rate_PU_DiTau_Progression_10->Fill(iLS,PU_per_LS[iLS],(nn_Progression_10/Denominator)*scale);
  rate_PU_DiTau_Progression_11->Fill(iLS,PU_per_LS[iLS],(nn_Progression_11/Denominator)*scale);
  rate_PU_DiTau_Progression_12->Fill(iLS,PU_per_LS[iLS],(nn_Progression_12/Denominator)*scale);
  rate_PU_DiTau_Progression_13->Fill(iLS,PU_per_LS[iLS],(nn_Progression_13/Denominator)*scale);
  rate_PU_DiTau_Progression_14->Fill(iLS,PU_per_LS[iLS],(nn_Progression_14/Denominator)*scale);
  rate_PU_DiTau_Progression_15->Fill(iLS,PU_per_LS[iLS],(nn_Progression_15/Denominator)*scale);
  rate_PU_DiTau_Progression_16->Fill(iLS,PU_per_LS[iLS],(nn_Progression_16/Denominator)*scale);
  rate_PU_DiTau_Progression_17->Fill(iLS,PU_per_LS[iLS],(nn_Progression_17/Denominator)*scale);
  rate_PU_DiTau_Progression_18->Fill(iLS,PU_per_LS[iLS],(nn_Progression_18/Denominator)*scale);
  rate_PU_DiTau_Progression_19->Fill(iLS,PU_per_LS[iLS],(nn_Progression_19/Denominator)*scale);
  rate_PU_DiTau_Progression_20->Fill(iLS,PU_per_LS[iLS],(nn_Progression_20/Denominator)*scale);
  rate_PU_DiTau_Progression_21->Fill(iLS,PU_per_LS[iLS],(nn_Progression_21/Denominator)*scale);
  rate_PU_DiTau_Progression_22->Fill(iLS,PU_per_LS[iLS],(nn_Progression_22/Denominator)*scale);
*/
  h2_rate_PU_DiTau_noIso->Fill(iPU,(nn_IsoInf/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_1->Fill(iPU,(nn_Progression_1/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_2->Fill(iPU,(nn_Progression_2/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_3->Fill(iPU,(nn_Progression_3/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_4->Fill(iPU,(nn_Progression_4/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_5->Fill(iPU,(nn_Progression_5/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_6->Fill(iPU,(nn_Progression_6/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_7->Fill(iPU,(nn_Progression_7/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_8->Fill(iPU,(nn_Progression_8/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_9->Fill(iPU,(nn_Progression_9/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_10->Fill(iPU,(nn_Progression_10/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_11->Fill(iPU,(nn_Progression_11/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_12->Fill(iPU,(nn_Progression_12/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_13->Fill(iPU,(nn_Progression_13/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_14->Fill(iPU,(nn_Progression_14/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_15->Fill(iPU,(nn_Progression_15/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_16->Fill(iPU,(nn_Progression_16/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_17->Fill(iPU,(nn_Progression_17/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_18->Fill(iPU,(nn_Progression_18/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_19->Fill(iPU,(nn_Progression_19/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_20->Fill(iPU,(nn_Progression_20/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_21->Fill(iPU,(nn_Progression_21/Denominator)*scale);
  h2_rate_PU_DiTau_Progression_22->Fill(iPU,(nn_Progression_22/Denominator)*scale);

  cout << "PU " << iPU <<  endl;
  cout << "N(all) =  " << Denominator << endl;
  cout << "N(pass_noIso) = " << nn_IsoInf << endl;
  cout << "Rate(noIso) = " << (nn_IsoInf/Denominator)*scale << endl;
  cout << "N(pass_Option22) = " << nn_Progression_22 << endl;
  cout << "Rate(Option22) = " << (nn_Progression_22/Denominator)*scale << endl;
//  cout << "-----" << endl;
  cout << "error 22 " << sqrt( ((1/sqrt(nn_Progression_22))/nn_Progression_22)*((1/sqrt(nn_Progression_22))/nn_Progression_22) + ((1/sqrt(Denominator))/Denominator)*((1/sqrt(Denominator))/Denominator) );
  cout << "----" << endl;
  
 }//end of iPU loop
  
  TFile f("/home/llr/cms/mperez/TauTrigger/CMSSW_9_2_10/src/TauTagAndProbe/TauTagAndProbe/test/Trees_meanparam/histos_rate_PU_Run306091_92X_mean_withh2.root","RECREATE");
/*
  rate_PU_DiTau_noIso->Write();
  rate_PU_DiTau_Progression_1->Write();
  rate_PU_DiTau_Progression_2->Write();
  rate_PU_DiTau_Progression_3->Write();
  rate_PU_DiTau_Progression_4->Write();
  rate_PU_DiTau_Progression_5->Write();
  rate_PU_DiTau_Progression_6->Write();
  rate_PU_DiTau_Progression_7->Write();
  rate_PU_DiTau_Progression_8->Write();
  rate_PU_DiTau_Progression_9->Write();
  rate_PU_DiTau_Progression_10->Write();
  rate_PU_DiTau_Progression_11->Write();
  rate_PU_DiTau_Progression_12->Write();
  rate_PU_DiTau_Progression_13->Write();
  rate_PU_DiTau_Progression_14->Write();
  rate_PU_DiTau_Progression_15->Write();
  rate_PU_DiTau_Progression_16->Write();
  rate_PU_DiTau_Progression_17->Write();
  rate_PU_DiTau_Progression_18->Write();
  rate_PU_DiTau_Progression_19->Write();
  rate_PU_DiTau_Progression_20->Write();
  rate_PU_DiTau_Progression_21->Write();
  rate_PU_DiTau_Progression_22->Write();
 */
  h2_rate_PU_DiTau_noIso->Write();
  h2_rate_PU_DiTau_Progression_1->Write();
  h2_rate_PU_DiTau_Progression_2->Write();
  h2_rate_PU_DiTau_Progression_3->Write();
  h2_rate_PU_DiTau_Progression_4->Write();
  h2_rate_PU_DiTau_Progression_5->Write();
  h2_rate_PU_DiTau_Progression_6->Write();
  h2_rate_PU_DiTau_Progression_7->Write();
  h2_rate_PU_DiTau_Progression_8->Write();
  h2_rate_PU_DiTau_Progression_9->Write();
  h2_rate_PU_DiTau_Progression_10->Write();
  h2_rate_PU_DiTau_Progression_11->Write();
  h2_rate_PU_DiTau_Progression_12->Write();
  h2_rate_PU_DiTau_Progression_13->Write();
  h2_rate_PU_DiTau_Progression_14->Write();
  h2_rate_PU_DiTau_Progression_15->Write();
  h2_rate_PU_DiTau_Progression_16->Write();
  h2_rate_PU_DiTau_Progression_17->Write();
  h2_rate_PU_DiTau_Progression_18->Write();
  h2_rate_PU_DiTau_Progression_19->Write();
  h2_rate_PU_DiTau_Progression_20->Write();
  h2_rate_PU_DiTau_Progression_21->Write();
  h2_rate_PU_DiTau_Progression_22->Write();
   
  return;
}
