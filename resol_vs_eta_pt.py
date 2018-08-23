from ROOT import *
from array import array

def SetLucaStyle ():
    #global LS
    LS = TStyle (gStyle) #copy some of the basics of defualt style...
    LS.SetName("LucaStyle")
    LS.SetTitle("Luca Style")

    # pad
    LS.SetOptStat(0)
    LS.SetTickLength(0.02,"X")
    LS.SetTickLength(0.02,"Y")
    LS.SetPadTickY(1)
    LS.SetPadTickX(1)
    LS.SetPadGridY(1);
    LS.SetPadGridX(1);
    #LS.SetPadTopMargin(0.05)
    #LS.SetPadBottomMargin(0.13)
    LS.SetPadLeftMargin(0.16)
    
    LS.SetCanvasDefH(600)
    LS.SetCanvasDefW(600)

    # axis
    LS.SetTitleYOffset(1.4)
    LS.SetTitleXOffset(0.9)
    LS.SetLabelOffset(0.009, "XYZ")
    LS.SetTitleSize(0.050, "XYZ")

    # legend
    LS.SetLegendBorderSize(0)
    LS.SetLegendFont(62)
    #LS.SetLegendFillStyle(0) #NOT IMPLEMENTED in root

    # if histoType == 0:
    #     LS.SetMarkerStyle(8);
    #     LS.SetMarkerSize(0.8);

    LS.cd() 
    return LS

# put resolution along y axis of hsto2d into hsito1d
def MakeResolVsVar (histo2d, histo1d):
    if histo2d.GetNbinsX() != histo1d.GetNbinsX():
        print "*** ERROR : not same binning"
        return False
    
    print "PROCESSING: " , histo2d.GetName()
    for ixbin in range (1, histo1d.GetNbinsX()+1):
        hproj = histo2d.ProjectionY("proj", ixbin, ixbin)
        histo1d.SetBinContent(ixbin, hproj.GetRMS() / hproj.GetMean())
        #histo1d.SetBinContent(ixbin, hproj.GetMean())

        print "bin:", ixbin, "mean:" , hproj.GetMean(), "integral:" , hproj.Integral()

        # error = 0.0
        # if hproj.Integral() > 0:

        # if hproj.GetMeanError() < 0.01:
        #     print hproj.GetMeanError() , hproj.GetMean() ,  hproj.Integral()
        err = hproj.GetRMS() / (TMath.Sqrt(hproj.Integral()))
        # histo1d.SetBinError(ixbin, hproj.GetRMSError())
        histo1d.SetBinError(ixbin, err)

    return True

gROOT.SetBatch(True)
TH1.SetDefaultSumw2();
styl = SetLucaStyle()

fData = TFile.Open("/data_CMS/cms/mperez/TauTrigger_data/2018/data/Menu2018/NTuple_SingleMu_Run2018A_v1_180507_forFit.root")
tData = fData.Get("TagAndProbe")

fOut = TFile("results/plotOutData_vsEtaPt_SingleMu_2018A_315252_315488.root", "recreate")

# risoluzione in pt vs altri parametri
etaPars = [20, 0, 2.5]
ptPars  = [20, 0, 100]

#etaBinning = [0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.50, 1.75, 2.0, 2.5]
etaBinning = [0, 0.26, 0.52, 0.78, 1.04, 1.30, 1.48, 1.75, 2.0, 2.5] 
# etaBinning = [0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.825, 1.0, 1.155, 1.25, 1.375, 1.50, 1.625, 1.75, 2.0, 2.5]
#ptBinning  = [19.99, 23, 26, 30, 50, 200]
ptBinning  = [20, 23, 26, 30, 35, 40, 45, 50, 60, 70, 90, 110]
nvtxBinning = [0, 10, 15, 20, 25, 30, 35, 40, 45, 50, 60, 70, 80]

# hResol_eta_2d = TH2F ("hResol_eta_2d", "hResol_eta_2d", etaPars[0], etaPars[1], etaPars[2], 1000, 0, 3)
# hResol_pt_2d = TH2F ("hResol_pt_2d", "hResol_pt_2d", ptPars[0], ptPars[1], ptPars[2], 1000, 0, 3)
# hResol_pt_barrel_2d = TH2F ("hResol_pt_barrel_2d", "hResol_pt_barrel_2d", ptPars[0], ptPars[1], ptPars[2], 1000, 0, 3)
# hResol_pt_endcap_2d = TH2F ("hResol_pt_endcap_2d", "hResol_pt_endcap_2d", ptPars[0], ptPars[1], ptPars[2], 1000,  0, 3)

hResol_eta_2d = TH2F ("hResol_eta_2d", "hResol_eta_2d", len(etaBinning)-1, array('d', etaBinning) , 1000, 0, 3)
hResol_pt_2d = TH2F ("hResol_pt_2d", "hResol_pt_2d",len(ptBinning)-1, array('d', ptBinning), 1000, 0, 3)
hResol_pt_barrel_2d = TH2F ("hResol_pt_barrel_2d", "hResol_pt_barrel_2d",len(ptBinning)-1, array('d', ptBinning), 1000, 0, 3)
hResol_pt_endcap_2d = TH2F ("hResol_pt_endcap_2d", "hResol_pt_endcap_2d",len(ptBinning)-1, array('d', ptBinning), 1000,  0, 3)
hResol_nvtx_2d = TH2F ("hResol_nvtx_2d", "hResol_nvtx_2d", len(nvtxBinning)-1, array('d', nvtxBinning) , 1000, 0, 3)

nEv = tData.GetEntries()
for iEv in range (0, nEv):
    tData.GetEntry(iEv)
    if iEv % 1000 == 0 : print iEv , "/" , nEv
    
#    if tData.OfflineTau_isMatched == 1:
    if 1 == 1:
        hResol_nvtx_2d.Fill(TMath.Abs(tData.Nvtx) , tData.l1tPt / tData.tauPt )
        hResol_eta_2d.Fill(TMath.Abs(tData.tauEta) , tData.l1tPt / tData.tauPt )
        hResol_pt_2d.Fill (tData.tauPt , tData.l1tPt / tData.tauPt )
        if TMath.Abs(tData.tauEta) < 1.305:
            hResol_pt_barrel_2d.Fill (tData.tauPt , tData.l1tPt / tData.tauPt )
        elif TMath.Abs(tData.tauEta) > 1.479:
            hResol_pt_endcap_2d.Fill (tData.tauPt , tData.l1tPt / tData.tauPt )

# hResol_eta = TH1F ("hResol_eta", "hResol_eta",  etaPars[0], etaPars[1], etaPars[2])
# hResol_pt = TH1F ("hResol_pt", "hResol_pt", ptPars[0], ptPars[1], ptPars[2])
# hResol_pt_barrel = TH1F ("hResol_pt_barrel", "hResol_pt_barrel", ptPars[0], ptPars[1], ptPars[2])
# hResol_pt_endcap = TH1F ("hResol_pt_endcap", "hResol_pt_endcap", ptPars[0], ptPars[1], ptPars[2])

hResol_eta = TH1F ("hResol_eta", "hResol_eta",  len(etaBinning)-1, array('d', etaBinning))
hResol_pt = TH1F ("hResol_pt", "hResol_pt", len(ptBinning)-1, array('d', ptBinning))
hResol_pt_barrel = TH1F ("hResol_pt_barrel", "hResol_pt_barrel", len(ptBinning)-1, array('d', ptBinning))
hResol_pt_endcap = TH1F ("hResol_pt_endcap", "hResol_pt_endcap", len(ptBinning)-1, array('d', ptBinning))
hResol_nvtx = TH1F ("hResol_nvtx", "hResol_nvtx",  len(nvtxBinning)-1, array('d', nvtxBinning))

MakeResolVsVar( hResol_eta_2d,  hResol_eta )
MakeResolVsVar( hResol_pt_2d,  hResol_pt )
MakeResolVsVar( hResol_pt_barrel_2d,  hResol_pt_barrel )
MakeResolVsVar( hResol_pt_endcap_2d,  hResol_pt_endcap )
MakeResolVsVar( hResol_nvtx_2d,  hResol_nvtx )

fOut.Write()
