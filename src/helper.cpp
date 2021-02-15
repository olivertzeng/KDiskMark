#include <QFile>

#include "helper.h"

ActionReply Helper::dropcache(const QVariantMap& args) {
    ActionReply reply;

    if (args["actuallyDo"].toBool()) {
        QFile file("/proc/sys/vm/drop_caches");

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            reply = ActionReply::HelperErrorReply();
            reply.setErrorDescription(file.errorString());
            return reply;
        }

        file.write("1");

        file.close();
    }

    return reply;
}

KAUTH_HELPER_MAIN("org.jonmagon.kdiskmark", Helper)
