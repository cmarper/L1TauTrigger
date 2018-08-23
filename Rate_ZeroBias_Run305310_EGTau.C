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
#include <map>

using namespace std;

void Rate()
{
  std::map<TString,TH3F*> histosIsolation;
  TFile f_Isolation("/home/llr/cms/mperez/TauTrigger/CMSSW_9_2_10/src/TauTagAndProbe/TauTagAndProbe/test/Trees_modeparam/Iso_LUTs_Options_MC_92X_mode.root","READ");

  for(UInt_t i = 0 ; i < 101 ; ++i)
  {
    TString CurrentNameHisto = "LUT_WP";
    ostringstream convert;
    convert << i;
    CurrentNameHisto += convert.str();
    TH3F* current_Histo = (TH3F*)f_Isolation.Get(CurrentNameHisto.Data());
    histosIsolation.insert(make_pair(CurrentNameHisto,current_Histo));
  }  

  for(UInt_t i = 1 ; i < 23 ; ++i)
  {
    TString CurrentNameHisto = "LUT_Progression_";
    ostringstream convert;
    convert << i;
    CurrentNameHisto += convert.str();
    TH3F* current_Histo = (TH3F*)f_Isolation.Get(CurrentNameHisto.Data());
    histosIsolation.insert(make_pair(CurrentNameHisto,current_Histo));
  }  

  TString FileName_in = "/home/llr/cms/mperez/TauTrigger/CMSSW_9_2_10/src/TauTagAndProbe/TauTagAndProbe/test/Trees_modeparam/calibratedOutput_Ntuple_ZeroBias_Run305310_92X_mode_EGTau.root";
  TFile f_in(FileName_in.Data(),"READ");
  TTree* inTree = (TTree*)f_in.Get("outTreeForCalibration");

  Int_t           in_EventNumber =  0;
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
  vector<bool>    *in_L1Tau_PassShapeVeto = 0;
  vector<float>   *in_l1tEGPt = 0;
  vector<float>   *in_l1tEGEta = 0;
  vector<float>   *in_l1tEGPhi = 0;
  vector<int>     *in_l1tEGQual = 0;
  vector<int>     *in_l1tEGIso = 0;
 
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
  inTree->SetBranchAddress("l1tEGPt", &in_l1tEGPt);
  inTree->SetBranchAddress("l1tEGEta", &in_l1tEGEta);
  inTree->SetBranchAddress("l1tEGPhi", &in_l1tEGPhi);
  inTree->SetBranchAddress("l1tEGQual", &in_l1tEGQual);
  inTree->SetBranchAddress("l1tEGIso", &in_l1tEGIso);

  TH1F* pt_IsoInf = new TH1F("pt_IsoInf","pt_IsoInf",240,0.,240.);
  TH1F* pt_Progression_1 = new TH1F("pt_Progression_1","pt_Progression_1",240,0.,240.);
  TH1F* pt_Progression_2 = new TH1F("pt_Progression_2","pt_Progression_2",240,0.,240.);
  TH1F* pt_Progression_3 = new TH1F("pt_Progression_3","pt_Progression_3",240,0.,240.);
  TH1F* pt_Progression_4 = new TH1F("pt_Progression_4","pt_Progression_4",240,0.,240.);
  TH1F* pt_Progression_5 = new TH1F("pt_Progression_5","pt_Progression_5",240,0.,240.);
  TH1F* pt_Progression_6 = new TH1F("pt_Progression_6","pt_Progression_6",240,0.,240.);
  TH1F* pt_Progression_7 = new TH1F("pt_Progression_7","pt_Progression_7",240,0.,240.);
  TH1F* pt_Progression_8 = new TH1F("pt_Progression_8","pt_Progression_8",240,0.,240.);
  TH1F* pt_Progression_9 = new TH1F("pt_Progression_9","pt_Progression_9",240,0.,240.);
  TH1F* pt_Progression_10 = new TH1F("pt_Progression_10","pt_Progression_10",240,0.,240.);
  TH1F* pt_Progression_11 = new TH1F("pt_Progression_11","pt_Progression_11",240,0.,240.);
  TH1F* pt_Progression_12 = new TH1F("pt_Progression_12","pt_Progression_12",240,0.,240.);
  TH1F* pt_Progression_13 = new TH1F("pt_Progression_13","pt_Progression_13",240,0.,240.);
  TH1F* pt_Progression_14 = new TH1F("pt_Progression_14","pt_Progression_14",240,0.,240.);
  TH1F* pt_Progression_15 = new TH1F("pt_Progression_15","pt_Progression_15",240,0.,240.);
  TH1F* pt_Progression_16 = new TH1F("pt_Progression_16","pt_Progression_16",240,0.,240.);
  TH1F* pt_Progression_17 = new TH1F("pt_Progression_17","pt_Progression_17",240,0.,240.);
  TH1F* pt_Progression_18 = new TH1F("pt_Progression_18","pt_Progression_18",240,0.,240.);
  TH1F* pt_Progression_19 = new TH1F("pt_Progression_19","pt_Progression_19",240,0.,240.);
  TH1F* pt_Progression_20 = new TH1F("pt_Progression_20","pt_Progression_20",240,0.,240.);
  TH1F* pt_Progression_21 = new TH1F("pt_Progression_21","pt_Progression_21",240,0.,240.);
  TH1F* pt_Progression_22 = new TH1F("pt_Progression_22","pt_Progression_22",240,0.,240.);
  
  Int_t Denominator = 0;

  cout<<"begin loop"<<endl;

  // loop through events
  for(UInt_t i = 0 ; i < inTree->GetEntries() ; ++i)  
    {
      inTree->GetEntry(i);
      if(i%10000==0) cout<<"Entry #"<<i<<endl; 
      // cout << "Entry # " << i << endl;

      //if(in_lumi<45 || in_lumi>155) continue; //run306091
      if(in_lumi<60 || in_lumi>455) continue; //run305310

      Float_t weight = 1.;
      ++Denominator;

      TLorentzVector HighestTauPt_noCut;
      TLorentzVector HighestTauPt_Progression_1;
      TLorentzVector HighestTauPt_Progression_2;
      TLorentzVector HighestTauPt_Progression_3;
      TLorentzVector HighestTauPt_Progression_4;
      TLorentzVector HighestTauPt_Progression_5;
      TLorentzVector HighestTauPt_Progression_6;
      TLorentzVector HighestTauPt_Progression_7;
      TLorentzVector HighestTauPt_Progression_8;
      TLorentzVector HighestTauPt_Progression_9;
      TLorentzVector HighestTauPt_Progression_10;
      TLorentzVector HighestTauPt_Progression_11;
      TLorentzVector HighestTauPt_Progression_12;
      TLorentzVector HighestTauPt_Progression_13;
      TLorentzVector HighestTauPt_Progression_14;
      TLorentzVector HighestTauPt_Progression_15;
      TLorentzVector HighestTauPt_Progression_16;
      TLorentzVector HighestTauPt_Progression_17;
      TLorentzVector HighestTauPt_Progression_18;
      TLorentzVector HighestTauPt_Progression_19;
      TLorentzVector HighestTauPt_Progression_20;
      TLorentzVector HighestTauPt_Progression_21;
      TLorentzVector HighestTauPt_Progression_22;

      //loop over taus    
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
  
	  for(UInt_t iL1EG = 0 ; iL1EG < in_l1tEGPt->size() ; ++iL1EG)
	    {
	      if(fabs(in_l1tEGEta->at(iL1EG))>2.1) continue; // eta restriction
	      if(in_l1tEGPt->at(iL1EG)<22) continue; // pT cut
	      if((in_l1tEGIso->at(iL1EG)>>1&1)==0) continue; //loose isolation	

	      TLorentzVector L1Tau;
	      L1Tau.SetPtEtaPhiM(in_CalibPt->at(iL1Tau),in_l1tEmuEta->at(iL1Tau),in_l1tEmuPhi->at(iL1Tau),0.);
	      TLorentzVector L1EG;
	      L1EG.SetPtEtaPhiM(in_l1tEGPt->at(iL1EG),in_l1tEGEta->at(iL1EG),in_l1tEGPhi->at(iL1EG),0.);
	      
	      if(L1EG.DeltaR(L1Tau)<0.3) continue;

	      if(L1Tau.Pt()>HighestTauPt_noCut.Pt()) HighestTauPt_noCut=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_1.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_1) HighestTauPt_Progression_1=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_2.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_2) HighestTauPt_Progression_2=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_3.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_3) HighestTauPt_Progression_3=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_4.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_4) HighestTauPt_Progression_4=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_5.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_5) HighestTauPt_Progression_5=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_6.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_6) HighestTauPt_Progression_6=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_7.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_7) HighestTauPt_Progression_7=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_8.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_8) HighestTauPt_Progression_8=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_9.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_9) HighestTauPt_Progression_9=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_10.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_10) HighestTauPt_Progression_10=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_11.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_11) HighestTauPt_Progression_11=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_12.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_12) HighestTauPt_Progression_12=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_13.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_13) HighestTauPt_Progression_13=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_14.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_14) HighestTauPt_Progression_14=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_15.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_15) HighestTauPt_Progression_15=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_16.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_16) HighestTauPt_Progression_16=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_17.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_17) HighestTauPt_Progression_17=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_18.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_18) HighestTauPt_Progression_18=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_19.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_19) HighestTauPt_Progression_19=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_20.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_20) HighestTauPt_Progression_20=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_21.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_21) HighestTauPt_Progression_21=L1Tau;
	      if(L1Tau.Pt()>HighestTauPt_Progression_22.Pt() && in_l1tEmuIsoEt->at(iL1Tau)<=IsoCut_Progression_22) HighestTauPt_Progression_22=L1Tau;	      
	    }
	}    

      if(HighestTauPt_noCut.Pt()>0)          pt_IsoInf->Fill(HighestTauPt_noCut.Pt());
      if(HighestTauPt_Progression_1.Pt()>0)  pt_Progression_1->Fill(HighestTauPt_Progression_1.Pt());
      if(HighestTauPt_Progression_2.Pt()>0)  pt_Progression_2->Fill(HighestTauPt_Progression_2.Pt());
      if(HighestTauPt_Progression_3.Pt()>0)  pt_Progression_3->Fill(HighestTauPt_Progression_3.Pt());
      if(HighestTauPt_Progression_4.Pt()>0)  pt_Progression_4->Fill(HighestTauPt_Progression_4.Pt());
      if(HighestTauPt_Progression_5.Pt()>0)  pt_Progression_5->Fill(HighestTauPt_Progression_5.Pt());
      if(HighestTauPt_Progression_6.Pt()>0)  pt_Progression_6->Fill(HighestTauPt_Progression_6.Pt());
      if(HighestTauPt_Progression_7.Pt()>0)  pt_Progression_7->Fill(HighestTauPt_Progression_7.Pt());
      if(HighestTauPt_Progression_8.Pt()>0)  pt_Progression_8->Fill(HighestTauPt_Progression_8.Pt());
      if(HighestTauPt_Progression_9.Pt()>0)  pt_Progression_9->Fill(HighestTauPt_Progression_9.Pt());
      if(HighestTauPt_Progression_10.Pt()>0) pt_Progression_10->Fill(HighestTauPt_Progression_10.Pt());
      if(HighestTauPt_Progression_11.Pt()>0) pt_Progression_11->Fill(HighestTauPt_Progression_11.Pt());
      if(HighestTauPt_Progression_12.Pt()>0) pt_Progression_12->Fill(HighestTauPt_Progression_12.Pt());
      if(HighestTauPt_Progression_13.Pt()>0) pt_Progression_13->Fill(HighestTauPt_Progression_13.Pt());
      if(HighestTauPt_Progression_14.Pt()>0) pt_Progression_14->Fill(HighestTauPt_Progression_14.Pt());
      if(HighestTauPt_Progression_15.Pt()>0) pt_Progression_15->Fill(HighestTauPt_Progression_15.Pt());
      if(HighestTauPt_Progression_16.Pt()>0) pt_Progression_16->Fill(HighestTauPt_Progression_16.Pt());
      if(HighestTauPt_Progression_17.Pt()>0) pt_Progression_17->Fill(HighestTauPt_Progression_17.Pt());
      if(HighestTauPt_Progression_18.Pt()>0) pt_Progression_18->Fill(HighestTauPt_Progression_18.Pt());
      if(HighestTauPt_Progression_19.Pt()>0) pt_Progression_19->Fill(HighestTauPt_Progression_19.Pt());
      if(HighestTauPt_Progression_20.Pt()>0) pt_Progression_20->Fill(HighestTauPt_Progression_20.Pt());
      if(HighestTauPt_Progression_21.Pt()>0) pt_Progression_21->Fill(HighestTauPt_Progression_21.Pt());
      if(HighestTauPt_Progression_22.Pt()>0) pt_Progression_22->Fill(HighestTauPt_Progression_22.Pt());
    } // end loop over events

float nb = 1866.;
//float thisLumiRun = 1.80E34; //run306091
float thisLumiRun = 1.46E34; //run 305310
float scaleToLumi = 2.00E34;
float scale = 0.001*(nb*11245.6)*scaleToLumi/thisLumiRun;

cout<<"Denominator = "<<Denominator<<endl;

TH1F* rate_noCut = new TH1F("rate_noCut","rate_noCut",240,0.,240.);
TH1F* rate_Progression_1 = new TH1F("rate_Progression_1","rate_Progression_1",240,0.,240.);
TH1F* rate_Progression_2 = new TH1F("rate_Progression_2","rate_Progression_2",240,0.,240.);
TH1F* rate_Progression_3 = new TH1F("rate_Progression_3","rate_Progression_3",240,0.,240.);
TH1F* rate_Progression_4 = new TH1F("rate_Progression_4","rate_Progression_4",240,0.,240.);
TH1F* rate_Progression_5 = new TH1F("rate_Progression_5","rate_Progression_5",240,0.,240.);
TH1F* rate_Progression_6 = new TH1F("rate_Progression_6","rate_Progression_6",240,0.,240.);
TH1F* rate_Progression_7 = new TH1F("rate_Progression_7","rate_Progression_7",240,0.,240.);
TH1F* rate_Progression_8 = new TH1F("rate_Progression_8","rate_Progression_8",240,0.,240.);
TH1F* rate_Progression_9 = new TH1F("rate_Progression_9","rate_Progression_9",240,0.,240.);
TH1F* rate_Progression_10 = new TH1F("rate_Progression_10","rate_Progression_10",240,0.,240.);
TH1F* rate_Progression_11 = new TH1F("rate_Progression_11","rate_Progression_11",240,0.,240.);
TH1F* rate_Progression_12 = new TH1F("rate_Progression_12","rate_Progression_12",240,0.,240.);
TH1F* rate_Progression_13 = new TH1F("rate_Progression_13","rate_Progression_13",240,0.,240.);
TH1F* rate_Progression_14 = new TH1F("rate_Progression_14","rate_Progression_14",240,0.,240.);
TH1F* rate_Progression_15 = new TH1F("rate_Progression_15","rate_Progression_15",240,0.,240.);
TH1F* rate_Progression_16 = new TH1F("rate_Progression_16","rate_Progression_16",240,0.,240.);
TH1F* rate_Progression_17 = new TH1F("rate_Progression_17","rate_Progression_17",240,0.,240.);
TH1F* rate_Progression_18 = new TH1F("rate_Progression_18","rate_Progression_18",240,0.,240.);
TH1F* rate_Progression_19 = new TH1F("rate_Progression_19","rate_Progression_19",240,0.,240.);
TH1F* rate_Progression_20 = new TH1F("rate_Progression_20","rate_Progression_20",240,0.,240.);
TH1F* rate_Progression_21 = new TH1F("rate_Progression_21","rate_Progression_21",240,0.,240.);
TH1F* rate_Progression_22 = new TH1F("rate_Progression_22","rate_Progression_22",240,0.,240.);

for(UInt_t i = 0 ; i < 241 ; ++i)
  {
    rate_noCut->SetBinContent(i+1,pt_IsoInf->Integral(i+1,241)/Denominator*scale);
    rate_Progression_1->SetBinContent(i+1,pt_Progression_1->Integral(i+1,241)/Denominator*scale);
    rate_Progression_2->SetBinContent(i+1,pt_Progression_2->Integral(i+1,241)/Denominator*scale);
    rate_Progression_3->SetBinContent(i+1,pt_Progression_3->Integral(i+1,241)/Denominator*scale);
    rate_Progression_4->SetBinContent(i+1,pt_Progression_4->Integral(i+1,241)/Denominator*scale);
    rate_Progression_5->SetBinContent(i+1,pt_Progression_5->Integral(i+1,241)/Denominator*scale);
    rate_Progression_6->SetBinContent(i+1,pt_Progression_6->Integral(i+1,241)/Denominator*scale);
    rate_Progression_7->SetBinContent(i+1,pt_Progression_7->Integral(i+1,241)/Denominator*scale);
    rate_Progression_8->SetBinContent(i+1,pt_Progression_8->Integral(i+1,241)/Denominator*scale);
    rate_Progression_9->SetBinContent(i+1,pt_Progression_9->Integral(i+1,241)/Denominator*scale);
    rate_Progression_10->SetBinContent(i+1,pt_Progression_10->Integral(i+1,241)/Denominator*scale);
    rate_Progression_11->SetBinContent(i+1,pt_Progression_11->Integral(i+1,241)/Denominator*scale);
    rate_Progression_12->SetBinContent(i+1,pt_Progression_12->Integral(i+1,241)/Denominator*scale);
    rate_Progression_13->SetBinContent(i+1,pt_Progression_13->Integral(i+1,241)/Denominator*scale);
    rate_Progression_14->SetBinContent(i+1,pt_Progression_14->Integral(i+1,241)/Denominator*scale);
    rate_Progression_15->SetBinContent(i+1,pt_Progression_15->Integral(i+1,241)/Denominator*scale);
    rate_Progression_16->SetBinContent(i+1,pt_Progression_16->Integral(i+1,241)/Denominator*scale);
    rate_Progression_17->SetBinContent(i+1,pt_Progression_17->Integral(i+1,241)/Denominator*scale);
    rate_Progression_18->SetBinContent(i+1,pt_Progression_18->Integral(i+1,241)/Denominator*scale);
    rate_Progression_19->SetBinContent(i+1,pt_Progression_19->Integral(i+1,241)/Denominator*scale);
    rate_Progression_20->SetBinContent(i+1,pt_Progression_20->Integral(i+1,241)/Denominator*scale);
    rate_Progression_21->SetBinContent(i+1,pt_Progression_21->Integral(i+1,241)/Denominator*scale);
    rate_Progression_22->SetBinContent(i+1,pt_Progression_22->Integral(i+1,241)/Denominator*scale);  
  }

  TFile f("./Trees_modeparam/histos_rate_Run305310_92X_mode_EGTau.root","RECREATE");

  pt_IsoInf->Write();
  pt_Progression_1->Write();
  pt_Progression_2->Write();
  pt_Progression_3->Write();
  pt_Progression_4->Write();
  pt_Progression_5->Write();
  pt_Progression_6->Write();
  pt_Progression_7->Write();
  pt_Progression_8->Write();
  pt_Progression_9->Write();
  pt_Progression_10->Write();
  pt_Progression_11->Write();
  pt_Progression_12->Write();
  pt_Progression_13->Write();
  pt_Progression_14->Write();
  pt_Progression_15->Write();
  pt_Progression_16->Write();
  pt_Progression_17->Write();
  pt_Progression_18->Write();
  pt_Progression_19->Write();
  pt_Progression_20->Write();
  pt_Progression_21->Write();
  pt_Progression_22->Write();

  rate_noCut->Write(); 
  rate_Progression_1->Write();  
  rate_Progression_2->Write();  
  rate_Progression_3->Write();  
  rate_Progression_4->Write();  
  rate_Progression_5->Write();  
  rate_Progression_6->Write();  
  rate_Progression_7->Write();  
  rate_Progression_8->Write();  
  rate_Progression_9->Write();  
  rate_Progression_10->Write();  
  rate_Progression_11->Write();  
  rate_Progression_12->Write();  
  rate_Progression_13->Write();  
  rate_Progression_14->Write();  
  rate_Progression_15->Write();  
  rate_Progression_16->Write();  
  rate_Progression_17->Write();  
  rate_Progression_18->Write();  
  rate_Progression_19->Write();  
  rate_Progression_20->Write();  
  rate_Progression_21->Write();  
  rate_Progression_22->Write();  

  return;
}
