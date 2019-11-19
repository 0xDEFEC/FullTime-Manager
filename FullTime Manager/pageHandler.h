enum PAGE_VALUES {
	PAGE_1 = 1,
	PAGE_2,
	PAGE_3
};

template <class T>
void pageSwitchHandler(int selectedPage, T className) { // deinits the respective tab depending on the page selected
	switch (selectedPage) {
		case PAGE_1: {
			className->deinitServerTabGUI_Page2();
			className->initServerTabGUI();
			break;
		}
		case PAGE_2: {
			className->deinitServerTabGUI();
			className->deinitServerTabGUI_Page3();
			className->initServerTabGUI_Page2();
			break;
		}
		case PAGE_3: {
			className->deinitServerTabGUI_Page2();
			className->initServerTabGUI_Page3();
		}
	}
}