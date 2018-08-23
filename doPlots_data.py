from ROOT import *

# global style for nice plots!
# histoType = 0: histos with errors via sumw2() ==> set markers, not lines!
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

gROOT.SetBatch(True)
TH1.SetDefaultSumw2();

styl = SetLucaStyle()
fData = TFile.Open("/data_CMS/cms/mperez/TauTrigger_data/2018/data/Menu2018/NTuple_SingleMu_Run2018A_v1_180507_forFit.root")
tData = fData.Get("TagAndProbe")

fOut = TFile("results/plotOutData_SingleMu_2018A_315252_315488.root", "recreate")

# all
hEta_Data = TH1F ("hEta_Data", "hEta_Data", 50, -0.3, 0.3)
hEt_Data = TH1F ("hEt_Data", "hEt_Data", 60, 0, 3)
hPhi_Data = TH1F ("hPhi_Data", "hPhi_Data", 50, -0.3, 0.3)

# barrel
hEta_Data_barrel = TH1F ("hEta_Data_barrel", "hEta_Data_barrel", 50, -0.3, 0.3)
hEt_Data_barrel = TH1F ("hEt_Data_barrel", "hEt_Data_barrel", 60, 0, 3)
hPhi_Data_barrel = TH1F ("hPhi_Data_barrel", "hPhi_Data_barrel", 50, -0.3, 0.3)

#endcap
hEta_Data_endcap = TH1F ("hEta_Data_endcap", "hEta_Data_endcap", 50, -0.3, 0.3)
hEt_Data_endcap = TH1F ("hEt_Data_endcap", "hEt_Data_endcap", 60, 0, 3)
hPhi_Data_endcap = TH1F ("hPhi_Data_endcap", "hPhi_Data_endcap", 50, -0.3, 0.3)

tData.Draw("l1tEta - tauEta >> hEta_Data", "tauPt > 20")
tData.Draw("l1tPt / tauPt >> hEt_Data", "tauPt > 20")
tData.Draw("l1tPhi - tauPhi >> hPhi_Data", "tauPt > 20")

tData.Draw("l1tEta - tauEta >> hEta_Data_barrel", "TMath::Abs(tauEta) < 1.305 && tauPt > 20")
tData.Draw("l1tPt / tauPt >> hEt_Data_barrel", "TMath::Abs(tauEta) < 1.305 && tauPt > 20")
tData.Draw("l1tPhi - tauPhi >> hPhi_Data_barrel", "TMath::Abs(tauEta) < 1.305 && tauPt > 20")

tData.Draw("l1tEta - tauEta >> hEta_Data_endcap", "TMath::Abs(tauEta) > 1.479 && tauPt > 20")
tData.Draw("l1tPt / tauPt >> hEt_Data_endcap", "TMath::Abs(tauEta) > 1.479 && tauPt > 20")
tData.Draw("l1tPhi - tauPhi >> hPhi_Data_endcap", "TMath::Abs(tauEta) > 1.479 && tauPt > 20")

#tData.Draw("l1tEta - tauEta >> hEta_Data", "OfflineTau_isMatched == 1")
#tData.Draw("L1Tau_pt / tauPt >> hEt_Data", "OfflineTau_isMatched == 1")
#tData.Draw("l1tPhi - tauPhi >> hPhi_Data", "OfflineTau_isMatched == 1")

#tData.Draw("l1tEta - tauEta >> hEta_Data_barrel", "OfflineTau_isMatched == 1 && TMath::Abs(tauEta) < 1.305")
#tData.Draw("L1Tau_pt / tauPt >> hEt_Data_barrel", "OfflineTau_isMatched == 1 && TMath::Abs(tauEta) < 1.305")
#tData.Draw("l1tPhi - tauPhi >> hPhi_Data_barrel", "OfflineTau_isMatched == 1 && TMath::Abs(tauEta) < 1.305")

#tData.Draw("l1tEta - tauEta >> hEta_Data_endcap", "OfflineTau_isMatched == 1 && TMath::Abs(tauEta) > 1.479")
#tData.Draw("L1Tau_pt / tauPt >> hEt_Data_endcap", "OfflineTau_isMatched == 1 && TMath::Abs(tauEta) > 1.479")
#tData.Draw("l1tPhi - tauPhi >> hPhi_Data_endcap", "OfflineTau_isMatched == 1 && TMath::Abs(tauEta) > 1.479")

# leg = TLegend (0.6, 0.6, 0.8, 0.8)
# # leg.AddEntry(hEta_MC, "MC", "l")
# leg.AddEntry(hEta_Data, "2017B Data", "l")

# c1 = TCanvas("c1", "c1", 600, 600)

# hEta_Data.SetLineColor(kRed)
# hEta_Data.SetTitle(";#eta(L1) - #eta(offline); a.u.")
# hEta_Data.DrawNormalized()
# leg.Draw()
# c1.Print("eta.pdf", "pdf")

# hEt_Data.SetLineWidth(2)
# hEt_Data.SetLineColor(kRed)
# hEt_Data.SetTitle(";E_{T}(L1) / E_{T}(offline); a.u.")
# hEt_Data.DrawNormalized()
# leg.Draw()
# c1.Print("et.pdf", "pdf")

# print "Data" , hEt_Data.GetRMS() / hEt_Data.GetMean()


# hPhi_Data.SetLineWidth(2)
# hPhi_Data.SetLineColor(kRed)
# hPhi_Data.SetTitle(";#varphi(L1) - #varphi(offline); a.u.")
# # hPhi_MC.DrawNormalized()
# # hPhi_Data.DrawNormalized("same")
# hPhi_Data.DrawNormalized()
# leg.Draw()
# c1.Print("phi.pdf", "pdf")

# c1.Update()
# raw_input()
fOut.Write()
