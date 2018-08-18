#include "stable.h"
#include "overlay.h"
#include "hookapp.h"
#include "session.h"

const char k_overlayIpcName[] = "n_overlay_1a1y2o8l0b";

namespace overlay
{

OverlayConnector::OverlayConnector()
{
}

OverlayConnector::~OverlayConnector()
{
}

void OverlayConnector::start()
{
    CHECK_THREAD(Threads::HookApp);

    std::string ipcName = k_overlayIpcName;
    ipcName.append("-");
    ipcName.append(win_utils::toLocal8Bit(HookApp::instance()->procName()));
    ipcName.append("-");
    ipcName.append(std::to_string(::GetCurrentProcessId()));
    getIpcCenter()->init(ipcName);

    std::string mainIpcName = k_overlayIpcName;
    mainIpcName.append("-");
    ipcLink_ = getIpcCenter()->getLink(mainIpcName);
    ipcLink_->addClient(this);
    getIpcCenter()->connectToHost(ipcLink_, "", "", false);
}

void OverlayConnector::quit()
{
    CHECK_THREAD(Threads::HookApp);

    if (ipcLink_)
    {
        _sendOverlayExit();
        getIpcCenter()->closeLink(ipcLink_);
        ipcLink_ = nullptr;
    }
    getIpcCenter()->uninit();
}

void OverlayConnector::sendGraphicsHookResult()
{
    CHECK_THREAD(Threads::HookApp);

    _sendGraphicsHookResult();
}

void OverlayConnector::sendGraphicsInitResult()
{
    CHECK_THREAD(Threads::Graphics);

    HookApp::instance()->async([this]() {
        _sendGraphicsInitResult();
    });
}

void OverlayConnector::sendGameWindowInput()
{
    CHECK_THREAD(Threads::Window);

    HookApp::instance()->async([this]() {
        _sendGameWindowInput();
    });
}

void OverlayConnector::sendGameWindowEvent()
{
    CHECK_THREAD(Threads::Window);
    HookApp::instance()->async([this]() {
        _sendGameWindowEvent();
    });
}

void OverlayConnector::_heartbeat()
{
    CHECK_THREAD(Threads::HookApp);
}

void OverlayConnector::_sendOverlayExit()
{
    CHECK_THREAD(Threads::HookApp);

}

void OverlayConnector::_sendGameProcessInfo()
{
    CHECK_THREAD(Threads::HookApp);
}

void OverlayConnector::_sendGraphicsHookResult()
{
    CHECK_THREAD(Threads::HookApp);

}

void OverlayConnector::_sendGraphicsInitResult()
{
    CHECK_THREAD(Threads::HookApp);

}

void OverlayConnector::_sendGameWindowInput()
{
    CHECK_THREAD(Threads::HookApp);

}

void OverlayConnector::_sendGameWindowEvent()
{
    CHECK_THREAD(Threads::HookApp);

}

void OverlayConnector::onIpcMessage()
{

}

void OverlayConnector::onCommand()
{
}

void OverlayConnector::onGraphicsCommand()
{
}

void OverlayConnector::onLinkConnect(IIpcLink *link)
{
    DAssert(link == ipcLink_);

    LOGGER("n_overlay") << "@trace";

    this->_sendGameProcessInfo();
}

void OverlayConnector::onLinkClose(IIpcLink *link)
{
    DAssert(link == ipcLink_);
    ipcLink_ = nullptr;
}

void OverlayConnector::onMessage(IIpcLink * /*link*/, int /*hostPort*/, const std::string &message)
{

}

void OverlayConnector::saveClientId(IIpcLink * /*link*/, int clientId)
{
    ipcClientId_ = clientId;
}

} // namespace overlay