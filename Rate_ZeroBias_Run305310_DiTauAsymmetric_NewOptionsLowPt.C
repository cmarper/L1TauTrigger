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
#include "../ApplyCalibration/ApplyCalibration.C"
#include <map>

using namespace std;

void Rate()
{
  
  std::map<TString,TH3F*> histosIsolation;
  TFile f_Isolation("/home/llr/cms/mperez/TauTrigger/CMSSW_9_2_10/src/TauTagAndProbe/TauTagAndProbe/test/Trees_meanparam/Iso_LUTs_Options_MC_92X_mean_NewOptionsLowPt.root","READ");

  for(UInt_t i = 1 ; i < 27 ; ++i)
    {
      TString CurrentNameHisto = "LUT_Progression_";
      ostringstream convert;
      convert << i;
      CurrentNameHisto += convert.str();
      TH3F* current_Histo = (TH3F*)f_Isolation.Get(CurrentNameHisto.Data());
      histosIsolation.insert(make_pair(CurrentNameHisto,current_Histo));
    }  

  TString FileName_in = "/home/llr/cms/mperez/TauTrigger/CMSSW_9_2_10/src/TauTagAndProbe/TauTagAndProbe/test/Trees_meanparam/calibratedOutput_Ntuple_ZeroBias_Run305310_92X_mean.root";
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


  TH2F* pt_IsoInf_DiTau = new TH2F("pt_IsoInf_DiTau","pt_IsoInf_DiTau",240,0.,240.,240,0.,240.);
  TH2F* pt_DiTau_Progression_1 = new TH2F("pt_DiTau_Progression_1","pt_DiTau_Progression_1",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_2 = new TH2F("pt_DiTau_Progression_2","pt_DiTau_Progression_2",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_3 = new TH2F("pt_DiTau_Progression_3","pt_DiTau_Progression_3",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_4 = new TH2F("pt_DiTau_Progression_4","pt_DiTau_Progression_4",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_5 = new TH2F("pt_DiTau_Progression_5","pt_DiTau_Progression_5",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_6 = new TH2F("pt_DiTau_Progression_6","pt_DiTau_Progression_6",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_7 = new TH2F("pt_DiTau_Progression_7","pt_DiTau_Progression_7",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_8 = new TH2F("pt_DiTau_Progression_8","pt_DiTau_Progression_8",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_9 = new TH2F("pt_DiTau_Progression_9","pt_DiTau_Progression_9",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_10 = new TH2F("pt_DiTau_Progression_10","pt_DiTau_Progression_10",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_11 = new TH2F("pt_DiTau_Progression_11","pt_DiTau_Progression_11",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_12 = new TH2F("pt_DiTau_Progression_12","pt_DiTau_Progression_12",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_13 = new TH2F("pt_DiTau_Progression_13","pt_DiTau_Progression_13",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_14 = new TH2F("pt_DiTau_Progression_14","pt_DiTau_Progression_14",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_15 = new TH2F("pt_DiTau_Progression_15","pt_DiTau_Progression_15",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_16 = new TH2F("pt_DiTau_Progression_16","pt_DiTau_Progression_16",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_17 = new TH2F("pt_DiTau_Progression_17","pt_DiTau_Progression_17",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_18 = new TH2F("pt_DiTau_Progression_18","pt_DiTau_Progression_18",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_19 = new TH2F("pt_DiTau_Progression_19","pt_DiTau_Progression_19",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_20 = new TH2F("pt_DiTau_Progression_20","pt_DiTau_Progression_20",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_21 = new TH2F("pt_DiTau_Progression_21","pt_DiTau_Progression_21",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_22 = new TH2F("pt_DiTau_Progression_22","pt_DiTau_Progression_22",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_23 = new TH2F("pt_DiTau_Progression_23","pt_DiTau_Progression_23",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_24 = new TH2F("pt_DiTau_Progression_24","pt_DiTau_Progression_24",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_25 = new TH2F("pt_DiTau_Progression_25","pt_DiTau_Progression_25",240,0.,240.,240,0.,240.);//
  TH2F* pt_DiTau_Progression_26 = new TH2F("pt_DiTau_Progression_26","pt_DiTau_Progression_26",240,0.,240.,240,0.,240.);//


  Int_t Denominator = 0;

  cout<<"begin loop"<<endl;
  for(UInt_t i = 0 ; i < inTree->GetEntries() ; ++i)
    {
      inTree->GetEntry(i);
      if(i%10000==0) cout<<"Entry #"<<i<<endl; 

      if(in_lumi<60 || in_lumi>455) continue;
      Float_t weight = 1.;

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

      std::vector<Int_t> Index_Taus_Progression_23;
      Index_Taus_Progression_23.push_back(-1); Index_Taus_Progression_23.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_23;
      pt_Taus_Progression_23.push_back(-99.); pt_Taus_Progression_23.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_24;
      Index_Taus_Progression_24.push_back(-1); Index_Taus_Progression_24.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_24;
      pt_Taus_Progression_24.push_back(-99.); pt_Taus_Progression_24.push_back(-99.);

      std::vector<Int_t> Index_Taus_Progression_25;
      Index_Taus_Progression_25.push_back(-1); Index_Taus_Progression_25.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_25;
      pt_Taus_Progression_25.push_back(-99.); pt_Taus_Progression_25.push_back(-99.);
  
      std::vector<Int_t> Index_Taus_Progression_26;
      Index_Taus_Progression_26.push_back(-1); Index_Taus_Progression_26.push_back(-1);
      std::vector<Float_t> pt_Taus_Progression_26;
      pt_Taus_Progression_26.push_back(-99.); pt_Taus_Progression_26.push_back(-99.);
      
      for(UInt_t iL1Tau = 0 ; iL1Tau < in_CalibPt->size() ; ++iL1Tau)
	{ 
          if(fabs(in_l1tEmuEta->at(iL1Tau))>2.1) continue;

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
	 
          TString Result_Progression_23 = "LUT_Progression_23";
          Int_t IsoCut_Progression_23 = histosIsolation[Result_Progression_23]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

          TString Result_Progression_24 = "LUT_Progression_24";
          Int_t IsoCut_Progression_24 = histosIsolation[Result_Progression_24]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

          TString Result_Progression_25 = "LUT_Progression_25";
          Int_t IsoCut_Progression_25 = histosIsolation[Result_Progression_25]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);

          TString Result_Progression_26 = "LUT_Progression_26";
          Int_t IsoCut_Progression_26 = histosIsolation[Result_Progression_26]->GetBinContent(in_compressedieta->at(iL1Tau)+1,in_compressedE->at(iL1Tau)+1,in_compressednTT->at(iL1Tau)+1);
	  
          //DiTau trigger
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

          if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_23.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_23)
            {
              Index_Taus_Progression_23.at(1)=Index_Taus_Progression_23.at(0);
              pt_Taus_Progression_23.at(1)=pt_Taus_Progression_23.at(0);
              Index_Taus_Progression_23.at(0)=iL1Tau;
              pt_Taus_Progression_23.at(0)=in_CalibPt->at(iL1Tau);
            }
          else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_23.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_23)
            {
              Index_Taus_Progression_23.at(1)=iL1Tau;
              pt_Taus_Progression_23.at(1)=in_CalibPt->at(iL1Tau);
            }

          if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_24.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_24)
            {
              Index_Taus_Progression_24.at(1)=Index_Taus_Progression_24.at(0);
              pt_Taus_Progression_24.at(1)=pt_Taus_Progression_24.at(0);
              Index_Taus_Progression_24.at(0)=iL1Tau;
              pt_Taus_Progression_24.at(0)=in_CalibPt->at(iL1Tau);
            }
          else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_24.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_24)
            {
              Index_Taus_Progression_24.at(1)=iL1Tau;
              pt_Taus_Progression_24.at(1)=in_CalibPt->at(iL1Tau);
            }

          if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_25.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_25)
            {
              Index_Taus_Progression_25.at(1)=Index_Taus_Progression_25.at(0);
              pt_Taus_Progression_25.at(1)=pt_Taus_Progression_25.at(0);
              Index_Taus_Progression_25.at(0)=iL1Tau;
              pt_Taus_Progression_25.at(0)=in_CalibPt->at(iL1Tau);
            }
          else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_25.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_25)
            {
              Index_Taus_Progression_25.at(1)=iL1Tau;
              pt_Taus_Progression_25.at(1)=in_CalibPt->at(iL1Tau);
            }

          if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_26.at(0) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_26)
            {
              Index_Taus_Progression_26.at(1)=Index_Taus_Progression_26.at(0);
              pt_Taus_Progression_26.at(1)=pt_Taus_Progression_26.at(0);
              Index_Taus_Progression_26.at(0)=iL1Tau;
              pt_Taus_Progression_26.at(0)=in_CalibPt->at(iL1Tau);
            }
          else if(in_CalibPt->at(iL1Tau)>=pt_Taus_Progression_26.at(1) && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_26)
            {
              Index_Taus_Progression_26.at(1)=iL1Tau;
              pt_Taus_Progression_26.at(1)=in_CalibPt->at(iL1Tau);
            }
}

      if(Index_Taus_IsoInf.at(0)>=0 && Index_Taus_IsoInf.at(1)>=0)
     	{
          pt_IsoInf_DiTau->Fill(pt_Taus_IsoInf.at(0),pt_Taus_IsoInf.at(1),weight);
	}
      if(Index_Taus_Progression_1.at(0)>=0 && Index_Taus_Progression_1.at(1)>=0)
	{
	  pt_DiTau_Progression_1->Fill(pt_Taus_Progression_1.at(0),pt_Taus_Progression_1.at(1),weight);
	}
      if(Index_Taus_Progression_2.at(0)>=0 && Index_Taus_Progression_2.at(1)>=0)
	{
	  pt_DiTau_Progression_2->Fill(pt_Taus_Progression_2.at(0),pt_Taus_Progression_2.at(1),weight);
	}
      if(Index_Taus_Progression_3.at(0)>=0 && Index_Taus_Progression_3.at(1)>=0)
	{
	  pt_DiTau_Progression_3->Fill(pt_Taus_Progression_3.at(0),pt_Taus_Progression_3.at(1),weight);
	}
      if(Index_Taus_Progression_4.at(0)>=0 && Index_Taus_Progression_4.at(1)>=0)
	{
	  pt_DiTau_Progression_4->Fill(pt_Taus_Progression_4.at(0),pt_Taus_Progression_4.at(1),weight);
	}
      if(Index_Taus_Progression_5.at(0)>=0 && Index_Taus_Progression_5.at(1)>=0)
	{
	  pt_DiTau_Progression_5->Fill(pt_Taus_Progression_5.at(0),pt_Taus_Progression_5.at(1),weight);
	}
      if(Index_Taus_Progression_6.at(0)>=0 && Index_Taus_Progression_6.at(1)>=0)
	{
	  pt_DiTau_Progression_6->Fill(pt_Taus_Progression_6.at(0),pt_Taus_Progression_6.at(1),weight);
	}
      if(Index_Taus_Progression_7.at(0)>=0 && Index_Taus_Progression_7.at(1)>=0)
	{
	  pt_DiTau_Progression_7->Fill(pt_Taus_Progression_7.at(0),pt_Taus_Progression_7.at(1),weight);
	}
      if(Index_Taus_Progression_8.at(0)>=0 && Index_Taus_Progression_8.at(1)>=0)
	{
	  pt_DiTau_Progression_8->Fill(pt_Taus_Progression_8.at(0),pt_Taus_Progression_8.at(1),weight);
	}
      if(Index_Taus_Progression_9.at(0)>=0 && Index_Taus_Progression_9.at(1)>=0)
	{
	  pt_DiTau_Progression_9->Fill(pt_Taus_Progression_9.at(0),pt_Taus_Progression_9.at(1),weight);
	}
      if(Index_Taus_Progression_10.at(0)>=0 && Index_Taus_Progression_10.at(1)>=0)
	{
	  pt_DiTau_Progression_10->Fill(pt_Taus_Progression_10.at(0),pt_Taus_Progression_10.at(1),weight);
	}
      if(Index_Taus_Progression_11.at(0)>=0 && Index_Taus_Progression_11.at(1)>=0)
	{
	  pt_DiTau_Progression_11->Fill(pt_Taus_Progression_11.at(0),pt_Taus_Progression_11.at(1),weight);
	}
      if(Index_Taus_Progression_12.at(0)>=0 && Index_Taus_Progression_12.at(1)>=0)
	{
	  pt_DiTau_Progression_12->Fill(pt_Taus_Progression_12.at(0),pt_Taus_Progression_12.at(1),weight);
	}
      if(Index_Taus_Progression_13.at(0)>=0 && Index_Taus_Progression_13.at(1)>=0)
	{
	  pt_DiTau_Progression_13->Fill(pt_Taus_Progression_13.at(0),pt_Taus_Progression_13.at(1),weight);
	}
      if(Index_Taus_Progression_14.at(0)>=0 && Index_Taus_Progression_14.at(1)>=0)
	{
	  pt_DiTau_Progression_14->Fill(pt_Taus_Progression_14.at(0),pt_Taus_Progression_14.at(1),weight);
	}
      if(Index_Taus_Progression_15.at(0)>=0 && Index_Taus_Progression_15.at(1)>=0)
	{
	  pt_DiTau_Progression_15->Fill(pt_Taus_Progression_15.at(0),pt_Taus_Progression_15.at(1),weight);
	}
      if(Index_Taus_Progression_16.at(0)>=0 && Index_Taus_Progression_16.at(1)>=0)
	{
	  pt_DiTau_Progression_16->Fill(pt_Taus_Progression_16.at(0),pt_Taus_Progression_16.at(1),weight);
	}
      if(Index_Taus_Progression_17.at(0)>=0 && Index_Taus_Progression_17.at(1)>=0)
	{
	  pt_DiTau_Progression_17->Fill(pt_Taus_Progression_17.at(0),pt_Taus_Progression_17.at(1),weight);
	}
      if(Index_Taus_Progression_18.at(0)>=0 && Index_Taus_Progression_18.at(1)>=0)
	{
	  pt_DiTau_Progression_18->Fill(pt_Taus_Progression_18.at(0),pt_Taus_Progression_18.at(1),weight);
	}
      if(Index_Taus_Progression_19.at(0)>=0 && Index_Taus_Progression_19.at(1)>=0)
	{
	  pt_DiTau_Progression_19->Fill(pt_Taus_Progression_19.at(0),pt_Taus_Progression_19.at(1),weight);
	}
      if(Index_Taus_Progression_20.at(0)>=0 && Index_Taus_Progression_20.at(1)>=0)
	{
	  pt_DiTau_Progression_20->Fill(pt_Taus_Progression_20.at(0),pt_Taus_Progression_20.at(1),weight);
	}
      if(Index_Taus_Progression_21.at(0)>=0 && Index_Taus_Progression_21.at(1)>=0)
	{
	  pt_DiTau_Progression_21->Fill(pt_Taus_Progression_21.at(0),pt_Taus_Progression_21.at(1),weight);
	}
      if(Index_Taus_Progression_22.at(0)>=0 && Index_Taus_Progression_22.at(1)>=0)
	{
	  pt_DiTau_Progression_22->Fill(pt_Taus_Progression_22.at(0),pt_Taus_Progression_22.at(1),weight);
	}
      if(Index_Taus_Progression_23.at(0)>=0 && Index_Taus_Progression_23.at(1)>=0)
        {
          pt_DiTau_Progression_23->Fill(pt_Taus_Progression_23.at(0),pt_Taus_Progression_23.at(1),weight);
        }
      if(Index_Taus_Progression_24.at(0)>=0 && Index_Taus_Progression_24.at(1)>=0)
        {
          pt_DiTau_Progression_24->Fill(pt_Taus_Progression_24.at(0),pt_Taus_Progression_24.at(1),weight);
        }
      if(Index_Taus_Progression_25.at(0)>=0 && Index_Taus_Progression_25.at(1)>=0)
        {
          pt_DiTau_Progression_25->Fill(pt_Taus_Progression_25.at(0),pt_Taus_Progression_25.at(1),weight);
        }
      if(Index_Taus_Progression_26.at(0)>=0 && Index_Taus_Progression_26.at(1)>=0)
        {
          pt_DiTau_Progression_26->Fill(pt_Taus_Progression_26.at(0),pt_Taus_Progression_26.at(1),weight);
        }
    }

  float nb = 1866.;
  float thisLumiRun = 1.46E34;
  float scaleToLumi = 2.00E34;
  float scale = 0.001*(nb*11245.6)*scaleToLumi/thisLumiRun;

  TH2F* rate_noCut_DiTau = new TH2F("rate_noCut_DiTau","rate_noCut_DiTau",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_1 = new TH2F("rate_DiTau_Progression_1","rate_DiTau_Progression_1",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_2 = new TH2F("rate_DiTau_Progression_2","rate_DiTau_Progression_2",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_3 = new TH2F("rate_DiTau_Progression_3","rate_DiTau_Progression_3",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_4 = new TH2F("rate_DiTau_Progression_4","rate_DiTau_Progression_4",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_5 = new TH2F("rate_DiTau_Progression_5","rate_DiTau_Progression_5",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_6 = new TH2F("rate_DiTau_Progression_6","rate_DiTau_Progression_6",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_7 = new TH2F("rate_DiTau_Progression_7","rate_DiTau_Progression_7",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_8 = new TH2F("rate_DiTau_Progression_8","rate_DiTau_Progression_8",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_9 = new TH2F("rate_DiTau_Progression_9","rate_DiTau_Progression_9",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_10 = new TH2F("rate_DiTau_Progression_10","rate_DiTau_Progression_10",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_11 = new TH2F("rate_DiTau_Progression_11","rate_DiTau_Progression_11",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_12 = new TH2F("rate_DiTau_Progression_12","rate_DiTau_Progression_12",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_13 = new TH2F("rate_DiTau_Progression_13","rate_DiTau_Progression_13",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_14 = new TH2F("rate_DiTau_Progression_14","rate_DiTau_Progression_14",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_15 = new TH2F("rate_DiTau_Progression_15","rate_DiTau_Progression_15",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_16 = new TH2F("rate_DiTau_Progression_16","rate_DiTau_Progression_16",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_17 = new TH2F("rate_DiTau_Progression_17","rate_DiTau_Progression_17",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_18 = new TH2F("rate_DiTau_Progression_18","rate_DiTau_Progression_18",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_19 = new TH2F("rate_DiTau_Progression_19","rate_DiTau_Progression_19",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_20 = new TH2F("rate_DiTau_Progression_20","rate_DiTau_Progression_20",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_21 = new TH2F("rate_DiTau_Progression_21","rate_DiTau_Progression_21",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_22 = new TH2F("rate_DiTau_Progression_22","rate_DiTau_Progression_22",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_23 = new TH2F("rate_DiTau_Progression_23","rate_DiTau_Progression_23",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_24 = new TH2F("rate_DiTau_Progression_24","rate_DiTau_Progression_24",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_25 = new TH2F("rate_DiTau_Progression_25","rate_DiTau_Progression_25",240,0.,240.,240,0.,240.);
  TH2F* rate_DiTau_Progression_26 = new TH2F("rate_DiTau_Progression_26","rate_DiTau_Progression_26",240,0.,240.,240,0.,240.);

  for(UInt_t i = 0 ; i < 241 ; ++i) //leading tau loop
    {
      for(UInt_t j = 0 ; j < 241 ; ++j) //subleading tau loop
      {   
          rate_noCut_DiTau->SetBinContent(i+1,j+1,pt_IsoInf_DiTau->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_1->SetBinContent(i+1,j+1,pt_DiTau_Progression_1->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_2->SetBinContent(i+1,j+1,pt_DiTau_Progression_2->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_3->SetBinContent(i+1,j+1,pt_DiTau_Progression_3->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_4->SetBinContent(i+1,j+1,pt_DiTau_Progression_4->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_5->SetBinContent(i+1,j+1,pt_DiTau_Progression_5->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_6->SetBinContent(i+1,j+1,pt_DiTau_Progression_6->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_7->SetBinContent(i+1,j+1,pt_DiTau_Progression_7->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_8->SetBinContent(i+1,j+1,pt_DiTau_Progression_8->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_9->SetBinContent(i+1,j+1,pt_DiTau_Progression_9->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_10->SetBinContent(i+1,j+1,pt_DiTau_Progression_10->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_11->SetBinContent(i+1,j+1,pt_DiTau_Progression_11->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_12->SetBinContent(i+1,j+1,pt_DiTau_Progression_12->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_13->SetBinContent(i+1,j+1,pt_DiTau_Progression_13->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_14->SetBinContent(i+1,j+1,pt_DiTau_Progression_14->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_15->SetBinContent(i+1,j+1,pt_DiTau_Progression_15->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_16->SetBinContent(i+1,j+1,pt_DiTau_Progression_16->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_17->SetBinContent(i+1,j+1,pt_DiTau_Progression_17->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_18->SetBinContent(i+1,j+1,pt_DiTau_Progression_18->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_19->SetBinContent(i+1,j+1,pt_DiTau_Progression_19->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_20->SetBinContent(i+1,j+1,pt_DiTau_Progression_20->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_21->SetBinContent(i+1,j+1,pt_DiTau_Progression_21->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_22->SetBinContent(i+1,j+1,pt_DiTau_Progression_22->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_23->SetBinContent(i+1,j+1,pt_DiTau_Progression_23->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_24->SetBinContent(i+1,j+1,pt_DiTau_Progression_24->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_25->SetBinContent(i+1,j+1,pt_DiTau_Progression_25->Integral(i+1,241,j+1,241)/Denominator*scale);
          rate_DiTau_Progression_26->SetBinContent(i+1,j+1,pt_DiTau_Progression_26->Integral(i+1,241,j+1,241)/Denominator*scale);
      }
    }

  TFile f("/home/llr/cms/mperez/TauTrigger/CMSSW_9_2_10/src/TauTagAndProbe/TauTagAndProbe/test/Trees_meanparam/histos_rate_DiTauasymetric_Run305310_92X_mean_NewOptionsLowPt.root","RECREATE");
  // TFile f("histos_rate_new_MC_NewCompression_extendedRange_Layer1_2016_Conditions_Thomas_nTT_NewLayer1_Option5_277069_OlivierFlatWP_SK1616.root","RECREATE");

  pt_IsoInf_DiTau->Write();
  pt_DiTau_Progression_1->Write();
  pt_DiTau_Progression_2->Write();
  pt_DiTau_Progression_4->Write();
  pt_DiTau_Progression_5->Write();
  pt_DiTau_Progression_6->Write();
  pt_DiTau_Progression_7->Write();
  pt_DiTau_Progression_8->Write();
  pt_DiTau_Progression_9->Write();
  pt_DiTau_Progression_10->Write();
  pt_DiTau_Progression_11->Write();
  pt_DiTau_Progression_12->Write();
  pt_DiTau_Progression_13->Write();
  pt_DiTau_Progression_14->Write();
  pt_DiTau_Progression_15->Write();
  pt_DiTau_Progression_16->Write();
  pt_DiTau_Progression_17->Write();
  pt_DiTau_Progression_18->Write();
  pt_DiTau_Progression_19->Write();
  pt_DiTau_Progression_20->Write();
  pt_DiTau_Progression_21->Write();
  pt_DiTau_Progression_22->Write();  
  pt_DiTau_Progression_23->Write();
  pt_DiTau_Progression_24->Write();
  pt_DiTau_Progression_25->Write();
  pt_DiTau_Progression_26->Write();
  
  rate_noCut_DiTau->Write();
  rate_DiTau_Progression_1->Write();
  rate_DiTau_Progression_2->Write();
  rate_DiTau_Progression_3->Write();
  rate_DiTau_Progression_4->Write();
  rate_DiTau_Progression_5->Write();
  rate_DiTau_Progression_6->Write();
  rate_DiTau_Progression_7->Write();
  rate_DiTau_Progression_8->Write();
  rate_DiTau_Progression_9->Write();
  rate_DiTau_Progression_10->Write();
  rate_DiTau_Progression_11->Write();
  rate_DiTau_Progression_12->Write();
  rate_DiTau_Progression_13->Write();
  rate_DiTau_Progression_14->Write();
  rate_DiTau_Progression_15->Write();
  rate_DiTau_Progression_16->Write();
  rate_DiTau_Progression_17->Write();
  rate_DiTau_Progression_18->Write();
  rate_DiTau_Progression_19->Write();
  rate_DiTau_Progression_20->Write();
  rate_DiTau_Progression_21->Write();
  rate_DiTau_Progression_22->Write();
  rate_DiTau_Progression_23->Write();
  rate_DiTau_Progression_24->Write();
  rate_DiTau_Progression_25->Write();
  rate_DiTau_Progression_26->Write();

  return;
}
