/**********************************************************************
  SpectraDialog - Visualize spectral data from QM calculations

  Copyright (C) 2009 by David Lonie

  This file is part of the Avogadro molecular editor project.
  For more information, see <http://avogadro.openmolecules.net/>

  This library is free software; you can redistribute it and/or modify
  it under the terms of the GNU Library General Public License as
  published by the Free Software Foundation; either version 2.1 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public icense for more details.
 ***********************************************************************/

#ifndef SPECTRATYPE_IR_H
#define SPECTRATYPE_IR_H

#include <QtCore/QHash>
#include <QtCore/QVariant>

#include "spectradialog.h"
#include "spectratype.h"
#include "ui_spectratabir.h"

#include <avogadro/plotwidget.h>

namespace Avogadro {

  enum ScalingType { LINEAR, RELATIVE };

  class IRSpectra : public SpectraType
  {
    Q_OBJECT

  public:
    IRSpectra( SpectraDialog *parent = 0 );
    ~IRSpectra();

    void writeSettings();
    void readSettings();

    bool checkForData(Molecule* mol);
    void setupPlot(PlotWidget * plot);

    void getCalculatedPlotObject(PlotObject *plotObject);
    void setImportedData(const QList<double> & xList, const QList<double> & yList);
    QString getTSV();

  private slots:
    void updateScaleSpin(int);
    void updateScaleSlider(double);
    void scaleSliderPressed();
    void scaleSliderReleased();
    void updateFWHMSpin(int);
    void updateFWHMSlider(double);
    void fwhmSliderPressed();
    void fwhmSliderReleased();
    void updateYAxis(QString);
    void changeScalingType(int);

  private:
    double scale(double w);
    
    Ui::Tab_IR ui;
    double m_scale;
    double m_fwhm;
    QString m_yaxis;
    ScalingType m_scalingType;
  };
}

#endif
