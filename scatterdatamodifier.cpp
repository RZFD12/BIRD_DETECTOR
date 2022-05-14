#include <QtDataVisualization/qscatterdataproxy.h>
#include <QtDataVisualization/qvalue3daxis.h>
#include <QtDataVisualization/q3dscene.h>
#include <QtDataVisualization/q3dcamera.h>
#include <QtDataVisualization/qscatter3dseries.h>
#include <QtDataVisualization/q3dtheme.h>
#include <QtCore/qmath.h>
#include <QtCore/qrandom.h>
#include <QtWidgets/QComboBox>

#include "scatterdatamodifier.h"

using namespace QtDataVisualization;

const int lowerNumberOfItems = 900;
const float lowerCurveDivider = 0.75f;

ScatterDataModifier::ScatterDataModifier(Q3DScatter* scatter)
    :m_graph(scatter),
     m_fontSize(40.0f),
     m_style(QAbstract3DSeries::MeshBevelCube),
     m_smooth(true),
     m_itemCount(lowerNumberOfItems),
     m_curveDivider(lowerCurveDivider)
{
    m_graph->activeTheme()->setType(Q3DTheme::ThemeStoneMoss);
    auto font = m_graph->activeTheme()->font();
    font.setPointSize(m_fontSize);
    m_graph->activeTheme()->setFont(font);
    m_graph->setShadowQuality(QAbstract3DGraph::ShadowQualitySoftLow);
    m_graph->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetIsometricLeft);
    m_graph->setAspectRatio(1.0);
    m_graph->setHorizontalAspectRatio(1.0);
    auto proxy = new QScatterDataProxy;
    auto series = new QScatter3DSeries(proxy);
    series->setItemLabelFormat(QStringLiteral("@xTitle: @xLabel @yTitle: @yLabel @zTitle: @zLabel"));
    series->setMeshSmooth(m_smooth);
    m_graph->addSeries(series);
    dataArray = new QScatterDataArray;
    m_graph->axisX()->setTitle("X");
    m_graph->axisY()->setTitle("Y");
    m_graph->axisZ()->setTitle("Z");
}

ScatterDataModifier::~ScatterDataModifier()
{
    delete m_graph;
}

void ScatterDataModifier::addData()
{
    // Configure the axes according to the data
    QScatterDataItem* ptrToDataArray = &dataArray->first();
    auto limit = static_cast<float>(qSqrt(m_itemCount) / 2.0f);
    for (auto i = -limit; i < limit;i++)
    {
        for (auto j = -limit; j < limit; j++)
        {
            ptrToDataArray->setPosition(QVector3D(i + 0.5f,
                                                  qSin(qDegreesToRadians((i * j) / m_curveDivider)),
                                                  j + 0.5f));
            ptrToDataArray++;
        }
    }
    m_graph->seriesList().at(0)->dataProxy()->resetArray(dataArray);
}

void ScatterDataModifier::AddData(const QVector<QVector3D>& Vec3D, QStringList color)
{
    //берем каждый 10 элемент
    auto size = m_graph->seriesList().length();
    //series->setBaseColor(color.at (series_vector.length()));    
    qDebug()<<size<<" size of data";
    for(size_t i = 0;i < static_cast<size_t>(Vec3D.length());i++)
    {
        auto series = new QScatter3DSeries();
        series->setItemSize(0.15f);
        series->setBaseColor(color.at(i));
        auto item3D = new QScatterDataItem;
        item3D->setX(Vec3D[i].x());
        item3D->setY(Vec3D[i].z());
        item3D->setZ(Vec3D[i].y());
        series->dataProxy()->addItem(*item3D);
        series_vector.push_back(series);
        m_graph->addSeries(series);
    }
}

void ScatterDataModifier::changeStyle(int style)
{
    auto comboBox = qobject_cast<QComboBox*>(sender());
    if (comboBox)
    {
        m_style = QAbstract3DSeries::Mesh(comboBox->itemData(style).toInt());
        if (m_graph->seriesList().size()) m_graph->seriesList().at(0)->setMesh(m_style);
    }
}

void ScatterDataModifier::setSmoothDots(int smooth)
{
    m_smooth = bool(smooth);
    auto series = m_graph->seriesList().at(0);
    series->setMeshSmooth(m_smooth);
}

void ScatterDataModifier::changeTheme(int theme)
{
    auto currentTheme = m_graph->activeTheme();
    currentTheme->setType(Q3DTheme::Theme(theme));
    emit backgroundEnabledChanged(currentTheme->isBackgroundEnabled());
    emit gridEnabledChanged(currentTheme->isGridEnabled());
    emit fontChanged(currentTheme->font());
}

void ScatterDataModifier::changePresetCamera()
{
    static int preset = Q3DCamera::CameraPresetFrontLow;
    m_graph->scene()->activeCamera()->setCameraPreset((Q3DCamera::CameraPreset)preset);
    if (++preset > Q3DCamera::CameraPresetDirectlyBelow) preset = Q3DCamera::CameraPresetFrontLow;
}

void ScatterDataModifier::changeLabelStyle()
{
    m_graph->activeTheme()->setLabelBackgroundEnabled(!m_graph->activeTheme()->isLabelBackgroundEnabled());
}

void ScatterDataModifier::changeFont(const QFont &font)
{
    auto newFont = font;
    newFont.setPointSizeF(m_fontSize);
    m_graph->activeTheme()->setFont(newFont);
}

void ScatterDataModifier::shadowQualityUpdatedByVisual(QAbstract3DGraph::ShadowQuality sq)
{
    auto quality = static_cast<int>(sq);
    emit shadowQualityChanged(quality); // connected to a checkbox in main.cpp
}

void ScatterDataModifier::changeShadowQuality(int quality)
{
    auto sq = QAbstract3DGraph::ShadowQuality(quality);
    m_graph->setShadowQuality(sq);
}

void ScatterDataModifier::setBackgroundEnabled(int enabled)
{
    m_graph->activeTheme()->setBackgroundEnabled((bool)enabled);
}

void ScatterDataModifier::setGridEnabled(int enabled)
{
    m_graph->activeTheme()->setGridEnabled((bool)enabled);
}

void ScatterDataModifier::clear()
{

    for(size_t i = 0; i < static_cast<size_t>(series_vector.length());i++)
    {
        m_graph->removeSeries(series_vector[i]);
    }
    series_vector.clear();
}
QVector3D ScatterDataModifier::randVector()
{
    return QVector3D(
                (float)(QRandomGenerator::global()->bounded(100)) / 2.0f -
                (float)(QRandomGenerator::global()->bounded(100)) / 2.0f,
                (float)(QRandomGenerator::global()->bounded(100)) / 100.0f -
                (float)(QRandomGenerator::global()->bounded(100)) / 100.0f,
                (float)(QRandomGenerator::global()->bounded(100)) / 2.0f -
                (float)(QRandomGenerator::global()->bounded(100)) / 2.0f);
}
