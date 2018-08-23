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
#include "ApplyCalibration_newnTT.C"
#include <map>
#include <stdio.h>

using namespace std;

void Rate()
{ 
  //output files 
  FILE *fnoIso = fopen("rates_PU_306091_mean/rate_PU_noIso_run306092_newnTT.txt", "w");
  FILE *fOption1 = fopen("rates_PU_306091_mean/rate_PU_Option1_run306092_newnTT.txt", "w");
  FILE *fOption2 = fopen("rates_PU_306091_mean/rate_PU_Option2_run306092_newnTT.txt", "w");
  FILE *fOption3 = fopen("rates_PU_306091_mean/rate_PU_Option3_run306092_newnTT.txt", "w");
  FILE *fOption4 = fopen("rates_PU_306091_mean/rate_PU_Option4_run306092_newnTT.txt", "w");
  FILE *fOption5 = fopen("rates_PU_306091_mean/rate_PU_Option5_run306092_newnTT.txt", "w");
  FILE *fOption6 = fopen("rates_PU_306091_mean/rate_PU_Option6_run306092_newnTT.txt", "w");
  FILE *fOption7 = fopen("rates_PU_306091_mean/rate_PU_Option7_run306092_newnTT.txt", "w");
  FILE *fOption8 = fopen("rates_PU_306091_mean/rate_PU_Option8_run306092_newnTT.txt", "w");
  FILE *fOption9 = fopen("rates_PU_306091_mean/rate_PU_Option9_run306092_newnTT.txt", "w");
  FILE *fOption10 = fopen("rates_PU_306091_mean/rate_PU_Option10_run306092_newnTT.txt", "w");
  FILE *fOption11 = fopen("rates_PU_306091_mean/rate_PU_Option11_run306092_newnTT.txt", "w");
  FILE *fOption12 = fopen("rates_PU_306091_mean/rate_PU_Option12_run306092_newnTT.txt", "w");
  FILE *fOption13 = fopen("rates_PU_306091_mean/rate_PU_Option13_run306092_newnTT.txt", "w");
  FILE *fOption14 = fopen("rates_PU_306091_mean/rate_PU_Option14_run306092_newnTT.txt", "w");
  FILE *fOption15 = fopen("rates_PU_306091_mean/rate_PU_Option15_run306092_newnTT.txt", "w");
  FILE *fOption16 = fopen("rates_PU_306091_mean/rate_PU_Option16_run306092_newnTT.txt", "w");
  FILE *fOption17 = fopen("rates_PU_306091_mean/rate_PU_Option17_run306092_newnTT.txt", "w");
  FILE *fOption18 = fopen("rates_PU_306091_mean/rate_PU_Option18_run306092_newnTT.txt", "w");
  FILE *fOption19 = fopen("rates_PU_306091_mean/rate_PU_Option19_run306092_newnTT.txt", "w");
  FILE *fOption20 = fopen("rates_PU_306091_mean/rate_PU_Option20_run306092_newnTT.txt", "w");
  FILE *fOption21 = fopen("rates_PU_306091_mean/rate_PU_Option21_run306092_newnTT.txt", "w");
  FILE *fOption22 = fopen("rates_PU_306091_mean/rate_PU_Option22_run306092_newnTT.txt", "w");
  //cout << "debug1" << endl;

  // *** PU PER LS FILE ***
  ifstream PUFile1("PU_LS_run306091.txt");
  std::map<Int_t,Float_t> PU_per_LS_306091;
  std::string str1; 
  while (std::getline(PUFile1, str1))
    { TString temp(str1);
      int pos_space = temp.First(" ");
      TString LS_str(temp,pos_space);
      TString Replacing = LS_str ;
      Replacing += " ";
      temp.ReplaceAll(Replacing.Data(),"");
      TString PU_str = temp;
      std::istringstream ss_LS(LS_str.Data());
      Int_t LS ;
      ss_LS >> LS;
      std::istringstream ss_PU(PU_str.Data());
      Float_t PU ;
      ss_PU >> PU;
      int PU_floor = floor(PU);     
      PU_per_LS_306091.insert(std::pair<Int_t,Int_t>(LS , PU_floor ));
    }
  
  //cout << "debug2" << endl;
 
  ifstream PUFile2("PU_LS_run306092.txt");
  std::map<Int_t,Float_t> PU_per_LS_306092;
  std::string str2;
  while (std::getline(PUFile2, str2))
    { TString temp2(str2);
      int pos_space2 = temp2.First(" ");
      TString LS_str2(temp2,pos_space2);
      TString Replacing2 = LS_str2 ;
      Replacing2 += " ";
      temp2.ReplaceAll(Replacing2.Data(),"");
      TString PU_str2 = temp2;
      std::istringstream ss_LS2(LS_str2.Data());
      Int_t LS2 ;
      ss_LS2 >> LS2;
      std::istringstream ss_PU2(PU_str2.Data());
      Float_t PU2 ;
      ss_PU2 >> PU2;
      int PU_floor2 = floor(PU2);
      PU_per_LS_306092.insert(std::pair<Int_t,Int_t>(LS2 , PU_floor2 ));
    } 

  //cout << "debug2b" << endl;
  
  // *** ISO OPTIONS FILE ***
  std::map<TString,TH3F*> histosIsolation;
  TFile f_Isolation("/home/llr/cms/mperez/TauTrigger/CMSSW_9_2_10/src/TauTagAndProbe/TauTagAndProbe/test/Trees_meanparam/Iso_LUTs_Options_MC_92X_mean_newnTT.root","READ");

  for(UInt_t i = 1 ; i < 23 ; ++i)
    {
      TString CurrentNameHisto = "LUT_Progression_";
      ostringstream convert;
      convert << i;
      CurrentNameHisto += convert.str();
      TH3F* current_Histo = (TH3F*)f_Isolation.Get(CurrentNameHisto.Data());
      histosIsolation.insert(make_pair(CurrentNameHisto,current_Histo));
    }  

  cout << "debug3" << endl;
  
  // *** NTUPLES ***
  TString FileName_in = "/home/llr/cms/mperez/TauTrigger/CMSSW_9_2_10/src/TauTagAndProbe/TauTagAndProbe/test/Trees_meanparam/calibratedOutput_Ntuple_ZeroBias_Run306091_306092_92X_mean_newnTT.root";
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
  
  // run 305310 
  // float nb = 1866.;
  // float thisLumiRun = 1.46E34;
  // float scaleToLumi = 2.00E34;
  // float scale = 0.001*(nb*11245.6)*scaleToLumi/thisLumiRun;
  
  //run 306091 and 306092
  float nb = 1866.;
  //float thisLumiRun = 1.50E34;
  float thisLumiRun = 9.58E33;
  float scaleToLumi = 2.00E34;
  float scale = 0.001*(nb*11245.6)*scaleToLumi/thisLumiRun;

  Float_t weight = 1.;
  
  // ***LOOP THROUGH PU***  
  for (Int_t iPU = 30; iPU < 53; iPU++){
  cout<< "PU = "<< iPU <<endl;
 
  //counters 
  float nn_all = 0; //pass all
  float nn_IsoInf = 0; //pass each option
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
      if(i%10000==0) cout<<"Entry #"<<i<<endl; 
      if(in_RunNumber == 306091) continue;
      if(PU_per_LS_306092[in_lumi] != iPU) continue;
      //if(in_RunNumber == 306091){
      //   if(PU_per_LS_306091[in_lumi] != iPU) continue;
      //}
      //if(in_RunNumber == 306092){
      //   if(PU_per_LS_306092[in_lumi] != iPU) continue;
      //}
      //cout << PU_per_LS[in_lumi] << endl;
      
      ++nn_all;

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
  }//end of loop through entries

  float myPU = iPU+0.5;
  float sigma_myPU = 0.5;

  float rate_noIso = (nn_IsoInf/nn_all)*scale;
  float rate_Option1 = (nn_Progression_1/nn_all)*scale;
  float rate_Option2 = (nn_Progression_2/nn_all)*scale;
  float rate_Option3 = (nn_Progression_3/nn_all)*scale;
  float rate_Option4 = (nn_Progression_4/nn_all)*scale;
  float rate_Option5 = (nn_Progression_5/nn_all)*scale;
  float rate_Option6 = (nn_Progression_6/nn_all)*scale;
  float rate_Option7 = (nn_Progression_7/nn_all)*scale;
  float rate_Option8 = (nn_Progression_8/nn_all)*scale;
  float rate_Option9 = (nn_Progression_9/nn_all)*scale;
  float rate_Option10 = (nn_Progression_10/nn_all)*scale;
  float rate_Option11 = (nn_Progression_11/nn_all)*scale;
  float rate_Option12 = (nn_Progression_12/nn_all)*scale;
  float rate_Option13 = (nn_Progression_13/nn_all)*scale;
  float rate_Option14 = (nn_Progression_14/nn_all)*scale;
  float rate_Option15 = (nn_Progression_15/nn_all)*scale;
  float rate_Option16 = (nn_Progression_16/nn_all)*scale;
  float rate_Option17 = (nn_Progression_17/nn_all)*scale;
  float rate_Option18 = (nn_Progression_18/nn_all)*scale;
  float rate_Option19 = (nn_Progression_19/nn_all)*scale;
  float rate_Option20 = (nn_Progression_20/nn_all)*scale;
  float rate_Option21 = (nn_Progression_21/nn_all)*scale;
  float rate_Option22 = (nn_Progression_22/nn_all)*scale;
  
  float sigma_rate_noIso = (nn_IsoInf/nn_all)*scale*sqrt( (sqrt(nn_IsoInf)/nn_IsoInf)*(sqrt(nn_IsoInf)/nn_IsoInf) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option1 = (nn_Progression_1/nn_all)*scale*sqrt( (sqrt(nn_Progression_1)/nn_Progression_1)*(sqrt(nn_Progression_1)/nn_Progression_1) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option2 = (nn_Progression_2/nn_all)*scale*sqrt( (sqrt(nn_Progression_2)/nn_Progression_2)*(sqrt(nn_Progression_2)/nn_Progression_2) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option3 = (nn_Progression_3/nn_all)*scale*sqrt( (sqrt(nn_Progression_3)/nn_Progression_3)*(sqrt(nn_Progression_3)/nn_Progression_3) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option4 = (nn_Progression_4/nn_all)*scale*sqrt( (sqrt(nn_Progression_4)/nn_Progression_4)*(sqrt(nn_Progression_4)/nn_Progression_4) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option5 = (nn_Progression_5/nn_all)*scale*sqrt( (sqrt(nn_Progression_5)/nn_Progression_5)*(sqrt(nn_Progression_5)/nn_Progression_5) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option6 = (nn_Progression_6/nn_all)*scale*sqrt( (sqrt(nn_Progression_6)/nn_Progression_6)*(sqrt(nn_Progression_6)/nn_Progression_6) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option7 = (nn_Progression_7/nn_all)*scale*sqrt( (sqrt(nn_Progression_7)/nn_Progression_7)*(sqrt(nn_Progression_7)/nn_Progression_7) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option8 = (nn_Progression_8/nn_all)*scale*sqrt( (sqrt(nn_Progression_8)/nn_Progression_8)*(sqrt(nn_Progression_8)/nn_Progression_8) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option9 = (nn_Progression_9/nn_all)*scale*sqrt( (sqrt(nn_Progression_9)/nn_Progression_9)*(sqrt(nn_Progression_9)/nn_Progression_9) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option10 = (nn_Progression_10/nn_all)*scale*sqrt( (sqrt(nn_Progression_10)/nn_Progression_10)*(sqrt(nn_Progression_10)/nn_Progression_10) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option11 = (nn_Progression_11/nn_all)*scale*sqrt( (sqrt(nn_Progression_11)/nn_Progression_11)*(sqrt(nn_Progression_11)/nn_Progression_11) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option12 = (nn_Progression_12/nn_all)*scale*sqrt( (sqrt(nn_Progression_12)/nn_Progression_12)*(sqrt(nn_Progression_12)/nn_Progression_12) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option13 = (nn_Progression_13/nn_all)*scale*sqrt( (sqrt(nn_Progression_13)/nn_Progression_13)*(sqrt(nn_Progression_13)/nn_Progression_13) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option14 = (nn_Progression_14/nn_all)*scale*sqrt( (sqrt(nn_Progression_14)/nn_Progression_14)*(sqrt(nn_Progression_14)/nn_Progression_14) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option15 = (nn_Progression_15/nn_all)*scale*sqrt( (sqrt(nn_Progression_15)/nn_Progression_15)*(sqrt(nn_Progression_15)/nn_Progression_15) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option16 = (nn_Progression_16/nn_all)*scale*sqrt( (sqrt(nn_Progression_16)/nn_Progression_16)*(sqrt(nn_Progression_16)/nn_Progression_16) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option17 = (nn_Progression_17/nn_all)*scale*sqrt( (sqrt(nn_Progression_17)/nn_Progression_17)*(sqrt(nn_Progression_17)/nn_Progression_17) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option18 = (nn_Progression_18/nn_all)*scale*sqrt( (sqrt(nn_Progression_18)/nn_Progression_18)*(sqrt(nn_Progression_18)/nn_Progression_18) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option19 = (nn_Progression_19/nn_all)*scale*sqrt( (sqrt(nn_Progression_19)/nn_Progression_19)*(sqrt(nn_Progression_19)/nn_Progression_19) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option20 = (nn_Progression_20/nn_all)*scale*sqrt( (sqrt(nn_Progression_20)/nn_Progression_20)*(sqrt(nn_Progression_20)/nn_Progression_20) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option21 = (nn_Progression_21/nn_all)*scale*sqrt( (sqrt(nn_Progression_21)/nn_Progression_21)*(sqrt(nn_Progression_21)/nn_Progression_21) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  float sigma_rate_Option22 = (nn_Progression_22/nn_all)*scale*sqrt( (sqrt(nn_Progression_22)/nn_Progression_22)*(sqrt(nn_Progression_22)/nn_Progression_22) + (sqrt(nn_all)/nn_all)*(sqrt(nn_all)/nn_all) );
  
  fprintf(fnoIso, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_noIso, sigma_rate_noIso);
  fprintf(fOption1, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option1, sigma_rate_Option1);
  fprintf(fOption2, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option2, sigma_rate_Option2);
  fprintf(fOption3, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option3, sigma_rate_Option3);
  fprintf(fOption4, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option4, sigma_rate_Option4);
  fprintf(fOption5, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option5, sigma_rate_Option5);
  fprintf(fOption6, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option6, sigma_rate_Option6);
  fprintf(fOption7, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option7, sigma_rate_Option7);
  fprintf(fOption8, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option8, sigma_rate_Option8);
  fprintf(fOption9, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option9, sigma_rate_Option9);
  fprintf(fOption10, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option10, sigma_rate_Option10);
  fprintf(fOption11, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option11, sigma_rate_Option11);
  fprintf(fOption12, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option12, sigma_rate_Option12);
  fprintf(fOption13, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option13, sigma_rate_Option13);
  fprintf(fOption14, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option14, sigma_rate_Option14);
  fprintf(fOption15, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option15, sigma_rate_Option15);
  fprintf(fOption16, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option16, sigma_rate_Option16);
  fprintf(fOption17, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option17, sigma_rate_Option17);
  fprintf(fOption18, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option18, sigma_rate_Option18);
  fprintf(fOption19, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option19, sigma_rate_Option19);
  fprintf(fOption20, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option20, sigma_rate_Option20);
  fprintf(fOption21, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option21, sigma_rate_Option21);
  fprintf(fOption22, "%.2f %.2f %.2f %.2f\n", myPU, sigma_myPU, rate_Option22, sigma_rate_Option22);
 
 }//end of iPU loop
  
  fclose(fnoIso);
  fclose(fOption1);
  fclose(fOption2);
  fclose(fOption3);
  fclose(fOption4);
  fclose(fOption5);
  fclose(fOption6);
  fclose(fOption7);
  fclose(fOption8);
  fclose(fOption9);
  fclose(fOption10);
  fclose(fOption11);
  fclose(fOption12);
  fclose(fOption13);
  fclose(fOption14);
  fclose(fOption15);
  fclose(fOption16);
  fclose(fOption17);
  fclose(fOption18);
  fclose(fOption19);
  fclose(fOption20);
  fclose(fOption21);
  fclose(fOption22); 

  return;
}
