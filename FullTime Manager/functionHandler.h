// enum holding billing-oriented values
enum FTH_BILLING_REQUESTS { // increment each enum by ten to avoid collision
	BILLING_INFO_REQUEST,                   // [GET]    api.fulltimehosting.net/me - gets account info - DONE
	BILLING_SETINFO_REQUEST,		// [PUT]    api.fulltimehosting.net/me - sets account info - DONE - NEEDS TESTING
												// PARAMS:
													// [firstname]   : string
													// [lastname]    : string
													// [country]     : string
													// [state]       : string
													// [address1]    : string
													// [city]        : string
													// [postcode]    : string
													// [phonenumber] : string
													// [email]       : string
													// [password2]   : string
													// [confirmpass] : string
	BILLING_INVOICEINFO_REQUEST,		// [GET]    api.fulltimehosting.net/me/invoice/[invoiceID] - gets info of ticket based on ID - DONE
												// PARAMS:
													// [invoiceID] : integer ($int64)
	BILLING_INVOICES_REQUEST,		// [GET]    api.fulltimehosting.net/me/invoice - gets invoices - DONE
	BILLING_SERVICES_REQUEST,		// [GET]    api.fulltimehosting.net/server - get active services - DONE
	BILLING_GETPRODUCTS_REQUEST,		// [GET]    api.fulltimehosting.net/products - get available products - DONE
	BILLING_GETTICKETS_REQUEST,             // [GET]    api.fulltimehosting.net/me/ticket - get tickets - DONE
	BILLING_SENDTICKET_REQUEST,             // [POST]   api.fulltimehosting.net/me/ticket - open ticket - DONE - NEEDS TESTING
												// PARAMS:
													// [subject]  : string
													// [priority] : string
													// [deptID]   : string
													// [message]  : string
	BILLING_GETTICKET_REQUEST,		// [GET]    api.fulltimehosting.net/me/ticket/[ticketID] - get ticket by ID - DONE
												// PARAMS:
													// [ticketID] : integer ($int64)
	BILLING_REPLYTICKET_REQUEST,		// [PUT]    api.fulltimehosting.net/me/ticket/[ticketID] - reply to ticket ID - DONE - NEEDS TESTING
												// PARAMS:
													// [ticketID] : integer ($int64)
													// [message]  : string
	BILLING_CLOSETICKET_REQUEST,		// [POST]   api.fulltimehosting.net/me/ticket/[ticketID]/close - close ticket by ID - DONE
												// PARAMS:
													// [ticketID] : integer ($int64)
	BILLING_PROMOINFO_REQUEST		// [GET]    api.fulltimehosting.net/order/promotion/[code] - gets info on supplied promo code - DONE
												// PARAMS:
													// [code] : string
};

// enum holding server-oriented values
enum FTH_SERVER_REQUESTS {
	SERVER_CONNECT_REQUEST = 12,            // [SSH]    custom function
	SERVER_INFO_REQUEST,                    // [GET]    api.fulltimehosting.net/server/[serverID] - gets info from server based on ID - DONE
	SERVER_DELETE_REQUEST,                  // [DELETE] api.fulltimehosting.net/server/[serverID] - deletes server based on ID - DONE NEEDS TESTING
	SERVER_EXPIREINFO_REQUEST,              // [GET]    api.fulltimehosting.net/server/[serverID]/expiration - gets server expiration info based on ID - DONE
	SERVER_MEDIAINFO_REQUEST,               // [GET]    api.fulltimehosting.net/server/[serverID]/media - gets server media info based on ID - DONE
	SERVER_BOOTORDER_REQUEST,               // [PUT]    api.fulltimehosting.net/server/[serverID]/media - sets server boot order - DONE NEEDS TESTING
	SERVER_POWERON_REQUEST,                 // [POST]   api.fulltimehosting.net/server/[serverID]/start - starts server - DONE
	SERVER_REBOOT_REQUEST,                  // [POST]   api.fulltimehosting.net/server/[serverID]/restart - reboot server - DONE
	SERVER_SHUTDOWN_REQUEST,                // [POST]   api.fulltimehosting.net/server/[serverID]/shutdown - shutdown server - DONE
	SERVER_FORCESTOP_REQUEST,               // [POST]   api.fulltimehosting.net/server/[serverID]/stop - force stop server - DONE
	SERVER_RENEW_REQUEST,                   // [POST]   api.fulltimehosting.net/server/[serverID]/renew - renew server - DONE
	SERVER_VNCINFO_REQUEST,                 // [GET]    api.fulltimehosting.net/server/[serverID]/vnc - gets VNC info - DONE
	SERVER_VNCSCOPEDINFO_REQUEST,           // [GET]    api.fulltimehosting.net/server/[serverID]/statistics/[timeFrame] - gets VNC info in timeFrame - DONE
	SERVER_BACKUPINFO_REQUEST,              // [GET]    api.fulltimehosting.net/server/[serverID]/backup - gets backup info - DONE
	SERVER_BACKUP_REQUEST,                  // [PUT]    api.fulltimehosting.net/server/[serverID]/backup - make a backup - DONE NEEDS TESTING
	SERVER_DELETEBACKUP_REQUEST,            // [DELETE] api.fulltimehosting.net/server/[serverID]/backup - delete backup - DONE
	SERVER_BANDWIDTHINFO_REQUEST,           // [GET]    api.fulltimehosting.net/server/[serverID]/bandwidthusage - gets bandwidth usage info - DONE
	SERVER_NEWISO_REQUEST,                  // [PUT]    api.fulltimehosting.net/server/[serverID]/iso - select new ISO - DONE NEEDS TESTING
	SERVER_SETHOSTNAME_REQUEST,             // [PUT]    api.fulltimehosting.net/server/[serverID]/hostname - set hostname info - DONE
	SERVER_RESETPASSWORD_REQUEST,           // [POST]   api.fulltimehosting.net/server/[serverID]/resetpassword - resets server password - DONE
	SERVER_REBUILD_REQUEST,                 // [POST]   api.fulltimehosting.net/server/[serverID]/rebuild - rebuild server - DONE
	SERVER_IPINFO_REQUEST,                  // [GET]    api.fulltimehosting.net/server/[serverID]/ip - gets server IP info - DONE
	SERVER_GETFIREWALLRULES_REQUEST,        // [GET]    api.fulltimehosting.net/server/[serverID]/firewall - gets server firewall rules - DONE
	SERVER_TOGGLEFIREWALLRULE_REQUEST,      // [PUT]    api.fulltimehosting.net/server/[serverID]/firewall - toggle firewall rule - DONE NEEDS TESTING
	SERVER_ADDFIREWALLRULE_REQUEST,         // [POST]   api.fulltimehosting.net/server/[serverID]/firewall - add firewall rule - DONE NEEDS TESTING
	SERVER_DELETEFIREWALLRULE_REQUEST,      // [DELETE] api.fulltimehosting.net/server/[serverID]/firewall - delete server firewall rule - DONE NEEDS TESTING
	SERVER_SETRDNS_REQUEST,                 // [POST]   api.fulltimehosting.net/server/[serverID]/ip/[ip]/rdns - set rDNS info - DONE NEEDS TESTING - METHOD MAY BE WRONG IN APIDOCS
	SERVER_GETIPRULES_REQUEST,              // [POST]   api.fulltimehosting.net/server/[serverID]/ip/[ip] - get IP rules - DONE READ BELOW
															// THIS HAS INCORRECT DOCUMENTATION! INCORRECT METHODS ARE BEING SAID TO BE USED! ANNOYING!!!!
	SERVER_GETMITIGATION_REQUEST,           // [GET]    api.fulltimehosting.net/server/[serverID]/ip/[ip]/mitigation - get mitigation status - DONE
	SERVER_TOGGLEMITIGATION_REQUEST,        // [PUT]    api.fulltimehosting.net/server/[serverID]/ip/[ip]/mitigation - set mitigation status - DONE NEEDS TESTING
	SERVER_ADDGAMERULE_REQUEST,             // [POST]   api.fulltimehosting.net/server/[serverID]/ip/[ip]/game - add GAME rule - DONE NEEDS TESTING
	SERVER_TOGGLEGAMEFIREWALL_REQUEST,      // [PUT]    api.fulltimehosting.net/server/[serverID]/ip/[ip]/game - toggle GAME firewall - DONE NEEDS TESTING (I GUESS)
	SERVER_DELETEGAMEFIREWALLRULE_REQUEST,  // [DELETE] api.fulltimehosting.net/server/[serverID]/ip/[ip]/game/[rule] - delete specified GAME rule - DONE
	SERVER_SETFIREWALLTEMPLATE_REQUEST,     // [PUT]    api.fulltimehosting.net/server/[serverID]/ip/[ip]/firewall/template - set firewall template - DONE
	SERVER_ADDFIREWALL_REQUEST,             // [POST]   api.fulltimehosting.net/server/[serverID]/ip/[ip]/firewall - add firewall - DONE NEEDS TESTING
	SERVER_DELETEIPFIREWALLRULE_REQUEST,    // [DELETE] api.fulltimehosting.net/server/[serverID]/ip/[ip]/firewall/[rule] - delete IP firewall rule
	SERVER_SETMITIGATIONTIMEOUT_REQUEST     // [PUT]    api.fulltimehosting.net/server/[serverID]/ip/[ip]/mitigationtimeout - set timeout for mitigation
};

// enum holding firewall-oriented values - logs mainly.
enum FTH_FIREWALL_REQUESTS { // all done
	FIREWALL_GETLOGS_REQUEST = 49,          // [GET]    api.fulltimehosting.net/firewall_log - get firewall logs - DONE
	FIREWALL_DELETELOGS_REQUEST,            // [DELETE] api.fulltimehosting.net/firewall_log - delete firewall logs - DONE
	FIREWALL_GETUNREADLOGS_REQUEST          // [GET]    api.fulltimehosting.net/firewall_log/unseen - get unread firewall logs - DONE
};

// only deinits functions that explicitly spawn components - i.e. only some BILLING and most SERVER functions
		template <class T>
		void functionDeinitHandler(int selectedFunction, T className) {
			switch (selectedFunction) {
				// BILLING begin
				case BILLING_INVOICEINFO_REQUEST: {
					className->billing_GetInvoiceByIDButtonComponent_TextField->Visible = false;
					className->billing_GetInvoiceByIDComponent_SendButton->Visible = false;
					className->billing_GetInvoiceByIDComponent_InstructionLabel->Visible = false;
		
					className->billing_GetInvoiceByIDButtonComponent_TextField->Enabled = false;
					className->billing_GetInvoiceByIDComponent_SendButton->Enabled = false;
					className->billing_GetInvoiceByIDComponent_InstructionLabel->Enabled = false;
					break;
				}
				case BILLING_GETTICKET_REQUEST: {
					className->billing_GetTicketByIDButtonComponent_TextField->Visible = false;
					className->billing_GetTicketByIDButtonComponent_SendButton->Visible = false;
					className->billing_GetTicketByIDButtonComponent_InstructionLabel->Visible = false;

					className->billing_GetTicketByIDButtonComponent_TextField->Enabled = false;
					className->billing_GetTicketByIDButtonComponent_SendButton->Enabled = false;
					className->billing_GetTicketByIDButtonComponent_InstructionLabel->Enabled = false;
					break;
				}
				case BILLING_PROMOINFO_REQUEST: {
					className->billing_GetPromoInfoButtonComponent_TextField->Visible = false;
					className->billing_GetPromoInfoButtonComponent_SendButton->Visible = false;
					className->billing_GetPromoInfoButtonComponent_InstructionLabel->Visible = false;

					className->billing_GetPromoInfoButtonComponent_TextField->Enabled = false;
					className->billing_GetPromoInfoButtonComponent_SendButton->Enabled = false;
					className->billing_GetPromoInfoButtonComponent_InstructionLabel->Enabled = false;
					break;
				}
				case BILLING_CLOSETICKET_REQUEST: {
					className->billing_CloseTicketByIDButtonComponent_TextField->Visible = false;
					className->billing_CloseTicketByIDButtonComponent_SendButton->Visible = false;
					className->billing_CloseTicketByIDButtonComponent_InstructionLabel->Visible = false;
				
					className->billing_CloseTicketByIDButtonComponent_TextField->Enabled = false;
					className->billing_CloseTicketByIDButtonComponent_SendButton->Enabled = false;
					className->billing_CloseTicketByIDButtonComponent_InstructionLabel->Enabled = false;
					break;
				}
				case BILLING_SENDTICKET_REQUEST: {
					className->billing_OpenNewTicketButtonComponent_TextField_Subject->Visible = false;
					className->billing_OpenNewTicketButtonComponent_TextField_Priority->Visible = false;
					className->billing_OpenNewTicketButtonComponent_TextField_Department->Visible = false;
					className->billing_OpenNewTicketButtonComponent_TextField_Message->Visible = false;
					className->billing_OpenNewTicketButtonComponent_SendButton->Visible = false;
					className->billing_OpenNewTicketButtonComponent_InstructionLabel_Subject->Visible = false;
					className->billing_OpenNewTicketButtonComponent_InstructionLabel_Priority->Visible = false;
					className->billing_OpenNewTicketButtonComponent_InstructionLabel_Department->Visible = false;
					className->billing_OpenNewTicketButtonComponent_InstructionLabel_Message->Visible = false;

					className->billing_OpenNewTicketButtonComponent_TextField_Subject->Enabled = false;
					className->billing_OpenNewTicketButtonComponent_TextField_Priority->Enabled = false;
					className->billing_OpenNewTicketButtonComponent_TextField_Department->Enabled = false;
					className->billing_OpenNewTicketButtonComponent_TextField_Message->Enabled = false;
					className->billing_OpenNewTicketButtonComponent_SendButton->Enabled = false;
					className->billing_OpenNewTicketButtonComponent_InstructionLabel_Subject->Enabled = false;
					className->billing_OpenNewTicketButtonComponent_InstructionLabel_Priority->Enabled = false;
					className->billing_OpenNewTicketButtonComponent_InstructionLabel_Department->Enabled = false;
					className->billing_OpenNewTicketButtonComponent_InstructionLabel_Message->Enabled = false;
					break;
				}
				case BILLING_REPLYTICKET_REQUEST: {
					className->billing_ReplyToTicketButtonComponent_TextField_TicketID->Visible = false;
					className->billing_ReplyToTicketButtonComponent_TextField_Message->Visible = false;
					className->billing_ReplyToTicketButtonComponent_SendButton->Visible = false;
					className->billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID->Visible = false;
					className->billing_ReplyToTicketButtonComponent_InstructionLabel_Message->Visible = false;

					className->billing_ReplyToTicketButtonComponent_TextField_TicketID->Enabled = false;
					className->billing_ReplyToTicketButtonComponent_TextField_Message->Enabled = false;
					className->billing_ReplyToTicketButtonComponent_SendButton->Enabled = false;
					className->billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID->Enabled = false;
					className->billing_ReplyToTicketButtonComponent_InstructionLabel_Message->Enabled = false;
					break;
				}
				case BILLING_SETINFO_REQUEST: {
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName->Visible = false;
					className->billing_SetAccountInfoButtonComponent_TextField_FirstName->Visible = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_LastName->Visible = false;
					className->billing_SetAccountInfoButtonComponent_TextField_LastName->Visible = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_Country->Visible = false;
					className->billing_SetAccountInfoButtonComponent_TextField_Country->Visible = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_State->Visible = false;
					className->billing_SetAccountInfoButtonComponent_TextField_State->Visible = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_Address->Visible = false;
					className->billing_SetAccountInfoButtonComponent_TextField_Address->Visible = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_City->Visible = false;
					className->billing_SetAccountInfoButtonComponent_TextField_City->Visible = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode->Visible = false;
					className->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Visible = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber->Visible = false;
					className->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Visible = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_Email->Visible = false;
					className->billing_SetAccountInfoButtonComponent_TextField_Email->Visible = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_Password->Visible = false;
					className->billing_SetAccountInfoButtonComponent_TextField_Password->Visible = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword->Visible = false;
					className->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Visible = false;
					className->billing_SetAccountInfoButtonComponent_SaveButton->Visible = false;

					className->billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_TextField_FirstName->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_LastName->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_TextField_LastName->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_Country->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_TextField_Country->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_State->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_TextField_State->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_Address->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_TextField_Address->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_City->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_TextField_City->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_Email->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_TextField_Email->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_Password->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_TextField_Password->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Enabled = false;
					className->billing_SetAccountInfoButtonComponent_SaveButton->Enabled = false;
					break;
				}
				// SERVER begin
				case SERVER_INFO_REQUEST: {
					className->server_GetInfoButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_GetInfoButtonComponent_TextField_ServerID->Visible = false;
					className->server_GetInfoButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_GetInfoButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_GetInfoButtonComponent_TextField_ServerID->Enabled = false;
					className->server_GetInfoButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;
				}
				case SERVER_DELETE_REQUEST: {
					className->server_DeleteByIDButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_DeleteByIDButtonComponent_TextField_ServerID->Visible = false;
					className->server_DeleteByIDButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_DeleteByIDButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_DeleteByIDButtonComponent_TextField_ServerID->Enabled = false;
					className->server_DeleteByIDButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;
				}
				case SERVER_EXPIREINFO_REQUEST: {
					className->server_GetExpireInfoButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_GetExpireInfoButtonComponent_TextField_ServerID->Visible = false;
					className->server_GetExpireInfoButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_GetExpireInfoButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_GetExpireInfoButtonComponent_TextField_ServerID->Enabled = false;
					className->server_GetExpireInfoButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;
				}
				case SERVER_MEDIAINFO_REQUEST: {
					className->server_GetMediaInfoButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_GetMediaInfoButtonComponent_TextField_ServerID->Visible = false;
					className->server_GetMediaInfoButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_GetMediaInfoButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_GetMediaInfoButtonComponent_TextField_ServerID->Enabled = false;
					className->server_GetMediaInfoButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;
				}
				case SERVER_POWERON_REQUEST: {
					className->server_PowerOnServerButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_PowerOnServerButtonComponent_TextField_ServerID->Visible = false;
					className->server_PowerOnServerButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_PowerOnServerButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_PowerOnServerButtonComponent_TextField_ServerID->Enabled = false;
					className->server_PowerOnServerButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;

				}
				case SERVER_REBOOT_REQUEST: {
					className->server_RestartServerButtonComponent_Instructionlabel_ServerID->Visible = false;
					className->server_RestartServerButtonComponent_TextField_ServerID->Visible = false;
					className->server_RestartServerButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_RestartServerButtonComponent_Instructionlabel_ServerID->Enabled = false;
					className->server_RestartServerButtonComponent_TextField_ServerID->Enabled = false;
					className->server_RestartServerButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;

				}
				case SERVER_SHUTDOWN_REQUEST: {
					className->server_ShutdownServerButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_ShutdownServerButtonComponent_TextField_ServerID->Visible = false;
					className->server_ShutdownServerButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_ShutdownServerButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_ShutdownServerButtonComponent_TextField_ServerID->Enabled = false;
					className->server_ShutdownServerButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;
				}
				case SERVER_FORCESTOP_REQUEST: {
					className->server_ForceStopServerButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_ForceStopServerButtonComponent_TextField_ServerID->Visible = false;
					className->server_ForceStopServerButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_ForceStopServerButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_ForceStopServerButtonComponent_TextField_ServerID->Enabled = false;
					className->server_ForceStopServerButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;
				}
				case SERVER_RENEW_REQUEST: {
					className->server_RenewServerButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_RenewServerButtonComponent_TextField_ServerID->Visible = false;
					className->server_RenewServerButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_RenewServerButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_RenewServerButtonComponent_TextField_ServerID->Enabled = false;
					className->server_RenewServerButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;
				}
				case SERVER_VNCINFO_REQUEST: {
					className->server_GetVNCInfoButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_GetVNCInfoButtonComponent_TextField_ServerID->Visible = false;
					className->server_GetVNCinfoButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_GetVNCInfoButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_GetVNCInfoButtonComponent_TextField_ServerID->Enabled = false;
					className->server_GetVNCinfoButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;
				}
				case SERVER_BACKUPINFO_REQUEST: {
					className->server_GetBackupInfoButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_GetBackupInfoButtonComponent_TextField_ServerID->Visible = false;
					className->server_GetBackupInfoButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_GetBackupInfoButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_GetBackupInfoButtonComponent_TextField_ServerID->Enabled = false;
					className->server_GetBackupInfoButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;
				}
				case SERVER_BACKUP_REQUEST: {
					className->server_MakeBackupButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_MakeBackupButtonComponent_TextField_ServerID->Visible = false;
					className->server_MakeBackupButtonComponent_InstructionLabel_Hostname->Visible = false;
					className->server_MakeBackupButtonComponent_TextField_Hostname->Visible = false;
					className->server_MakeBackupButtonComponent_InstructionLabel_Port->Visible = false;
					className->server_MakeBackupButtonComponent_TextField_Port->Visible = false;
					className->server_MakeBackupButtonComponent_InstructionLabel_Password->Visible = false;
					className->server_MakeBackupButtonComponent_TextField_Password->Visible = false;
					className->server_MakeBackupButtonComponent_InstructionLabel_Rotation->Visible = false;
					className->server_MakeBackupButtonComponent_TextField_Rotation->Visible = false;
					className->server_MakeBackupButtonComponent_InstructionLabel_UseSSL->Visible = false;
					className->server_MakeBackupButtonComponent_TextField_UseSSL->Visible = false;
					className->server_MakeBackupButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;

					className->server_MakeBackupButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_MakeBackupButtonComponent_TextField_ServerID->Enabled = false;
					className->server_MakeBackupButtonComponent_InstructionLabel_Hostname->Enabled = false;
					className->server_MakeBackupButtonComponent_TextField_Hostname->Enabled = false;
					className->server_MakeBackupButtonComponent_InstructionLabel_Port->Enabled = false;
					className->server_MakeBackupButtonComponent_TextField_Port->Enabled = false;
					className->server_MakeBackupButtonComponent_InstructionLabel_Password->Enabled = false;
					className->server_MakeBackupButtonComponent_TextField_Password->Enabled = false;
					className->server_MakeBackupButtonComponent_InstructionLabel_Rotation->Enabled = false;
					className->server_MakeBackupButtonComponent_TextField_Rotation->Enabled = false;
					className->server_MakeBackupButtonComponent_InstructionLabel_UseSSL->Enabled = false;
					className->server_MakeBackupButtonComponent_TextField_UseSSL->Enabled = false;
					className->server_MakeBackupButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					break;
				}
				case SERVER_DELETEBACKUP_REQUEST: {
					className->server_DeleteBackupButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_DeleteBackupButtonComponent_TextField_ServerID->Visible = false;
					className->server_DeleteBackupButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_DeleteBackupButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_DeleteBackupButtonComponent_TextField_ServerID->Enabled = false;
					className->server_DeleteBackupButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;
				}
				case SERVER_BANDWIDTHINFO_REQUEST: {
					className->server_GetBandwidthButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_GetBandwidthButtonComponent_TextField_ServerID->Visible = false;
					className->server_GetBandwidthButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_GetBandwidthButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_GetBandwidthButtonComponent_TextField_ServerID->Enabled = false;
					className->server_GetBandwidthButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;
				}
				case SERVER_NEWISO_REQUEST: {
					className->server_SelectISOButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_SelectISOButtonComponent_TextField_ServerID->Visible = false;
					className->server_SelectISOButtonComponent_InstructionLabel_FirstFile->Visible = false;
					className->server_SelectISOButtonComponent_TextField_FirstFile->Visible = false;
					className->server_SelectISOButtonComponent_InstructionLabel_SecondFile->Visible = false;
					className->server_SelectISOButtonComponent_TextField_SecondFile->Visible = false;
					className->server_SelectISOButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;

					className->server_SelectISOButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_SelectISOButtonComponent_TextField_ServerID->Enabled = false;
					className->server_SelectISOButtonComponent_InstructionLabel_FirstFile->Enabled = false;
					className->server_SelectISOButtonComponent_TextField_FirstFile->Enabled = false;
					className->server_SelectISOButtonComponent_InstructionLabel_SecondFile->Enabled = false;
					className->server_SelectISOButtonComponent_TextField_SecondFile->Enabled = false;
					className->server_SelectISOButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					break;
				}
				case SERVER_RESETPASSWORD_REQUEST: {
					className->server_ResetPasswordButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_ResetPasswordButtonComponent_TextField_ServerID->Visible = false;
					className->server_ResetPasswordButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_ResetPasswordButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_ResetPasswordButtonComponent_TextField_ServerID->Enabled = false;
					className->server_ResetPasswordButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;
				}
				case SERVER_SETHOSTNAME_REQUEST: {
					className->server_SetHostnameButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_SetHostnameButtonComponent_TextField_ServerID->Visible = false;
					className->server_SetHostnameButtonComponent_InstructionLabel_Hostname->Visible = false;
					className->server_SetHostnameButtonComponent_TextField_Hostname->Visible = false;
					className->server_SetHostnameButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;

					className->server_SetHostnameButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_SetHostnameButtonComponent_TextField_ServerID->Enabled = false;
					className->server_SetHostnameButtonComponent_InstructionLabel_Hostname->Enabled = false;
					className->server_SetHostnameButtonComponent_TextField_Hostname->Enabled = false;
					className->server_SetHostnameButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					break;
				}
				case SERVER_REBUILD_REQUEST: {
					className->server_RebuildButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_RebuildButtonComponent_TextField_ServerID->Visible = false;
					className->server_RebuildButtonComponent_InstructionLabel_NewOS->Visible = false;
					className->server_RebuildButtonComponent_TextField_NewOS->Visible = false;
					className->server_RebuildButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;

					className->server_RebuildButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_RebuildButtonComponent_TextField_ServerID->Enabled = false;
					className->server_RebuildButtonComponent_InstructionLabel_NewOS->Enabled = false;
					className->server_RebuildButtonComponent_TextField_NewOS->Enabled = false;
					className->server_RebuildButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					break;
				}
				case SERVER_IPINFO_REQUEST: {
					className->server_GetIPInfoButtonComponent_Instructionlabel_ServerID->Visible = false;
					className->server_GetIPInfoButtonComponent_TextField_ServerID->Visible = false;
					className->server_GetIPInfoButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_GetIPInfoButtonComponent_Instructionlabel_ServerID->Enabled = false;
					className->server_GetIPInfoButtonComponent_TextField_ServerID->Enabled = false;
					className->server_GetIPInfoButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;
				}
				case SERVER_VNCSCOPEDINFO_REQUEST: {
					className->server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_GetVNCInfoTFButtonComponent_TextField_ServerID->Visible = false;
					className->server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame->Visible = false;
					className->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Visible = false;
					className->server_GetVNCInfoTFButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;

					className->server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_GetVNCInfoTFButtonComponent_TextField_ServerID->Enabled = false;
					className->server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame->Enabled = false;
					className->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Enabled = false;
					className->server_GetVNCInfoTFButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					break;
				}
				case SERVER_BOOTORDER_REQUEST: {
					className->server_SetBootOrderButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_SetBootOrderButtonComponent_TextField_ServerID->Visible = false;
					className->server_SetBootOrderButtonComponent_InstructionLabel_BootOrder->Visible = false;
					className->server_SetBootOrderButtonComponent_TextField_BootOrder->Visible = false;
					className->server_SetBootOrderButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;

					className->server_SetBootOrderButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_SetBootOrderButtonComponent_TextField_ServerID->Enabled = false;
					className->server_SetBootOrderButtonComponent_InstructionLabel_BootOrder->Enabled = false;
					className->server_SetBootOrderButtonComponent_TextField_BootOrder->Enabled = false;
					className->server_SetBootOrderButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					break;
				}
				case SERVER_GETFIREWALLRULES_REQUEST: {
					className->server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_GetFirewallRulesButtonComponent_TextField_ServerID->Visible = false;
					className->server_GetFirewallRulesButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs->Visible = false;

					className->server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_GetFirewallRulesButtonComponent_TextField_ServerID->Enabled = false;
					className->server_GetFirewallRulesButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs->Enabled = false;
					break;
				}
				case SERVER_TOGGLEFIREWALLRULE_REQUEST: {
					className->server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Visible = false;
					className->server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle->Visible = false;
					className->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Visible = false;
					className->server_ToggleFirewallRuleButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;

					className->server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Enabled = false;
					className->server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle->Enabled = false;
					className->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Enabled = false;
					className->server_ToggleFirewallRuleButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					break;
				}
				case SERVER_ADDFIREWALLRULE_REQUEST: {
					className->server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_AddFirewallRuleButtonComponent_TextField_ServerID->Visible = false;
					className->server_AddFirewallRuleButtonComponent_InstructionLabel_Data->Visible = false;
					className->server_AddFirewallRuleButtonComponent_TextField_Data->Visible = false;
					className->server_AddFirewallRuleButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;

					className->server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_AddFirewallRuleButtonComponent_TextField_ServerID->Enabled = false;
					className->server_AddFirewallRuleButtonComponent_InstructionLabel_Data->Enabled = false;
					className->server_AddFirewallRuleButtonComponent_TextField_Data->Enabled = false;
					className->server_AddFirewallRuleButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					break;
				}
				case SERVER_DELETEFIREWALLRULE_REQUEST: {
					className->server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Visible = false;
					className->server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID->Visible = false;
					className->server_DeleteFirewallRuleButtonComponent_TextField_RID->Visible = false;
					className->server_DeleteFirewallRuleButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;

					className->server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Enabled = false;
					className->server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID->Enabled = false;
					className->server_DeleteFirewallRuleButtonComponent_TextField_RID->Enabled = false;
					className->server_DeleteFirewallRuleButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					break;
				}
				case SERVER_SETRDNS_REQUEST: {
					className->server_SetIPrDNSButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_SetIPrDNSButtonComponent_TextField_ServerID->Visible = false;
					className->server_SetIPrDNSButtonComponent_InstructionLabel_IP->Visible = false;
					className->server_SetIPrDNSButtonComponent_TextField_IP->Visible = false;
					className->server_SetIPrDNSButtonComponent_InstructionLabel_rDNS->Visible = false;
					className->server_SetIPrDNSButtonComponent_TextField_rDNS->Visible = false;
					className->server_SetIPrDNSButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;
					className->server_IndependentComponentShowIPs_RightPos->Visible = false;

					className->server_SetIPrDNSButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_SetIPrDNSButtonComponent_TextField_ServerID->Enabled = false;
					className->server_SetIPrDNSButtonComponent_InstructionLabel_IP->Enabled = false;
					className->server_SetIPrDNSButtonComponent_TextField_IP->Enabled = false;
					className->server_SetIPrDNSButtonComponent_InstructionLabel_rDNS->Enabled = false;
					className->server_SetIPrDNSButtonComponent_TextField_rDNS->Enabled = false;
					className->server_SetIPrDNSButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					className->server_IndependentComponentShowIPs_RightPos->Enabled = false;
					break;
				}
				case SERVER_GETIPRULES_REQUEST: {
					className->server_GetIPRulesButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_GetIPRulesButtonComponent_TextField_ServerID->Visible = false;
					className->server_GetIPRulesButtonComponent_InstructionLabel_IP->Visible = false;
					className->server_GetIPRulesButtonComponent_TextField_IP->Visible = false;
					className->server_GetIPRulesButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;
					className->server_IndependentComponentShowIPs->Visible = false;

					className->server_GetIPRulesButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_GetIPRulesButtonComponent_TextField_ServerID->Enabled = false;
					className->server_GetIPRulesButtonComponent_InstructionLabel_IP->Enabled = false;
					className->server_GetIPRulesButtonComponent_TextField_IP->Enabled = false;
					className->server_GetIPRulesButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					className->server_IndependentComponentShowIPs->Enabled = false;
					break;
				}
				case SERVER_GETMITIGATION_REQUEST: {
					className->server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_GetMitigationStatusButtonComponent_TextField_ServerID->Visible = false;
					className->server_GetMitigationStatusButtonComponent_InstructionLabel_IP->Visible = false;
					className->server_GetMitigationStatusButtonComponent_TextField_IP->Visible = false;
					className->server_GetMitigationStatusButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;
					className->server_IndependentComponentShowIPs->Visible = false;

					className->server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_GetMitigationStatusButtonComponent_TextField_ServerID->Enabled = false;
					className->server_GetMitigationStatusButtonComponent_InstructionLabel_IP->Enabled = false;
					className->server_GetMitigationStatusButtonComponent_TextField_IP->Enabled = false;
					className->server_GetMitigationStatusButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					className->server_IndependentComponentShowIPs->Enabled = false;
					break;
				}
				case SERVER_TOGGLEMITIGATION_REQUEST: {
					className->server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_SetMitigationStatusButtonComponent_TextField_ServerID->Visible = false;
					className->server_SetMitigationStatusButtonComponent_InstructionLabel_IP->Visible = false;
					className->server_SetMitigationStatusButtonComponent_TextField_IP->Visible = false;
					className->server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle->Visible = false;
					className->server_SetMitigationStatusButtonComponent_TextField_Toggle->Visible = false;
					className->server_SetMitigationStatusButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;
					className->server_IndependentComponentShowIPs_RightPos->Visible = false;

					className->server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_SetMitigationStatusButtonComponent_TextField_ServerID->Enabled = false;
					className->server_SetMitigationStatusButtonComponent_InstructionLabel_IP->Enabled = false;
					className->server_SetMitigationStatusButtonComponent_TextField_IP->Enabled = false;
					className->server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle->Enabled = false;
					className->server_SetMitigationStatusButtonComponent_TextField_Toggle->Enabled = false;
					className->server_SetMitigationStatusButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					className->server_IndependentComponentShowIPs_RightPos->Enabled = false;
					break;
				}
				case SERVER_ADDGAMERULE_REQUEST: {
					className->server_AddGAMERuleButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_AddGAMERuleButtonComponent_TextField_ServerID->Visible = false;
					className->server_AddGAMERuleButtonComponent_InstructionLabel_IP->Visible = false;
					className->server_AddGAMERuleButtonComponent_TextField_IP->Visible = false;
					className->server_AddGAMERuleButtonComponent_InstructionLabel_Proto->Visible = false;
					className->server_AddGAMERuleButtonComponent_TextField_Proto->Visible = false;
					className->server_AddGAMERuleButtonComponent_InstructionLabel_Port->Visible = false;
					className->server_AddGAMERuleButtonComponent_TextField_Port->Visible = false;
					className->server_AddGAMERuleButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;
					className->server_IndependentComponentShowIPs_RightPos->Visible = false;

					className->server_AddGAMERuleButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_AddGAMERuleButtonComponent_TextField_ServerID->Enabled = false;
					className->server_AddGAMERuleButtonComponent_InstructionLabel_IP->Enabled = false;
					className->server_AddGAMERuleButtonComponent_TextField_IP->Enabled = false;
					className->server_AddGAMERuleButtonComponent_InstructionLabel_Proto->Enabled = false;
					className->server_AddGAMERuleButtonComponent_TextField_Proto->Enabled = false;
					className->server_AddGAMERuleButtonComponent_InstructionLabel_Port->Enabled = false;
					className->server_AddGAMERuleButtonComponent_TextField_Port->Enabled = false;
					className->server_AddGAMERuleButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					className->server_IndependentComponentShowIPs_RightPos->Enabled = false;
					break;
				}
				case SERVER_TOGGLEGAMEFIREWALL_REQUEST: {
					className->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Visible = false;
					className->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP->Visible = false;
					className->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Visible = false;
					className->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle->Visible = false;
					className->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Visible = false;
					className->server_ToggleGAMEFirewallButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;
					className->server_IndependentComponentShowIPs_RightPos->Visible = false;

					className->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Enabled = false;
					className->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP->Enabled = false;
					className->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Enabled = false;
					className->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle->Enabled = false;
					className->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Enabled = false;
					className->server_ToggleGAMEFirewallButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					className->server_IndependentComponentShowIPs_RightPos->Enabled = false;
					break;
				}
				case SERVER_DELETEGAMEFIREWALLRULE_REQUEST: {
					className->server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Visible = false;
					className->server_DeleteGAMERuleButtonComponent_InstructionLabel_IP->Visible = false;
					className->server_DeleteGAMERuleButtonComponent_TextField_IP->Visible = false;
					className->server_DeleteGAMERuleButtonComponent_InstructionLabel_RID->Visible = false;
					className->server_DeleteGAMERuleButtonComponent_TextField_RID->Visible = false;
					className->server_DeleteGAMERuleButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;
					className->server_IndependentComponentShowIPs_RightPos->Visible = false;

					className->server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Enabled = false;
					className->server_DeleteGAMERuleButtonComponent_InstructionLabel_IP->Enabled = false;
					className->server_DeleteGAMERuleButtonComponent_TextField_IP->Enabled = false;
					className->server_DeleteGAMERuleButtonComponent_InstructionLabel_RID->Enabled = false;
					className->server_DeleteGAMERuleButtonComponent_TextField_RID->Enabled = false;
					className->server_DeleteGAMERuleButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					className->server_IndependentComponentShowIPs_RightPos->Enabled = false;
					break;
				}
				case SERVER_SETFIREWALLTEMPLATE_REQUEST: {
					className->server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Visible = false;
					className->server_SetFirewallTemplateButtonComponent_InstructionLabel_IP->Visible = false;
					className->server_SetFirewallTemplateButtonComponent_TextField_IP->Visible = false;
					className->server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName->Visible = false;
					className->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Visible = false;
					className->server_SetFirewallTemplateButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;
					className->server_IndependentComponentShowIPs_RightPos->Visible = false;

					className->server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Enabled = false;
					className->server_SetFirewallTemplateButtonComponent_InstructionLabel_IP->Enabled = false;
					className->server_SetFirewallTemplateButtonComponent_TextField_IP->Enabled = false;
					className->server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName->Enabled = false;
					className->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Enabled = false;
					className->server_SetFirewallTemplateButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					className->server_IndependentComponentShowIPs_RightPos->Enabled = false;
					break;
				}
				case SERVER_ADDFIREWALL_REQUEST: {
					className->server_AddFirewallButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_AddFirewallButtonComponent_TextField_ServerID->Visible = false;
					className->server_AddFirewallButtonComponent_InstructionLabel_IP->Visible = false;
					className->server_AddFirewallButtonComponent_TextField_IP->Visible = false;
					className->server_AddFirewallButtonComponent_InstructionLabel_Data->Visible = false;
					className->server_AddFirewallButtonComponent_TextField_Data->Visible = false;
					className->server_AddFirewallButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;
					className->server_IndependentComponentShowIPs_RightPos->Visible = false;

					className->server_AddFirewallButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_AddFirewallButtonComponent_TextField_ServerID->Enabled = false;
					className->server_AddFirewallButtonComponent_InstructionLabel_IP->Enabled = false;
					className->server_AddFirewallButtonComponent_TextField_IP->Enabled = false;
					className->server_AddFirewallButtonComponent_InstructionLabel_Data->Enabled = false;
					className->server_AddFirewallButtonComponent_TextField_Data->Enabled = false;
					className->server_AddFirewallButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					className->server_IndependentComponentShowIPs_RightPos->Enabled = false;
					break;
				}
				case SERVER_DELETEIPFIREWALLRULE_REQUEST: {
					className->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Visible = false;
					className->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP->Visible = false;
					className->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Visible = false;
					className->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID->Visible = false;
					className->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Visible = false;
					className->server_DeleteFirewallIPRuleButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;
					className->server_IndependentComponentShowIPs_RightPos->Visible = false;

					className->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Enabled = false;
					className->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP->Enabled = false;
					className->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Enabled = false;
					className->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID->Enabled = false;
					className->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Enabled = false;
					className->server_DeleteFirewallIPRuleButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					className->server_IndependentComponentShowIPs_RightPos->Enabled = false;
					break;
				}
				case SERVER_SETMITIGATIONTIMEOUT_REQUEST: {
					className->server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID->Visible = false;
					className->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Visible = false;
					className->server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP->Visible = false;
					className->server_SetMitigationTimeoutButtonComponent_TextField_IP->Visible = false;
					className->server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout->Visible = false;
					className->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Visible = false;
					className->server_SetMitigationTimeoutButtonComponent_SendButton->Visible = false;
					className->server_IndependentComponentShowIDs_RightPos->Visible = false;
					className->server_IndependentComponentShowIPs_RightPos->Visible = false;

					className->server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID->Enabled = false;
					className->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Enabled = false;
					className->server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP->Enabled = false;
					className->server_SetMitigationTimeoutButtonComponent_TextField_IP->Enabled = false;
					className->server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout->Enabled = false;
					className->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Enabled = false;
					className->server_SetMitigationTimeoutButtonComponent_SendButton->Enabled = false;
					className->server_IndependentComponentShowIDs_RightPos->Enabled = false;
					className->server_IndependentComponentShowIPs_RightPos->Enabled = false;
					break;
				}
			}
		}
