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

void EisoPU()
{ 
  //TH1I* Eiso_PU4045 = new TH1I("Eiso_PU4045","Eiso_PU4045",500,0,1000);
  TH1I* Eiso_PU4550 = new TH1I("Eiso_PU4550","Eiso_PU4550",100,0,200);
  TH1I* Eiso_PU5055 = new TH1I("Eiso_PU5055","Eiso_PU5055",100,0,200);
  TH1I* Eiso_PU5560 = new TH1I("Eiso_PU5560","Eiso_PU5560",100,0,200);
  TH1I* Eiso_PU6065 = new TH1I("Eiso_PU6065","Eiso_PU6065",100,0,200);
  TH1I* Eiso_PU6570 = new TH1I("Eiso_PU6570","Eiso_PU6570",100,0,200);
  TH1I* Eiso_PU7075 = new TH1I("Eiso_PU7075","Eiso_PU7075",100,0,200);

  TH2I* Eiso_nTT = new TH2I("Eiso_nTT","Eiso_nTT",100,0,200,100,0,200);
  TH2I* Eiso_compressednTT = new TH2I("Eiso_compressednTT","Eiso_compressednTT",32,0,32,100,0,200);
  TH2I* Eiso_supercompressednTT = new TH2I("Eiso_supercompressednTT","Eiso_supercompressednTT",11,0,11,100,0,200);

  TH2I* Eiso_nTT_PU4550 = new TH2I("Eiso_nTT_PU4550","Eiso_nTT_PU4550",100,0,200,100,0,200);
  TH2I* Eiso_nTT_PU5055 = new TH2I("Eiso_nTT_PU5055","Eiso_nTT_PU5055",100,0,200,100,0,200);
  TH2I* Eiso_nTT_PU5560 = new TH2I("Eiso_nTT_PU5560","Eiso_nTT_PU5560",100,0,200,100,0,200);
  TH2I* Eiso_nTT_PU6065 = new TH2I("Eiso_nTT_PU6065","Eiso_nTT_PU6065",100,0,200,100,0,200);
  TH2I* Eiso_nTT_PU6570 = new TH2I("Eiso_nTT_PU6570","Eiso_nTT_PU6570",100,0,200,100,0,200);
  TH2I* Eiso_nTT_PU7075 = new TH2I("Eiso_nTT_PU7075","Eiso_nTT_PU7075",100,0,200,100,0,200);
  
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
  
  // *** NTUPLES ***
  TString FileName_in = "/home/llr/cms/mperez/TauTrigger/CMSSW_9_2_10/src/TauTagAndProbe/TauTagAndProbe/test/Trees_meanparam/calibratedOutput_Ntuple_ZeroBias_Run306091_306092_92X_mean.root";
  TFile f_in(FileName_in.Data(),"READ");
  TTree* inTree = (TTree*)f_in.Get("outTreeForCalibration"); 
  
  if(!inTree) { cout << "tree not there" << endl;}
 
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
   
  // ***LOOP THROUGH EVENTS***
  for(UInt_t i = 0 ; i < inTree->GetEntries() ; ++i) 
    { 
    inTree->GetEntry(i);
    if(i%10000==0) cout<<"Entry #"<<i<<endl; 
    if(in_RunNumber == 306092) continue;
 
    for(UInt_t iL1Tau = 0 ; iL1Tau < in_CalibPt->size() ; ++iL1Tau){
      
      Eiso_nTT->Fill(in_l1tEmuNTT->at(iL1Tau),in_l1tEmuIsoEt->at(iL1Tau));
      Eiso_compressednTT->Fill(in_compressednTT->at(iL1Tau),in_l1tEmuIsoEt->at(iL1Tau));
      Eiso_supercompressednTT->Fill(in_supercompressednTT->at(iL1Tau),in_l1tEmuIsoEt->at(iL1Tau));

      if(PU_per_LS_306091[in_lumi] >= 45 && PU_per_LS_306091[in_lumi] < 50) {
          Eiso_PU4550->Fill(in_l1tEmuIsoEt->at(iL1Tau));
          Eiso_nTT_PU4550->Fill(in_l1tEmuNTT->at(iL1Tau),in_l1tEmuIsoEt->at(iL1Tau));
      }
      if(PU_per_LS_306091[in_lumi] >= 50 && PU_per_LS_306091[in_lumi] < 55) {
          Eiso_PU5055->Fill(in_l1tEmuIsoEt->at(iL1Tau));
          Eiso_nTT_PU5055->Fill(in_l1tEmuNTT->at(iL1Tau),in_l1tEmuIsoEt->at(iL1Tau));
      }
      if(PU_per_LS_306091[in_lumi] >= 55 && PU_per_LS_306091[in_lumi] < 60) {
          Eiso_PU5560->Fill(in_l1tEmuIsoEt->at(iL1Tau));
          Eiso_nTT_PU5560->Fill(in_l1tEmuNTT->at(iL1Tau),in_l1tEmuIsoEt->at(iL1Tau));
      }
      if(PU_per_LS_306091[in_lumi] >= 60 && PU_per_LS_306091[in_lumi] < 65) {
          Eiso_PU6065->Fill(in_l1tEmuIsoEt->at(iL1Tau));
          Eiso_nTT_PU6065->Fill(in_l1tEmuNTT->at(iL1Tau),in_l1tEmuIsoEt->at(iL1Tau));
      }
      if(PU_per_LS_306091[in_lumi] >= 65 && PU_per_LS_306091[in_lumi] < 70) {
          Eiso_PU6570->Fill(in_l1tEmuIsoEt->at(iL1Tau));
          Eiso_nTT_PU6570->Fill(in_l1tEmuNTT->at(iL1Tau),in_l1tEmuIsoEt->at(iL1Tau));
      }
      if(PU_per_LS_306091[in_lumi] >= 70 && PU_per_LS_306091[in_lumi] < 75) {
          Eiso_PU7075->Fill(in_l1tEmuIsoEt->at(iL1Tau));
          Eiso_nTT_PU7075->Fill(in_l1tEmuNTT->at(iL1Tau),in_l1tEmuIsoEt->at(iL1Tau));
      }
    }
  }
 
  TString FileName_out = "/home/llr/cms/mperez/TauTrigger/CMSSW_9_2_10/src/TauTagAndProbe/TauTagAndProbe/test/Trees_meanparam/Eiso_PU_306091_mean.root";
  TFile f_out(FileName_out.Data(),"RECREATE");

  Eiso_PU4550->Write();
  Eiso_PU5055->Write();
  Eiso_PU5560->Write();
  Eiso_PU6065->Write();
  Eiso_PU6570->Write();
  Eiso_PU7075->Write();

  Eiso_nTT->Write();
  Eiso_compressednTT->Write();
  Eiso_supercompressednTT->Write();

  Eiso_nTT_PU4550->Write();
  Eiso_nTT_PU5055->Write();
  Eiso_nTT_PU5560->Write();
  Eiso_nTT_PU6065->Write();
  Eiso_nTT_PU6570->Write();
  Eiso_nTT_PU7075->Write();
/*
  TCanvas *c1 = new TCanvas("c1","multigraph",700,500);

  //Eiso_PU4045->SetLineColor(2);
  Eiso_PU4550->SetLineColor(3);
  Eiso_PU5055->SetLineColor(4);
  Eiso_PU5560->SetLineColor(5);
  Eiso_PU6065->SetLineColor(6);
  Eiso_PU6570->SetLineColor(7);
  Eiso_PU7075->SetLineColor(8);

  Eiso_PU4045->Draw();
  Eiso_PU4550->Draw("same");
  Eiso_PU5055->Draw("same");
  Eiso_PU5560->Draw("same");
  Eiso_PU6065->Draw("same");
  Eiso_PU6570->Draw("same");
  Eiso_PU7075->Draw("same");

  c1->SaveAs("rates_PU_306091_mean/ratesEiso_PU.png","png");
*/
  return;
}
