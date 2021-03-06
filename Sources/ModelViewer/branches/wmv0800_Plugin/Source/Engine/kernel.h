// Main Kernel for WMV Engine
#ifndef WMV_KERNEL_H
#define WMV_KERNEL_H

// Qt Includes
#include <QString>
#include <QMap>

// Primary Includes
#include "../Foundation/Singleton.h"
#include "wmv_engine.h"
#include "version.h"

// Other includes
#include "display_server.h"			// Our Display Engine list
#include "model_exporter_server.h"	// Our 3D Model Exporter Engine list
#include "video_exporter_server.h"	// Our Video Exporter Engine list
#include "plugin.h"					// The Plugin system

namespace WMVEngine {

class Kernel{
	public:
		QString TestText;

		// Access the Display Server
		DisplayServer &getDisplayServer() {return m_DisplayServer;}
		// Access the 3D Model Exporter Server
		ModelExporterServer &getModelExporterServer() {return m_ModelExporterServer;}
		// Access the Video Exporter Server
		VideoExporterServer &getVideoExporterServer() {return m_VideoExporterServer;}

		// Loads a Plugin
		void loadPlugin(const QString &sFileName) {
			QLOG_TRACE() << "Loading Plugin:" << sFileName;
			QLOG_TRACE() << "Checking to see if we've already loaded it...";
			if (m_LoadedPlugins.contains(sFileName) == false){
				QLOG_TRACE() << "Plugin Not Loaded. Loading...";
				Plugin p = Plugin(sFileName);
				m_LoadedPlugins.insert(sFileName,p);
				p.registerPlugin(*this);
			}else{
				QLOG_TRACE() << "Plugin already loaded. Aborting...";
			}
		}
		Kernel(){ TestText = "Default Test Text"; }

	private:
		typedef QMap<QString,Plugin> PluginMap;

		PluginMap				m_LoadedPlugins;			// All the Plugins
		DisplayServer			m_DisplayServer;			// Display/Renderer Server
		ModelExporterServer		m_ModelExporterServer;		// Model Exporter Server
		VideoExporterServer		m_VideoExporterServer;		// Video Exporter Server
};

#define TheKernel Singleton<Kernel>::getInstance()

}	// End Namespace

#endif