void PlotJets() {

    gROOT->Reset();
    TString file_name = "/home/llr/cms/mperez/TauTrigger/CMSSW_9_2_10/src/TauTagAndProbe/TauTagAndProbe/test/2018MC/NTuple_MC_VBFHToTauTau_MiniAOD_180815.root";
    TFile *myFile = TFile::Open(file_name);
    TTree *myTree = (TTree*)myFile->Get("Ntuplizer_noTagAndProbe/TagAndProbe");

    TFile * myoutput = TFile::Open("myoutput.root","RECREATE");
 
    TH1F* hEt_MC_pt_20_25_endcap    = new TH1F ("hEt_MC_pt_20_25_endcap", "hEt_MC_pt_20_25_endcap", 90, 0, 3);
    TH1F* hEt_MC_pt_25_30_endcap    = new TH1F ("hEt_MC_pt_25_30_endcap", "hEt_MC_pt_25_30_endcap", 90, 0, 3);
    TH1F* hEt_MC_pt_30_35_endcap    = new TH1F ("hEt_MC_pt_30_35_endcap", "hEt_MC_pt_30_35_endcap", 90, 0, 3);
    TH1F* hEt_MC_pt_35_40_endcap    = new TH1F ("hEt_MC_pt_35_40_endcap", "hEt_MC_pt_35_40_endcap", 90, 0, 3);
    TH1F* hEt_MC_pt_40_45_endcap    = new TH1F ("hEt_MC_pt_40_45_endcap", "hEt_MC_pt_40_45_endcap", 90, 0, 3);
    TH1F* hEt_MC_pt_45_50_endcap    = new TH1F ("hEt_MC_pt_45_50_endcap", "hEt_MC_pt_45_50_endcap", 90, 0, 3);
    TH1F* hEt_MC_pt_50_60_endcap    = new TH1F ("hEt_MC_pt_50_60_endcap", "hEt_MC_pt_50_60_endcap", 90, 0, 3);
    TH1F* hEt_MC_pt_60_80_endcap    = new TH1F ("hEt_MC_pt_60_80_endcap", "hEt_MC_pt_60_80_endcap", 90, 0, 3);
    TH1F* hEt_MC_pt_80_120_endcap   = new TH1F ("hEt_MC_pt_80_120_endcap", "hEt_MC_pt_80_120_endcap", 90, 0, 3);
    TH1F* hEt_MC_pt_120_180_endcap  = new TH1F ("hEt_MC_pt_120_180_endcap", "hEt_MC_pt_120_180_endcap", 90, 0, 3);
    TH1F* hEt_MC_pt_180_255_endcap  = new TH1F ("hEt_MC_pt_180_255_endcap", "hEt_MC_pt_180_255_endcap", 90, 0, 3);
    TH1F* hEt_MC_pt_255_1000_endcap = new TH1F ("hEt_MC_pt_255_1000_endcap", "hEt_MC_pt_255_1000_endcap", 90, 0, 3);

    TH1F* hEt_MC_pt_20_25_barrel    = new TH1F ("hEt_MC_pt_20_25_barrel", "hEt_MC_pt_20_25_barrel", 90, 0, 3);
    TH1F* hEt_MC_pt_25_30_barrel    = new TH1F ("hEt_MC_pt_25_30_barrel", "hEt_MC_pt_25_30_barrel", 90, 0, 3);
    TH1F* hEt_MC_pt_30_35_barrel    = new TH1F ("hEt_MC_pt_30_35_barrel", "hEt_MC_pt_30_35_barrel", 90, 0, 3);
    TH1F* hEt_MC_pt_35_40_barrel    = new TH1F ("hEt_MC_pt_35_40_barrel", "hEt_MC_pt_35_40_barrel", 90, 0, 3);
    TH1F* hEt_MC_pt_40_45_barrel    = new TH1F ("hEt_MC_pt_40_45_barrel", "hEt_MC_pt_40_45_barrel", 90, 0, 3);
    TH1F* hEt_MC_pt_45_50_barrel    = new TH1F ("hEt_MC_pt_45_50_barrel", "hEt_MC_pt_45_50_barrel", 90, 0, 3);
    TH1F* hEt_MC_pt_50_60_barrel    = new TH1F ("hEt_MC_pt_50_60_barrel", "hEt_MC_pt_50_60_barrel", 90, 0, 3);
    TH1F* hEt_MC_pt_60_80_barrel    = new TH1F ("hEt_MC_pt_60_80_barrel", "hEt_MC_pt_60_80_barrel", 90, 0, 3);
    TH1F* hEt_MC_pt_80_120_barrel   = new TH1F ("hEt_MC_pt_80_120_barrel", "hEt_MC_pt_80_120_barrel", 90, 0, 3);
    TH1F* hEt_MC_pt_120_180_barrel  = new TH1F ("hEt_MC_pt_120_180_barrel", "hEt_MC_pt_120_180_barrel", 90, 0, 3);
    TH1F* hEt_MC_pt_180_255_barrel  = new TH1F ("hEt_MC_pt_180_255_barrel", "hEt_MC_pt_180_255_barrel", 90, 0, 3);
    TH1F* hEt_MC_pt_255_1000_barrel = new TH1F ("hEt_MC_pt_255_1000_barrel", "hEt_MC_pt_255_1000_barrel", 90, 0, 3);

    TH1F* hEt_MC_pt_20_30_eta_0p0_0p5 = new TH1F ("hEt_MC_pt_20_30_eta_0p0_0p5", "hEt_MC_pt_20_30_eta_0p0_0p5", 90, 0, 3);
    TH1F* hEt_MC_pt_20_30_eta_0p5_1p0 = new TH1F ("hEt_MC_pt_20_30_eta_0p5_1p0", "hEt_MC_pt_20_30_eta_0p5_1p0", 90, 0, 3);
    TH1F* hEt_MC_pt_20_30_eta_1p0_1p5 = new TH1F ("hEt_MC_pt_20_30_eta_1p0_1p5", "hEt_MC_pt_20_30_eta_1p0_1p5", 90, 0, 3);
    TH1F* hEt_MC_pt_20_30_eta_1p5_2p1 = new TH1F ("hEt_MC_pt_20_30_eta_1p5_2p1", "hEt_MC_pt_20_30_eta_1p5_2p1", 90, 0, 3);

    TH1F* hEt_MC_pt_30_40_eta_0p0_0p5 = new TH1F ("hEt_MC_pt_30_40_eta_0p0_0p5", "hEt_MC_pt_30_40_eta_0p0_0p5", 90, 0, 3);
    TH1F* hEt_MC_pt_30_40_eta_0p5_1p0 = new TH1F ("hEt_MC_pt_30_40_eta_0p5_1p0", "hEt_MC_pt_30_40_eta_0p5_1p0", 90, 0, 3);
    TH1F* hEt_MC_pt_30_40_eta_1p0_1p5 = new TH1F ("hEt_MC_pt_30_40_eta_1p0_1p5", "hEt_MC_pt_30_40_eta_1p0_1p5", 90, 0, 3);
    TH1F* hEt_MC_pt_30_40_eta_1p5_2p1 = new TH1F ("hEt_MC_pt_30_40_eta_1p5_2p1", "hEt_MC_pt_30_40_eta_1p5_2p1", 90, 0, 3);

    TH1F* hEt_MC_pt_40_60_eta_0p0_0p5 = new TH1F ("hEt_MC_pt_40_60_eta_0p0_0p5", "hEt_MC_pt_40_60_eta_0p0_0p5", 90, 0, 3);
    TH1F* hEt_MC_pt_40_60_eta_0p5_1p0 = new TH1F ("hEt_MC_pt_40_60_eta_0p5_1p0", "hEt_MC_pt_40_60_eta_0p5_1p0", 90, 0, 3);
    TH1F* hEt_MC_pt_40_60_eta_1p0_1p5 = new TH1F ("hEt_MC_pt_40_60_eta_1p0_1p5", "hEt_MC_pt_40_60_eta_1p0_1p5", 90, 0, 3);
    TH1F* hEt_MC_pt_40_60_eta_1p5_2p1 = new TH1F ("hEt_MC_pt_40_60_eta_1p5_2p1", "hEt_MC_pt_40_60_eta_1p5_2p1", 90, 0, 3);

    // old variables
    ULong64_t EventNumber;
    int RunNumber;
    int lumi;
    int JetsNumber;
    vector<float>* _jets_px;
    vector<float>* _jets_py;
    vector<float>* _jets_pz;
    vector<float>* _jets_e;
    vector<float>* _jets_rawPt;
    vector<float>* _l1tPtJet;
    vector<float>* _l1tEtaJet;
    vector<float>* _l1tPhiJet;
    vector<float>* _l1tRawEtJet;

    myTree->SetBranchAddress("EventNumber",&EventNumber);
    myTree->SetBranchAddress("RunNumber",&RunNumber);
    myTree->SetBranchAddress("lumi",&lumi);
    myTree->SetBranchAddress("JetsNumber",&JetsNumber);
    myTree->SetBranchAddress("jets_px",&_jets_px);
    myTree->SetBranchAddress("jets_py",&_jets_py);
    myTree->SetBranchAddress("jets_pz",&_jets_pz);
    myTree->SetBranchAddress("jets_e",&_jets_e);
    myTree->SetBranchAddress("jets_rawPt",&_jets_rawPt);
    myTree->SetBranchAddress("l1tPtJet",&_l1tPtJet);
    myTree->SetBranchAddress("l1tEtaJet",&_l1tEtaJet);
    myTree->SetBranchAddress("l1tPhiJet",&_l1tPhiJet);
    myTree->SetBranchAddress("l1tRawEtJet",&_l1tRawEtJet);

    Long64_t nentries = myTree->GetEntries();
    cout<<"entries"<<nentries<<endl;

    TTree* tree_new = myTree->GetTree()->CloneTree(0);
    
    vector<float>* _jets_pt;
    tree_new->Branch("jets_pt",&_jets_pt,"jets_pt/F");

    for (int ievt=0; ievt < nentries; ievt++) {
   
        if(ievt%10000==0)
	   cout<<"i="<<ievt<<endl;
 
        EventNumber = 0;
        RunNumber = 0;
	    lumi = 0;
	JetsNumber = 0;

	_jets_px = 0;
	_jets_py = 0;
	_jets_pz = 0;
	_jets_e = 0;
	_jets_rawPt = 0;
	_l1tPtJet = 0;
	_l1tEtaJet = 0;
	_l1tPhiJet = 0;
	_l1tRawEtJet = 0;

        
        myTree->GetEntry(ievt);

        for (int ijet=0; ijet < JetsNumber; ijet++ ){
            
            TLorentzVector jet((*_jets_px)[ijet],(*_jets_py)[ijet],(*_jets_pz)[ijet],(*_jets_e)[ijet]);
            float OfflineJetPt = jet.Pt();
            float L1JetPt = (*_l1tPtJet)[ijet];
	        if (L1JetPt<1.0e-3) continue;

            if ( (abs((*_l1tEtaJet)[ijet])<1.305) ){
                if ((OfflineJetPt>20) && (OfflineJetPt<=25) )    hEt_MC_pt_20_25_endcap->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>25) && (OfflineJetPt<=30) )    hEt_MC_pt_25_30_endcap->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>30) && (OfflineJetPt<=35) )    hEt_MC_pt_30_35_endcap->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>35) && (OfflineJetPt<=40) )    hEt_MC_pt_35_40_endcap->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>40) && (OfflineJetPt<=45) )    hEt_MC_pt_40_45_endcap->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>45) && (OfflineJetPt<=50) )    hEt_MC_pt_45_50_endcap->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>50) && (OfflineJetPt<=60) )    hEt_MC_pt_50_60_endcap->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>60) && (OfflineJetPt<=80) )    hEt_MC_pt_60_80_endcap->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>80) && (OfflineJetPt<=120) )   hEt_MC_pt_80_120_endcap->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>120) && (OfflineJetPt<=180) )  hEt_MC_pt_120_180_endcap->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>180) && (OfflineJetPt<=255) )  hEt_MC_pt_180_255_endcap->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>255) && (OfflineJetPt<=1000) ) hEt_MC_pt_255_1000_endcap->Fill(L1JetPt/OfflineJetPt);
            }

            if ( (abs((*_l1tEtaJet)[ijet])>1.479) ){
                if ((OfflineJetPt>20) && (OfflineJetPt<=25) )    hEt_MC_pt_20_25_barrel->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>25) && (OfflineJetPt<=30) )    hEt_MC_pt_25_30_barrel->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>30) && (OfflineJetPt<=35) )    hEt_MC_pt_30_35_barrel->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>35) && (OfflineJetPt<=40) )    hEt_MC_pt_35_40_barrel->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>40) && (OfflineJetPt<=45) )    hEt_MC_pt_40_45_barrel->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>45) && (OfflineJetPt<=50) )    hEt_MC_pt_45_50_barrel->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>50) && (OfflineJetPt<=60) )    hEt_MC_pt_50_60_barrel->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>60) && (OfflineJetPt<=80) )    hEt_MC_pt_60_80_barrel->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>80) && (OfflineJetPt<=120) )   hEt_MC_pt_80_120_barrel->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>120) && (OfflineJetPt<=180) )  hEt_MC_pt_120_180_barrel->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>180) && (OfflineJetPt<=255) )  hEt_MC_pt_180_255_barrel->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>255) && (OfflineJetPt<=1000) ) hEt_MC_pt_255_1000_barrel->Fill(L1JetPt/OfflineJetPt);
            }

            if ( (abs((*_l1tEtaJet)[ijet])>0.0) && (abs((*_l1tEtaJet)[ijet])<0.5) ){
                if ((OfflineJetPt>20) && (OfflineJetPt<=30) ) hEt_MC_pt_20_30_eta_0p0_0p5->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>30) && (OfflineJetPt<=40) ) hEt_MC_pt_30_40_eta_0p0_0p5->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>40) && (OfflineJetPt<=60) ) hEt_MC_pt_40_60_eta_0p0_0p5->Fill(L1JetPt/OfflineJetPt);
            }

            if ( (abs((*_l1tEtaJet)[ijet])>0.5) && (abs((*_l1tEtaJet)[ijet])<1.0) ){
                if ((OfflineJetPt>20) && (OfflineJetPt<=30) ) hEt_MC_pt_20_30_eta_0p5_1p0->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>30) && (OfflineJetPt<=40) ) hEt_MC_pt_30_40_eta_0p5_1p0->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>40) && (OfflineJetPt<=60) ) hEt_MC_pt_40_60_eta_0p5_1p0->Fill(L1JetPt/OfflineJetPt);

            }

            if ( (abs((*_l1tEtaJet)[ijet])>1.0) && (abs((*_l1tEtaJet)[ijet])<1.5) ){
                if ((OfflineJetPt>20) && (OfflineJetPt<=30) ) hEt_MC_pt_20_30_eta_1p0_1p5->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>30) && (OfflineJetPt<=40) ) hEt_MC_pt_30_40_eta_1p0_1p5->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>40) && (OfflineJetPt<=60) ) hEt_MC_pt_40_60_eta_1p0_1p5->Fill(L1JetPt/OfflineJetPt);

            }

            if ( (abs((*_l1tEtaJet)[ijet])>1.5) && (abs((*_l1tEtaJet)[ijet])<2.1) ){
                if ((OfflineJetPt>20) && (OfflineJetPt<=30) ) hEt_MC_pt_20_30_eta_1p5_2p1->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>30) && (OfflineJetPt<=40) ) hEt_MC_pt_30_40_eta_1p5_2p1->Fill(L1JetPt/OfflineJetPt);
                if ((OfflineJetPt>40) && (OfflineJetPt<=60) ) hEt_MC_pt_40_60_eta_1p5_2p1->Fill(L1JetPt/OfflineJetPt);

            }
		      
        }
        
    }

    myoutput->Write();
}
