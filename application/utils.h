// SPDX-FileCopyrightText: 2019 - 2022 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef UTILS_H
#define UTILS_H
#define SINGLE_READ_CNT 500
#include <QObject>
#include <QHash>
/**
 * @brief 公用工具静态函数类
 */
class Utils : public QObject
{
    Q_OBJECT

public:
    explicit Utils(QObject *parent = nullptr);
    ~Utils();
    /**
     * @brief The CommandErrorType enum
     * QProccess命令返回日志的过程中如果发生报错的类型
     */
    enum CommandErrorType {
        NoError = 0x0000, //无错误，预备，一般不用
        PermissionError = 0x0001, //权限问题
        RetryError = 0x0002 //返回请重试的情况
    };
    static QHash<QString, QPixmap> m_imgCacheHash;
    static QHash<QString, QString> m_fontNameCache;

    static QString getQssContent(const QString &filePath);
    static QString getConfigPath();
    static bool isFontMimeType(const QString &filePath);
    static bool isTextFileType(const QString &filePath);
    static QString suffixList();
    static QPixmap renderSVG(const QString &filePath, const QSize &size);
    static QString loadFontFamilyFromFiles(const QString &fontFileName);
    static QByteArray replaceEmptyByteArray(QByteArray &iReplaceStr);
    static CommandErrorType isErroCommand(const QString &str);
    static bool checkAndDeleteDir(const QString &iFilePath);
    static bool deleteDir(const QString &iFilePath);
    static void replaceColorfulFont(QString *iStr);
    static bool isWayland();
    static bool sleep(unsigned int msec);
    //创建多级文件夹
    static QString mkMutiDir(const QString &path);
    //授权框
    static bool checkAuthorization(const QString &actionId, qint64 applicationPid);
};

#endif
