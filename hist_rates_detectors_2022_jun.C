// ==============================================================
// Interaction rate plot
// Max Rate = detector or accelerator limited
// Date: 2018-May-1
// Date update: 2021-Feb-01  NA60+ : change interaction rate 2e5 Hz
// Date update: 2021-Apr-11  Star collider 7.7 GeV change from 10 to 20 Hz
// Date update: 2021-Jun-08  CEE@HIAF change to CEE+ @ HIAF, energy range up to 4 GeV, interaction rate up to 5e5 Hz
// Author: T. Galatyuk
// Cite as: T. Galatyuk, Nucl.Phys. A982 (2019)
// ==============================================================


{
    gROOT->Reset();
    #include "Riostream.h"
    #include "TColor.h"

    gStyle->SetEndErrorSize(3);

    // ----------------------------------------------------------
    gStyle->SetPaperSize(28, 28);
    gStyle->SetOptStat(0);
    TH2F *h1 = new TH2F("h1", "", 1000, 0, 1000, 500, 5, 1e8);
    h1->GetXaxis()->SetTitle("Collision energy #sqrt{s_{NN}} [GeV]");
    h1->GetXaxis()->SetTitleFont(42);
    h1->GetXaxis()->SetTitleColor(1);
    h1->GetXaxis()->SetTitleOffset(1.);
    h1->GetXaxis()->SetTitleSize(0.06);
    h1->GetXaxis()->SetLabelFont(42);
    h1->GetXaxis()->SetLabelSize(0.05);
    h1->GetXaxis()->SetNdivisions(510);
    h1->GetYaxis()->SetTitle("Interaction rate [Hz]");
    h1->GetYaxis()->SetTitleFont(42);
    h1->GetYaxis()->SetTitleOffset(0.8);
    h1->GetYaxis()->SetTitleSize(0.06);
    h1->GetYaxis()->SetLabelFont(42);
    h1->GetYaxis()->SetLabelSize(0.05);
    h1->GetZaxis()->SetLabelFont(42);
    h1->GetZaxis()->SetLabelSize(0.05);
    h1->SetTitle();
    //--------------------------------------

    h1->GetXaxis()->SetMoreLogLabels();
    h1->GetXaxis()->SetNoExponent();

    Int_t ci95,ci90,ci85,ci80,ci75,ci70,ci65,ci60,ci55,ci50,ci45,ci40,ci35,ci30,ci25,ci20,ci15,ci10,ci5;      // for color index setting
    TColor *color; // for color definition with alpha

    ci_helm_b    = TColor::GetColor("#005aa0");
    ci_helm_lb   = TColor::GetColor("#b0cae1");
    ci_helm_gre  = TColor::GetColor("#8db423");
    ci_helm_or   = TColor::GetColor("#f0781e");
    ci_helm_az   = TColor::GetColor("#27b4f8");
    ci_helm_ye   = TColor::GetColor("#ffd228");
    ci_helm_gr   = TColor::GetColor("#50c8aa");
    ci_helm_ma   = TColor::GetColor("#d23264");
    ci_helm_ef   = TColor::GetColor("#326469");
    ci_helm_gray = TColor::GetColor("#dcdcdc");

    // ----------------------------------------
    Double_t cbm100_e[] = {  2.7,   3.2,   4,    4.9};
    Double_t cbm100_r[] = {1e7, 1e7, 1e7,  1e7};
    TGraphAsymmErrors *gr_cbm100 = new TGraphAsymmErrors(4, cbm100_e, cbm100_r);
    gr_cbm100->SetMarkerColor(kGray+3);
    gr_cbm100->SetLineColor(kGray+3);
    //gr_cbm100->SetMarkerColor(ci_helm_or);
    //gr_cbm100->SetLineColor(ci_helm_or);
    gr_cbm100->SetLineWidth(3);
    gr_cbm100->SetLineStyle(7);
    gr_cbm100->SetMarkerSize(2.3);
    gr_cbm100->SetMarkerStyle(22);
    // ----------------------------------------

    // ----------------------------------------
    Double_t ceep_e[] = {  1.9, 4.};
    Double_t ceep_r[] = {5e5, 5e5};
    TGraphAsymmErrors *gr_ceep = new TGraphAsymmErrors(2, ceep_e, ceep_r);
    gr_ceep->SetMarkerColor(kGray+3);
    gr_ceep->SetLineColor(kGray+3);
    gr_ceep->SetLineWidth(3);
    gr_ceep->SetLineStyle(2);
    gr_ceep->SetMarkerSize(2.8);
    gr_ceep->SetMarkerStyle(33);
    // ----------------------------------------

    // ----------------------------------------
    Double_t lamps_e[] = {1.86};
    Double_t lamps_r[] = {5e4};
    TGraphAsymmErrors *gr_lamps = new TGraphAsymmErrors(2, lamps_e, lamps_r);
    gr_lamps->SetMarkerColor(kGray+3);
    gr_lamps->SetLineColor(kGray+3);
    gr_lamps->SetLineWidth(3);
    gr_lamps->SetLineStyle(9);
    gr_lamps->SetMarkerSize(2.8);
    gr_lamps->SetMarkerStyle(33);
    // ----------------------------------------


    // ----------------------------------------
    Double_t star_ft_e[] = {  3., 3.2, 3.5, 4., 4.5, 5.2, 6.2, 7.7};
    Double_t star_ft_r[] = {1800,1800,1800,1800,1800,1800,1800,1800};
    TGraphAsymmErrors *gr_star_ft = new TGraphAsymmErrors(8, star_ft_e, star_ft_r);
    gr_star_ft->SetMarkerColor(1);
    gr_star_ft->SetLineColor(1);
    gr_star_ft->SetLineWidth(3);
    gr_star_ft->SetLineStyle(1);
    gr_star_ft->SetMarkerSize(2.5);
    gr_star_ft->SetMarkerStyle(29);

    TGraphAsymmErrors *gr_star_ft1 = new TGraphAsymmErrors(8, star_ft_e, star_ft_r);
    gr_star_ft1->SetMarkerColor(10);
    gr_star_ft1->SetMarkerSize(1.1);
    gr_star_ft1->SetMarkerStyle(29);
    // ----------------------------------------

    // ----------------------------------------
    Double_t star_bes_e[] = {  7.7,   9.1,   11.5,  14.5,  19.6};
    Double_t star_bes_r[] = {   20,    60,    200,   600,   1100};
    TGraphAsymmErrors *gr_star_bes1 = new TGraphAsymmErrors(5, star_bes_e, star_bes_r);
    gr_star_bes1->SetMarkerColor(kBlue+1);
    gr_star_bes1->SetLineColor(kBlue+1);
    gr_star_bes1->SetLineWidth(3);
    gr_star_bes1->SetLineStyle(1);
    gr_star_bes1->SetMarkerSize(2.5);
    gr_star_bes1->SetMarkerStyle(29);

    TGraphAsymmErrors *gr_star_bes1a = new TGraphAsymmErrors(5, star_bes_e, star_bes_r);
    gr_star_bes1a->SetMarkerColor(10);
    gr_star_bes1a->SetMarkerSize(1.1);
    gr_star_bes1a->SetMarkerStyle(29);


    Double_t star_bes_e2[] = {  19.6,  27,   39,   54,   62.4, 200};
    Double_t star_bes_r2[] = {  1100,  1600, 1800, 1800, 1800, 1800};
    TGraphAsymmErrors *gr_star_bes2 = new TGraphAsymmErrors(6, star_bes_e2, star_bes_r2);
    gr_star_bes2->SetMarkerColor(kBlue+1);
    gr_star_bes2->SetLineColor(kBlue+1);
    gr_star_bes2->SetLineWidth(3);
    gr_star_bes2->SetMarkerSize(2.5);
    gr_star_bes2->SetMarkerStyle(29);

    TGraphAsymmErrors *gr_star_bes2a = new TGraphAsymmErrors(6, star_bes_e2, star_bes_r2);
    gr_star_bes2a->SetMarkerColor(10);
    gr_star_bes2a->SetMarkerSize(1.1);
    gr_star_bes2a->SetMarkerStyle(29);
    // ----------------------------------------

    // ----------------------------------------
    Double_t hades_e[] = { 1.86,    3.};
    Double_t hades_r[] = {  2e4,   2e4};
    TGraphAsymmErrors *gr_hades = new TGraphAsymmErrors(2, hades_e, hades_r);
    gr_hades->SetMarkerColor(1);
    gr_hades->SetLineColor(1);
//    gr_hades->SetMarkerColor(ci_helm_or);
//    gr_hades->SetLineColor(ci_helm_or);
    gr_hades->SetLineWidth(3);
    gr_hades->SetMarkerSize(2.3);
    gr_hades->SetMarkerStyle(22);
    // ----------------------------------------

    // ----------------------------------------
    Double_t na61_e[] = {  8.86,  16.9};
    Double_t na61_r[] = {  1000,  1000};
    TGraphAsymmErrors *gr_na61 = new TGraphAsymmErrors(2, na61_e, na61_r);
    gr_na61->SetMarkerColor(1);
    gr_na61->SetLineColor(1);
    gr_na61->SetLineWidth(3);
    gr_na61->SetLineStyle(1);
    gr_na61->SetMarkerSize(2.1);
    gr_na61->SetMarkerStyle(20);

    TGraphAsymmErrors *gr_na61a = new TGraphAsymmErrors(2, na61_e, na61_r);
    gr_na61a->SetMarkerColor(10);
    gr_na61a->SetMarkerSize(1.);
    gr_na61a->SetMarkerStyle(20);
    // ----------------------------------------


    // ----------------------------------------
    Double_t mpd_e[] = {  4,  4.5,  5., 6.5,    8,   9, 10, 11};
    Double_t mpd_r[] = {  50, 2e2,  6e2, 3e3,  6e3, 6e3, 6e3, 6e3};
    TGraphAsymmErrors *gr_mpd = new TGraphAsymmErrors(8, mpd_e, mpd_r);
    gr_mpd->SetMarkerColor(kBlue+1);
    gr_mpd->SetLineColor(kBlue+1);
    gr_mpd->SetLineWidth(3);
    gr_mpd->SetLineStyle(9);
    gr_mpd->SetMarkerSize(1.8);
    gr_mpd->SetMarkerStyle(21);

    TGraphAsymmErrors *gr_mpd1 = new TGraphAsymmErrors(8, mpd_e, mpd_r);
    gr_mpd1->SetMarkerColor(10);
    gr_mpd1->SetMarkerSize(1.1);
    gr_mpd1->SetMarkerStyle(21);
    // ----------------------------------------
    // ----------------------------------------
    Double_t bmn_e[] = {  2.3,  3.8};   //   1 - AGeV
    Double_t bmn_r[] = {  5e4, 5e4};
    TGraphAsymmErrors *gr_bmn = new TGraphAsymmErrors(2, bmn_e, bmn_r);
    gr_bmn->SetMarkerColor(kGray+3);
    gr_bmn->SetLineColor(kGray+3);
    gr_bmn->SetLineWidth(3);
    gr_bmn->SetLineStyle(9);
    gr_bmn->SetMarkerSize(1.8);
    gr_bmn->SetMarkerStyle(21);

    TGraphAsymmErrors *gr_bmn1 = new TGraphAsymmErrors(2, bmn_e, bmn_r);
    gr_bmn1->SetMarkerColor(10);
    gr_bmn1->SetMarkerSize(1.1);
    gr_bmn1->SetMarkerStyle(21);
    // ----------------------------------------

    // ----------------------------------------
    Double_t na60p_e[] = {6.3, 8.8, 17.3};
    //Double_t na60p_r[] = {1e7, 1e7, 1e7};
    Double_t na60p_r[] = {2e5, 2e5, 2e5};
    TGraphAsymmErrors *gr_na60p = new TGraphAsymmErrors(3, na60p_e, na60p_r);
    gr_na60p->SetMarkerColor(kGray+2);
    gr_na60p->SetLineColor(kGray+2);
    gr_na60p->SetLineWidth(3);
    gr_na60p->SetLineStyle(2);
    gr_na60p->SetMarkerSize(1.8);
    gr_na60p->SetMarkerStyle(8);

    TGraphAsymmErrors *gr_na60p1 = new TGraphAsymmErrors(3, na60p_e, na60p_r);
    gr_na60p1->SetMarkerColor(10);
    gr_na60p1->SetMarkerSize(1.1);
    gr_na60p1->SetMarkerStyle(8);
    // ----------------------------------------

    // ----------------------------------------
    Double_t jparc_e[] = {2, 6.3};
    Double_t jparc_r[] = {1e7, 1e7};
    TGraphAsymmErrors *gr_jparc = new TGraphAsymmErrors(2, jparc_e, jparc_r);
    gr_jparc->SetMarkerColor(kGray+2);
    gr_jparc->SetLineColor(kGray+2);
    gr_jparc->SetLineWidth(3);
    gr_jparc->SetLineStyle(2);
    gr_jparc->SetMarkerSize(2.2);
    gr_jparc->SetMarkerStyle(23);

    TGraphAsymmErrors *gr_jparc1 = new TGraphAsymmErrors(2, jparc_e, jparc_r);
    gr_jparc1->SetMarkerColor(10);
    gr_jparc1->SetMarkerSize(1.1);
    gr_jparc1->SetMarkerStyle(23);
    // ----------------------------------------











    //--------------------------------------
    //--------------------------------------
    TCanvas* can_exp = new TCanvas ("can_exp", "", 10, 10, 1020, 765);
    can_exp->SetFillColor(10);
    can_exp->SetBottomMargin(0.15);
    can_exp->SetTopMargin(0.04);
//    can_exp->SetGridx();
//    can_exp->SetGridy();

    gPad->SetTicks(1,1);


    gPad->SetLeftMargin(0.1);
    gPad->SetRightMargin(0.025);
    h1->GetYaxis()->SetRangeUser(5., 1e8);
    h1->GetXaxis()->SetRangeUser(1.,  300.);
    can_exp->SetLogx();
    can_exp->SetLogy();

    h1->Draw();
    gr_hades->Draw("plsame");

    gr_star_ft->Draw("plsame");
    gr_star_ft1->Draw("psame");

    gr_star_bes1->Draw("plsame");
    gr_star_bes1a->Draw("psame");

    gr_star_bes2->Draw("plsame");
    gr_star_bes2a->Draw("psame");

    gr_na61->Draw("plsame");
    gr_na61a->Draw("psame");

    gr_mpd->Draw("plsame");
    gr_mpd1->Draw("psame");

    gr_bmn->Draw("plsame");
    gr_bmn1->Draw("psame");

    gr_ceep->Draw("plsame");

    gr_lamps->Draw("psame");

    //gr_na60->Draw("psame");
    gr_na60p->Draw("plsame");
    gr_na60p1->Draw("psame");

    gr_jparc->Draw("plsame");
    gr_jparc1->Draw("psame");

    //gr_cbm300->Draw("plsame");
    gr_cbm100->Draw("plsame");


    TPaveText *pt = new TPaveText(3.8,2.e7,3.8,2.e7,"br");
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetLineColor(0);
    pt->SetTextSize(0.025);
    pt->SetTextFont(42);
    TText *text = pt->AddText("CBM@FAIR SIS100");
    pt->Draw();

    TPaveText *pt = new TPaveText(2.8,7e5,2.8,7e5);
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetLineColor(0);
    pt->SetTextSize(0.025);
    pt->SetTextFont(42);
    TText *text = pt->AddText("CEE+@HIAF");
    pt->Draw();

    TPaveText *pt = new TPaveText(1.4,5e4,1.4,5e4);
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetLineColor(0);
    pt->SetTextSize(0.025);
    pt->SetTextFont(42);
    TText *text = pt->AddText("LAMPS");
    pt->Draw();
    TPaveText *pt = new TPaveText(1.4,3e4,1.4,3e4);
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetLineColor(0);
    pt->SetTextSize(0.025);
    pt->SetTextFont(42);
    TText *text = pt->AddText("@RAON");
    pt->Draw();

    TPaveText *pt = new TPaveText(2.4,1.2e4,2.4,1.2e4"br");
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetLineColor(0);
    pt->SetTextSize(0.025);
    pt->SetTextFont(42);
    TText *text = pt->AddText("HADES@GSI");
    pt->Draw();

    TPaveText *pt = new TPaveText(2.95,7.8e4,2.95,7.8e4);
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetLineColor(0);
    pt->SetTextSize(0.025);
    pt->SetTextFont(42);
    TText *text = pt->AddText("BM@N");
    pt->Draw();


    TPaveText *pt = new TPaveText(10,1e4,10,1e4,"br");
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetLineColor(0);
    pt->SetTextSize(0.025);
    pt->SetTextFont(42);
    TText *text = pt->AddText("MPD@NICA");
    pt->Draw();


    TPaveText *pt = new TPaveText(3,1e3,3,1e3,"br");
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetLineColor(0);
    pt->SetTextSize(0.025);
    pt->SetTextFont(42);
    TText *text = pt->AddText("STAR FXT");
    pt->Draw();

    TPaveText *pt = new TPaveText(40,1e3,40,1e3);
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetLineColor(0);
    pt->SetTextSize(0.025);
    pt->SetTextColor(1);
    pt->SetTextFont(42);
    TText *text = pt->AddText("STAR@RHIC");
    pt->Draw();


    TPaveText *pt = new TPaveText(13,16e2,13,16e2,"br");
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetLineColor(0);
    pt->SetTextSize(0.025);
    pt->SetTextFont(42);
    TText *text = pt->AddText("NA61/SHINE");
    pt->Draw();

    pt->Draw();
    TPaveText *pt = new TPaveText(11,3.3e5,11,3.3e5);
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetLineColor(0);
    pt->SetTextSize(0.025);
    pt->SetTextFont(42);
    TText *text = pt->AddText("NA60+@SPS");
    pt->Draw();

    TPaveText *pt = new TPaveText(2, 6e6, 2, 6e6);
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetLineColor(0);
    pt->SetTextSize(0.025);
    pt->SetTextColor(1);
    pt->SetTextFont(42);
    TText *text = pt->AddText("J-PARC-HI");
    pt->Draw();


    TArrow *arrow = new TArrow(150,50000,250,50000,0.01,">");
    arrow->SetFillColor(kRed);
    arrow->SetFillStyle(1001);
    arrow->SetLineWidth(3);
    arrow->SetLineStyle(9);
    arrow->SetLineColor(kBlue+1);
    arrow->SetAngle(51);
    arrow->Draw();

    TArrow *arrow = new TArrow(130,15000,200,15000,0.01,"+");
    arrow->SetFillColor(1);
    arrow->SetLineStyle(9);
    arrow->SetLineWidth(3);
    arrow->SetLineColor(kBlue+1);
    arrow->SetAngle(51);
    arrow->Draw();

    TMarker *marker = new TMarker(200,15000,20);
    marker->SetMarkerColor(kBlue+1);
    marker->SetMarkerStyle(20);
    marker->SetMarkerSize(1.2);
    marker->Draw();

    TPaveText *pt = new TPaveText(180,7e4,180,7e4);
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetLineColor(0);
    pt->SetTextSize(0.025);
    pt->SetTextColor(1);
    pt->SetTextFont(42);
    TText *text = pt->AddText("ALICE@LHC");
    pt->Draw();

    TPaveText *pt = new TPaveText(140,2.2e4,140,2.2e4);
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetLineColor(0);
    pt->SetTextSize(0.025);
    pt->SetTextColor(1);
    pt->SetTextFont(42);
    TText *text = pt->AddText("sPHENIX@RHIC");
    pt->Draw();





    tex = new TLatex(1.3, 1e5,"Fixed-target experiments");
    tex->SetTextAngle(91.05441);
    tex->SetTextFont(62);
    tex->SetTextSize(0.02);
    tex->SetTextColor(kGray+3);
    tex->Draw();
    tex = new TLatex(220, 400,"Collider experiments");
    tex->SetTextAngle(270);
    tex->SetTextColor(kBlue+1);
    tex->SetTextFont(62);
    tex->SetTextSize(0.02);
    tex->Draw();

    tex = new TLatex(28, 2e7,"Heavy ion collisions");
    tex->SetTextFont(62);
    tex->SetTextSize(0.05);
    tex->Draw();

}