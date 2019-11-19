enum GUI_SELECTED_VALUES {
	GUI_SERVER,
	GUI_FIREWALL,
	GUI_BILLING,
	GUI_SETTINGS
};

template <class T>
inline void apiDeinitHandler(int guiCode, T className) {
	switch (guiCode) {
		case GUI_SERVER: {
			className->deinitServerTabGUI();
			className->deinitServerTabGUI_Page2();
			className->deinitServerTabGUI_Page3();
			break;
		}
		case GUI_FIREWALL: className->deinitFirewallTabGUI(); break;
		case GUI_BILLING:  className->deinitBillingTabGUI();  break;
		case GUI_SETTINGS: className->deinitSettingsTabGUI(); break;
	}
}