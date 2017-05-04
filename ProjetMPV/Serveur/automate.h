#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <QObject>
#include <QStateMachine>
#include <QState>
#include <QHistoryState>
#include <QFinalState>
#include <QSignalTransition>
#include <QTimer>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>
#include "sendjsoncommand.h"
#include "../../Common/common.h"

class Automate : public QObject
{
    Q_OBJECT
public:
    explicit Automate(QObject *parent = 0);

private:
    QStateMachine *machine;

    QState *play;
    QState *pause;
    QState *changement;
    QState *playPlaylist;
    QState *changementPlaylist;
    QState *pausePlaylist;

    QState *fonction;
    QHistoryState *fonctionHistory;

    QSignalTransition *dePlay;
    QSignalTransition *dePause;
    QSignalTransition *deChangement;
    QSignalTransition *deChangementPlaylist;
    QSignalTransition *dePlayPlaylist;
    QSignalTransition *dePausePlaylist;


    SendJSONCommand *mpv_json;

    QString currentMusique;


signals:

    void signalMachine(signalType,QVariantMap);
    void signalPause();
    void signalChangement();
    void signalToUI(signalType,QVariantMap);
    void signalChangementPlaylist();
    void signalPausePlaylist();

public slots:

    void messageFromServer(signalType, QVariantMap);
    void start(bool);
    void changementMusique();
    void playMusique();
    void pauseMusique();
    void readSocket();

};

#endif // AUTOMATE_H
