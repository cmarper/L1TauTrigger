{

   TFile *file= new TFile("/home/llr/cms/mperez/TauTrigger/CMSSW_9_2_10/src/TauTagAndProbe/TauTagAndProbe/test/2018MC/NTuple_MC_VBFHToTauTau_MiniAOD_180815.root");
   TDirectory *dir = file->GetDirectory("Ntuplizer_noTagAndProbe");
   TTree * tree = (TTree*)dir->Get("outTreeForCalibration");
   Long64_t nentries = tree->GetEntries(); 
 
   //tree->GetEntry(2);
   //TTree * tree = new TTree("outTreeForCalibration");
   //   //TTree * Tree2 = (TTree*)File2.Get("ZeroBias/ZeroBias"); 

   //TH1F * hEt_MC_calib_pt_20_25_endcap = new TH1F("hEt_MC_calib_pt_20_25_endcap", "hEt_MC_calib_pt_20_25_endcap", 60, 0, 3);

   //TTree * tree = new TTree("outTreeForCalibration");

   //Long64_t nentries = tree->GetEntries();   
}

