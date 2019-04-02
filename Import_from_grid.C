#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TString.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TF1.h>
#include <iostream>

using namespace std;

void import_from_grid( vector<TString> filein, TString fileout){
	
	TFile* f_new = TFile::Open(fileout);
  	if(f_new!=0){
      cout<<fileout<<" already exists, please delete it before converting again"<<endl;
      return;
	}

	f_new = TFile::Open(fileout,"RECREATE");

	TChain * tree = new TChain("Ntuplizer_noTagAndProbe_multipleTaus/TagAndProbe");
	//TChain * tree = new TChain("Ntuplizer_noTagAndProbe/TagAndProbe");
	//TChain * tree = new TChain("ZeroBias/ZeroBias");

	for (unsigned int ifile = 0; ifile<filein.size(); ifile++){
		tree->Add(filein[ifile]);
	}

	Long64_t nentries = tree->GetEntries();
	cout<<"nentries="<<tree->GetEntries()<<endl;

	// new branches

	TTree* tree_new=tree->GetTree()->CloneTree();

	for (int i=0;i<nentries;i++) {

		if(i%1000==0) cout<<"i="<<i<<endl;

		int entry_ok = tree->GetEntry(i);
		if(entry_ok<0) continue;

		tree_new->Fill();

	}

	f_new->cd();
    tree_new->Write();
    f_new->Close();

	return;

}


void test(){

  //TString indir = "root://polgrid4.in2p3.fr//store/user/cmartinp/2018L1Taus/VBFHToTauTau_M125_13TeV_powheg_pythia8/TagAndProbe_MC_MiniAOD_2018_VBFHtautau/190312_164018/0000/";
  //TString indir = "root://polgrid4.in2p3.fr//store/user/cmartinp/2018L1Taus/VBFHToTauTau_M125_13TeV_powheg_pythia8/TagAndProbe_MC_RAW_2018_VBFHtautau/190312_162351/0000/";
  //TString indir = "root://polgrid4.in2p3.fr//store/user/cmartinp/2018L1Taus/ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8/TagAndProbe_MC_MiniAOD_2018_ttHHtoNonbb_multipletaus/190401_143925/0000/";
  TString indir = "root://polgrid4.in2p3.fr//store/user/cmartinp/2018L1Taus/GluGluToHHTo2B2Tau_node_SM_13TeV-madgraph_correctedcfg/TagAndProbe_MC_MiniAOD_2017_ggFHH2b2tau_multipletaus/190401_143739/0000/";

  vector<TString> infiles;
  for (int j=1; j<39; j++){
  	infiles.push_back(indir+Form("NTuple_37_%i.root",j));
  	cout<<"Importing file "<<j<<endl;
  }

  /*for (int j=1; j<307; j++){
  	infiles.push_back(indir+Form("NTuple_ZeroBias_%i.root",j));
  	cout<<"Importing file "<<j<<endl;
  }*/

  //TString outfile = "/data_CMS/cms/mperez/TauTrigger_data/2018/MC/NTuple_MC_VBFHToTauTau_MiniAOD_RunIIAutumn18_12Mar19.root";
  //TString outfile = "/data_CMS/cms/mperez/TauTrigger_data/2018/MC/NTuple_MC_VBFHToTauTau_RAW_RunII_Autumn18_12Mar19.root";
  //TString outfile = "/data_CMS/cms/mperez/TauTrigger_data/2018/MC/NTuple_MC_ttHnonbb_MiniAOD_RunIIAutumn18_2Apr19.root";
  TString outfile = "/data_CMS/cms/mperez/TauTrigger_data/2018/MC/NTuple_MC_ggFHHTo2B2Tau_MiniAOD_RunIIAutumn18_2Apr19.root";

  import_from_grid(infiles, outfile);

}
