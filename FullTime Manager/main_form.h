#include "configuration.h"
#include "requestHandler.h"
#include "functionHandler.h"
#include "pageHandler.h"
#include "apiHandler.h"

namespace FullTimeManager {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class main_form : public System::Windows::Forms::Form {
		public: System::Windows::Forms::Panel^           ribbonHoriPanel;
		public: System::Windows::Forms::Panel^           ribbonVertPanel;
		public: System::Windows::Forms::Button^          fthLogo;
		public: System::ComponentModel::Container^       components;
		public: System::Windows::Forms::RichTextBox^     apiKeyInputField;
		public: System::Windows::Forms::Button^          fthApiInputExtendedBanner;
		public: System::Windows::Forms::Label^           apiInstructionLabel;
		public: System::Windows::Forms::Button^          apiKeySaveButton;
		public: System::Windows::Forms::Button^          settingsButton;
		public: System::Windows::Forms::Button^          serverButton;
		public: System::Windows::Forms::Button^          firewallButton;
		public: System::Windows::Forms::Button^          billingButton;
		public: System::Windows::Forms::RichTextBox^     settings_ChangeApiKeyInputField;
		public: System::Windows::Forms::Label^           settings_ApiInstructionLabel;
		public: System::Windows::Forms::Button^          settings_SaveChangedKeyButton;
		public: System::Windows::Forms::Label^           settings_ServerIDInstructionlabel;
		public: System::Windows::Forms::RichTextBox^     settings_ServerIDInputField;
		public: System::Windows::Forms::Button^          settings_ServerIDSaveButton;
		public: System::Windows::Forms::Button^          settings_ServerIDResetButton;
		public: System::Windows::Forms::Label^           settings_ServerIPInstructionLabel;
		public: System::Windows::Forms::RichTextBox^     settings_ServerIPInputField;
		public: System::Windows::Forms::Button^          settings_ServerIPSaveButton;
		public: System::Windows::Forms::Button^          settings_ServerIPResetButton;
		public: System::Windows::Forms::Button^          firewall_GetFirewallLogsButton;
		public: System::Windows::Forms::Button^          firewall_DeleteFirewallLogsButton;
		public: System::Windows::Forms::Button^          firewall_GetUnreadFirewallLogsButton;
		public: System::Windows::Forms::Button^          billing_GetAccountInfoButton;
		public: System::Windows::Forms::Button^          billing_GetAllInvoicesButton;
		public: System::Windows::Forms::Button^          billing_GetActiveServicesButton;
		public: System::Windows::Forms::Button^          billing_GetProductsButton;
		public: System::Windows::Forms::Button^          billing_GetAllTickets;
		public: System::Windows::Forms::Button^          billing_GetInvoiceByIDButton;
		public: System::Windows::Forms::RichTextBox^     billing_GetInvoiceByIDButtonComponent_TextField;
		public: System::Windows::Forms::Button^          billing_GetInvoiceByIDComponent_SendButton;
		public: System::Windows::Forms::Label^           billing_GetInvoiceByIDComponent_InstructionLabel;
		public: System::Windows::Forms::Button^          billing_GetTicketByIDButton;
		public: System::Windows::Forms::RichTextBox^     billing_GetTicketByIDButtonComponent_TextField;
		public: System::Windows::Forms::Button^          billing_GetTicketByIDButtonComponent_SendButton;
		public: System::Windows::Forms::Label^           billing_GetTicketByIDButtonComponent_InstructionLabel;
		public: System::Windows::Forms::Button^          billing_GetPromoInfoButton;
		public: System::Windows::Forms::RichTextBox^     billing_GetPromoInfoButtonComponent_TextField;
		public: System::Windows::Forms::Button^          billing_GetPromoInfoButtonComponent_SendButton;
		public: System::Windows::Forms::Label^           billing_GetPromoInfoButtonComponent_InstructionLabel;
		public: System::Windows::Forms::Button^          billing_CloseTicketByIDButton;
		public: System::Windows::Forms::Label^           billing_CloseTicketByIDButtonComponent_InstructionLabel;
		public: System::Windows::Forms::Button^          billing_CloseTicketByIDButtonComponent_SendButton;
		public: System::Windows::Forms::RichTextBox^     billing_CloseTicketByIDButtonComponent_TextField;
		public: System::Windows::Forms::Button^          billing_OpenNewTicketButton;
		public: System::Windows::Forms::RichTextBox^     billing_OpenNewTicketButtonComponent_TextField_Subject;
		public: System::Windows::Forms::RichTextBox^     billing_OpenNewTicketButtonComponent_TextField_Priority;
		public: System::Windows::Forms::RichTextBox^     billing_OpenNewTicketButtonComponent_TextField_Department;
		public: System::Windows::Forms::RichTextBox^     billing_OpenNewTicketButtonComponent_TextField_Message;
		public: System::Windows::Forms::Button^          billing_OpenNewTicketButtonComponent_SendButton;
		public: System::Windows::Forms::Label^           billing_OpenNewTicketButtonComponent_InstructionLabel_Message;
		public: System::Windows::Forms::Label^           billing_OpenNewTicketButtonComponent_InstructionLabel_Subject;
		public: System::Windows::Forms::Label^           billing_OpenNewTicketButtonComponent_InstructionLabel_Priority;
		public: System::Windows::Forms::Label^           billing_OpenNewTicketButtonComponent_InstructionLabel_Department;
		public: System::Windows::Forms::Button^          billing_ReplyToTicketButton;
		public: System::Windows::Forms::RichTextBox^     billing_ReplyToTicketButtonComponent_TextField_TicketID;
		public: System::Windows::Forms::RichTextBox^     billing_ReplyToTicketButtonComponent_TextField_Message;
		public: System::Windows::Forms::Button^          billing_ReplyToTicketButtonComponent_SendButton;
		public: System::Windows::Forms::Label^           billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID;
		public: System::Windows::Forms::Label^           billing_ReplyToTicketButtonComponent_InstructionLabel_Message;
		public: System::Windows::Forms::Button^          billing_SetAccountInfoButton;
		public: System::Windows::Forms::Label^           billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName;
		public: System::Windows::Forms::RichTextBox^     billing_SetAccountInfoButtonComponent_TextField_FirstName;
		public: System::Windows::Forms::RichTextBox^     billing_SetAccountInfoButtonComponent_TextField_LastName;
		public: System::Windows::Forms::Label^           billing_SetAccountInfoButtonComponent_InstructionLabel_LastName;
		public: System::Windows::Forms::Label^           billing_SetAccountInfoButtonComponent_InstructionLabel_Country;
		public: System::Windows::Forms::RichTextBox^     billing_SetAccountInfoButtonComponent_TextField_Country;
		public: System::Windows::Forms::Label^           billing_SetAccountInfoButtonComponent_InstructionLabel_State;
		public: System::Windows::Forms::RichTextBox^     billing_SetAccountInfoButtonComponent_TextField_State;
		public: System::Windows::Forms::Label^           billing_SetAccountInfoButtonComponent_InstructionLabel_Address;
		public: System::Windows::Forms::RichTextBox^     billing_SetAccountInfoButtonComponent_TextField_Address;
		public: System::Windows::Forms::RichTextBox^     billing_SetAccountInfoButtonComponent_TextField_City;
		public: System::Windows::Forms::Label^           billing_SetAccountInfoButtonComponent_InstructionLabel_City;
		public: System::Windows::Forms::RichTextBox^     billing_SetAccountInfoButtonComponent_TextField_ZIPCode;
		public: System::Windows::Forms::Label^           billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode;
		public: System::Windows::Forms::Label^           billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber;
		public: System::Windows::Forms::RichTextBox^     billing_SetAccountInfoButtonComponent_TextField_PhoneNumber;
		public: System::Windows::Forms::Label^           billing_SetAccountInfoButtonComponent_InstructionLabel_Email;
		public: System::Windows::Forms::RichTextBox^     billing_SetAccountInfoButtonComponent_TextField_Email;
		public: System::Windows::Forms::RichTextBox^     billing_SetAccountInfoButtonComponent_TextField_Password;
		public: System::Windows::Forms::Label^           billing_SetAccountInfoButtonComponent_InstructionLabel_Password;
		public: System::Windows::Forms::Label^           billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword;
		public: System::Windows::Forms::RichTextBox^     billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword;
		public: System::Windows::Forms::Button^          billing_SetAccountInfoButtonComponent_SaveButton;
		public: System::Windows::Forms::Button^          server_GetInfoButton;
		public: System::Windows::Forms::RichTextBox^     server_GetInfoButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Label^           server_GetInfoButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::Button^          server_GetInfoButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_IndependentComponentShowIDs;
		public: System::Windows::Forms::Button^          server_DeleteByIDButton;
		public: System::Windows::Forms::Label^           server_DeleteByIDButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_DeleteByIDButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_DeleteByIDButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_GetExpireInfoButton;
		public: System::Windows::Forms::Label^           server_GetExpireInfoButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_GetExpireInfoButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_GetExpireInfoButtonComponent_SendButton;
		public: System::Windows::Forms::Label^           server_GetMediaInfoButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::Button^          server_GetMediaInfoButton;
		public: System::Windows::Forms::RichTextBox^     server_GetMediaInfoButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_GetMediaInfoButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_PowerOnServerButton;
		public: System::Windows::Forms::Label^           server_PowerOnServerButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_PowerOnServerButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_PowerOnServerButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_RestartServerButton;
		public: System::Windows::Forms::Label^           server_RestartServerButtonComponent_Instructionlabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_RestartServerButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_RestartServerButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_ShutdownServerButton;
		public: System::Windows::Forms::Label^           server_ShutdownServerButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_ShutdownServerButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_ShutdownServerButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_ForceStopServerButton;
		public: System::Windows::Forms::Label^           server_ForceStopServerButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_ForceStopServerButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_ForceStopServerButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_RenewServerButton;
		public: System::Windows::Forms::Label^           server_RenewServerButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_RenewServerButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_RenewServerButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_GetVNCInfoButton;
		public: System::Windows::Forms::Label^           server_GetVNCInfoButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_GetVNCInfoButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_GetVNCinfoButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_GetBackupInfoButton;
		public: System::Windows::Forms::Label^           server_GetBackupInfoButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_GetBackupInfoButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_GetBackupInfoButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_MakeBackupButton;
		public: System::Windows::Forms::Label^           server_MakeBackupButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_MakeBackupButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Label^           server_MakeBackupButtonComponent_InstructionLabel_Hostname;
		public: System::Windows::Forms::RichTextBox^     server_MakeBackupButtonComponent_TextField_Hostname;
		public: System::Windows::Forms::Label^           server_MakeBackupButtonComponent_InstructionLabel_Port;
		public: System::Windows::Forms::RichTextBox^     server_MakeBackupButtonComponent_TextField_Port;
		public: System::Windows::Forms::Label^           server_MakeBackupButtonComponent_InstructionLabel_Password;
		public: System::Windows::Forms::RichTextBox^     server_MakeBackupButtonComponent_TextField_Password;
		public: System::Windows::Forms::Label^           server_MakeBackupButtonComponent_InstructionLabel_Rotation;
		public: System::Windows::Forms::RichTextBox^     server_MakeBackupButtonComponent_TextField_Rotation;
		public: System::Windows::Forms::Label^           server_MakeBackupButtonComponent_InstructionLabel_UseSSL;
		public: System::Windows::Forms::RichTextBox^     server_MakeBackupButtonComponent_TextField_UseSSL;
		public: System::Windows::Forms::Button^          server_MakeBackupButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_IndependentComponentShowIDs_RightPos;
		public: System::Windows::Forms::Button^          server_PrevPageButton;
		public: System::Windows::Forms::Button^          server_NextPageButton;
		public: System::Windows::Forms::Button^          server_DeleteBackupButton;
		public: System::Windows::Forms::Label^           server_DeleteBackupButtonComponent_InstructionLabel_ServerID;	
		public: System::Windows::Forms::RichTextBox^     server_DeleteBackupButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_DeleteBackupButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_GetBandwidthButton;
		public: System::Windows::Forms::Label^           server_GetBandwidthButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_GetBandwidthButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_GetBandwidthButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_SelectISOButton;
		public: System::Windows::Forms::Label^           server_SelectISOButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::Label^           server_SelectISOButtonComponent_InstructionLabel_FirstFile;
		public: System::Windows::Forms::RichTextBox^     server_SelectISOButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_SelectISOButtonComponent_TextField_FirstFile;
		public: System::Windows::Forms::Label^           server_SelectISOButtonComponent_InstructionLabel_SecondFile;
		public: System::Windows::Forms::RichTextBox^     server_SelectISOButtonComponent_TextField_SecondFile;
		public: System::Windows::Forms::Button^          server_SelectISOButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_ResetPasswordButton;
		public: System::Windows::Forms::Label^           server_ResetPasswordButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_ResetPasswordButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_ResetPasswordButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_SetHostnameButton;
		public: System::Windows::Forms::Label^           server_SetHostnameButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_SetHostnameButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_SetHostnameButtonComponent_SendButton;
		public: System::Windows::Forms::Label^           server_SetHostnameButtonComponent_InstructionLabel_Hostname;
		public: System::Windows::Forms::RichTextBox^     server_SetHostnameButtonComponent_TextField_Hostname;
		public: System::Windows::Forms::Button^          server_RebuildButton;
		public: System::Windows::Forms::Label^           server_RebuildButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_RebuildButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Label^           server_RebuildButtonComponent_InstructionLabel_NewOS;
		public: System::Windows::Forms::RichTextBox^     server_RebuildButtonComponent_TextField_NewOS;
		public: System::Windows::Forms::Button^          server_RebuildButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_GetIPInfoButton;
		public: System::Windows::Forms::Label^           server_GetIPInfoButtonComponent_Instructionlabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_GetIPInfoButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_GetIPInfoButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_GetVNCInfoTFButton;
		public: System::Windows::Forms::Label^           server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_GetVNCInfoTFButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Label^           server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame;
		public: System::Windows::Forms::RichTextBox^     server_GetVNCInfoTFButtonComponent_TextField_TimeFrame;
		public: System::Windows::Forms::Button^          server_GetVNCInfoTFButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_SetBootOrderButton;
		public: System::Windows::Forms::Label^           server_SetBootOrderButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_SetBootOrderButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Label^           server_SetBootOrderButtonComponent_InstructionLabel_BootOrder;
		public: System::Windows::Forms::RichTextBox^     server_SetBootOrderButtonComponent_TextField_BootOrder;
		public: System::Windows::Forms::Button^          server_SetBootOrderButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_GetFirewallRulesButton;
		public: System::Windows::Forms::Button^          server_AddFirewallRuleButton;
		public: System::Windows::Forms::Button^          server_ToggleFirewallRuleButton;
		public: System::Windows::Forms::Label^           server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_GetFirewallRulesButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_GetFirewallRulesButtonComponent_SendButton;
		public: System::Windows::Forms::Label^           server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_ToggleFirewallRuleButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Label^           server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle;
		public: System::Windows::Forms::RichTextBox^     server_ToggleFirewallRuleButtonComponent_TextField_Toggle;
		public: System::Windows::Forms::Button^          server_ToggleFirewallRuleButtonComponent_SendButton;
		public: System::Windows::Forms::Label^           server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_AddFirewallRuleButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Label^           server_AddFirewallRuleButtonComponent_InstructionLabel_Data;
		public: System::Windows::Forms::RichTextBox^     server_AddFirewallRuleButtonComponent_TextField_Data;
		public: System::Windows::Forms::Button^          server_AddFirewallRuleButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_DeleteFirewallRuleButton;
		public: System::Windows::Forms::Label^           server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID;
		public: System::Windows::Forms::RichTextBox^     server_DeleteFirewallRuleButtonComponent_TextField_RID;
		public: System::Windows::Forms::Button^          server_DeleteFirewallRuleButtonComponent_SendButton;
		public: System::Windows::Forms::Label^           server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_DeleteFirewallRuleButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_SetIPrDNSButton;
		public: System::Windows::Forms::Label^           server_SetIPrDNSButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_SetIPrDNSButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Label^           server_SetIPrDNSButtonComponent_InstructionLabel_IP;
		public: System::Windows::Forms::RichTextBox^     server_SetIPrDNSButtonComponent_TextField_IP;
		public: System::Windows::Forms::Label^           server_SetIPrDNSButtonComponent_InstructionLabel_rDNS;
		public: System::Windows::Forms::RichTextBox^     server_SetIPrDNSButtonComponent_TextField_rDNS;
		public: System::Windows::Forms::Button^          server_SetIPrDNSButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_IndependentComponentShowIPs_RightPos;
		public: System::Windows::Forms::Button^          server_GetIPRulesButton;
		public: System::Windows::Forms::RichTextBox^     server_GetIPRulesButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Label^           server_GetIPRulesButtonComponent_InstructionLabel_IP;
		public: System::Windows::Forms::RichTextBox^     server_GetIPRulesButtonComponent_TextField_IP;
		public: System::Windows::Forms::Button^          server_GetIPRulesButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_IndependentComponentShowIPs;
		public: System::Windows::Forms::Label^           server_GetIPRulesButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::Button^          server_GetMitigationStatusButton;
		public: System::Windows::Forms::Label^           server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_GetMitigationStatusButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Label^           server_GetMitigationStatusButtonComponent_InstructionLabel_IP;
		public: System::Windows::Forms::RichTextBox^     server_GetMitigationStatusButtonComponent_TextField_IP;
		public: System::Windows::Forms::Button^          server_GetMitigationStatusButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_SetMitigationStatusButton;
		public: System::Windows::Forms::Label^           server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_SetMitigationStatusButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Label^           server_SetMitigationStatusButtonComponent_InstructionLabel_IP;
		public: System::Windows::Forms::RichTextBox^     server_SetMitigationStatusButtonComponent_TextField_IP;
		public: System::Windows::Forms::Label^           server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle;
		public: System::Windows::Forms::RichTextBox^     server_SetMitigationStatusButtonComponent_TextField_Toggle;
		public: System::Windows::Forms::Button^          server_SetMitigationStatusButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_AddGAMERuleButton;
		public: System::Windows::Forms::Label^           server_AddGAMERuleButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_AddGAMERuleButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Label^           server_AddGAMERuleButtonComponent_InstructionLabel_IP;
		public: System::Windows::Forms::RichTextBox^     server_AddGAMERuleButtonComponent_TextField_IP;
		public: System::Windows::Forms::Label^           server_AddGAMERuleButtonComponent_InstructionLabel_Proto;
		public: System::Windows::Forms::RichTextBox^     server_AddGAMERuleButtonComponent_TextField_Proto;
		public: System::Windows::Forms::Label^           server_AddGAMERuleButtonComponent_InstructionLabel_Port;
		public: System::Windows::Forms::RichTextBox^     server_AddGAMERuleButtonComponent_TextField_Port;
		public: System::Windows::Forms::Button^          server_AddGAMERuleButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_ToggleGAMEFirewallButton;
		public: System::Windows::Forms::Label^           server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::Label^           server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP;
		public: System::Windows::Forms::Label^           server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle;
		public: System::Windows::Forms::RichTextBox^     server_ToggleGAMEFirewallButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_ToggleGAMEFirewallButtonComponent_TextField_IP;
		public: System::Windows::Forms::RichTextBox^     server_ToggleGAMEFirewallButtonComponent_TextField_Toggle;
		public: System::Windows::Forms::Button^          server_ToggleGAMEFirewallButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_DeleteGAMERuleButton;
		public: System::Windows::Forms::Label^           server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_DeleteGAMERuleButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Label^           server_DeleteGAMERuleButtonComponent_InstructionLabel_IP;
		public: System::Windows::Forms::RichTextBox^     server_DeleteGAMERuleButtonComponent_TextField_IP;
		public: System::Windows::Forms::Label^           server_DeleteGAMERuleButtonComponent_InstructionLabel_RID;
		public: System::Windows::Forms::RichTextBox^     server_DeleteGAMERuleButtonComponent_TextField_RID;
		public: System::Windows::Forms::Button^          server_DeleteGAMERuleButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_SetFirewallTemplateButton;
		public: System::Windows::Forms::Label^           server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::Label^           server_SetFirewallTemplateButtonComponent_InstructionLabel_IP;
		public: System::Windows::Forms::Label^           server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName;
		public: System::Windows::Forms::RichTextBox^     server_SetFirewallTemplateButtonComponent_TextField_TemplateName;
		public: System::Windows::Forms::RichTextBox^     server_SetFirewallTemplateButtonComponent_TextField_IP;
		public: System::Windows::Forms::RichTextBox^     server_SetFirewallTemplateButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Button^          server_SetFirewallTemplateButtonComponent_SendButton;
		public: System::Windows::Forms::Button^          server_SetMitigationTimeoutButton;
		public: System::Windows::Forms::Button^          server_DeleteFirewallIPRuleButton;
		public: System::Windows::Forms::Button^          server_AddFirewallButton;
		public: System::Windows::Forms::Label^           server_AddFirewallButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_AddFirewallButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_AddFirewallButtonComponent_TextField_IP;
		public: System::Windows::Forms::Label^           server_AddFirewallButtonComponent_InstructionLabel_IP;
		public: System::Windows::Forms::Label^           server_AddFirewallButtonComponent_InstructionLabel_Data;
		public: System::Windows::Forms::RichTextBox^     server_AddFirewallButtonComponent_TextField_Data;
		public: System::Windows::Forms::Button^          server_AddFirewallButtonComponent_SendButton;
		public: System::Windows::Forms::Label^           server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::Label^           server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP;
		public: System::Windows::Forms::RichTextBox^     server_DeleteFirewallIPRuleButtonComponent_TextField_IP;
		public: System::Windows::Forms::Label^           server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID;
		public: System::Windows::Forms::RichTextBox^     server_DeleteFirewallIPRuleButtonComponent_TextField_RID;
		public: System::Windows::Forms::Button^          server_DeleteFirewallIPRuleButtonComponent_SendButton;
		public: System::Windows::Forms::Label^           server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID;
		public: System::Windows::Forms::RichTextBox^     server_SetMitigationTimeoutButtonComponent_TextField_ServerID;
		public: System::Windows::Forms::RichTextBox^	 server_SetMitigationTimeoutButtonComponent_TextField_IP;
		public: System::Windows::Forms::Label^           server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout;
		public: System::Windows::Forms::RichTextBox^     server_SetMitigationTimeoutButtonComponent_TextField_Timeout;
		public: System::Windows::Forms::Button^          server_SetMitigationTimeoutButtonComponent_SendButton;
		public: System::Windows::Forms::Label^           server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP;
		public: System::Windows::Forms::RichTextBox^     responseOutputField;
		public: int                                      selectedGUI;
		public: int                                      selectedFunction; // i.e. the button that is currently selected - the function
		public: int                                      selectedPage = 1; // when we need more pages for buttons
		public: System::String^                          apiKey;

		public: main_form(void) {
			InitializeComponent();
		}

		protected: ~main_form() {
			if (components) {
				delete components;
			}
		}

		// init/deinit API key input GUI - these functions work together
		public: inline void initApiKeyGUI() {
			// element enabling
			this->fthApiInputExtendedBanner->Enabled = false; // don't want people clicking the banner, like, wtf.
			this->apiInstructionLabel->Enabled = true;
			this->apiKeyInputField->Enabled = true;
			this->apiKeySaveButton->Enabled = true;

			// element visibility [on]
			this->fthApiInputExtendedBanner->Visible = true;
			this->apiInstructionLabel->Visible = true;
			this->apiKeyInputField->Visible = true;
			this->apiKeySaveButton->Visible = true;
		} public: inline void deinitApiKeyGUI() {
			// element disabling
			this->fthApiInputExtendedBanner->Enabled = false; 
			this->apiInstructionLabel->Enabled = false;
			this->apiKeyInputField->Enabled = false;
			this->apiKeySaveButton->Enabled = false;

			// element visibility [off]
			this->fthApiInputExtendedBanner->Visible = false;
			this->apiInstructionLabel->Visible = false;
			this->apiKeyInputField->Visible = false;
			this->apiKeySaveButton->Visible = false;
			this->apiKeySaveButton->Visible = false;
		}

		// init/deinit Server GUI - these functions work together
		public: inline void initServerTabGUI() { // page 1
			this->server_NextPageButton->Visible = true;
			this->server_GetInfoButton->Visible = true;
			this->server_DeleteByIDButton->Visible = true;
			this->server_GetExpireInfoButton->Visible = true;
			this->server_GetMediaInfoButton->Visible = true;
			this->server_PowerOnServerButton->Visible = true;
			this->server_RestartServerButton->Visible = true;
			this->server_ShutdownServerButton->Visible = true;
			this->server_ForceStopServerButton->Visible = true;
			this->server_RenewServerButton->Visible = true;
			this->server_GetVNCInfoButton->Visible = true;
			this->server_GetBackupInfoButton->Visible = true;
			this->server_MakeBackupButton->Visible = true;

			this->server_NextPageButton->Enabled = true;
			this->server_GetInfoButton->Enabled = true;
			this->server_DeleteByIDButton->Enabled = true;
			this->server_GetExpireInfoButton->Enabled = true;
			this->server_GetMediaInfoButton->Enabled = true;
			this->server_PowerOnServerButton->Enabled = true;
			this->server_RestartServerButton->Enabled = true;
			this->server_ShutdownServerButton->Enabled = true;
			this->server_ForceStopServerButton->Enabled = true;
			this->server_RenewServerButton->Enabled = true;
			this->server_GetVNCInfoButton->Enabled = true;
			this->server_GetBackupInfoButton->Enabled = true;
			this->server_MakeBackupButton->Enabled = true;
		} public: inline void deinitServerTabGUI() { // page 1
			this->responseOutputField->Text = "";

			this->server_NextPageButton->Visible = false;
			this->server_PrevPageButton->Visible = false;
			this->server_GetInfoButton->Visible = false;
			this->server_DeleteByIDButton->Visible = false;
			this->server_GetExpireInfoButton->Visible = false;
			this->server_GetMediaInfoButton->Visible = false;
			this->server_PowerOnServerButton->Visible = false;
			this->server_RestartServerButton->Visible = false;
			this->server_ShutdownServerButton->Visible = false;
			this->server_ForceStopServerButton->Visible = false;
			this->server_RenewServerButton->Visible = false;
			this->server_GetVNCInfoButton->Visible = false;
			this->server_GetBackupInfoButton->Visible = false;
			this->server_MakeBackupButton->Visible = false;

			this->server_NextPageButton->Enabled = false;
			this->server_PrevPageButton->Enabled = false;
			this->server_GetInfoButton->Enabled = false;
			this->server_DeleteByIDButton->Enabled = false;
			this->server_GetExpireInfoButton->Enabled = false;
			this->server_GetMediaInfoButton->Enabled = false;
			this->server_PowerOnServerButton->Enabled = false;
			this->server_RestartServerButton->Enabled = false;
			this->server_ShutdownServerButton->Enabled = false;
			this->server_ForceStopServerButton->Enabled = false;
			this->server_RenewServerButton->Enabled = false;
			this->server_GetVNCInfoButton->Enabled = false;
			this->server_GetBackupInfoButton->Enabled = false;
			this->server_MakeBackupButton->Enabled = false;
		} public: inline void initServerTabGUI_Page2() {
			this->server_NextPageButton->Visible = true;
			this->server_PrevPageButton->Visible = true;
			this->server_DeleteBackupButton->Visible = true;
			this->server_GetBandwidthButton->Visible = true;
			this->server_SelectISOButton->Visible = true;
			this->server_ResetPasswordButton->Visible = true;
			this->server_SetHostnameButton->Visible = true;
			this->server_RebuildButton->Visible = true;
			this->server_GetIPInfoButton->Visible = true;
			this->server_GetVNCInfoTFButton->Visible = true;
			this->server_SetBootOrderButton->Visible = true;
			this->server_GetFirewallRulesButton->Visible = true;
			this->server_ToggleFirewallRuleButton->Visible = true;
			this->server_AddFirewallRuleButton->Visible = true;

			this->server_NextPageButton->Enabled = true;
			this->server_PrevPageButton->Enabled = true;
			this->server_DeleteBackupButton->Enabled = true;
			this->server_GetBandwidthButton->Enabled = true;
			this->server_SelectISOButton->Enabled = true;
			this->server_ResetPasswordButton->Enabled = true;
			this->server_SetHostnameButton->Enabled = true;
			this->server_RebuildButton->Enabled = true;
			this->server_GetIPInfoButton->Enabled = true;
			this->server_GetVNCInfoTFButton->Enabled = true;
			this->server_SetBootOrderButton->Enabled = true;
			this->server_GetFirewallRulesButton->Enabled = true;
			this->server_ToggleFirewallRuleButton->Enabled = true;
			this->server_AddFirewallRuleButton->Enabled = true;
		} public: inline void deinitServerTabGUI_Page2() {
			this->server_NextPageButton->Visible = false;
			this->server_PrevPageButton->Visible = false;
			this->server_DeleteBackupButton->Visible = false;
			this->server_GetBandwidthButton->Visible = false;
			this->server_SelectISOButton->Visible = false;
			this->server_ResetPasswordButton->Visible = false;
			this->server_SetHostnameButton->Visible = false;
			this->server_RebuildButton->Visible = false;
			this->server_GetIPInfoButton->Visible = false;
			this->server_GetVNCInfoTFButton->Visible = false;
			this->server_SetBootOrderButton->Visible = false;
			this->server_GetFirewallRulesButton->Visible = false;
			this->server_ToggleFirewallRuleButton->Visible = false;
			this->server_AddFirewallRuleButton->Visible = false;

			this->server_NextPageButton->Enabled = false;
			this->server_PrevPageButton->Enabled = false;
			this->server_DeleteBackupButton->Enabled = false;
			this->server_GetBandwidthButton->Enabled = false;
			this->server_SelectISOButton->Enabled  = false;
			this->server_ResetPasswordButton->Enabled = false;
			this->server_SetHostnameButton->Enabled = false;
			this->server_RebuildButton->Enabled = false;
			this->server_GetIPInfoButton->Enabled = false;
			this->server_GetVNCInfoTFButton->Enabled = false;
			this->server_SetBootOrderButton->Enabled = false;
			this->server_GetFirewallRulesButton->Enabled = false;
			this->server_ToggleFirewallRuleButton->Enabled = false;
			this->server_AddFirewallRuleButton->Enabled = false;
		} public: inline void initServerTabGUI_Page3() {
			this->server_PrevPageButton->Visible = true;
			this->server_DeleteFirewallRuleButton->Visible = true;
			this->server_SetIPrDNSButton->Visible = true;
			this->server_GetIPRulesButton->Visible = true;
			this->server_GetMitigationStatusButton->Visible = true;
			this->server_SetMitigationStatusButton->Visible = true;
			this->server_AddGAMERuleButton->Visible = true;
			this->server_ToggleGAMEFirewallButton->Visible = true;
			this->server_DeleteGAMERuleButton->Visible = true;
			this->server_SetFirewallTemplateButton->Visible = true;
			this->server_AddFirewallButton->Visible = true;
			this->server_DeleteFirewallIPRuleButton->Visible = true;
			this->server_SetMitigationTimeoutButton->Visible = true;

			this->server_PrevPageButton->Enabled = true;
			this->server_DeleteFirewallRuleButton->Enabled = true;
			this->server_SetIPrDNSButton->Enabled = true;
			this->server_GetIPRulesButton->Enabled = true;
			this->server_GetMitigationStatusButton->Enabled = true;
			this->server_SetMitigationStatusButton->Enabled = true;
			this->server_AddGAMERuleButton->Enabled = true;
			this->server_ToggleGAMEFirewallButton->Enabled = true;
			this->server_DeleteGAMERuleButton->Enabled = true;
			this->server_SetFirewallTemplateButton->Enabled = true;
			this->server_AddFirewallButton->Enabled = true;
			this->server_DeleteFirewallIPRuleButton->Enabled = true;
			this->server_SetMitigationTimeoutButton->Enabled = true;
		} public: inline void deinitServerTabGUI_Page3() {
			this->server_PrevPageButton->Visible = false;
			this->server_DeleteFirewallRuleButton->Visible = false;
			this->server_SetIPrDNSButton->Visible = false;
			this->server_GetIPRulesButton->Visible = false;
			this->server_GetMitigationStatusButton->Visible = false;
			this->server_SetMitigationStatusButton->Visible = false;
			this->server_AddGAMERuleButton->Visible = false;
			this->server_ToggleGAMEFirewallButton->Visible = false;
			this->server_DeleteGAMERuleButton->Visible = false;
			this->server_SetFirewallTemplateButton->Visible = false;
			this->server_AddFirewallButton->Visible = false;
			this->server_DeleteFirewallIPRuleButton->Visible = false;
			this->server_SetMitigationTimeoutButton->Visible = false;

			this->server_PrevPageButton->Enabled = false;
			this->server_DeleteFirewallRuleButton->Enabled = false;
			this->server_SetIPrDNSButton->Enabled = false;
			this->server_GetIPRulesButton->Enabled = false;
			this->server_GetMitigationStatusButton->Enabled = false;
			this->server_SetMitigationStatusButton->Enabled = false;
			this->server_AddGAMERuleButton->Enabled = false;
			this->server_ToggleGAMEFirewallButton->Enabled = false;
			this->server_DeleteGAMERuleButton->Enabled = false;
			this->server_SetFirewallTemplateButton->Enabled = false;
			this->server_AddFirewallButton->Enabled = false;
			this->server_DeleteFirewallIPRuleButton->Enabled = false;
			this->server_SetMitigationTimeoutButton->Enabled = false;
		}
		
		// init/deinit Firewall GUI - these functions work together
		public: inline void initFirewallTabGUI() {
			this->firewall_GetFirewallLogsButton->Visible = true;
			this->firewall_GetUnreadFirewallLogsButton->Visible = true;
			this->firewall_DeleteFirewallLogsButton->Visible = true;

			this->firewall_GetFirewallLogsButton->Enabled = true;
			this->firewall_GetUnreadFirewallLogsButton->Enabled = true;
			this->firewall_DeleteFirewallLogsButton->Enabled = true;
		} public: inline void deinitFirewallTabGUI() {
			this->responseOutputField->Text = "";

			this->firewall_GetFirewallLogsButton->Visible = false;
			this->firewall_GetUnreadFirewallLogsButton->Visible = false;
			this->firewall_DeleteFirewallLogsButton->Visible = false;

			this->firewall_GetFirewallLogsButton->Enabled = false;
			this->firewall_GetUnreadFirewallLogsButton->Visible = false;
			this->firewall_DeleteFirewallLogsButton->Enabled = false;
		}

		// init/deinit Billing GUI - these functions work together
		public: inline void initBillingTabGUI() {
			this->billing_GetAccountInfoButton->Visible = true;
			this->billing_GetAllInvoicesButton->Visible = true;
			this->billing_GetActiveServicesButton->Visible = true;
			this->billing_GetProductsButton->Visible = true;
			this->billing_GetAllTickets->Visible = true;
			this->billing_GetInvoiceByIDButton->Visible = true;
			this->billing_GetTicketByIDButton->Visible = true;
			this->billing_GetPromoInfoButton->Visible = true;
			this->billing_CloseTicketByIDButton->Visible = true;
			this->billing_OpenNewTicketButton->Visible = true;
			this->billing_ReplyToTicketButton->Visible = true;
			this->billing_SetAccountInfoButton->Visible = true;

			this->billing_GetAccountInfoButton->Enabled = true;
			this->billing_GetAllInvoicesButton->Enabled = true;
			this->billing_GetActiveServicesButton->Enabled = true;
			this->billing_GetProductsButton->Enabled = true;
			this->billing_GetAllTickets->Enabled = true;
			this->billing_GetInvoiceByIDButton->Enabled = true;
			this->billing_GetTicketByIDButton->Enabled = true;
			this->billing_GetPromoInfoButton->Enabled = true;
			this->billing_CloseTicketByIDButton->Enabled = true;
			this->billing_OpenNewTicketButton->Enabled = true;
			this->billing_ReplyToTicketButton->Enabled = true;
			this->billing_SetAccountInfoButton->Enabled = true;
		} public: inline void deinitBillingTabGUI() {
			this->responseOutputField->Text = "";

			this->billing_GetAccountInfoButton->Visible = false;
			this->billing_GetAllInvoicesButton->Visible = false;
			this->billing_GetActiveServicesButton->Visible = false;
			this->billing_GetProductsButton->Visible = false;
			this->billing_GetAllTickets->Visible = false;
			this->billing_GetInvoiceByIDButton->Visible = false;
			this->billing_GetTicketByIDButton->Visible = false;
			this->billing_GetPromoInfoButton->Visible = false;
			this->billing_CloseTicketByIDButton->Visible = false;
			this->billing_OpenNewTicketButton->Visible = false;
			this->billing_ReplyToTicketButton->Visible = false;
			this->billing_SetAccountInfoButton->Visible = false;

			this->billing_GetAccountInfoButton->Enabled = false;
			this->billing_GetAllInvoicesButton->Enabled = false;
			this->billing_GetActiveServicesButton->Enabled = false;
			this->billing_GetProductsButton->Enabled = false;
			this->billing_GetAllTickets->Enabled = false;
			this->billing_GetInvoiceByIDButton->Enabled = false;
			this->billing_GetTicketByIDButton->Enabled = false;
			this->billing_GetPromoInfoButton->Enabled = false;
			this->billing_CloseTicketByIDButton->Enabled = false;
			this->billing_OpenNewTicketButton->Enabled = false;
			this->billing_ReplyToTicketButton->Enabled = false;
			this->billing_SetAccountInfoButton->Enabled = false;
		}
			
		// init/deinit Settings GUI - these functions work together
		public: inline void initSettingsTabGUI() {
			this->settings_ChangeApiKeyInputField->Visible = true;
			this->settings_ApiInstructionLabel->Visible = true;
			this->settings_SaveChangedKeyButton->Visible = true;
			this->settings_ServerIDInputField->Visible = true;
			this->settings_ServerIDInstructionlabel->Visible = true;
			this->settings_ServerIDSaveButton->Visible = true;
			this->settings_ServerIDResetButton->Visible = true;
			this->settings_ServerIPInputField->Visible = true;
			this->settings_ServerIPInstructionLabel->Visible = true;
			this->settings_ServerIPSaveButton->Visible = true;
			this->settings_ServerIPResetButton->Visible = true;

			this->settings_ChangeApiKeyInputField->Enabled = true;
			this->settings_ApiInstructionLabel->Enabled = true;
			this->settings_SaveChangedKeyButton->Enabled = true;
			this->settings_ServerIDInputField->Enabled = true;
			this->settings_ServerIDInstructionlabel->Enabled = true;
			this->settings_ServerIDSaveButton->Enabled = true;
			this->settings_ServerIDResetButton->Enabled = true;
			this->settings_ServerIPInputField->Enabled = true;
			this->settings_ServerIPInstructionLabel->Enabled = true;
			this->settings_ServerIPSaveButton->Enabled = true;
			this->settings_ServerIPResetButton->Enabled = true;
		} public: inline void deinitSettingsTabGUI() {
			this->responseOutputField->Text = "";

			this->settings_ChangeApiKeyInputField->Visible = false;
			this->settings_ApiInstructionLabel->Visible = false;
			this->settings_SaveChangedKeyButton->Visible = false;
			this->settings_ServerIDInputField->Visible = false;
			this->settings_ServerIDInstructionlabel->Visible = false;
			this->settings_ServerIDSaveButton->Visible = false;
			this->settings_ServerIDResetButton->Visible = false;
			this->settings_ServerIPInputField->Visible = false;
			this->settings_ServerIPInstructionLabel->Visible = false;
			this->settings_ServerIPSaveButton->Visible = false;
			this->settings_ServerIPResetButton->Visible = false;

			this->settings_ChangeApiKeyInputField->Enabled = false;
			this->settings_ApiInstructionLabel->Enabled = false;
			this->settings_SaveChangedKeyButton->Enabled = false;
			this->settings_ServerIDInputField->Enabled = false;
			this->settings_ServerIDInstructionlabel->Enabled = false;
			this->settings_ServerIDSaveButton->Enabled = false;
			this->settings_ServerIDResetButton->Enabled = false;
			this->settings_ServerIPInputField->Enabled = false;
			this->settings_ServerIPInstructionLabel->Enabled = false;
			this->settings_ServerIPSaveButton->Enabled = false;
			this->settings_ServerIPResetButton->Enabled = false;
		}

		public: void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(main_form::typeid));
			this->ribbonHoriPanel = (gcnew System::Windows::Forms::Panel());
			this->server_SetMitigationTimeoutButton = (gcnew System::Windows::Forms::Button());
			this->server_DeleteFirewallIPRuleButton = (gcnew System::Windows::Forms::Button());
			this->server_AddFirewallButton = (gcnew System::Windows::Forms::Button());
			this->server_SetFirewallTemplateButton = (gcnew System::Windows::Forms::Button());
			this->server_DeleteGAMERuleButton = (gcnew System::Windows::Forms::Button());
			this->server_ToggleGAMEFirewallButton = (gcnew System::Windows::Forms::Button());
			this->server_AddGAMERuleButton = (gcnew System::Windows::Forms::Button());
			this->server_SetMitigationStatusButton = (gcnew System::Windows::Forms::Button());
			this->server_GetMitigationStatusButton = (gcnew System::Windows::Forms::Button());
			this->server_GetIPRulesButton = (gcnew System::Windows::Forms::Button());
			this->server_SetIPrDNSButton = (gcnew System::Windows::Forms::Button());
			this->server_DeleteFirewallRuleButton = (gcnew System::Windows::Forms::Button());
			this->server_AddFirewallRuleButton = (gcnew System::Windows::Forms::Button());
			this->server_ToggleFirewallRuleButton = (gcnew System::Windows::Forms::Button());
			this->server_GetFirewallRulesButton = (gcnew System::Windows::Forms::Button());
			this->server_SetBootOrderButton = (gcnew System::Windows::Forms::Button());
			this->server_GetVNCInfoTFButton = (gcnew System::Windows::Forms::Button());
			this->server_GetIPInfoButton = (gcnew System::Windows::Forms::Button());
			this->server_RebuildButton = (gcnew System::Windows::Forms::Button());
			this->server_SetHostnameButton = (gcnew System::Windows::Forms::Button());
			this->server_ResetPasswordButton = (gcnew System::Windows::Forms::Button());
			this->server_SelectISOButton = (gcnew System::Windows::Forms::Button());
			this->server_GetBandwidthButton = (gcnew System::Windows::Forms::Button());
			this->server_DeleteBackupButton = (gcnew System::Windows::Forms::Button());
			this->server_PrevPageButton = (gcnew System::Windows::Forms::Button());
			this->server_NextPageButton = (gcnew System::Windows::Forms::Button());
			this->server_MakeBackupButton = (gcnew System::Windows::Forms::Button());
			this->server_GetBackupInfoButton = (gcnew System::Windows::Forms::Button());
			this->server_GetVNCInfoButton = (gcnew System::Windows::Forms::Button());
			this->server_RenewServerButton = (gcnew System::Windows::Forms::Button());
			this->server_ForceStopServerButton = (gcnew System::Windows::Forms::Button());
			this->server_ShutdownServerButton = (gcnew System::Windows::Forms::Button());
			this->server_RestartServerButton = (gcnew System::Windows::Forms::Button());
			this->server_PowerOnServerButton = (gcnew System::Windows::Forms::Button());
			this->server_GetMediaInfoButton = (gcnew System::Windows::Forms::Button());
			this->server_GetExpireInfoButton = (gcnew System::Windows::Forms::Button());
			this->server_DeleteByIDButton = (gcnew System::Windows::Forms::Button());
			this->server_GetInfoButton = (gcnew System::Windows::Forms::Button());
			this->billing_SetAccountInfoButton = (gcnew System::Windows::Forms::Button());
			this->billing_ReplyToTicketButton = (gcnew System::Windows::Forms::Button());
			this->billing_OpenNewTicketButton = (gcnew System::Windows::Forms::Button());
			this->billing_CloseTicketByIDButton = (gcnew System::Windows::Forms::Button());
			this->billing_GetPromoInfoButton = (gcnew System::Windows::Forms::Button());
			this->billing_GetTicketByIDButton = (gcnew System::Windows::Forms::Button());
			this->billing_GetInvoiceByIDButton = (gcnew System::Windows::Forms::Button());
			this->billing_GetAllTickets = (gcnew System::Windows::Forms::Button());
			this->billing_GetProductsButton = (gcnew System::Windows::Forms::Button());
			this->billing_GetActiveServicesButton = (gcnew System::Windows::Forms::Button());
			this->billing_GetAllInvoicesButton = (gcnew System::Windows::Forms::Button());
			this->billing_GetAccountInfoButton = (gcnew System::Windows::Forms::Button());
			this->firewall_GetUnreadFirewallLogsButton = (gcnew System::Windows::Forms::Button());
			this->firewall_DeleteFirewallLogsButton = (gcnew System::Windows::Forms::Button());
			this->firewall_GetFirewallLogsButton = (gcnew System::Windows::Forms::Button());
			this->fthLogo = (gcnew System::Windows::Forms::Button());
			this->ribbonVertPanel = (gcnew System::Windows::Forms::Panel());
			this->settingsButton = (gcnew System::Windows::Forms::Button());
			this->serverButton = (gcnew System::Windows::Forms::Button());
			this->firewallButton = (gcnew System::Windows::Forms::Button());
			this->billingButton = (gcnew System::Windows::Forms::Button());
			this->apiKeyInputField = (gcnew System::Windows::Forms::RichTextBox());
			this->fthApiInputExtendedBanner = (gcnew System::Windows::Forms::Button());
			this->apiInstructionLabel = (gcnew System::Windows::Forms::Label());
			this->apiKeySaveButton = (gcnew System::Windows::Forms::Button());
			this->settings_ChangeApiKeyInputField = (gcnew System::Windows::Forms::RichTextBox());
			this->settings_ApiInstructionLabel = (gcnew System::Windows::Forms::Label());
			this->settings_SaveChangedKeyButton = (gcnew System::Windows::Forms::Button());
			this->settings_ServerIDInstructionlabel = (gcnew System::Windows::Forms::Label());
			this->settings_ServerIDInputField = (gcnew System::Windows::Forms::RichTextBox());
			this->settings_ServerIDSaveButton = (gcnew System::Windows::Forms::Button());
			this->settings_ServerIDResetButton = (gcnew System::Windows::Forms::Button());
			this->settings_ServerIPInstructionLabel = (gcnew System::Windows::Forms::Label());
			this->settings_ServerIPInputField = (gcnew System::Windows::Forms::RichTextBox());
			this->settings_ServerIPSaveButton = (gcnew System::Windows::Forms::Button());
			this->settings_ServerIPResetButton = (gcnew System::Windows::Forms::Button());
			this->responseOutputField = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_GetInvoiceByIDButtonComponent_TextField = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_GetInvoiceByIDComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->billing_GetInvoiceByIDComponent_InstructionLabel = (gcnew System::Windows::Forms::Label());
			this->billing_GetTicketByIDButtonComponent_TextField = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_GetTicketByIDButtonComponent_InstructionLabel = (gcnew System::Windows::Forms::Label());
			this->billing_GetTicketByIDButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->billing_GetPromoInfoButtonComponent_TextField = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_GetPromoInfoButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->billing_GetPromoInfoButtonComponent_InstructionLabel = (gcnew System::Windows::Forms::Label());
			this->billing_CloseTicketByIDButtonComponent_InstructionLabel = (gcnew System::Windows::Forms::Label());
			this->billing_CloseTicketByIDButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->billing_CloseTicketByIDButtonComponent_TextField = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_OpenNewTicketButtonComponent_TextField_Subject = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_OpenNewTicketButtonComponent_TextField_Priority = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_OpenNewTicketButtonComponent_TextField_Department = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_OpenNewTicketButtonComponent_TextField_Message = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_OpenNewTicketButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Message = (gcnew System::Windows::Forms::Label());
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Subject = (gcnew System::Windows::Forms::Label());
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Priority = (gcnew System::Windows::Forms::Label());
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Department = (gcnew System::Windows::Forms::Label());
			this->billing_ReplyToTicketButtonComponent_TextField_TicketID = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_ReplyToTicketButtonComponent_TextField_Message = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_ReplyToTicketButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID = (gcnew System::Windows::Forms::Label());
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_Message = (gcnew System::Windows::Forms::Label());
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName = (gcnew System::Windows::Forms::Label());
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_SetAccountInfoButtonComponent_TextField_LastName = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_LastName = (gcnew System::Windows::Forms::Label());
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Country = (gcnew System::Windows::Forms::Label());
			this->billing_SetAccountInfoButtonComponent_TextField_Country = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_State = (gcnew System::Windows::Forms::Label());
			this->billing_SetAccountInfoButtonComponent_TextField_State = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Address = (gcnew System::Windows::Forms::Label());
			this->billing_SetAccountInfoButtonComponent_TextField_Address = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_SetAccountInfoButtonComponent_TextField_City = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_City = (gcnew System::Windows::Forms::Label());
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode = (gcnew System::Windows::Forms::Label());
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber = (gcnew System::Windows::Forms::Label());
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Email = (gcnew System::Windows::Forms::Label());
			this->billing_SetAccountInfoButtonComponent_TextField_Email = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_SetAccountInfoButtonComponent_TextField_Password = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Password = (gcnew System::Windows::Forms::Label());
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword = (gcnew System::Windows::Forms::Label());
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword = (gcnew System::Windows::Forms::RichTextBox());
			this->billing_SetAccountInfoButtonComponent_SaveButton = (gcnew System::Windows::Forms::Button());
			this->server_GetInfoButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_GetInfoButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_GetInfoButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_IndependentComponentShowIDs = (gcnew System::Windows::Forms::Button());
			this->server_DeleteByIDButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_DeleteByIDButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_DeleteByIDButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_GetExpireInfoButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_GetExpireInfoButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_GetExpireInfoButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_GetMediaInfoButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_GetMediaInfoButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_GetMediaInfoButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_PowerOnServerButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_PowerOnServerButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_PowerOnServerButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_RestartServerButtonComponent_Instructionlabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_RestartServerButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_RestartServerButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_ShutdownServerButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_ShutdownServerButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_ShutdownServerButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_ForceStopServerButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_ForceStopServerButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_ForceStopServerButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_RenewServerButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_RenewServerButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_RenewServerButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_GetVNCInfoButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_GetVNCInfoButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_GetVNCinfoButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_GetBackupInfoButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_GetBackupInfoButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_GetBackupInfoButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_MakeBackupButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_MakeBackupButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_MakeBackupButtonComponent_InstructionLabel_Hostname = (gcnew System::Windows::Forms::Label());
			this->server_MakeBackupButtonComponent_TextField_Hostname = (gcnew System::Windows::Forms::RichTextBox());
			this->server_MakeBackupButtonComponent_InstructionLabel_Port = (gcnew System::Windows::Forms::Label());
			this->server_MakeBackupButtonComponent_TextField_Port = (gcnew System::Windows::Forms::RichTextBox());
			this->server_MakeBackupButtonComponent_InstructionLabel_Password = (gcnew System::Windows::Forms::Label());
			this->server_MakeBackupButtonComponent_TextField_Password = (gcnew System::Windows::Forms::RichTextBox());
			this->server_MakeBackupButtonComponent_InstructionLabel_Rotation = (gcnew System::Windows::Forms::Label());
			this->server_MakeBackupButtonComponent_TextField_Rotation = (gcnew System::Windows::Forms::RichTextBox());
			this->server_MakeBackupButtonComponent_InstructionLabel_UseSSL = (gcnew System::Windows::Forms::Label());
			this->server_MakeBackupButtonComponent_TextField_UseSSL = (gcnew System::Windows::Forms::RichTextBox());
			this->server_MakeBackupButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_IndependentComponentShowIDs_RightPos = (gcnew System::Windows::Forms::Button());
			this->server_DeleteBackupButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_DeleteBackupButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_DeleteBackupButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_GetBandwidthButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_GetBandwidthButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_GetBandwidthButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_SelectISOButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_SelectISOButtonComponent_InstructionLabel_FirstFile = (gcnew System::Windows::Forms::Label());
			this->server_SelectISOButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SelectISOButtonComponent_TextField_FirstFile = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SelectISOButtonComponent_InstructionLabel_SecondFile = (gcnew System::Windows::Forms::Label());
			this->server_SelectISOButtonComponent_TextField_SecondFile = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SelectISOButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_ResetPasswordButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_ResetPasswordButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_ResetPasswordButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_SetHostnameButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_SetHostnameButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetHostnameButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_SetHostnameButtonComponent_InstructionLabel_Hostname = (gcnew System::Windows::Forms::Label());
			this->server_SetHostnameButtonComponent_TextField_Hostname = (gcnew System::Windows::Forms::RichTextBox());
			this->server_RebuildButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_RebuildButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_RebuildButtonComponent_InstructionLabel_NewOS = (gcnew System::Windows::Forms::Label());
			this->server_RebuildButtonComponent_TextField_NewOS = (gcnew System::Windows::Forms::RichTextBox());
			this->server_RebuildButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_GetIPInfoButtonComponent_Instructionlabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_GetIPInfoButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_GetIPInfoButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame = (gcnew System::Windows::Forms::Label());
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame = (gcnew System::Windows::Forms::RichTextBox());
			this->server_GetVNCInfoTFButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_SetBootOrderButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_SetBootOrderButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetBootOrderButtonComponent_InstructionLabel_BootOrder = (gcnew System::Windows::Forms::Label());
			this->server_SetBootOrderButtonComponent_TextField_BootOrder = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetBootOrderButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_GetFirewallRulesButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle = (gcnew System::Windows::Forms::Label());
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle = (gcnew System::Windows::Forms::RichTextBox());
			this->server_ToggleFirewallRuleButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_Data = (gcnew System::Windows::Forms::Label());
			this->server_AddFirewallRuleButtonComponent_TextField_Data = (gcnew System::Windows::Forms::RichTextBox());
			this->server_AddFirewallRuleButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID = (gcnew System::Windows::Forms::Label());
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_DeleteFirewallRuleButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetIPrDNSButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_SetIPrDNSButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetIPrDNSButtonComponent_InstructionLabel_IP = (gcnew System::Windows::Forms::Label());
			this->server_SetIPrDNSButtonComponent_TextField_IP = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetIPrDNSButtonComponent_InstructionLabel_rDNS = (gcnew System::Windows::Forms::Label());
			this->server_SetIPrDNSButtonComponent_TextField_rDNS = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetIPrDNSButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_IndependentComponentShowIPs_RightPos = (gcnew System::Windows::Forms::Button());
			this->server_GetIPRulesButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_GetIPRulesButtonComponent_InstructionLabel_IP = (gcnew System::Windows::Forms::Label());
			this->server_GetIPRulesButtonComponent_TextField_IP = (gcnew System::Windows::Forms::RichTextBox());
			this->server_GetIPRulesButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_IndependentComponentShowIPs = (gcnew System::Windows::Forms::Button());
			this->server_GetIPRulesButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_IP = (gcnew System::Windows::Forms::Label());
			this->server_GetMitigationStatusButtonComponent_TextField_IP = (gcnew System::Windows::Forms::RichTextBox());
			this->server_GetMitigationStatusButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_IP = (gcnew System::Windows::Forms::Label());
			this->server_SetMitigationStatusButtonComponent_TextField_IP = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle = (gcnew System::Windows::Forms::Label());
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetMitigationStatusButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_AddGAMERuleButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_AddGAMERuleButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_AddGAMERuleButtonComponent_InstructionLabel_IP = (gcnew System::Windows::Forms::Label());
			this->server_AddGAMERuleButtonComponent_TextField_IP = (gcnew System::Windows::Forms::RichTextBox());
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Proto = (gcnew System::Windows::Forms::Label());
			this->server_AddGAMERuleButtonComponent_TextField_Proto = (gcnew System::Windows::Forms::RichTextBox());
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Port = (gcnew System::Windows::Forms::Label());
			this->server_AddGAMERuleButtonComponent_TextField_Port = (gcnew System::Windows::Forms::RichTextBox());
			this->server_AddGAMERuleButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP = (gcnew System::Windows::Forms::Label());
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle = (gcnew System::Windows::Forms::Label());
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP = (gcnew System::Windows::Forms::RichTextBox());
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle = (gcnew System::Windows::Forms::RichTextBox());
			this->server_ToggleGAMEFirewallButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_IP = (gcnew System::Windows::Forms::Label());
			this->server_DeleteGAMERuleButtonComponent_TextField_IP = (gcnew System::Windows::Forms::RichTextBox());
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_RID = (gcnew System::Windows::Forms::Label());
			this->server_DeleteGAMERuleButtonComponent_TextField_RID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_DeleteGAMERuleButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_IP = (gcnew System::Windows::Forms::Label());
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName = (gcnew System::Windows::Forms::Label());
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetFirewallTemplateButtonComponent_TextField_IP = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetFirewallTemplateButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_AddFirewallButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_AddFirewallButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_AddFirewallButtonComponent_TextField_IP = (gcnew System::Windows::Forms::RichTextBox());
			this->server_AddFirewallButtonComponent_InstructionLabel_IP = (gcnew System::Windows::Forms::Label());
			this->server_AddFirewallButtonComponent_InstructionLabel_Data = (gcnew System::Windows::Forms::Label());
			this->server_AddFirewallButtonComponent_TextField_Data = (gcnew System::Windows::Forms::RichTextBox());
			this->server_AddFirewallButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP = (gcnew System::Windows::Forms::Label());
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP = (gcnew System::Windows::Forms::RichTextBox());
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID = (gcnew System::Windows::Forms::Label());
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID = (gcnew System::Windows::Forms::Label());
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout = (gcnew System::Windows::Forms::Label());
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout = (gcnew System::Windows::Forms::RichTextBox());
			this->server_SetMitigationTimeoutButtonComponent_SendButton = (gcnew System::Windows::Forms::Button());
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP = (gcnew System::Windows::Forms::Label());
			this->ribbonHoriPanel->SuspendLayout();
			this->ribbonVertPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// ribbonHoriPanel
			// 
			this->ribbonHoriPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)));
			this->ribbonHoriPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ribbonHoriPanel->Controls->Add(this->server_SetMitigationTimeoutButton);
			this->ribbonHoriPanel->Controls->Add(this->server_DeleteFirewallIPRuleButton);
			this->ribbonHoriPanel->Controls->Add(this->server_AddFirewallButton);
			this->ribbonHoriPanel->Controls->Add(this->server_SetFirewallTemplateButton);
			this->ribbonHoriPanel->Controls->Add(this->server_DeleteGAMERuleButton);
			this->ribbonHoriPanel->Controls->Add(this->server_ToggleGAMEFirewallButton);
			this->ribbonHoriPanel->Controls->Add(this->server_AddGAMERuleButton);
			this->ribbonHoriPanel->Controls->Add(this->server_SetMitigationStatusButton);
			this->ribbonHoriPanel->Controls->Add(this->server_GetMitigationStatusButton);
			this->ribbonHoriPanel->Controls->Add(this->server_GetIPRulesButton);
			this->ribbonHoriPanel->Controls->Add(this->server_SetIPrDNSButton);
			this->ribbonHoriPanel->Controls->Add(this->server_DeleteFirewallRuleButton);
			this->ribbonHoriPanel->Controls->Add(this->server_AddFirewallRuleButton);
			this->ribbonHoriPanel->Controls->Add(this->server_ToggleFirewallRuleButton);
			this->ribbonHoriPanel->Controls->Add(this->server_GetFirewallRulesButton);
			this->ribbonHoriPanel->Controls->Add(this->server_SetBootOrderButton);
			this->ribbonHoriPanel->Controls->Add(this->server_GetVNCInfoTFButton);
			this->ribbonHoriPanel->Controls->Add(this->server_GetIPInfoButton);
			this->ribbonHoriPanel->Controls->Add(this->server_RebuildButton);
			this->ribbonHoriPanel->Controls->Add(this->server_SetHostnameButton);
			this->ribbonHoriPanel->Controls->Add(this->server_ResetPasswordButton);
			this->ribbonHoriPanel->Controls->Add(this->server_SelectISOButton);
			this->ribbonHoriPanel->Controls->Add(this->server_GetBandwidthButton);
			this->ribbonHoriPanel->Controls->Add(this->server_DeleteBackupButton);
			this->ribbonHoriPanel->Controls->Add(this->server_PrevPageButton);
			this->ribbonHoriPanel->Controls->Add(this->server_NextPageButton);
			this->ribbonHoriPanel->Controls->Add(this->server_MakeBackupButton);
			this->ribbonHoriPanel->Controls->Add(this->server_GetBackupInfoButton);
			this->ribbonHoriPanel->Controls->Add(this->server_GetVNCInfoButton);
			this->ribbonHoriPanel->Controls->Add(this->server_RenewServerButton);
			this->ribbonHoriPanel->Controls->Add(this->server_ForceStopServerButton);
			this->ribbonHoriPanel->Controls->Add(this->server_ShutdownServerButton);
			this->ribbonHoriPanel->Controls->Add(this->server_RestartServerButton);
			this->ribbonHoriPanel->Controls->Add(this->server_PowerOnServerButton);
			this->ribbonHoriPanel->Controls->Add(this->server_GetMediaInfoButton);
			this->ribbonHoriPanel->Controls->Add(this->server_GetExpireInfoButton);
			this->ribbonHoriPanel->Controls->Add(this->server_DeleteByIDButton);
			this->ribbonHoriPanel->Controls->Add(this->server_GetInfoButton);
			this->ribbonHoriPanel->Controls->Add(this->billing_SetAccountInfoButton);
			this->ribbonHoriPanel->Controls->Add(this->billing_ReplyToTicketButton);
			this->ribbonHoriPanel->Controls->Add(this->billing_OpenNewTicketButton);
			this->ribbonHoriPanel->Controls->Add(this->billing_CloseTicketByIDButton);
			this->ribbonHoriPanel->Controls->Add(this->billing_GetPromoInfoButton);
			this->ribbonHoriPanel->Controls->Add(this->billing_GetTicketByIDButton);
			this->ribbonHoriPanel->Controls->Add(this->billing_GetInvoiceByIDButton);
			this->ribbonHoriPanel->Controls->Add(this->billing_GetAllTickets);
			this->ribbonHoriPanel->Controls->Add(this->billing_GetProductsButton);
			this->ribbonHoriPanel->Controls->Add(this->billing_GetActiveServicesButton);
			this->ribbonHoriPanel->Controls->Add(this->billing_GetAllInvoicesButton);
			this->ribbonHoriPanel->Controls->Add(this->billing_GetAccountInfoButton);
			this->ribbonHoriPanel->Controls->Add(this->firewall_GetUnreadFirewallLogsButton);
			this->ribbonHoriPanel->Controls->Add(this->firewall_DeleteFirewallLogsButton);
			this->ribbonHoriPanel->Controls->Add(this->firewall_GetFirewallLogsButton);
			this->ribbonHoriPanel->Controls->Add(this->fthLogo);
			this->ribbonHoriPanel->Location = System::Drawing::Point(-12, 0);
			this->ribbonHoriPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ribbonHoriPanel->Name = L"ribbonHoriPanel";
			this->ribbonHoriPanel->Size = System::Drawing::Size(1106, 100);
			this->ribbonHoriPanel->TabIndex = 0;
			// 
			// server_SetMitigationTimeoutButton
			// 
			this->server_SetMitigationTimeoutButton->Enabled = false;
			this->server_SetMitigationTimeoutButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_SetMitigationTimeoutButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationTimeoutButton->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationTimeoutButton->Location = System::Drawing::Point(608, 66);
			this->server_SetMitigationTimeoutButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetMitigationTimeoutButton->Name = L"server_SetMitigationTimeoutButton";
			this->server_SetMitigationTimeoutButton->Size = System::Drawing::Size(192, 30);
			this->server_SetMitigationTimeoutButton->TabIndex = 75;
			this->server_SetMitigationTimeoutButton->Text = L"Set Miti. Timeout";
			this->server_SetMitigationTimeoutButton->UseVisualStyleBackColor = true;
			this->server_SetMitigationTimeoutButton->Visible = false;
			this->server_SetMitigationTimeoutButton->Click += gcnew System::EventHandler(this, &main_form::server_SetMitigationTimeoutButton_Click);
			// 
			// server_DeleteFirewallIPRuleButton
			// 
			this->server_DeleteFirewallIPRuleButton->Enabled = false;
			this->server_DeleteFirewallIPRuleButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_DeleteFirewallIPRuleButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteFirewallIPRuleButton->ForeColor = System::Drawing::Color::White;
			this->server_DeleteFirewallIPRuleButton->Location = System::Drawing::Point(608, 34);
			this->server_DeleteFirewallIPRuleButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteFirewallIPRuleButton->Name = L"server_DeleteFirewallIPRuleButton";
			this->server_DeleteFirewallIPRuleButton->Size = System::Drawing::Size(192, 30);
			this->server_DeleteFirewallIPRuleButton->TabIndex = 74;
			this->server_DeleteFirewallIPRuleButton->Text = L"Delete IP Rule";
			this->server_DeleteFirewallIPRuleButton->UseVisualStyleBackColor = true;
			this->server_DeleteFirewallIPRuleButton->Visible = false;
			this->server_DeleteFirewallIPRuleButton->Click += gcnew System::EventHandler(this, &main_form::server_DeleteFirewallIPRuleButton_Click);
			// 
			// server_AddFirewallButton
			// 
			this->server_AddFirewallButton->Enabled = false;
			this->server_AddFirewallButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_AddFirewallButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddFirewallButton->ForeColor = System::Drawing::Color::White;
			this->server_AddFirewallButton->Location = System::Drawing::Point(608, 2);
			this->server_AddFirewallButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_AddFirewallButton->Name = L"server_AddFirewallButton";
			this->server_AddFirewallButton->Size = System::Drawing::Size(192, 30);
			this->server_AddFirewallButton->TabIndex = 73;
			this->server_AddFirewallButton->Text = L"Add Firewall";
			this->server_AddFirewallButton->UseVisualStyleBackColor = true;
			this->server_AddFirewallButton->Visible = false;
			this->server_AddFirewallButton->Click += gcnew System::EventHandler(this, &main_form::Server_AddFirewallButton_Click);
			// 
			// server_SetFirewallTemplateButton
			// 
			this->server_SetFirewallTemplateButton->Enabled = false;
			this->server_SetFirewallTemplateButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_SetFirewallTemplateButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetFirewallTemplateButton->ForeColor = System::Drawing::Color::White;
			this->server_SetFirewallTemplateButton->Location = System::Drawing::Point(411, 66);
			this->server_SetFirewallTemplateButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetFirewallTemplateButton->Name = L"server_SetFirewallTemplateButton";
			this->server_SetFirewallTemplateButton->Size = System::Drawing::Size(192, 30);
			this->server_SetFirewallTemplateButton->TabIndex = 72;
			this->server_SetFirewallTemplateButton->Text = L"Set Template";
			this->server_SetFirewallTemplateButton->UseVisualStyleBackColor = true;
			this->server_SetFirewallTemplateButton->Visible = false;
			this->server_SetFirewallTemplateButton->Click += gcnew System::EventHandler(this, &main_form::server_SetFirewallTemplateButton_Click);
			// 
			// server_DeleteGAMERuleButton
			// 
			this->server_DeleteGAMERuleButton->Enabled = false;
			this->server_DeleteGAMERuleButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_DeleteGAMERuleButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteGAMERuleButton->ForeColor = System::Drawing::Color::White;
			this->server_DeleteGAMERuleButton->Location = System::Drawing::Point(411, 34);
			this->server_DeleteGAMERuleButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteGAMERuleButton->Name = L"server_DeleteGAMERuleButton";
			this->server_DeleteGAMERuleButton->Size = System::Drawing::Size(192, 30);
			this->server_DeleteGAMERuleButton->TabIndex = 71;
			this->server_DeleteGAMERuleButton->Text = L"Delete GAME Rule";
			this->server_DeleteGAMERuleButton->UseVisualStyleBackColor = true;
			this->server_DeleteGAMERuleButton->Visible = false;
			this->server_DeleteGAMERuleButton->Click += gcnew System::EventHandler(this, &main_form::Server_DeleteGAMERuleButton_Click);
			// 
			// server_ToggleGAMEFirewallButton
			// 
			this->server_ToggleGAMEFirewallButton->Enabled = false;
			this->server_ToggleGAMEFirewallButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_ToggleGAMEFirewallButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ToggleGAMEFirewallButton->ForeColor = System::Drawing::Color::White;
			this->server_ToggleGAMEFirewallButton->Location = System::Drawing::Point(411, 2);
			this->server_ToggleGAMEFirewallButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ToggleGAMEFirewallButton->Name = L"server_ToggleGAMEFirewallButton";
			this->server_ToggleGAMEFirewallButton->Size = System::Drawing::Size(192, 30);
			this->server_ToggleGAMEFirewallButton->TabIndex = 70;
			this->server_ToggleGAMEFirewallButton->Text = L"Toggle GAME";
			this->server_ToggleGAMEFirewallButton->UseVisualStyleBackColor = true;
			this->server_ToggleGAMEFirewallButton->Visible = false;
			this->server_ToggleGAMEFirewallButton->Click += gcnew System::EventHandler(this, &main_form::Server_ToggleGAMEFirewallButton_Click);
			// 
			// server_AddGAMERuleButton
			// 
			this->server_AddGAMERuleButton->Enabled = false;
			this->server_AddGAMERuleButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_AddGAMERuleButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddGAMERuleButton->ForeColor = System::Drawing::Color::White;
			this->server_AddGAMERuleButton->Location = System::Drawing::Point(213, 66);
			this->server_AddGAMERuleButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_AddGAMERuleButton->Name = L"server_AddGAMERuleButton";
			this->server_AddGAMERuleButton->Size = System::Drawing::Size(192, 30);
			this->server_AddGAMERuleButton->TabIndex = 69;
			this->server_AddGAMERuleButton->Text = L"Add GAME Rule";
			this->server_AddGAMERuleButton->UseVisualStyleBackColor = true;
			this->server_AddGAMERuleButton->Visible = false;
			this->server_AddGAMERuleButton->Click += gcnew System::EventHandler(this, &main_form::Server_AddGAMERuleButton_Click);
			// 
			// server_SetMitigationStatusButton
			// 
			this->server_SetMitigationStatusButton->Enabled = false;
			this->server_SetMitigationStatusButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_SetMitigationStatusButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationStatusButton->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationStatusButton->Location = System::Drawing::Point(212, 34);
			this->server_SetMitigationStatusButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetMitigationStatusButton->Name = L"server_SetMitigationStatusButton";
			this->server_SetMitigationStatusButton->Size = System::Drawing::Size(192, 30);
			this->server_SetMitigationStatusButton->TabIndex = 68;
			this->server_SetMitigationStatusButton->Text = L"Set Mitigation Status";
			this->server_SetMitigationStatusButton->UseVisualStyleBackColor = true;
			this->server_SetMitigationStatusButton->Visible = false;
			this->server_SetMitigationStatusButton->Click += gcnew System::EventHandler(this, &main_form::server_SetMitigationStatusButton_Click);
			// 
			// server_GetMitigationStatusButton
			// 
			this->server_GetMitigationStatusButton->Enabled = false;
			this->server_GetMitigationStatusButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetMitigationStatusButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetMitigationStatusButton->ForeColor = System::Drawing::Color::White;
			this->server_GetMitigationStatusButton->Location = System::Drawing::Point(212, 2);
			this->server_GetMitigationStatusButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetMitigationStatusButton->Name = L"server_GetMitigationStatusButton";
			this->server_GetMitigationStatusButton->Size = System::Drawing::Size(192, 30);
			this->server_GetMitigationStatusButton->TabIndex = 67;
			this->server_GetMitigationStatusButton->Text = L"Get Mitigation Status";
			this->server_GetMitigationStatusButton->UseVisualStyleBackColor = true;
			this->server_GetMitigationStatusButton->Visible = false;
			this->server_GetMitigationStatusButton->Click += gcnew System::EventHandler(this, &main_form::server_GetMitigationStatusButton_Click);
			// 
			// server_GetIPRulesButton
			// 
			this->server_GetIPRulesButton->Enabled = false;
			this->server_GetIPRulesButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetIPRulesButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetIPRulesButton->ForeColor = System::Drawing::Color::White;
			this->server_GetIPRulesButton->Location = System::Drawing::Point(13, 66);
			this->server_GetIPRulesButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetIPRulesButton->Name = L"server_GetIPRulesButton";
			this->server_GetIPRulesButton->Size = System::Drawing::Size(192, 30);
			this->server_GetIPRulesButton->TabIndex = 66;
			this->server_GetIPRulesButton->Text = L"Get IP Rules";
			this->server_GetIPRulesButton->UseVisualStyleBackColor = true;
			this->server_GetIPRulesButton->Visible = false;
			this->server_GetIPRulesButton->Click += gcnew System::EventHandler(this, &main_form::server_GetIPRulesButton_Click);
			// 
			// server_SetIPrDNSButton
			// 
			this->server_SetIPrDNSButton->Enabled = false;
			this->server_SetIPrDNSButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_SetIPrDNSButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetIPrDNSButton->ForeColor = System::Drawing::Color::White;
			this->server_SetIPrDNSButton->Location = System::Drawing::Point(13, 34);
			this->server_SetIPrDNSButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetIPrDNSButton->Name = L"server_SetIPrDNSButton";
			this->server_SetIPrDNSButton->Size = System::Drawing::Size(192, 30);
			this->server_SetIPrDNSButton->TabIndex = 65;
			this->server_SetIPrDNSButton->Text = L"Set IP rDNS Info";
			this->server_SetIPrDNSButton->UseVisualStyleBackColor = true;
			this->server_SetIPrDNSButton->Visible = false;
			this->server_SetIPrDNSButton->Click += gcnew System::EventHandler(this, &main_form::server_SetIPrDNSButton_Click);
			// 
			// server_DeleteFirewallRuleButton
			// 
			this->server_DeleteFirewallRuleButton->Enabled = false;
			this->server_DeleteFirewallRuleButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_DeleteFirewallRuleButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteFirewallRuleButton->ForeColor = System::Drawing::Color::White;
			this->server_DeleteFirewallRuleButton->Location = System::Drawing::Point(13, 2);
			this->server_DeleteFirewallRuleButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteFirewallRuleButton->Name = L"server_DeleteFirewallRuleButton";
			this->server_DeleteFirewallRuleButton->Size = System::Drawing::Size(192, 30);
			this->server_DeleteFirewallRuleButton->TabIndex = 64;
			this->server_DeleteFirewallRuleButton->Text = L"Delete Firewall Rule";
			this->server_DeleteFirewallRuleButton->UseVisualStyleBackColor = true;
			this->server_DeleteFirewallRuleButton->Visible = false;
			this->server_DeleteFirewallRuleButton->Click += gcnew System::EventHandler(this, &main_form::server_DeleteFirewallRuleButton_Click);
			// 
			// server_AddFirewallRuleButton
			// 
			this->server_AddFirewallRuleButton->Enabled = false;
			this->server_AddFirewallRuleButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_AddFirewallRuleButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddFirewallRuleButton->ForeColor = System::Drawing::Color::White;
			this->server_AddFirewallRuleButton->Location = System::Drawing::Point(608, 66);
			this->server_AddFirewallRuleButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_AddFirewallRuleButton->Name = L"server_AddFirewallRuleButton";
			this->server_AddFirewallRuleButton->Size = System::Drawing::Size(192, 30);
			this->server_AddFirewallRuleButton->TabIndex = 63;
			this->server_AddFirewallRuleButton->Text = L"Add Firewall Rule";
			this->server_AddFirewallRuleButton->UseVisualStyleBackColor = true;
			this->server_AddFirewallRuleButton->Visible = false;
			this->server_AddFirewallRuleButton->Click += gcnew System::EventHandler(this, &main_form::server_AddFirewallRuleButton_Click);
			// 
			// server_ToggleFirewallRuleButton
			// 
			this->server_ToggleFirewallRuleButton->Enabled = false;
			this->server_ToggleFirewallRuleButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_ToggleFirewallRuleButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ToggleFirewallRuleButton->ForeColor = System::Drawing::Color::White;
			this->server_ToggleFirewallRuleButton->Location = System::Drawing::Point(608, 34);
			this->server_ToggleFirewallRuleButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ToggleFirewallRuleButton->Name = L"server_ToggleFirewallRuleButton";
			this->server_ToggleFirewallRuleButton->Size = System::Drawing::Size(192, 30);
			this->server_ToggleFirewallRuleButton->TabIndex = 62;
			this->server_ToggleFirewallRuleButton->Text = L"Toggle Firewall Rule";
			this->server_ToggleFirewallRuleButton->UseVisualStyleBackColor = true;
			this->server_ToggleFirewallRuleButton->Visible = false;
			this->server_ToggleFirewallRuleButton->Click += gcnew System::EventHandler(this, &main_form::server_ToggleFirewallRuleButton_Click);
			// 
			// server_GetFirewallRulesButton
			// 
			this->server_GetFirewallRulesButton->Enabled = false;
			this->server_GetFirewallRulesButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetFirewallRulesButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetFirewallRulesButton->ForeColor = System::Drawing::Color::White;
			this->server_GetFirewallRulesButton->Location = System::Drawing::Point(608, 2);
			this->server_GetFirewallRulesButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetFirewallRulesButton->Name = L"server_GetFirewallRulesButton";
			this->server_GetFirewallRulesButton->Size = System::Drawing::Size(192, 30);
			this->server_GetFirewallRulesButton->TabIndex = 61;
			this->server_GetFirewallRulesButton->Text = L"Get Firewall Rules";
			this->server_GetFirewallRulesButton->UseVisualStyleBackColor = true;
			this->server_GetFirewallRulesButton->Visible = false;
			this->server_GetFirewallRulesButton->Click += gcnew System::EventHandler(this, &main_form::server_GetFirewallRulesButton_Click);
			// 
			// server_SetBootOrderButton
			// 
			this->server_SetBootOrderButton->Enabled = false;
			this->server_SetBootOrderButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_SetBootOrderButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetBootOrderButton->ForeColor = System::Drawing::Color::White;
			this->server_SetBootOrderButton->Location = System::Drawing::Point(411, 66);
			this->server_SetBootOrderButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetBootOrderButton->Name = L"server_SetBootOrderButton";
			this->server_SetBootOrderButton->Size = System::Drawing::Size(192, 30);
			this->server_SetBootOrderButton->TabIndex = 60;
			this->server_SetBootOrderButton->Text = L"Set Boot Order";
			this->server_SetBootOrderButton->UseVisualStyleBackColor = true;
			this->server_SetBootOrderButton->Visible = false;
			this->server_SetBootOrderButton->Click += gcnew System::EventHandler(this, &main_form::server_SetBootOrderButton_Click);
			// 
			// server_GetVNCInfoTFButton
			// 
			this->server_GetVNCInfoTFButton->Enabled = false;
			this->server_GetVNCInfoTFButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetVNCInfoTFButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetVNCInfoTFButton->ForeColor = System::Drawing::Color::White;
			this->server_GetVNCInfoTFButton->Location = System::Drawing::Point(411, 34);
			this->server_GetVNCInfoTFButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetVNCInfoTFButton->Name = L"server_GetVNCInfoTFButton";
			this->server_GetVNCInfoTFButton->Size = System::Drawing::Size(192, 30);
			this->server_GetVNCInfoTFButton->TabIndex = 59;
			this->server_GetVNCInfoTFButton->Text = L"Get Timed VNC Info";
			this->server_GetVNCInfoTFButton->UseVisualStyleBackColor = true;
			this->server_GetVNCInfoTFButton->Visible = false;
			this->server_GetVNCInfoTFButton->Click += gcnew System::EventHandler(this, &main_form::server_GetVNCInfoTFButton_Click);
			// 
			// server_GetIPInfoButton
			// 
			this->server_GetIPInfoButton->Enabled = false;
			this->server_GetIPInfoButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetIPInfoButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetIPInfoButton->ForeColor = System::Drawing::Color::White;
			this->server_GetIPInfoButton->Location = System::Drawing::Point(411, 2);
			this->server_GetIPInfoButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetIPInfoButton->Name = L"server_GetIPInfoButton";
			this->server_GetIPInfoButton->Size = System::Drawing::Size(192, 30);
			this->server_GetIPInfoButton->TabIndex = 58;
			this->server_GetIPInfoButton->Text = L"Get Server IP Info";
			this->server_GetIPInfoButton->UseVisualStyleBackColor = true;
			this->server_GetIPInfoButton->Visible = false;
			this->server_GetIPInfoButton->Click += gcnew System::EventHandler(this, &main_form::server_GetIPInfoButton_Click);
			// 
			// server_RebuildButton
			// 
			this->server_RebuildButton->Enabled = false;
			this->server_RebuildButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_RebuildButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_RebuildButton->ForeColor = System::Drawing::Color::White;
			this->server_RebuildButton->Location = System::Drawing::Point(212, 66);
			this->server_RebuildButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_RebuildButton->Name = L"server_RebuildButton";
			this->server_RebuildButton->Size = System::Drawing::Size(192, 30);
			this->server_RebuildButton->TabIndex = 57;
			this->server_RebuildButton->Text = L"Rebuild Server";
			this->server_RebuildButton->UseVisualStyleBackColor = true;
			this->server_RebuildButton->Visible = false;
			this->server_RebuildButton->Click += gcnew System::EventHandler(this, &main_form::server_RebuildButton_Click);
			// 
			// server_SetHostnameButton
			// 
			this->server_SetHostnameButton->Enabled = false;
			this->server_SetHostnameButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_SetHostnameButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetHostnameButton->ForeColor = System::Drawing::Color::White;
			this->server_SetHostnameButton->Location = System::Drawing::Point(212, 34);
			this->server_SetHostnameButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetHostnameButton->Name = L"server_SetHostnameButton";
			this->server_SetHostnameButton->Size = System::Drawing::Size(192, 30);
			this->server_SetHostnameButton->TabIndex = 56;
			this->server_SetHostnameButton->Text = L"Set Hostname info";
			this->server_SetHostnameButton->UseVisualStyleBackColor = true;
			this->server_SetHostnameButton->Visible = false;
			this->server_SetHostnameButton->Click += gcnew System::EventHandler(this, &main_form::server_SetHostnameButton_Click);
			// 
			// server_ResetPasswordButton
			// 
			this->server_ResetPasswordButton->Enabled = false;
			this->server_ResetPasswordButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_ResetPasswordButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ResetPasswordButton->ForeColor = System::Drawing::Color::White;
			this->server_ResetPasswordButton->Location = System::Drawing::Point(212, 2);
			this->server_ResetPasswordButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ResetPasswordButton->Name = L"server_ResetPasswordButton";
			this->server_ResetPasswordButton->Size = System::Drawing::Size(192, 30);
			this->server_ResetPasswordButton->TabIndex = 55;
			this->server_ResetPasswordButton->Text = L"Reset Password";
			this->server_ResetPasswordButton->UseVisualStyleBackColor = true;
			this->server_ResetPasswordButton->Visible = false;
			this->server_ResetPasswordButton->Click += gcnew System::EventHandler(this, &main_form::server_ResetPasswordButton_Click);
			// 
			// server_SelectISOButton
			// 
			this->server_SelectISOButton->Enabled = false;
			this->server_SelectISOButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_SelectISOButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SelectISOButton->ForeColor = System::Drawing::Color::White;
			this->server_SelectISOButton->Location = System::Drawing::Point(13, 66);
			this->server_SelectISOButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SelectISOButton->Name = L"server_SelectISOButton";
			this->server_SelectISOButton->Size = System::Drawing::Size(192, 30);
			this->server_SelectISOButton->TabIndex = 54;
			this->server_SelectISOButton->Text = L"Select New ISO";
			this->server_SelectISOButton->UseVisualStyleBackColor = true;
			this->server_SelectISOButton->Visible = false;
			this->server_SelectISOButton->Click += gcnew System::EventHandler(this, &main_form::server_SelectISOButton_Click);
			// 
			// server_GetBandwidthButton
			// 
			this->server_GetBandwidthButton->Enabled = false;
			this->server_GetBandwidthButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetBandwidthButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetBandwidthButton->ForeColor = System::Drawing::Color::White;
			this->server_GetBandwidthButton->Location = System::Drawing::Point(13, 34);
			this->server_GetBandwidthButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetBandwidthButton->Name = L"server_GetBandwidthButton";
			this->server_GetBandwidthButton->Size = System::Drawing::Size(192, 30);
			this->server_GetBandwidthButton->TabIndex = 53;
			this->server_GetBandwidthButton->Text = L"Get Bandwidth Info";
			this->server_GetBandwidthButton->UseVisualStyleBackColor = true;
			this->server_GetBandwidthButton->Visible = false;
			this->server_GetBandwidthButton->Click += gcnew System::EventHandler(this, &main_form::serverGetBandwidthButton_Click);
			// 
			// server_DeleteBackupButton
			// 
			this->server_DeleteBackupButton->Enabled = false;
			this->server_DeleteBackupButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_DeleteBackupButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteBackupButton->ForeColor = System::Drawing::Color::White;
			this->server_DeleteBackupButton->Location = System::Drawing::Point(13, 2);
			this->server_DeleteBackupButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteBackupButton->Name = L"server_DeleteBackupButton";
			this->server_DeleteBackupButton->Size = System::Drawing::Size(192, 30);
			this->server_DeleteBackupButton->TabIndex = 52;
			this->server_DeleteBackupButton->Text = L"Delete Server Backup";
			this->server_DeleteBackupButton->UseVisualStyleBackColor = true;
			this->server_DeleteBackupButton->Visible = false;
			this->server_DeleteBackupButton->Click += gcnew System::EventHandler(this, &main_form::server_DeleteBackupButton_Click);
			// 
			// server_PrevPageButton
			// 
			this->server_PrevPageButton->Enabled = false;
			this->server_PrevPageButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_PrevPageButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_PrevPageButton->ForeColor = System::Drawing::Color::White;
			this->server_PrevPageButton->Location = System::Drawing::Point(828, 50);
			this->server_PrevPageButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_PrevPageButton->Name = L"server_PrevPageButton";
			this->server_PrevPageButton->Size = System::Drawing::Size(84, 30);
			this->server_PrevPageButton->TabIndex = 51;
			this->server_PrevPageButton->Text = L"Back";
			this->server_PrevPageButton->UseVisualStyleBackColor = true;
			this->server_PrevPageButton->Visible = false;
			this->server_PrevPageButton->Click += gcnew System::EventHandler(this, &main_form::server_PrevPageButton_Click);
			// 
			// server_NextPageButton
			// 
			this->server_NextPageButton->Enabled = false;
			this->server_NextPageButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_NextPageButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_NextPageButton->ForeColor = System::Drawing::Color::White;
			this->server_NextPageButton->Location = System::Drawing::Point(828, 16);
			this->server_NextPageButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_NextPageButton->Name = L"server_NextPageButton";
			this->server_NextPageButton->Size = System::Drawing::Size(84, 30);
			this->server_NextPageButton->TabIndex = 50;
			this->server_NextPageButton->Text = L"Next";
			this->server_NextPageButton->UseVisualStyleBackColor = true;
			this->server_NextPageButton->Visible = false;
			this->server_NextPageButton->Click += gcnew System::EventHandler(this, &main_form::server_NextPageButton_Click);
			// 
			// server_MakeBackupButton
			// 
			this->server_MakeBackupButton->Enabled = false;
			this->server_MakeBackupButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_MakeBackupButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_MakeBackupButton->ForeColor = System::Drawing::Color::White;
			this->server_MakeBackupButton->Location = System::Drawing::Point(608, 66);
			this->server_MakeBackupButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_MakeBackupButton->Name = L"server_MakeBackupButton";
			this->server_MakeBackupButton->Size = System::Drawing::Size(192, 30);
			this->server_MakeBackupButton->TabIndex = 49;
			this->server_MakeBackupButton->Text = L"Make Server Backup";
			this->server_MakeBackupButton->UseVisualStyleBackColor = true;
			this->server_MakeBackupButton->Visible = false;
			this->server_MakeBackupButton->Click += gcnew System::EventHandler(this, &main_form::server_MakeBackupButton_Click);
			// 
			// server_GetBackupInfoButton
			// 
			this->server_GetBackupInfoButton->Enabled = false;
			this->server_GetBackupInfoButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetBackupInfoButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetBackupInfoButton->ForeColor = System::Drawing::Color::White;
			this->server_GetBackupInfoButton->Location = System::Drawing::Point(608, 34);
			this->server_GetBackupInfoButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetBackupInfoButton->Name = L"server_GetBackupInfoButton";
			this->server_GetBackupInfoButton->Size = System::Drawing::Size(192, 30);
			this->server_GetBackupInfoButton->TabIndex = 48;
			this->server_GetBackupInfoButton->Text = L"Get Backup info";
			this->server_GetBackupInfoButton->UseVisualStyleBackColor = true;
			this->server_GetBackupInfoButton->Visible = false;
			this->server_GetBackupInfoButton->Click += gcnew System::EventHandler(this, &main_form::server_GetBackupInfoButton_Click);
			// 
			// server_GetVNCInfoButton
			// 
			this->server_GetVNCInfoButton->Enabled = false;
			this->server_GetVNCInfoButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetVNCInfoButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetVNCInfoButton->ForeColor = System::Drawing::Color::White;
			this->server_GetVNCInfoButton->Location = System::Drawing::Point(608, 2);
			this->server_GetVNCInfoButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetVNCInfoButton->Name = L"server_GetVNCInfoButton";
			this->server_GetVNCInfoButton->Size = System::Drawing::Size(192, 30);
			this->server_GetVNCInfoButton->TabIndex = 47;
			this->server_GetVNCInfoButton->Text = L"Get VNC Info";
			this->server_GetVNCInfoButton->UseVisualStyleBackColor = true;
			this->server_GetVNCInfoButton->Visible = false;
			this->server_GetVNCInfoButton->Click += gcnew System::EventHandler(this, &main_form::server_GetVNCInfoButton_Click);
			// 
			// server_RenewServerButton
			// 
			this->server_RenewServerButton->Enabled = false;
			this->server_RenewServerButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_RenewServerButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_RenewServerButton->ForeColor = System::Drawing::Color::White;
			this->server_RenewServerButton->Location = System::Drawing::Point(411, 66);
			this->server_RenewServerButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_RenewServerButton->Name = L"server_RenewServerButton";
			this->server_RenewServerButton->Size = System::Drawing::Size(192, 30);
			this->server_RenewServerButton->TabIndex = 46;
			this->server_RenewServerButton->Text = L"Renew Server";
			this->server_RenewServerButton->UseVisualStyleBackColor = true;
			this->server_RenewServerButton->Visible = false;
			this->server_RenewServerButton->Click += gcnew System::EventHandler(this, &main_form::server_RenewServerButton_Click);
			// 
			// server_ForceStopServerButton
			// 
			this->server_ForceStopServerButton->Enabled = false;
			this->server_ForceStopServerButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_ForceStopServerButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ForceStopServerButton->ForeColor = System::Drawing::Color::White;
			this->server_ForceStopServerButton->Location = System::Drawing::Point(411, 34);
			this->server_ForceStopServerButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ForceStopServerButton->Name = L"server_ForceStopServerButton";
			this->server_ForceStopServerButton->Size = System::Drawing::Size(192, 30);
			this->server_ForceStopServerButton->TabIndex = 45;
			this->server_ForceStopServerButton->Text = L"Force Stop Server";
			this->server_ForceStopServerButton->UseVisualStyleBackColor = true;
			this->server_ForceStopServerButton->Visible = false;
			this->server_ForceStopServerButton->Click += gcnew System::EventHandler(this, &main_form::server_ForceStopServerButton_Click);
			// 
			// server_ShutdownServerButton
			// 
			this->server_ShutdownServerButton->Enabled = false;
			this->server_ShutdownServerButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_ShutdownServerButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ShutdownServerButton->ForeColor = System::Drawing::Color::White;
			this->server_ShutdownServerButton->Location = System::Drawing::Point(411, 2);
			this->server_ShutdownServerButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ShutdownServerButton->Name = L"server_ShutdownServerButton";
			this->server_ShutdownServerButton->Size = System::Drawing::Size(192, 30);
			this->server_ShutdownServerButton->TabIndex = 44;
			this->server_ShutdownServerButton->Text = L"Shutdown Server";
			this->server_ShutdownServerButton->UseVisualStyleBackColor = true;
			this->server_ShutdownServerButton->Visible = false;
			this->server_ShutdownServerButton->Click += gcnew System::EventHandler(this, &main_form::server_ShutdownServerButton_Click);
			// 
			// server_RestartServerButton
			// 
			this->server_RestartServerButton->Enabled = false;
			this->server_RestartServerButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_RestartServerButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_RestartServerButton->ForeColor = System::Drawing::Color::White;
			this->server_RestartServerButton->Location = System::Drawing::Point(212, 66);
			this->server_RestartServerButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_RestartServerButton->Name = L"server_RestartServerButton";
			this->server_RestartServerButton->Size = System::Drawing::Size(192, 30);
			this->server_RestartServerButton->TabIndex = 43;
			this->server_RestartServerButton->Text = L"Restart Server";
			this->server_RestartServerButton->UseVisualStyleBackColor = true;
			this->server_RestartServerButton->Visible = false;
			this->server_RestartServerButton->Click += gcnew System::EventHandler(this, &main_form::server_RestartServerButton_Click);
			// 
			// server_PowerOnServerButton
			// 
			this->server_PowerOnServerButton->Enabled = false;
			this->server_PowerOnServerButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_PowerOnServerButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_PowerOnServerButton->ForeColor = System::Drawing::Color::White;
			this->server_PowerOnServerButton->Location = System::Drawing::Point(212, 34);
			this->server_PowerOnServerButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_PowerOnServerButton->Name = L"server_PowerOnServerButton";
			this->server_PowerOnServerButton->Size = System::Drawing::Size(192, 30);
			this->server_PowerOnServerButton->TabIndex = 42;
			this->server_PowerOnServerButton->Text = L"Power On Server";
			this->server_PowerOnServerButton->UseVisualStyleBackColor = true;
			this->server_PowerOnServerButton->Visible = false;
			this->server_PowerOnServerButton->Click += gcnew System::EventHandler(this, &main_form::server_PowerOnServerButton_Click);
			// 
			// server_GetMediaInfoButton
			// 
			this->server_GetMediaInfoButton->Enabled = false;
			this->server_GetMediaInfoButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetMediaInfoButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetMediaInfoButton->ForeColor = System::Drawing::Color::White;
			this->server_GetMediaInfoButton->Location = System::Drawing::Point(212, 2);
			this->server_GetMediaInfoButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetMediaInfoButton->Name = L"server_GetMediaInfoButton";
			this->server_GetMediaInfoButton->Size = System::Drawing::Size(192, 30);
			this->server_GetMediaInfoButton->TabIndex = 41;
			this->server_GetMediaInfoButton->Text = L"Get Media Info";
			this->server_GetMediaInfoButton->UseVisualStyleBackColor = true;
			this->server_GetMediaInfoButton->Visible = false;
			this->server_GetMediaInfoButton->Click += gcnew System::EventHandler(this, &main_form::server_GetMediaInfoButton_Click);
			// 
			// server_GetExpireInfoButton
			// 
			this->server_GetExpireInfoButton->Enabled = false;
			this->server_GetExpireInfoButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetExpireInfoButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetExpireInfoButton->ForeColor = System::Drawing::Color::White;
			this->server_GetExpireInfoButton->Location = System::Drawing::Point(13, 66);
			this->server_GetExpireInfoButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetExpireInfoButton->Name = L"server_GetExpireInfoButton";
			this->server_GetExpireInfoButton->Size = System::Drawing::Size(192, 30);
			this->server_GetExpireInfoButton->TabIndex = 40;
			this->server_GetExpireInfoButton->Text = L"Get Expiration info";
			this->server_GetExpireInfoButton->UseVisualStyleBackColor = true;
			this->server_GetExpireInfoButton->Visible = false;
			this->server_GetExpireInfoButton->Click += gcnew System::EventHandler(this, &main_form::server_GetExpireInfoButton_Click);
			// 
			// server_DeleteByIDButton
			// 
			this->server_DeleteByIDButton->Enabled = false;
			this->server_DeleteByIDButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_DeleteByIDButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteByIDButton->ForeColor = System::Drawing::Color::White;
			this->server_DeleteByIDButton->Location = System::Drawing::Point(13, 34);
			this->server_DeleteByIDButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteByIDButton->Name = L"server_DeleteByIDButton";
			this->server_DeleteByIDButton->Size = System::Drawing::Size(192, 30);
			this->server_DeleteByIDButton->TabIndex = 39;
			this->server_DeleteByIDButton->Text = L"Delete Server By ID";
			this->server_DeleteByIDButton->UseVisualStyleBackColor = true;
			this->server_DeleteByIDButton->Visible = false;
			this->server_DeleteByIDButton->Click += gcnew System::EventHandler(this, &main_form::server_DeleteByIDButton_Click);
			// 
			// server_GetInfoButton
			// 
			this->server_GetInfoButton->Enabled = false;
			this->server_GetInfoButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetInfoButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetInfoButton->ForeColor = System::Drawing::Color::White;
			this->server_GetInfoButton->Location = System::Drawing::Point(13, 2);
			this->server_GetInfoButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetInfoButton->Name = L"server_GetInfoButton";
			this->server_GetInfoButton->Size = System::Drawing::Size(192, 30);
			this->server_GetInfoButton->TabIndex = 38;
			this->server_GetInfoButton->Text = L"Get Server Info";
			this->server_GetInfoButton->UseVisualStyleBackColor = true;
			this->server_GetInfoButton->Visible = false;
			this->server_GetInfoButton->Click += gcnew System::EventHandler(this, &main_form::server_GetInfoButton_Click);
			// 
			// billing_SetAccountInfoButton
			// 
			this->billing_SetAccountInfoButton->Enabled = false;
			this->billing_SetAccountInfoButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_SetAccountInfoButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButton->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButton->Location = System::Drawing::Point(608, 2);
			this->billing_SetAccountInfoButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_SetAccountInfoButton->Name = L"billing_SetAccountInfoButton";
			this->billing_SetAccountInfoButton->Size = System::Drawing::Size(192, 30);
			this->billing_SetAccountInfoButton->TabIndex = 36;
			this->billing_SetAccountInfoButton->Text = L"Set Account Info";
			this->billing_SetAccountInfoButton->UseVisualStyleBackColor = true;
			this->billing_SetAccountInfoButton->Visible = false;
			this->billing_SetAccountInfoButton->Click += gcnew System::EventHandler(this, &main_form::billing_SetAccountInfoButton_Click);
			// 
			// billing_ReplyToTicketButton
			// 
			this->billing_ReplyToTicketButton->Enabled = false;
			this->billing_ReplyToTicketButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_ReplyToTicketButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_ReplyToTicketButton->ForeColor = System::Drawing::Color::White;
			this->billing_ReplyToTicketButton->Location = System::Drawing::Point(608, 34);
			this->billing_ReplyToTicketButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_ReplyToTicketButton->Name = L"billing_ReplyToTicketButton";
			this->billing_ReplyToTicketButton->Size = System::Drawing::Size(192, 30);
			this->billing_ReplyToTicketButton->TabIndex = 35;
			this->billing_ReplyToTicketButton->Text = L"Reply to Ticket";
			this->billing_ReplyToTicketButton->UseVisualStyleBackColor = true;
			this->billing_ReplyToTicketButton->Visible = false;
			this->billing_ReplyToTicketButton->Click += gcnew System::EventHandler(this, &main_form::billing_ReplyToTicketButton_Click);
			// 
			// billing_OpenNewTicketButton
			// 
			this->billing_OpenNewTicketButton->Enabled = false;
			this->billing_OpenNewTicketButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_OpenNewTicketButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_OpenNewTicketButton->ForeColor = System::Drawing::Color::White;
			this->billing_OpenNewTicketButton->Location = System::Drawing::Point(608, 66);
			this->billing_OpenNewTicketButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_OpenNewTicketButton->Name = L"billing_OpenNewTicketButton";
			this->billing_OpenNewTicketButton->Size = System::Drawing::Size(192, 30);
			this->billing_OpenNewTicketButton->TabIndex = 34;
			this->billing_OpenNewTicketButton->Text = L"Open New Ticket";
			this->billing_OpenNewTicketButton->UseVisualStyleBackColor = true;
			this->billing_OpenNewTicketButton->Visible = false;
			this->billing_OpenNewTicketButton->Click += gcnew System::EventHandler(this, &main_form::billing_OpenNewTicketButton_Click);
			// 
			// billing_CloseTicketByIDButton
			// 
			this->billing_CloseTicketByIDButton->Enabled = false;
			this->billing_CloseTicketByIDButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_CloseTicketByIDButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_CloseTicketByIDButton->ForeColor = System::Drawing::Color::White;
			this->billing_CloseTicketByIDButton->Location = System::Drawing::Point(411, 66);
			this->billing_CloseTicketByIDButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_CloseTicketByIDButton->Name = L"billing_CloseTicketByIDButton";
			this->billing_CloseTicketByIDButton->Size = System::Drawing::Size(192, 30);
			this->billing_CloseTicketByIDButton->TabIndex = 33;
			this->billing_CloseTicketByIDButton->Text = L"Close Ticket By ID";
			this->billing_CloseTicketByIDButton->UseVisualStyleBackColor = true;
			this->billing_CloseTicketByIDButton->Visible = false;
			this->billing_CloseTicketByIDButton->Click += gcnew System::EventHandler(this, &main_form::billing_CloseTicketByIDButton_Click);
			// 
			// billing_GetPromoInfoButton
			// 
			this->billing_GetPromoInfoButton->Enabled = false;
			this->billing_GetPromoInfoButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_GetPromoInfoButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetPromoInfoButton->ForeColor = System::Drawing::Color::White;
			this->billing_GetPromoInfoButton->Location = System::Drawing::Point(411, 34);
			this->billing_GetPromoInfoButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_GetPromoInfoButton->Name = L"billing_GetPromoInfoButton";
			this->billing_GetPromoInfoButton->Size = System::Drawing::Size(192, 30);
			this->billing_GetPromoInfoButton->TabIndex = 32;
			this->billing_GetPromoInfoButton->Text = L"Get Promotion Info";
			this->billing_GetPromoInfoButton->UseVisualStyleBackColor = true;
			this->billing_GetPromoInfoButton->Visible = false;
			this->billing_GetPromoInfoButton->Click += gcnew System::EventHandler(this, &main_form::billing_GetPromoInfoButton_Click);
			// 
			// billing_GetTicketByIDButton
			// 
			this->billing_GetTicketByIDButton->Enabled = false;
			this->billing_GetTicketByIDButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_GetTicketByIDButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetTicketByIDButton->ForeColor = System::Drawing::Color::White;
			this->billing_GetTicketByIDButton->Location = System::Drawing::Point(411, 2);
			this->billing_GetTicketByIDButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_GetTicketByIDButton->Name = L"billing_GetTicketByIDButton";
			this->billing_GetTicketByIDButton->Size = System::Drawing::Size(192, 30);
			this->billing_GetTicketByIDButton->TabIndex = 31;
			this->billing_GetTicketByIDButton->Text = L"Get Ticket By ID";
			this->billing_GetTicketByIDButton->UseVisualStyleBackColor = true;
			this->billing_GetTicketByIDButton->Visible = false;
			this->billing_GetTicketByIDButton->Click += gcnew System::EventHandler(this, &main_form::billing_GetTicketByIDButton_Click);
			// 
			// billing_GetInvoiceByIDButton
			// 
			this->billing_GetInvoiceByIDButton->Enabled = false;
			this->billing_GetInvoiceByIDButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_GetInvoiceByIDButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetInvoiceByIDButton->ForeColor = System::Drawing::Color::White;
			this->billing_GetInvoiceByIDButton->Location = System::Drawing::Point(212, 66);
			this->billing_GetInvoiceByIDButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_GetInvoiceByIDButton->Name = L"billing_GetInvoiceByIDButton";
			this->billing_GetInvoiceByIDButton->Size = System::Drawing::Size(192, 30);
			this->billing_GetInvoiceByIDButton->TabIndex = 30;
			this->billing_GetInvoiceByIDButton->Text = L"Get Invoice By ID";
			this->billing_GetInvoiceByIDButton->UseVisualStyleBackColor = true;
			this->billing_GetInvoiceByIDButton->Visible = false;
			this->billing_GetInvoiceByIDButton->Click += gcnew System::EventHandler(this, &main_form::billing_GetInvoiceByIDButton_Click);
			// 
			// billing_GetAllTickets
			// 
			this->billing_GetAllTickets->Enabled = false;
			this->billing_GetAllTickets->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_GetAllTickets->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetAllTickets->ForeColor = System::Drawing::Color::White;
			this->billing_GetAllTickets->Location = System::Drawing::Point(212, 34);
			this->billing_GetAllTickets->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_GetAllTickets->Name = L"billing_GetAllTickets";
			this->billing_GetAllTickets->Size = System::Drawing::Size(192, 30);
			this->billing_GetAllTickets->TabIndex = 29;
			this->billing_GetAllTickets->Text = L"Get All Tickets";
			this->billing_GetAllTickets->UseVisualStyleBackColor = true;
			this->billing_GetAllTickets->Visible = false;
			this->billing_GetAllTickets->Click += gcnew System::EventHandler(this, &main_form::billing_GetAllTickets_Click);
			// 
			// billing_GetProductsButton
			// 
			this->billing_GetProductsButton->Enabled = false;
			this->billing_GetProductsButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_GetProductsButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetProductsButton->ForeColor = System::Drawing::Color::White;
			this->billing_GetProductsButton->Location = System::Drawing::Point(212, 2);
			this->billing_GetProductsButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_GetProductsButton->Name = L"billing_GetProductsButton";
			this->billing_GetProductsButton->Size = System::Drawing::Size(192, 30);
			this->billing_GetProductsButton->TabIndex = 28;
			this->billing_GetProductsButton->Text = L"Get Product List";
			this->billing_GetProductsButton->UseVisualStyleBackColor = true;
			this->billing_GetProductsButton->Visible = false;
			this->billing_GetProductsButton->Click += gcnew System::EventHandler(this, &main_form::billing_GetProductsButton_Click);
			// 
			// billing_GetActiveServicesButton
			// 
			this->billing_GetActiveServicesButton->Enabled = false;
			this->billing_GetActiveServicesButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_GetActiveServicesButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetActiveServicesButton->ForeColor = System::Drawing::Color::White;
			this->billing_GetActiveServicesButton->Location = System::Drawing::Point(13, 66);
			this->billing_GetActiveServicesButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_GetActiveServicesButton->Name = L"billing_GetActiveServicesButton";
			this->billing_GetActiveServicesButton->Size = System::Drawing::Size(192, 30);
			this->billing_GetActiveServicesButton->TabIndex = 27;
			this->billing_GetActiveServicesButton->Text = L"Get Active Services";
			this->billing_GetActiveServicesButton->UseVisualStyleBackColor = true;
			this->billing_GetActiveServicesButton->Visible = false;
			this->billing_GetActiveServicesButton->Click += gcnew System::EventHandler(this, &main_form::billing_GetActiveServicesButton_Click);
			// 
			// billing_GetAllInvoicesButton
			// 
			this->billing_GetAllInvoicesButton->Enabled = false;
			this->billing_GetAllInvoicesButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_GetAllInvoicesButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetAllInvoicesButton->ForeColor = System::Drawing::Color::White;
			this->billing_GetAllInvoicesButton->Location = System::Drawing::Point(13, 34);
			this->billing_GetAllInvoicesButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_GetAllInvoicesButton->Name = L"billing_GetAllInvoicesButton";
			this->billing_GetAllInvoicesButton->Size = System::Drawing::Size(192, 30);
			this->billing_GetAllInvoicesButton->TabIndex = 26;
			this->billing_GetAllInvoicesButton->Text = L"Get All Invoices";
			this->billing_GetAllInvoicesButton->UseVisualStyleBackColor = true;
			this->billing_GetAllInvoicesButton->Visible = false;
			this->billing_GetAllInvoicesButton->Click += gcnew System::EventHandler(this, &main_form::billing_GetAllInvoicesButton_Click);
			// 
			// billing_GetAccountInfoButton
			// 
			this->billing_GetAccountInfoButton->Enabled = false;
			this->billing_GetAccountInfoButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_GetAccountInfoButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetAccountInfoButton->ForeColor = System::Drawing::Color::White;
			this->billing_GetAccountInfoButton->Location = System::Drawing::Point(13, 2);
			this->billing_GetAccountInfoButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_GetAccountInfoButton->Name = L"billing_GetAccountInfoButton";
			this->billing_GetAccountInfoButton->Size = System::Drawing::Size(192, 30);
			this->billing_GetAccountInfoButton->TabIndex = 25;
			this->billing_GetAccountInfoButton->Text = L"Get Account Info";
			this->billing_GetAccountInfoButton->UseVisualStyleBackColor = true;
			this->billing_GetAccountInfoButton->Visible = false;
			this->billing_GetAccountInfoButton->Click += gcnew System::EventHandler(this, &main_form::billing_GetAccountInfoButton_Click);
			// 
			// firewall_GetUnreadFirewallLogsButton
			// 
			this->firewall_GetUnreadFirewallLogsButton->Enabled = false;
			this->firewall_GetUnreadFirewallLogsButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->firewall_GetUnreadFirewallLogsButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->firewall_GetUnreadFirewallLogsButton->ForeColor = System::Drawing::Color::White;
			this->firewall_GetUnreadFirewallLogsButton->Location = System::Drawing::Point(13, 34);
			this->firewall_GetUnreadFirewallLogsButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->firewall_GetUnreadFirewallLogsButton->Name = L"firewall_GetUnreadFirewallLogsButton";
			this->firewall_GetUnreadFirewallLogsButton->Size = System::Drawing::Size(192, 30);
			this->firewall_GetUnreadFirewallLogsButton->TabIndex = 24;
			this->firewall_GetUnreadFirewallLogsButton->Text = L"Get Unread Logs";
			this->firewall_GetUnreadFirewallLogsButton->UseVisualStyleBackColor = true;
			this->firewall_GetUnreadFirewallLogsButton->Visible = false;
			this->firewall_GetUnreadFirewallLogsButton->Click += gcnew System::EventHandler(this, &main_form::firewall_GetUnreadFirewallLogsButton_Click);
			// 
			// firewall_DeleteFirewallLogsButton
			// 
			this->firewall_DeleteFirewallLogsButton->Enabled = false;
			this->firewall_DeleteFirewallLogsButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->firewall_DeleteFirewallLogsButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->firewall_DeleteFirewallLogsButton->ForeColor = System::Drawing::Color::White;
			this->firewall_DeleteFirewallLogsButton->Location = System::Drawing::Point(13, 66);
			this->firewall_DeleteFirewallLogsButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->firewall_DeleteFirewallLogsButton->Name = L"firewall_DeleteFirewallLogsButton";
			this->firewall_DeleteFirewallLogsButton->Size = System::Drawing::Size(192, 30);
			this->firewall_DeleteFirewallLogsButton->TabIndex = 23;
			this->firewall_DeleteFirewallLogsButton->Text = L"Delete Logs";
			this->firewall_DeleteFirewallLogsButton->UseVisualStyleBackColor = true;
			this->firewall_DeleteFirewallLogsButton->Visible = false;
			this->firewall_DeleteFirewallLogsButton->Click += gcnew System::EventHandler(this, &main_form::firewall_DeleteFirewallLogsButton_Click);
			// 
			// firewall_GetFirewallLogsButton
			// 
			this->firewall_GetFirewallLogsButton->Enabled = false;
			this->firewall_GetFirewallLogsButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->firewall_GetFirewallLogsButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->firewall_GetFirewallLogsButton->ForeColor = System::Drawing::Color::White;
			this->firewall_GetFirewallLogsButton->Location = System::Drawing::Point(13, 2);
			this->firewall_GetFirewallLogsButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->firewall_GetFirewallLogsButton->Name = L"firewall_GetFirewallLogsButton";
			this->firewall_GetFirewallLogsButton->Size = System::Drawing::Size(192, 30);
			this->firewall_GetFirewallLogsButton->TabIndex = 12;
			this->firewall_GetFirewallLogsButton->Text = L"Get All Logs";
			this->firewall_GetFirewallLogsButton->UseVisualStyleBackColor = true;
			this->firewall_GetFirewallLogsButton->Visible = false;
			this->firewall_GetFirewallLogsButton->Click += gcnew System::EventHandler(this, &main_form::firewall_GetFirewallLogsButton_Click);
			// 
			// fthLogo
			// 
			this->fthLogo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fthLogo.BackgroundImage")));
			this->fthLogo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->fthLogo->Enabled = false;
			this->fthLogo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->fthLogo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)));
			this->fthLogo->Location = System::Drawing::Point(931, -16);
			this->fthLogo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->fthLogo->Name = L"fthLogo";
			this->fthLogo->Size = System::Drawing::Size(161, 130);
			this->fthLogo->TabIndex = 22;
			this->fthLogo->UseVisualStyleBackColor = true;
			// 
			// ribbonVertPanel
			// 
			this->ribbonVertPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)));
			this->ribbonVertPanel->Controls->Add(this->settingsButton);
			this->ribbonVertPanel->Controls->Add(this->serverButton);
			this->ribbonVertPanel->Controls->Add(this->firewallButton);
			this->ribbonVertPanel->Controls->Add(this->billingButton);
			this->ribbonVertPanel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)));
			this->ribbonVertPanel->Location = System::Drawing::Point(-12, 85);
			this->ribbonVertPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ribbonVertPanel->Name = L"ribbonVertPanel";
			this->ribbonVertPanel->Size = System::Drawing::Size(143, 485);
			this->ribbonVertPanel->TabIndex = 1;
			// 
			// settingsButton
			// 
			this->settingsButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->settingsButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->settingsButton->ForeColor = System::Drawing::Color::White;
			this->settingsButton->Location = System::Drawing::Point(24, 391);
			this->settingsButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->settingsButton->Name = L"settingsButton";
			this->settingsButton->Size = System::Drawing::Size(101, 62);
			this->settingsButton->TabIndex = 10;
			this->settingsButton->Text = L"Settings";
			this->settingsButton->UseVisualStyleBackColor = true;
			this->settingsButton->Click += gcnew System::EventHandler(this, &main_form::settingsButton_Click);
			// 
			// serverButton
			// 
			this->serverButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->serverButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->serverButton->ForeColor = System::Drawing::Color::White;
			this->serverButton->Location = System::Drawing::Point(24, 31);
			this->serverButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->serverButton->Name = L"serverButton";
			this->serverButton->Size = System::Drawing::Size(101, 62);
			this->serverButton->TabIndex = 0;
			this->serverButton->Text = L"Server";
			this->serverButton->UseVisualStyleBackColor = true;
			this->serverButton->Click += gcnew System::EventHandler(this, &main_form::serverButton_Click);
			// 
			// firewallButton
			// 
			this->firewallButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->firewallButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->firewallButton->ForeColor = System::Drawing::Color::White;
			this->firewallButton->Location = System::Drawing::Point(24, 151);
			this->firewallButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->firewallButton->Name = L"firewallButton";
			this->firewallButton->Size = System::Drawing::Size(101, 62);
			this->firewallButton->TabIndex = 11;
			this->firewallButton->Text = L"Firewall";
			this->firewallButton->UseVisualStyleBackColor = true;
			this->firewallButton->Click += gcnew System::EventHandler(this, &main_form::firewallButton_Click);
			// 
			// billingButton
			// 
			this->billingButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billingButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billingButton->ForeColor = System::Drawing::Color::White;
			this->billingButton->Location = System::Drawing::Point(24, 271);
			this->billingButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billingButton->Name = L"billingButton";
			this->billingButton->Size = System::Drawing::Size(101, 62);
			this->billingButton->TabIndex = 9;
			this->billingButton->Text = L"Billing";
			this->billingButton->UseVisualStyleBackColor = true;
			this->billingButton->Click += gcnew System::EventHandler(this, &main_form::billingButton_Click);
			// 
			// apiKeyInputField
			// 
			this->apiKeyInputField->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->apiKeyInputField->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->apiKeyInputField->Enabled = false;
			this->apiKeyInputField->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->apiKeyInputField->ForeColor = System::Drawing::Color::White;
			this->apiKeyInputField->Location = System::Drawing::Point(327, 369);
			this->apiKeyInputField->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->apiKeyInputField->Multiline = false;
			this->apiKeyInputField->Name = L"apiKeyInputField";
			this->apiKeyInputField->Size = System::Drawing::Size(429, 29);
			this->apiKeyInputField->TabIndex = 0;
			this->apiKeyInputField->Text = L"";
			this->apiKeyInputField->Visible = false;
			// 
			// fthApiInputExtendedBanner
			// 
			this->fthApiInputExtendedBanner->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fthApiInputExtendedBanner.BackgroundImage")));
			this->fthApiInputExtendedBanner->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->fthApiInputExtendedBanner->Enabled = false;
			this->fthApiInputExtendedBanner->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->fthApiInputExtendedBanner->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->fthApiInputExtendedBanner->Location = System::Drawing::Point(287, 146);
			this->fthApiInputExtendedBanner->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->fthApiInputExtendedBanner->Name = L"fthApiInputExtendedBanner";
			this->fthApiInputExtendedBanner->Size = System::Drawing::Size(515, 217);
			this->fthApiInputExtendedBanner->TabIndex = 5;
			this->fthApiInputExtendedBanner->UseVisualStyleBackColor = true;
			this->fthApiInputExtendedBanner->Visible = false;
			// 
			// apiInstructionLabel
			// 
			this->apiInstructionLabel->Enabled = false;
			this->apiInstructionLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->apiInstructionLabel->ForeColor = System::Drawing::Color::White;
			this->apiInstructionLabel->Location = System::Drawing::Point(323, 401);
			this->apiInstructionLabel->Name = L"apiInstructionLabel";
			this->apiInstructionLabel->Size = System::Drawing::Size(160, 23);
			this->apiInstructionLabel->TabIndex = 6;
			this->apiInstructionLabel->Text = L"Input API Key:";
			this->apiInstructionLabel->Visible = false;
			// 
			// apiKeySaveButton
			// 
			this->apiKeySaveButton->Enabled = false;
			this->apiKeySaveButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->apiKeySaveButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->apiKeySaveButton->ForeColor = System::Drawing::Color::White;
			this->apiKeySaveButton->Location = System::Drawing::Point(681, 404);
			this->apiKeySaveButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->apiKeySaveButton->Name = L"apiKeySaveButton";
			this->apiKeySaveButton->Size = System::Drawing::Size(75, 23);
			this->apiKeySaveButton->TabIndex = 7;
			this->apiKeySaveButton->Text = L"Save";
			this->apiKeySaveButton->UseVisualStyleBackColor = true;
			this->apiKeySaveButton->Visible = false;
			this->apiKeySaveButton->Click += gcnew System::EventHandler(this, &main_form::apiKeySaveButton_Click);
			// 
			// settings_ChangeApiKeyInputField
			// 
			this->settings_ChangeApiKeyInputField->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->settings_ChangeApiKeyInputField->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->settings_ChangeApiKeyInputField->Enabled = false;
			this->settings_ChangeApiKeyInputField->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->settings_ChangeApiKeyInputField->ForeColor = System::Drawing::Color::White;
			this->settings_ChangeApiKeyInputField->Location = System::Drawing::Point(141, 142);
			this->settings_ChangeApiKeyInputField->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->settings_ChangeApiKeyInputField->Multiline = false;
			this->settings_ChangeApiKeyInputField->Name = L"settings_ChangeApiKeyInputField";
			this->settings_ChangeApiKeyInputField->Size = System::Drawing::Size(429, 29);
			this->settings_ChangeApiKeyInputField->TabIndex = 9;
			this->settings_ChangeApiKeyInputField->Text = L"";
			this->settings_ChangeApiKeyInputField->Visible = false;
			// 
			// settings_ApiInstructionLabel
			// 
			this->settings_ApiInstructionLabel->Enabled = false;
			this->settings_ApiInstructionLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->settings_ApiInstructionLabel->ForeColor = System::Drawing::Color::White;
			this->settings_ApiInstructionLabel->Location = System::Drawing::Point(137, 116);
			this->settings_ApiInstructionLabel->Name = L"settings_ApiInstructionLabel";
			this->settings_ApiInstructionLabel->Size = System::Drawing::Size(160, 23);
			this->settings_ApiInstructionLabel->TabIndex = 10;
			this->settings_ApiInstructionLabel->Text = L"Change API Key:";
			this->settings_ApiInstructionLabel->Visible = false;
			// 
			// settings_SaveChangedKeyButton
			// 
			this->settings_SaveChangedKeyButton->Enabled = false;
			this->settings_SaveChangedKeyButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->settings_SaveChangedKeyButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->settings_SaveChangedKeyButton->ForeColor = System::Drawing::Color::White;
			this->settings_SaveChangedKeyButton->Location = System::Drawing::Point(495, 177);
			this->settings_SaveChangedKeyButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->settings_SaveChangedKeyButton->Name = L"settings_SaveChangedKeyButton";
			this->settings_SaveChangedKeyButton->Size = System::Drawing::Size(75, 23);
			this->settings_SaveChangedKeyButton->TabIndex = 11;
			this->settings_SaveChangedKeyButton->Text = L"Save";
			this->settings_SaveChangedKeyButton->UseVisualStyleBackColor = true;
			this->settings_SaveChangedKeyButton->Visible = false;
			this->settings_SaveChangedKeyButton->Click += gcnew System::EventHandler(this, &main_form::settings_SaveChangedKeyButton_Click);
			// 
			// settings_ServerIDInstructionlabel
			// 
			this->settings_ServerIDInstructionlabel->Enabled = false;
			this->settings_ServerIDInstructionlabel->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->settings_ServerIDInstructionlabel->ForeColor = System::Drawing::Color::White;
			this->settings_ServerIDInstructionlabel->Location = System::Drawing::Point(137, 215);
			this->settings_ServerIDInstructionlabel->Name = L"settings_ServerIDInstructionlabel";
			this->settings_ServerIDInstructionlabel->Size = System::Drawing::Size(167, 23);
			this->settings_ServerIDInstructionlabel->TabIndex = 12;
			this->settings_ServerIDInstructionlabel->Text = L"Add New Server ID:";
			this->settings_ServerIDInstructionlabel->Visible = false;
			// 
			// settings_ServerIDInputField
			// 
			this->settings_ServerIDInputField->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->settings_ServerIDInputField->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->settings_ServerIDInputField->Enabled = false;
			this->settings_ServerIDInputField->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->settings_ServerIDInputField->ForeColor = System::Drawing::Color::White;
			this->settings_ServerIDInputField->Location = System::Drawing::Point(141, 241);
			this->settings_ServerIDInputField->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->settings_ServerIDInputField->Multiline = false;
			this->settings_ServerIDInputField->Name = L"settings_ServerIDInputField";
			this->settings_ServerIDInputField->Size = System::Drawing::Size(429, 29);
			this->settings_ServerIDInputField->TabIndex = 13;
			this->settings_ServerIDInputField->Text = L"";
			this->settings_ServerIDInputField->Visible = false;
			// 
			// settings_ServerIDSaveButton
			// 
			this->settings_ServerIDSaveButton->Enabled = false;
			this->settings_ServerIDSaveButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->settings_ServerIDSaveButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->settings_ServerIDSaveButton->ForeColor = System::Drawing::Color::White;
			this->settings_ServerIDSaveButton->Location = System::Drawing::Point(495, 276);
			this->settings_ServerIDSaveButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->settings_ServerIDSaveButton->Name = L"settings_ServerIDSaveButton";
			this->settings_ServerIDSaveButton->Size = System::Drawing::Size(75, 23);
			this->settings_ServerIDSaveButton->TabIndex = 14;
			this->settings_ServerIDSaveButton->Text = L"Save";
			this->settings_ServerIDSaveButton->UseVisualStyleBackColor = true;
			this->settings_ServerIDSaveButton->Visible = false;
			this->settings_ServerIDSaveButton->Click += gcnew System::EventHandler(this, &main_form::settings_ServerIDSaveButton_Click);
			// 
			// settings_ServerIDResetButton
			// 
			this->settings_ServerIDResetButton->Enabled = false;
			this->settings_ServerIDResetButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->settings_ServerIDResetButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->settings_ServerIDResetButton->ForeColor = System::Drawing::Color::White;
			this->settings_ServerIDResetButton->Location = System::Drawing::Point(141, 276);
			this->settings_ServerIDResetButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->settings_ServerIDResetButton->Name = L"settings_ServerIDResetButton";
			this->settings_ServerIDResetButton->Size = System::Drawing::Size(107, 23);
			this->settings_ServerIDResetButton->TabIndex = 15;
			this->settings_ServerIDResetButton->Text = L"Reset IDs";
			this->settings_ServerIDResetButton->UseVisualStyleBackColor = true;
			this->settings_ServerIDResetButton->Visible = false;
			this->settings_ServerIDResetButton->Click += gcnew System::EventHandler(this, &main_form::settings_ServerIDResetButton_Click);
			// 
			// settings_ServerIPInstructionLabel
			// 
			this->settings_ServerIPInstructionLabel->Enabled = false;
			this->settings_ServerIPInstructionLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->settings_ServerIPInstructionLabel->ForeColor = System::Drawing::Color::White;
			this->settings_ServerIPInstructionLabel->Location = System::Drawing::Point(137, 321);
			this->settings_ServerIPInstructionLabel->Name = L"settings_ServerIPInstructionLabel";
			this->settings_ServerIPInstructionLabel->Size = System::Drawing::Size(167, 23);
			this->settings_ServerIPInstructionLabel->TabIndex = 16;
			this->settings_ServerIPInstructionLabel->Text = L"Add New Server IP:";
			this->settings_ServerIPInstructionLabel->Visible = false;
			// 
			// settings_ServerIPInputField
			// 
			this->settings_ServerIPInputField->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->settings_ServerIPInputField->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->settings_ServerIPInputField->Enabled = false;
			this->settings_ServerIPInputField->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->settings_ServerIPInputField->ForeColor = System::Drawing::Color::White;
			this->settings_ServerIPInputField->Location = System::Drawing::Point(141, 347);
			this->settings_ServerIPInputField->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->settings_ServerIPInputField->Multiline = false;
			this->settings_ServerIPInputField->Name = L"settings_ServerIPInputField";
			this->settings_ServerIPInputField->Size = System::Drawing::Size(429, 29);
			this->settings_ServerIPInputField->TabIndex = 17;
			this->settings_ServerIPInputField->Text = L"";
			this->settings_ServerIPInputField->Visible = false;
			// 
			// settings_ServerIPSaveButton
			// 
			this->settings_ServerIPSaveButton->Enabled = false;
			this->settings_ServerIPSaveButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->settings_ServerIPSaveButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->settings_ServerIPSaveButton->ForeColor = System::Drawing::Color::White;
			this->settings_ServerIPSaveButton->Location = System::Drawing::Point(495, 382);
			this->settings_ServerIPSaveButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->settings_ServerIPSaveButton->Name = L"settings_ServerIPSaveButton";
			this->settings_ServerIPSaveButton->Size = System::Drawing::Size(75, 23);
			this->settings_ServerIPSaveButton->TabIndex = 18;
			this->settings_ServerIPSaveButton->Text = L"Save";
			this->settings_ServerIPSaveButton->UseVisualStyleBackColor = true;
			this->settings_ServerIPSaveButton->Visible = false;
			this->settings_ServerIPSaveButton->Click += gcnew System::EventHandler(this, &main_form::settings_ServerIPSaveButton_Click);
			// 
			// settings_ServerIPResetButton
			// 
			this->settings_ServerIPResetButton->Enabled = false;
			this->settings_ServerIPResetButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->settings_ServerIPResetButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->settings_ServerIPResetButton->ForeColor = System::Drawing::Color::White;
			this->settings_ServerIPResetButton->Location = System::Drawing::Point(141, 382);
			this->settings_ServerIPResetButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->settings_ServerIPResetButton->Name = L"settings_ServerIPResetButton";
			this->settings_ServerIPResetButton->Size = System::Drawing::Size(107, 23);
			this->settings_ServerIPResetButton->TabIndex = 19;
			this->settings_ServerIPResetButton->Text = L"Reset IPs";
			this->settings_ServerIPResetButton->UseVisualStyleBackColor = true;
			this->settings_ServerIPResetButton->Visible = false;
			this->settings_ServerIPResetButton->Click += gcnew System::EventHandler(this, &main_form::settings_ServerIPResetButton_Click);
			// 
			// responseOutputField
			// 
			this->responseOutputField->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->responseOutputField->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->responseOutputField->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->responseOutputField->ForeColor = System::Drawing::Color::White;
			this->responseOutputField->Location = System::Drawing::Point(137, 103);
			this->responseOutputField->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->responseOutputField->Name = L"responseOutputField";
			this->responseOutputField->ReadOnly = true;
			this->responseOutputField->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->responseOutputField->Size = System::Drawing::Size(944, 452);
			this->responseOutputField->TabIndex = 20;
			this->responseOutputField->Text = L"";
			// 
			// billing_GetInvoiceByIDButtonComponent_TextField
			// 
			this->billing_GetInvoiceByIDButtonComponent_TextField->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_GetInvoiceByIDButtonComponent_TextField->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_GetInvoiceByIDButtonComponent_TextField->Enabled = false;
			this->billing_GetInvoiceByIDButtonComponent_TextField->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetInvoiceByIDButtonComponent_TextField->ForeColor = System::Drawing::Color::White;
			this->billing_GetInvoiceByIDButtonComponent_TextField->Location = System::Drawing::Point(141, 142);
			this->billing_GetInvoiceByIDButtonComponent_TextField->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_GetInvoiceByIDButtonComponent_TextField->Multiline = false;
			this->billing_GetInvoiceByIDButtonComponent_TextField->Name = L"billing_GetInvoiceByIDButtonComponent_TextField";
			this->billing_GetInvoiceByIDButtonComponent_TextField->Size = System::Drawing::Size(429, 29);
			this->billing_GetInvoiceByIDButtonComponent_TextField->TabIndex = 21;
			this->billing_GetInvoiceByIDButtonComponent_TextField->Text = L"";
			this->billing_GetInvoiceByIDButtonComponent_TextField->Visible = false;
			// 
			// billing_GetInvoiceByIDComponent_SendButton
			// 
			this->billing_GetInvoiceByIDComponent_SendButton->Enabled = false;
			this->billing_GetInvoiceByIDComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_GetInvoiceByIDComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetInvoiceByIDComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->billing_GetInvoiceByIDComponent_SendButton->Location = System::Drawing::Point(495, 177);
			this->billing_GetInvoiceByIDComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_GetInvoiceByIDComponent_SendButton->Name = L"billing_GetInvoiceByIDComponent_SendButton";
			this->billing_GetInvoiceByIDComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->billing_GetInvoiceByIDComponent_SendButton->TabIndex = 22;
			this->billing_GetInvoiceByIDComponent_SendButton->Text = L"Send";
			this->billing_GetInvoiceByIDComponent_SendButton->UseVisualStyleBackColor = true;
			this->billing_GetInvoiceByIDComponent_SendButton->Visible = false;
			this->billing_GetInvoiceByIDComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::billing_GetInvoiceByIDComponent_SendButton_Click);
			// 
			// billing_GetInvoiceByIDComponent_InstructionLabel
			// 
			this->billing_GetInvoiceByIDComponent_InstructionLabel->Enabled = false;
			this->billing_GetInvoiceByIDComponent_InstructionLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetInvoiceByIDComponent_InstructionLabel->ForeColor = System::Drawing::Color::White;
			this->billing_GetInvoiceByIDComponent_InstructionLabel->Location = System::Drawing::Point(137, 116);
			this->billing_GetInvoiceByIDComponent_InstructionLabel->Name = L"billing_GetInvoiceByIDComponent_InstructionLabel";
			this->billing_GetInvoiceByIDComponent_InstructionLabel->Size = System::Drawing::Size(160, 23);
			this->billing_GetInvoiceByIDComponent_InstructionLabel->TabIndex = 23;
			this->billing_GetInvoiceByIDComponent_InstructionLabel->Text = L"Enter Invoice ID:";
			this->billing_GetInvoiceByIDComponent_InstructionLabel->Visible = false;
			// 
			// billing_GetTicketByIDButtonComponent_TextField
			// 
			this->billing_GetTicketByIDButtonComponent_TextField->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_GetTicketByIDButtonComponent_TextField->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_GetTicketByIDButtonComponent_TextField->Enabled = false;
			this->billing_GetTicketByIDButtonComponent_TextField->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetTicketByIDButtonComponent_TextField->ForeColor = System::Drawing::Color::White;
			this->billing_GetTicketByIDButtonComponent_TextField->Location = System::Drawing::Point(141, 142);
			this->billing_GetTicketByIDButtonComponent_TextField->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_GetTicketByIDButtonComponent_TextField->Multiline = false;
			this->billing_GetTicketByIDButtonComponent_TextField->Name = L"billing_GetTicketByIDButtonComponent_TextField";
			this->billing_GetTicketByIDButtonComponent_TextField->Size = System::Drawing::Size(429, 29);
			this->billing_GetTicketByIDButtonComponent_TextField->TabIndex = 24;
			this->billing_GetTicketByIDButtonComponent_TextField->Text = L"";
			this->billing_GetTicketByIDButtonComponent_TextField->Visible = false;
			// 
			// billing_GetTicketByIDButtonComponent_InstructionLabel
			// 
			this->billing_GetTicketByIDButtonComponent_InstructionLabel->Enabled = false;
			this->billing_GetTicketByIDButtonComponent_InstructionLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetTicketByIDButtonComponent_InstructionLabel->ForeColor = System::Drawing::Color::White;
			this->billing_GetTicketByIDButtonComponent_InstructionLabel->Location = System::Drawing::Point(137, 116);
			this->billing_GetTicketByIDButtonComponent_InstructionLabel->Name = L"billing_GetTicketByIDButtonComponent_InstructionLabel";
			this->billing_GetTicketByIDButtonComponent_InstructionLabel->Size = System::Drawing::Size(160, 23);
			this->billing_GetTicketByIDButtonComponent_InstructionLabel->TabIndex = 25;
			this->billing_GetTicketByIDButtonComponent_InstructionLabel->Text = L"Enter Ticket ID:";
			this->billing_GetTicketByIDButtonComponent_InstructionLabel->Visible = false;
			// 
			// billing_GetTicketByIDButtonComponent_SendButton
			// 
			this->billing_GetTicketByIDButtonComponent_SendButton->Enabled = false;
			this->billing_GetTicketByIDButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_GetTicketByIDButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetTicketByIDButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->billing_GetTicketByIDButtonComponent_SendButton->Location = System::Drawing::Point(495, 177);
			this->billing_GetTicketByIDButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_GetTicketByIDButtonComponent_SendButton->Name = L"billing_GetTicketByIDButtonComponent_SendButton";
			this->billing_GetTicketByIDButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->billing_GetTicketByIDButtonComponent_SendButton->TabIndex = 26;
			this->billing_GetTicketByIDButtonComponent_SendButton->Text = L"Send";
			this->billing_GetTicketByIDButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->billing_GetTicketByIDButtonComponent_SendButton->Visible = false;
			this->billing_GetTicketByIDButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::billing_GetTicketByIDButtonComponent_SendButton_Click);
			// 
			// billing_GetPromoInfoButtonComponent_TextField
			// 
			this->billing_GetPromoInfoButtonComponent_TextField->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_GetPromoInfoButtonComponent_TextField->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_GetPromoInfoButtonComponent_TextField->Enabled = false;
			this->billing_GetPromoInfoButtonComponent_TextField->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetPromoInfoButtonComponent_TextField->ForeColor = System::Drawing::Color::White;
			this->billing_GetPromoInfoButtonComponent_TextField->Location = System::Drawing::Point(141, 142);
			this->billing_GetPromoInfoButtonComponent_TextField->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_GetPromoInfoButtonComponent_TextField->Multiline = false;
			this->billing_GetPromoInfoButtonComponent_TextField->Name = L"billing_GetPromoInfoButtonComponent_TextField";
			this->billing_GetPromoInfoButtonComponent_TextField->Size = System::Drawing::Size(429, 29);
			this->billing_GetPromoInfoButtonComponent_TextField->TabIndex = 27;
			this->billing_GetPromoInfoButtonComponent_TextField->Text = L"";
			this->billing_GetPromoInfoButtonComponent_TextField->Visible = false;
			// 
			// billing_GetPromoInfoButtonComponent_SendButton
			// 
			this->billing_GetPromoInfoButtonComponent_SendButton->Enabled = false;
			this->billing_GetPromoInfoButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_GetPromoInfoButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetPromoInfoButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->billing_GetPromoInfoButtonComponent_SendButton->Location = System::Drawing::Point(495, 177);
			this->billing_GetPromoInfoButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_GetPromoInfoButtonComponent_SendButton->Name = L"billing_GetPromoInfoButtonComponent_SendButton";
			this->billing_GetPromoInfoButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->billing_GetPromoInfoButtonComponent_SendButton->TabIndex = 28;
			this->billing_GetPromoInfoButtonComponent_SendButton->Text = L"Send";
			this->billing_GetPromoInfoButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->billing_GetPromoInfoButtonComponent_SendButton->Visible = false;
			this->billing_GetPromoInfoButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::billing_GetPromoInfoButtonComponent_SendButton_Click);
			// 
			// billing_GetPromoInfoButtonComponent_InstructionLabel
			// 
			this->billing_GetPromoInfoButtonComponent_InstructionLabel->Enabled = false;
			this->billing_GetPromoInfoButtonComponent_InstructionLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_GetPromoInfoButtonComponent_InstructionLabel->ForeColor = System::Drawing::Color::White;
			this->billing_GetPromoInfoButtonComponent_InstructionLabel->Location = System::Drawing::Point(139, 116);
			this->billing_GetPromoInfoButtonComponent_InstructionLabel->Name = L"billing_GetPromoInfoButtonComponent_InstructionLabel";
			this->billing_GetPromoInfoButtonComponent_InstructionLabel->Size = System::Drawing::Size(167, 23);
			this->billing_GetPromoInfoButtonComponent_InstructionLabel->TabIndex = 29;
			this->billing_GetPromoInfoButtonComponent_InstructionLabel->Text = L"Input Promo Code:";
			this->billing_GetPromoInfoButtonComponent_InstructionLabel->Visible = false;
			// 
			// billing_CloseTicketByIDButtonComponent_InstructionLabel
			// 
			this->billing_CloseTicketByIDButtonComponent_InstructionLabel->Enabled = false;
			this->billing_CloseTicketByIDButtonComponent_InstructionLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_CloseTicketByIDButtonComponent_InstructionLabel->ForeColor = System::Drawing::Color::White;
			this->billing_CloseTicketByIDButtonComponent_InstructionLabel->Location = System::Drawing::Point(137, 116);
			this->billing_CloseTicketByIDButtonComponent_InstructionLabel->Name = L"billing_CloseTicketByIDButtonComponent_InstructionLabel";
			this->billing_CloseTicketByIDButtonComponent_InstructionLabel->Size = System::Drawing::Size(160, 23);
			this->billing_CloseTicketByIDButtonComponent_InstructionLabel->TabIndex = 30;
			this->billing_CloseTicketByIDButtonComponent_InstructionLabel->Text = L"Enter Ticket ID:";
			this->billing_CloseTicketByIDButtonComponent_InstructionLabel->Visible = false;
			// 
			// billing_CloseTicketByIDButtonComponent_SendButton
			// 
			this->billing_CloseTicketByIDButtonComponent_SendButton->Enabled = false;
			this->billing_CloseTicketByIDButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_CloseTicketByIDButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_CloseTicketByIDButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->billing_CloseTicketByIDButtonComponent_SendButton->Location = System::Drawing::Point(495, 177);
			this->billing_CloseTicketByIDButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_CloseTicketByIDButtonComponent_SendButton->Name = L"billing_CloseTicketByIDButtonComponent_SendButton";
			this->billing_CloseTicketByIDButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->billing_CloseTicketByIDButtonComponent_SendButton->TabIndex = 31;
			this->billing_CloseTicketByIDButtonComponent_SendButton->Text = L"Send";
			this->billing_CloseTicketByIDButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->billing_CloseTicketByIDButtonComponent_SendButton->Visible = false;
			this->billing_CloseTicketByIDButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::billing_CloseTicketByIDButtonComponent_SendButton_Click);
			// 
			// billing_CloseTicketByIDButtonComponent_TextField
			// 
			this->billing_CloseTicketByIDButtonComponent_TextField->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_CloseTicketByIDButtonComponent_TextField->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_CloseTicketByIDButtonComponent_TextField->Enabled = false;
			this->billing_CloseTicketByIDButtonComponent_TextField->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_CloseTicketByIDButtonComponent_TextField->ForeColor = System::Drawing::Color::White;
			this->billing_CloseTicketByIDButtonComponent_TextField->Location = System::Drawing::Point(143, 142);
			this->billing_CloseTicketByIDButtonComponent_TextField->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_CloseTicketByIDButtonComponent_TextField->Multiline = false;
			this->billing_CloseTicketByIDButtonComponent_TextField->Name = L"billing_CloseTicketByIDButtonComponent_TextField";
			this->billing_CloseTicketByIDButtonComponent_TextField->Size = System::Drawing::Size(429, 29);
			this->billing_CloseTicketByIDButtonComponent_TextField->TabIndex = 32;
			this->billing_CloseTicketByIDButtonComponent_TextField->Text = L"";
			this->billing_CloseTicketByIDButtonComponent_TextField->Visible = false;
			// 
			// billing_OpenNewTicketButtonComponent_TextField_Subject
			// 
			this->billing_OpenNewTicketButtonComponent_TextField_Subject->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_OpenNewTicketButtonComponent_TextField_Subject->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_OpenNewTicketButtonComponent_TextField_Subject->Enabled = false;
			this->billing_OpenNewTicketButtonComponent_TextField_Subject->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_OpenNewTicketButtonComponent_TextField_Subject->ForeColor = System::Drawing::Color::White;
			this->billing_OpenNewTicketButtonComponent_TextField_Subject->Location = System::Drawing::Point(143, 142);
			this->billing_OpenNewTicketButtonComponent_TextField_Subject->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_OpenNewTicketButtonComponent_TextField_Subject->Multiline = false;
			this->billing_OpenNewTicketButtonComponent_TextField_Subject->Name = L"billing_OpenNewTicketButtonComponent_TextField_Subject";
			this->billing_OpenNewTicketButtonComponent_TextField_Subject->Size = System::Drawing::Size(429, 29);
			this->billing_OpenNewTicketButtonComponent_TextField_Subject->TabIndex = 33;
			this->billing_OpenNewTicketButtonComponent_TextField_Subject->Text = L"";
			this->billing_OpenNewTicketButtonComponent_TextField_Subject->Visible = false;
			// 
			// billing_OpenNewTicketButtonComponent_TextField_Priority
			// 
			this->billing_OpenNewTicketButtonComponent_TextField_Priority->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_OpenNewTicketButtonComponent_TextField_Priority->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_OpenNewTicketButtonComponent_TextField_Priority->Enabled = false;
			this->billing_OpenNewTicketButtonComponent_TextField_Priority->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_OpenNewTicketButtonComponent_TextField_Priority->ForeColor = System::Drawing::Color::White;
			this->billing_OpenNewTicketButtonComponent_TextField_Priority->Location = System::Drawing::Point(141, 240);
			this->billing_OpenNewTicketButtonComponent_TextField_Priority->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_OpenNewTicketButtonComponent_TextField_Priority->Multiline = false;
			this->billing_OpenNewTicketButtonComponent_TextField_Priority->Name = L"billing_OpenNewTicketButtonComponent_TextField_Priority";
			this->billing_OpenNewTicketButtonComponent_TextField_Priority->Size = System::Drawing::Size(429, 29);
			this->billing_OpenNewTicketButtonComponent_TextField_Priority->TabIndex = 34;
			this->billing_OpenNewTicketButtonComponent_TextField_Priority->Text = L"";
			this->billing_OpenNewTicketButtonComponent_TextField_Priority->Visible = false;
			// 
			// billing_OpenNewTicketButtonComponent_TextField_Department
			// 
			this->billing_OpenNewTicketButtonComponent_TextField_Department->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_OpenNewTicketButtonComponent_TextField_Department->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_OpenNewTicketButtonComponent_TextField_Department->Enabled = false;
			this->billing_OpenNewTicketButtonComponent_TextField_Department->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_OpenNewTicketButtonComponent_TextField_Department->ForeColor = System::Drawing::Color::White;
			this->billing_OpenNewTicketButtonComponent_TextField_Department->Location = System::Drawing::Point(141, 347);
			this->billing_OpenNewTicketButtonComponent_TextField_Department->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_OpenNewTicketButtonComponent_TextField_Department->Multiline = false;
			this->billing_OpenNewTicketButtonComponent_TextField_Department->Name = L"billing_OpenNewTicketButtonComponent_TextField_Department";
			this->billing_OpenNewTicketButtonComponent_TextField_Department->Size = System::Drawing::Size(429, 29);
			this->billing_OpenNewTicketButtonComponent_TextField_Department->TabIndex = 35;
			this->billing_OpenNewTicketButtonComponent_TextField_Department->Text = L"";
			this->billing_OpenNewTicketButtonComponent_TextField_Department->Visible = false;
			// 
			// billing_OpenNewTicketButtonComponent_TextField_Message
			// 
			this->billing_OpenNewTicketButtonComponent_TextField_Message->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_OpenNewTicketButtonComponent_TextField_Message->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_OpenNewTicketButtonComponent_TextField_Message->Enabled = false;
			this->billing_OpenNewTicketButtonComponent_TextField_Message->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_OpenNewTicketButtonComponent_TextField_Message->ForeColor = System::Drawing::Color::White;
			this->billing_OpenNewTicketButtonComponent_TextField_Message->Location = System::Drawing::Point(141, 444);
			this->billing_OpenNewTicketButtonComponent_TextField_Message->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_OpenNewTicketButtonComponent_TextField_Message->Multiline = false;
			this->billing_OpenNewTicketButtonComponent_TextField_Message->Name = L"billing_OpenNewTicketButtonComponent_TextField_Message";
			this->billing_OpenNewTicketButtonComponent_TextField_Message->Size = System::Drawing::Size(429, 29);
			this->billing_OpenNewTicketButtonComponent_TextField_Message->TabIndex = 36;
			this->billing_OpenNewTicketButtonComponent_TextField_Message->Text = L"";
			this->billing_OpenNewTicketButtonComponent_TextField_Message->Visible = false;
			// 
			// billing_OpenNewTicketButtonComponent_SendButton
			// 
			this->billing_OpenNewTicketButtonComponent_SendButton->Enabled = false;
			this->billing_OpenNewTicketButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_OpenNewTicketButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_OpenNewTicketButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->billing_OpenNewTicketButtonComponent_SendButton->Location = System::Drawing::Point(495, 489);
			this->billing_OpenNewTicketButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_OpenNewTicketButtonComponent_SendButton->Name = L"billing_OpenNewTicketButtonComponent_SendButton";
			this->billing_OpenNewTicketButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->billing_OpenNewTicketButtonComponent_SendButton->TabIndex = 37;
			this->billing_OpenNewTicketButtonComponent_SendButton->Text = L"Send";
			this->billing_OpenNewTicketButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->billing_OpenNewTicketButtonComponent_SendButton->Visible = false;
			this->billing_OpenNewTicketButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::billing_OpenNewTicketButtonComponent_SendButton_Click);
			// 
			// billing_OpenNewTicketButtonComponent_InstructionLabel_Message
			// 
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Message->Enabled = false;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Message->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Message->ForeColor = System::Drawing::Color::White;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Message->Location = System::Drawing::Point(137, 428);
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Message->Name = L"billing_OpenNewTicketButtonComponent_InstructionLabel_Message";
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Message->Size = System::Drawing::Size(167, 23);
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Message->TabIndex = 38;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Message->Text = L"Ticket Message:";
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Message->Visible = false;
			// 
			// billing_OpenNewTicketButtonComponent_InstructionLabel_Subject
			// 
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Subject->Enabled = false;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Subject->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Subject->ForeColor = System::Drawing::Color::White;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Subject->Location = System::Drawing::Point(137, 116);
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Subject->Name = L"billing_OpenNewTicketButtonComponent_InstructionLabel_Subject";
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Subject->Size = System::Drawing::Size(167, 23);
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Subject->TabIndex = 39;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Subject->Text = L"Ticket Subject:";
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Subject->Visible = false;
			// 
			// billing_OpenNewTicketButtonComponent_InstructionLabel_Priority
			// 
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Priority->Enabled = false;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Priority->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Priority->ForeColor = System::Drawing::Color::White;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Priority->Location = System::Drawing::Point(137, 214);
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Priority->Name = L"billing_OpenNewTicketButtonComponent_InstructionLabel_Priority";
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Priority->Size = System::Drawing::Size(167, 23);
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Priority->TabIndex = 40;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Priority->Text = L"Ticket Priority:";
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Priority->Visible = false;
			// 
			// billing_OpenNewTicketButtonComponent_InstructionLabel_Department
			// 
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Department->Enabled = false;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Department->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Department->ForeColor = System::Drawing::Color::White;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Department->Location = System::Drawing::Point(137, 321);
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Department->Name = L"billing_OpenNewTicketButtonComponent_InstructionLabel_Department";
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Department->Size = System::Drawing::Size(167, 23);
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Department->TabIndex = 41;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Department->Text = L"Ticket Dept. ID:";
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Department->Visible = false;
			// 
			// billing_ReplyToTicketButtonComponent_TextField_TicketID
			// 
			this->billing_ReplyToTicketButtonComponent_TextField_TicketID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_ReplyToTicketButtonComponent_TextField_TicketID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_ReplyToTicketButtonComponent_TextField_TicketID->Enabled = false;
			this->billing_ReplyToTicketButtonComponent_TextField_TicketID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_ReplyToTicketButtonComponent_TextField_TicketID->ForeColor = System::Drawing::Color::White;
			this->billing_ReplyToTicketButtonComponent_TextField_TicketID->Location = System::Drawing::Point(143, 142);
			this->billing_ReplyToTicketButtonComponent_TextField_TicketID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_ReplyToTicketButtonComponent_TextField_TicketID->Multiline = false;
			this->billing_ReplyToTicketButtonComponent_TextField_TicketID->Name = L"billing_ReplyToTicketButtonComponent_TextField_TicketID";
			this->billing_ReplyToTicketButtonComponent_TextField_TicketID->Size = System::Drawing::Size(429, 29);
			this->billing_ReplyToTicketButtonComponent_TextField_TicketID->TabIndex = 42;
			this->billing_ReplyToTicketButtonComponent_TextField_TicketID->Text = L"";
			this->billing_ReplyToTicketButtonComponent_TextField_TicketID->Visible = false;
			// 
			// billing_ReplyToTicketButtonComponent_TextField_Message
			// 
			this->billing_ReplyToTicketButtonComponent_TextField_Message->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_ReplyToTicketButtonComponent_TextField_Message->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_ReplyToTicketButtonComponent_TextField_Message->Enabled = false;
			this->billing_ReplyToTicketButtonComponent_TextField_Message->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_ReplyToTicketButtonComponent_TextField_Message->ForeColor = System::Drawing::Color::White;
			this->billing_ReplyToTicketButtonComponent_TextField_Message->Location = System::Drawing::Point(143, 241);
			this->billing_ReplyToTicketButtonComponent_TextField_Message->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_ReplyToTicketButtonComponent_TextField_Message->Multiline = false;
			this->billing_ReplyToTicketButtonComponent_TextField_Message->Name = L"billing_ReplyToTicketButtonComponent_TextField_Message";
			this->billing_ReplyToTicketButtonComponent_TextField_Message->Size = System::Drawing::Size(429, 29);
			this->billing_ReplyToTicketButtonComponent_TextField_Message->TabIndex = 43;
			this->billing_ReplyToTicketButtonComponent_TextField_Message->Text = L"";
			this->billing_ReplyToTicketButtonComponent_TextField_Message->Visible = false;
			// 
			// billing_ReplyToTicketButtonComponent_SendButton
			// 
			this->billing_ReplyToTicketButtonComponent_SendButton->Enabled = false;
			this->billing_ReplyToTicketButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_ReplyToTicketButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_ReplyToTicketButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->billing_ReplyToTicketButtonComponent_SendButton->Location = System::Drawing::Point(495, 276);
			this->billing_ReplyToTicketButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_ReplyToTicketButtonComponent_SendButton->Name = L"billing_ReplyToTicketButtonComponent_SendButton";
			this->billing_ReplyToTicketButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->billing_ReplyToTicketButtonComponent_SendButton->TabIndex = 44;
			this->billing_ReplyToTicketButtonComponent_SendButton->Text = L"Send";
			this->billing_ReplyToTicketButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->billing_ReplyToTicketButtonComponent_SendButton->Visible = false;
			this->billing_ReplyToTicketButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::billing_ReplyToTicketButtonComponent_SendButton_Click);
			// 
			// billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID
			// 
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID->Enabled = false;
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID->ForeColor = System::Drawing::Color::White;
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID->Location = System::Drawing::Point(133, 116);
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID->Name = L"billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID";
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID->Size = System::Drawing::Size(167, 23);
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID->TabIndex = 45;
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID->Text = L"Ticket ID:";
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID->Visible = false;
			// 
			// billing_ReplyToTicketButtonComponent_InstructionLabel_Message
			// 
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_Message->Enabled = false;
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_Message->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_Message->ForeColor = System::Drawing::Color::White;
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_Message->Location = System::Drawing::Point(137, 214);
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_Message->Name = L"billing_ReplyToTicketButtonComponent_InstructionLabel_Message";
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_Message->Size = System::Drawing::Size(167, 23);
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_Message->TabIndex = 46;
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_Message->Text = L"Ticket Message:";
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_Message->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName
			// 
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName->Location = System::Drawing::Point(137, 116);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName->Name = L"billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName->Size = System::Drawing::Size(167, 23);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName->TabIndex = 47;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName->Text = L"First Name:";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_TextField_FirstName
			// 
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName->Location = System::Drawing::Point(137, 142);
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName->Multiline = false;
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName->Name = L"billing_SetAccountInfoButtonComponent_TextField_FirstName";
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName->Size = System::Drawing::Size(429, 29);
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName->TabIndex = 48;
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName->Text = L"";
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_TextField_LastName
			// 
			this->billing_SetAccountInfoButtonComponent_TextField_LastName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_SetAccountInfoButtonComponent_TextField_LastName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_SetAccountInfoButtonComponent_TextField_LastName->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_TextField_LastName->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_TextField_LastName->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_TextField_LastName->Location = System::Drawing::Point(137, 206);
			this->billing_SetAccountInfoButtonComponent_TextField_LastName->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_SetAccountInfoButtonComponent_TextField_LastName->Multiline = false;
			this->billing_SetAccountInfoButtonComponent_TextField_LastName->Name = L"billing_SetAccountInfoButtonComponent_TextField_LastName";
			this->billing_SetAccountInfoButtonComponent_TextField_LastName->Size = System::Drawing::Size(429, 29);
			this->billing_SetAccountInfoButtonComponent_TextField_LastName->TabIndex = 49;
			this->billing_SetAccountInfoButtonComponent_TextField_LastName->Text = L"";
			this->billing_SetAccountInfoButtonComponent_TextField_LastName->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_InstructionLabel_LastName
			// 
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_LastName->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_LastName->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_LastName->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_LastName->Location = System::Drawing::Point(139, 177);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_LastName->Name = L"billing_SetAccountInfoButtonComponent_InstructionLabel_LastName";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_LastName->Size = System::Drawing::Size(167, 23);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_LastName->TabIndex = 50;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_LastName->Text = L"Last Name:";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_LastName->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_InstructionLabel_Country
			// 
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Country->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Country->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Country->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Country->Location = System::Drawing::Point(137, 246);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Country->Name = L"billing_SetAccountInfoButtonComponent_InstructionLabel_Country";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Country->Size = System::Drawing::Size(167, 23);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Country->TabIndex = 51;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Country->Text = L"Country:";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Country->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_TextField_Country
			// 
			this->billing_SetAccountInfoButtonComponent_TextField_Country->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_SetAccountInfoButtonComponent_TextField_Country->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_SetAccountInfoButtonComponent_TextField_Country->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_TextField_Country->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_TextField_Country->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_TextField_Country->Location = System::Drawing::Point(137, 272);
			this->billing_SetAccountInfoButtonComponent_TextField_Country->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_SetAccountInfoButtonComponent_TextField_Country->Multiline = false;
			this->billing_SetAccountInfoButtonComponent_TextField_Country->Name = L"billing_SetAccountInfoButtonComponent_TextField_Country";
			this->billing_SetAccountInfoButtonComponent_TextField_Country->Size = System::Drawing::Size(429, 29);
			this->billing_SetAccountInfoButtonComponent_TextField_Country->TabIndex = 52;
			this->billing_SetAccountInfoButtonComponent_TextField_Country->Text = L"";
			this->billing_SetAccountInfoButtonComponent_TextField_Country->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_InstructionLabel_State
			// 
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_State->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_State->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_State->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_State->Location = System::Drawing::Point(137, 321);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_State->Name = L"billing_SetAccountInfoButtonComponent_InstructionLabel_State";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_State->Size = System::Drawing::Size(167, 23);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_State->TabIndex = 53;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_State->Text = L"State:";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_State->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_TextField_State
			// 
			this->billing_SetAccountInfoButtonComponent_TextField_State->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_SetAccountInfoButtonComponent_TextField_State->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_SetAccountInfoButtonComponent_TextField_State->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_TextField_State->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_TextField_State->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_TextField_State->Location = System::Drawing::Point(137, 347);
			this->billing_SetAccountInfoButtonComponent_TextField_State->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_SetAccountInfoButtonComponent_TextField_State->Multiline = false;
			this->billing_SetAccountInfoButtonComponent_TextField_State->Name = L"billing_SetAccountInfoButtonComponent_TextField_State";
			this->billing_SetAccountInfoButtonComponent_TextField_State->Size = System::Drawing::Size(429, 29);
			this->billing_SetAccountInfoButtonComponent_TextField_State->TabIndex = 54;
			this->billing_SetAccountInfoButtonComponent_TextField_State->Text = L"";
			this->billing_SetAccountInfoButtonComponent_TextField_State->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_InstructionLabel_Address
			// 
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Address->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Address->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Address->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Address->Location = System::Drawing::Point(137, 394);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Address->Name = L"billing_SetAccountInfoButtonComponent_InstructionLabel_Address";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Address->Size = System::Drawing::Size(167, 23);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Address->TabIndex = 55;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Address->Text = L"Address:";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Address->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_TextField_Address
			// 
			this->billing_SetAccountInfoButtonComponent_TextField_Address->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_SetAccountInfoButtonComponent_TextField_Address->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_SetAccountInfoButtonComponent_TextField_Address->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_TextField_Address->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_TextField_Address->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_TextField_Address->Location = System::Drawing::Point(137, 420);
			this->billing_SetAccountInfoButtonComponent_TextField_Address->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_SetAccountInfoButtonComponent_TextField_Address->Multiline = false;
			this->billing_SetAccountInfoButtonComponent_TextField_Address->Name = L"billing_SetAccountInfoButtonComponent_TextField_Address";
			this->billing_SetAccountInfoButtonComponent_TextField_Address->Size = System::Drawing::Size(429, 29);
			this->billing_SetAccountInfoButtonComponent_TextField_Address->TabIndex = 56;
			this->billing_SetAccountInfoButtonComponent_TextField_Address->Text = L"";
			this->billing_SetAccountInfoButtonComponent_TextField_Address->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_TextField_City
			// 
			this->billing_SetAccountInfoButtonComponent_TextField_City->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_SetAccountInfoButtonComponent_TextField_City->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_SetAccountInfoButtonComponent_TextField_City->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_TextField_City->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_TextField_City->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_TextField_City->Location = System::Drawing::Point(137, 487);
			this->billing_SetAccountInfoButtonComponent_TextField_City->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_SetAccountInfoButtonComponent_TextField_City->Multiline = false;
			this->billing_SetAccountInfoButtonComponent_TextField_City->Name = L"billing_SetAccountInfoButtonComponent_TextField_City";
			this->billing_SetAccountInfoButtonComponent_TextField_City->Size = System::Drawing::Size(429, 29);
			this->billing_SetAccountInfoButtonComponent_TextField_City->TabIndex = 57;
			this->billing_SetAccountInfoButtonComponent_TextField_City->Text = L"";
			this->billing_SetAccountInfoButtonComponent_TextField_City->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_InstructionLabel_City
			// 
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_City->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_City->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_City->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_City->Location = System::Drawing::Point(137, 462);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_City->Name = L"billing_SetAccountInfoButtonComponent_InstructionLabel_City";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_City->Size = System::Drawing::Size(167, 23);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_City->TabIndex = 58;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_City->Text = L"City:";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_City->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_TextField_ZIPCode
			// 
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Location = System::Drawing::Point(597, 142);
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Multiline = false;
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Name = L"billing_SetAccountInfoButtonComponent_TextField_ZIPCode";
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Size = System::Drawing::Size(429, 29);
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->TabIndex = 59;
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Text = L"";
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode
			// 
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode->Location = System::Drawing::Point(593, 116);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode->Name = L"billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode->Size = System::Drawing::Size(167, 23);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode->TabIndex = 60;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode->Text = L"ZIP Code:";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber
			// 
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber->Location = System::Drawing::Point(593, 177);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber->Name = L"billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber->Size = System::Drawing::Size(167, 23);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber->TabIndex = 61;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber->Text = L"Phone Number:";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_TextField_PhoneNumber
			// 
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Location = System::Drawing::Point(597, 203);
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Multiline = false;
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Name = L"billing_SetAccountInfoButtonComponent_TextField_PhoneNumber";
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Size = System::Drawing::Size(429, 29);
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->TabIndex = 62;
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Text = L"";
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_InstructionLabel_Email
			// 
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Email->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Email->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Email->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Email->Location = System::Drawing::Point(593, 246);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Email->Name = L"billing_SetAccountInfoButtonComponent_InstructionLabel_Email";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Email->Size = System::Drawing::Size(167, 23);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Email->TabIndex = 63;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Email->Text = L"E-Mail:";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Email->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_TextField_Email
			// 
			this->billing_SetAccountInfoButtonComponent_TextField_Email->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_SetAccountInfoButtonComponent_TextField_Email->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_SetAccountInfoButtonComponent_TextField_Email->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_TextField_Email->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_TextField_Email->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_TextField_Email->Location = System::Drawing::Point(597, 272);
			this->billing_SetAccountInfoButtonComponent_TextField_Email->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_SetAccountInfoButtonComponent_TextField_Email->Multiline = false;
			this->billing_SetAccountInfoButtonComponent_TextField_Email->Name = L"billing_SetAccountInfoButtonComponent_TextField_Email";
			this->billing_SetAccountInfoButtonComponent_TextField_Email->Size = System::Drawing::Size(429, 29);
			this->billing_SetAccountInfoButtonComponent_TextField_Email->TabIndex = 64;
			this->billing_SetAccountInfoButtonComponent_TextField_Email->Text = L"";
			this->billing_SetAccountInfoButtonComponent_TextField_Email->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_TextField_Password
			// 
			this->billing_SetAccountInfoButtonComponent_TextField_Password->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_SetAccountInfoButtonComponent_TextField_Password->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_SetAccountInfoButtonComponent_TextField_Password->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_TextField_Password->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_TextField_Password->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_TextField_Password->Location = System::Drawing::Point(597, 347);
			this->billing_SetAccountInfoButtonComponent_TextField_Password->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_SetAccountInfoButtonComponent_TextField_Password->Multiline = false;
			this->billing_SetAccountInfoButtonComponent_TextField_Password->Name = L"billing_SetAccountInfoButtonComponent_TextField_Password";
			this->billing_SetAccountInfoButtonComponent_TextField_Password->Size = System::Drawing::Size(429, 29);
			this->billing_SetAccountInfoButtonComponent_TextField_Password->TabIndex = 65;
			this->billing_SetAccountInfoButtonComponent_TextField_Password->Text = L"";
			this->billing_SetAccountInfoButtonComponent_TextField_Password->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_InstructionLabel_Password
			// 
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Password->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Password->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Password->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Password->Location = System::Drawing::Point(593, 321);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Password->Name = L"billing_SetAccountInfoButtonComponent_InstructionLabel_Password";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Password->Size = System::Drawing::Size(167, 23);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Password->TabIndex = 66;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Password->Text = L"New Password:";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Password->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword
			// 
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword->Location = System::Drawing::Point(593, 394);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword->Name = L"billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword->Size = System::Drawing::Size(167, 23);
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword->TabIndex = 67;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword->Text = L"Confirm Password:";
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword
			// 
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Location = System::Drawing::Point(597, 420);
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Multiline = false;
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Name = L"billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword";
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Size = System::Drawing::Size(429, 29);
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->TabIndex = 68;
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Text = L"";
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Visible = false;
			// 
			// billing_SetAccountInfoButtonComponent_SaveButton
			// 
			this->billing_SetAccountInfoButtonComponent_SaveButton->Enabled = false;
			this->billing_SetAccountInfoButtonComponent_SaveButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->billing_SetAccountInfoButtonComponent_SaveButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->billing_SetAccountInfoButtonComponent_SaveButton->ForeColor = System::Drawing::Color::White;
			this->billing_SetAccountInfoButtonComponent_SaveButton->Location = System::Drawing::Point(951, 455);
			this->billing_SetAccountInfoButtonComponent_SaveButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->billing_SetAccountInfoButtonComponent_SaveButton->Name = L"billing_SetAccountInfoButtonComponent_SaveButton";
			this->billing_SetAccountInfoButtonComponent_SaveButton->Size = System::Drawing::Size(75, 23);
			this->billing_SetAccountInfoButtonComponent_SaveButton->TabIndex = 69;
			this->billing_SetAccountInfoButtonComponent_SaveButton->Text = L"Save";
			this->billing_SetAccountInfoButtonComponent_SaveButton->UseVisualStyleBackColor = true;
			this->billing_SetAccountInfoButtonComponent_SaveButton->Visible = false;
			this->billing_SetAccountInfoButtonComponent_SaveButton->Click += gcnew System::EventHandler(this, &main_form::billing_SetAccountInfoButtonComponent_SaveButton_Click);
			// 
			// server_GetInfoButtonComponent_TextField_ServerID
			// 
			this->server_GetInfoButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_GetInfoButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_GetInfoButtonComponent_TextField_ServerID->Enabled = false;
			this->server_GetInfoButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetInfoButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetInfoButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_GetInfoButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetInfoButtonComponent_TextField_ServerID->Multiline = false;
			this->server_GetInfoButtonComponent_TextField_ServerID->Name = L"server_GetInfoButtonComponent_TextField_ServerID";
			this->server_GetInfoButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_GetInfoButtonComponent_TextField_ServerID->TabIndex = 70;
			this->server_GetInfoButtonComponent_TextField_ServerID->Text = L"";
			this->server_GetInfoButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_GetInfoButtonComponent_InstructionLabel_ServerID
			// 
			this->server_GetInfoButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_GetInfoButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetInfoButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetInfoButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(137, 116);
			this->server_GetInfoButtonComponent_InstructionLabel_ServerID->Name = L"server_GetInfoButtonComponent_InstructionLabel_ServerID";
			this->server_GetInfoButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_GetInfoButtonComponent_InstructionLabel_ServerID->TabIndex = 71;
			this->server_GetInfoButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_GetInfoButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_GetInfoButtonComponent_SendButton
			// 
			this->server_GetInfoButtonComponent_SendButton->Enabled = false;
			this->server_GetInfoButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetInfoButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetInfoButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_GetInfoButtonComponent_SendButton->Location = System::Drawing::Point(491, 177);
			this->server_GetInfoButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetInfoButtonComponent_SendButton->Name = L"server_GetInfoButtonComponent_SendButton";
			this->server_GetInfoButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_GetInfoButtonComponent_SendButton->TabIndex = 72;
			this->server_GetInfoButtonComponent_SendButton->Text = L"Send";
			this->server_GetInfoButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_GetInfoButtonComponent_SendButton->Visible = false;
			this->server_GetInfoButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_GetInfoButtonComponent_SendButton_Click);
			// 
			// server_IndependentComponentShowIDs
			// 
			this->server_IndependentComponentShowIDs->Enabled = false;
			this->server_IndependentComponentShowIDs->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_IndependentComponentShowIDs->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_IndependentComponentShowIDs->ForeColor = System::Drawing::Color::White;
			this->server_IndependentComponentShowIDs->Location = System::Drawing::Point(137, 177);
			this->server_IndependentComponentShowIDs->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_IndependentComponentShowIDs->Name = L"server_IndependentComponentShowIDs";
			this->server_IndependentComponentShowIDs->Size = System::Drawing::Size(111, 23);
			this->server_IndependentComponentShowIDs->TabIndex = 73;
			this->server_IndependentComponentShowIDs->Text = L"Show IDs";
			this->server_IndependentComponentShowIDs->UseVisualStyleBackColor = true;
			this->server_IndependentComponentShowIDs->Visible = false;
			this->server_IndependentComponentShowIDs->Click += gcnew System::EventHandler(this, &main_form::server_IndependentComponentShowIDs_Click);
			// 
			// server_DeleteByIDButtonComponent_InstructionLabel_ServerID
			// 
			this->server_DeleteByIDButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_DeleteByIDButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteByIDButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteByIDButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_DeleteByIDButtonComponent_InstructionLabel_ServerID->Name = L"server_DeleteByIDButtonComponent_InstructionLabel_ServerID";
			this->server_DeleteByIDButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_DeleteByIDButtonComponent_InstructionLabel_ServerID->TabIndex = 74;
			this->server_DeleteByIDButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_DeleteByIDButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_DeleteByIDButtonComponent_TextField_ServerID
			// 
			this->server_DeleteByIDButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_DeleteByIDButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_DeleteByIDButtonComponent_TextField_ServerID->Enabled = false;
			this->server_DeleteByIDButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteByIDButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteByIDButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_DeleteByIDButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteByIDButtonComponent_TextField_ServerID->Multiline = false;
			this->server_DeleteByIDButtonComponent_TextField_ServerID->Name = L"server_DeleteByIDButtonComponent_TextField_ServerID";
			this->server_DeleteByIDButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_DeleteByIDButtonComponent_TextField_ServerID->TabIndex = 75;
			this->server_DeleteByIDButtonComponent_TextField_ServerID->Text = L"";
			this->server_DeleteByIDButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_DeleteByIDButtonComponent_SendButton
			// 
			this->server_DeleteByIDButtonComponent_SendButton->Enabled = false;
			this->server_DeleteByIDButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_DeleteByIDButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteByIDButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_DeleteByIDButtonComponent_SendButton->Location = System::Drawing::Point(491, 177);
			this->server_DeleteByIDButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteByIDButtonComponent_SendButton->Name = L"server_DeleteByIDButtonComponent_SendButton";
			this->server_DeleteByIDButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_DeleteByIDButtonComponent_SendButton->TabIndex = 76;
			this->server_DeleteByIDButtonComponent_SendButton->Text = L"Send";
			this->server_DeleteByIDButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_DeleteByIDButtonComponent_SendButton->Visible = false;
			this->server_DeleteByIDButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_DeleteByIDButtonComponent_SendButton_Click);
			// 
			// server_GetExpireInfoButtonComponent_InstructionLabel_ServerID
			// 
			this->server_GetExpireInfoButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_GetExpireInfoButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetExpireInfoButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetExpireInfoButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(137, 116);
			this->server_GetExpireInfoButtonComponent_InstructionLabel_ServerID->Name = L"server_GetExpireInfoButtonComponent_InstructionLabel_ServerID";
			this->server_GetExpireInfoButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_GetExpireInfoButtonComponent_InstructionLabel_ServerID->TabIndex = 77;
			this->server_GetExpireInfoButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_GetExpireInfoButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_GetExpireInfoButtonComponent_TextField_ServerID
			// 
			this->server_GetExpireInfoButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_GetExpireInfoButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_GetExpireInfoButtonComponent_TextField_ServerID->Enabled = false;
			this->server_GetExpireInfoButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetExpireInfoButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetExpireInfoButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_GetExpireInfoButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetExpireInfoButtonComponent_TextField_ServerID->Multiline = false;
			this->server_GetExpireInfoButtonComponent_TextField_ServerID->Name = L"server_GetExpireInfoButtonComponent_TextField_ServerID";
			this->server_GetExpireInfoButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_GetExpireInfoButtonComponent_TextField_ServerID->TabIndex = 78;
			this->server_GetExpireInfoButtonComponent_TextField_ServerID->Text = L"";
			this->server_GetExpireInfoButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_GetExpireInfoButtonComponent_SendButton
			// 
			this->server_GetExpireInfoButtonComponent_SendButton->Enabled = false;
			this->server_GetExpireInfoButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetExpireInfoButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetExpireInfoButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_GetExpireInfoButtonComponent_SendButton->Location = System::Drawing::Point(495, 177);
			this->server_GetExpireInfoButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetExpireInfoButtonComponent_SendButton->Name = L"server_GetExpireInfoButtonComponent_SendButton";
			this->server_GetExpireInfoButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_GetExpireInfoButtonComponent_SendButton->TabIndex = 79;
			this->server_GetExpireInfoButtonComponent_SendButton->Text = L"Send";
			this->server_GetExpireInfoButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_GetExpireInfoButtonComponent_SendButton->Visible = false;
			this->server_GetExpireInfoButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_GetExpireInfoButtonComponent_SendButton_Click);
			// 
			// server_GetMediaInfoButtonComponent_InstructionLabel_ServerID
			// 
			this->server_GetMediaInfoButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_GetMediaInfoButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetMediaInfoButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetMediaInfoButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(137, 116);
			this->server_GetMediaInfoButtonComponent_InstructionLabel_ServerID->Name = L"server_GetMediaInfoButtonComponent_InstructionLabel_ServerID";
			this->server_GetMediaInfoButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_GetMediaInfoButtonComponent_InstructionLabel_ServerID->TabIndex = 80;
			this->server_GetMediaInfoButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_GetMediaInfoButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_GetMediaInfoButtonComponent_TextField_ServerID
			// 
			this->server_GetMediaInfoButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_GetMediaInfoButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_GetMediaInfoButtonComponent_TextField_ServerID->Enabled = false;
			this->server_GetMediaInfoButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetMediaInfoButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetMediaInfoButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_GetMediaInfoButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetMediaInfoButtonComponent_TextField_ServerID->Multiline = false;
			this->server_GetMediaInfoButtonComponent_TextField_ServerID->Name = L"server_GetMediaInfoButtonComponent_TextField_ServerID";
			this->server_GetMediaInfoButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_GetMediaInfoButtonComponent_TextField_ServerID->TabIndex = 81;
			this->server_GetMediaInfoButtonComponent_TextField_ServerID->Text = L"";
			this->server_GetMediaInfoButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_GetMediaInfoButtonComponent_SendButton
			// 
			this->server_GetMediaInfoButtonComponent_SendButton->Enabled = false;
			this->server_GetMediaInfoButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetMediaInfoButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetMediaInfoButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_GetMediaInfoButtonComponent_SendButton->Location = System::Drawing::Point(491, 176);
			this->server_GetMediaInfoButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetMediaInfoButtonComponent_SendButton->Name = L"server_GetMediaInfoButtonComponent_SendButton";
			this->server_GetMediaInfoButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_GetMediaInfoButtonComponent_SendButton->TabIndex = 82;
			this->server_GetMediaInfoButtonComponent_SendButton->Text = L"Send";
			this->server_GetMediaInfoButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_GetMediaInfoButtonComponent_SendButton->Visible = false;
			this->server_GetMediaInfoButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_GetMediaInfoButtonComponent_SendButton_Click);
			// 
			// server_PowerOnServerButtonComponent_InstructionLabel_ServerID
			// 
			this->server_PowerOnServerButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_PowerOnServerButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_PowerOnServerButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_PowerOnServerButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_PowerOnServerButtonComponent_InstructionLabel_ServerID->Name = L"server_PowerOnServerButtonComponent_InstructionLabel_ServerID";
			this->server_PowerOnServerButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_PowerOnServerButtonComponent_InstructionLabel_ServerID->TabIndex = 83;
			this->server_PowerOnServerButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_PowerOnServerButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_PowerOnServerButtonComponent_TextField_ServerID
			// 
			this->server_PowerOnServerButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_PowerOnServerButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_PowerOnServerButtonComponent_TextField_ServerID->Enabled = false;
			this->server_PowerOnServerButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_PowerOnServerButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_PowerOnServerButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_PowerOnServerButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_PowerOnServerButtonComponent_TextField_ServerID->Multiline = false;
			this->server_PowerOnServerButtonComponent_TextField_ServerID->Name = L"server_PowerOnServerButtonComponent_TextField_ServerID";
			this->server_PowerOnServerButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_PowerOnServerButtonComponent_TextField_ServerID->TabIndex = 84;
			this->server_PowerOnServerButtonComponent_TextField_ServerID->Text = L"";
			this->server_PowerOnServerButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_PowerOnServerButtonComponent_SendButton
			// 
			this->server_PowerOnServerButtonComponent_SendButton->Enabled = false;
			this->server_PowerOnServerButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_PowerOnServerButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_PowerOnServerButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_PowerOnServerButtonComponent_SendButton->Location = System::Drawing::Point(491, 177);
			this->server_PowerOnServerButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_PowerOnServerButtonComponent_SendButton->Name = L"server_PowerOnServerButtonComponent_SendButton";
			this->server_PowerOnServerButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_PowerOnServerButtonComponent_SendButton->TabIndex = 85;
			this->server_PowerOnServerButtonComponent_SendButton->Text = L"Send";
			this->server_PowerOnServerButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_PowerOnServerButtonComponent_SendButton->Visible = false;
			this->server_PowerOnServerButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_PowerOnServerButtonComponent_SendButton_Click);
			// 
			// server_RestartServerButtonComponent_Instructionlabel_ServerID
			// 
			this->server_RestartServerButtonComponent_Instructionlabel_ServerID->Enabled = false;
			this->server_RestartServerButtonComponent_Instructionlabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_RestartServerButtonComponent_Instructionlabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_RestartServerButtonComponent_Instructionlabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_RestartServerButtonComponent_Instructionlabel_ServerID->Name = L"server_RestartServerButtonComponent_Instructionlabel_ServerID";
			this->server_RestartServerButtonComponent_Instructionlabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_RestartServerButtonComponent_Instructionlabel_ServerID->TabIndex = 86;
			this->server_RestartServerButtonComponent_Instructionlabel_ServerID->Text = L"Server ID:";
			this->server_RestartServerButtonComponent_Instructionlabel_ServerID->Visible = false;
			// 
			// server_RestartServerButtonComponent_TextField_ServerID
			// 
			this->server_RestartServerButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_RestartServerButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_RestartServerButtonComponent_TextField_ServerID->Enabled = false;
			this->server_RestartServerButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_RestartServerButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_RestartServerButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_RestartServerButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_RestartServerButtonComponent_TextField_ServerID->Multiline = false;
			this->server_RestartServerButtonComponent_TextField_ServerID->Name = L"server_RestartServerButtonComponent_TextField_ServerID";
			this->server_RestartServerButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_RestartServerButtonComponent_TextField_ServerID->TabIndex = 87;
			this->server_RestartServerButtonComponent_TextField_ServerID->Text = L"";
			this->server_RestartServerButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_RestartServerButtonComponent_SendButton
			// 
			this->server_RestartServerButtonComponent_SendButton->Enabled = false;
			this->server_RestartServerButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_RestartServerButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_RestartServerButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_RestartServerButtonComponent_SendButton->Location = System::Drawing::Point(491, 177);
			this->server_RestartServerButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_RestartServerButtonComponent_SendButton->Name = L"server_RestartServerButtonComponent_SendButton";
			this->server_RestartServerButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_RestartServerButtonComponent_SendButton->TabIndex = 88;
			this->server_RestartServerButtonComponent_SendButton->Text = L"Send";
			this->server_RestartServerButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_RestartServerButtonComponent_SendButton->Visible = false;
			this->server_RestartServerButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_RestartServerButtonComponent_SendButton_Click);
			// 
			// server_ShutdownServerButtonComponent_InstructionLabel_ServerID
			// 
			this->server_ShutdownServerButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_ShutdownServerButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ShutdownServerButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_ShutdownServerButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_ShutdownServerButtonComponent_InstructionLabel_ServerID->Name = L"server_ShutdownServerButtonComponent_InstructionLabel_ServerID";
			this->server_ShutdownServerButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_ShutdownServerButtonComponent_InstructionLabel_ServerID->TabIndex = 89;
			this->server_ShutdownServerButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_ShutdownServerButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_ShutdownServerButtonComponent_TextField_ServerID
			// 
			this->server_ShutdownServerButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_ShutdownServerButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_ShutdownServerButtonComponent_TextField_ServerID->Enabled = false;
			this->server_ShutdownServerButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ShutdownServerButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_ShutdownServerButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_ShutdownServerButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ShutdownServerButtonComponent_TextField_ServerID->Multiline = false;
			this->server_ShutdownServerButtonComponent_TextField_ServerID->Name = L"server_ShutdownServerButtonComponent_TextField_ServerID";
			this->server_ShutdownServerButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_ShutdownServerButtonComponent_TextField_ServerID->TabIndex = 90;
			this->server_ShutdownServerButtonComponent_TextField_ServerID->Text = L"";
			this->server_ShutdownServerButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_ShutdownServerButtonComponent_SendButton
			// 
			this->server_ShutdownServerButtonComponent_SendButton->Enabled = false;
			this->server_ShutdownServerButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_ShutdownServerButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ShutdownServerButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_ShutdownServerButtonComponent_SendButton->Location = System::Drawing::Point(491, 176);
			this->server_ShutdownServerButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ShutdownServerButtonComponent_SendButton->Name = L"server_ShutdownServerButtonComponent_SendButton";
			this->server_ShutdownServerButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_ShutdownServerButtonComponent_SendButton->TabIndex = 91;
			this->server_ShutdownServerButtonComponent_SendButton->Text = L"Send";
			this->server_ShutdownServerButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_ShutdownServerButtonComponent_SendButton->Visible = false;
			this->server_ShutdownServerButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_ShutdownServerButtonComponent_SendButton_Click);
			// 
			// server_ForceStopServerButtonComponent_InstructionLabel_ServerID
			// 
			this->server_ForceStopServerButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_ForceStopServerButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ForceStopServerButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_ForceStopServerButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_ForceStopServerButtonComponent_InstructionLabel_ServerID->Name = L"server_ForceStopServerButtonComponent_InstructionLabel_ServerID";
			this->server_ForceStopServerButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_ForceStopServerButtonComponent_InstructionLabel_ServerID->TabIndex = 92;
			this->server_ForceStopServerButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_ForceStopServerButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_ForceStopServerButtonComponent_TextField_ServerID
			// 
			this->server_ForceStopServerButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_ForceStopServerButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_ForceStopServerButtonComponent_TextField_ServerID->Enabled = false;
			this->server_ForceStopServerButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ForceStopServerButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_ForceStopServerButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_ForceStopServerButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ForceStopServerButtonComponent_TextField_ServerID->Multiline = false;
			this->server_ForceStopServerButtonComponent_TextField_ServerID->Name = L"server_ForceStopServerButtonComponent_TextField_ServerID";
			this->server_ForceStopServerButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_ForceStopServerButtonComponent_TextField_ServerID->TabIndex = 93;
			this->server_ForceStopServerButtonComponent_TextField_ServerID->Text = L"";
			this->server_ForceStopServerButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_ForceStopServerButtonComponent_SendButton
			// 
			this->server_ForceStopServerButtonComponent_SendButton->Enabled = false;
			this->server_ForceStopServerButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_ForceStopServerButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ForceStopServerButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_ForceStopServerButtonComponent_SendButton->Location = System::Drawing::Point(491, 177);
			this->server_ForceStopServerButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ForceStopServerButtonComponent_SendButton->Name = L"server_ForceStopServerButtonComponent_SendButton";
			this->server_ForceStopServerButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_ForceStopServerButtonComponent_SendButton->TabIndex = 94;
			this->server_ForceStopServerButtonComponent_SendButton->Text = L"Send";
			this->server_ForceStopServerButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_ForceStopServerButtonComponent_SendButton->Visible = false;
			this->server_ForceStopServerButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_ForceStopServerButtonComponent_SendButton_Click);
			// 
			// server_RenewServerButtonComponent_InstructionLabel_ServerID
			// 
			this->server_RenewServerButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_RenewServerButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_RenewServerButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_RenewServerButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_RenewServerButtonComponent_InstructionLabel_ServerID->Name = L"server_RenewServerButtonComponent_InstructionLabel_ServerID";
			this->server_RenewServerButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_RenewServerButtonComponent_InstructionLabel_ServerID->TabIndex = 95;
			this->server_RenewServerButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_RenewServerButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_RenewServerButtonComponent_TextField_ServerID
			// 
			this->server_RenewServerButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_RenewServerButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_RenewServerButtonComponent_TextField_ServerID->Enabled = false;
			this->server_RenewServerButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_RenewServerButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_RenewServerButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_RenewServerButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_RenewServerButtonComponent_TextField_ServerID->Multiline = false;
			this->server_RenewServerButtonComponent_TextField_ServerID->Name = L"server_RenewServerButtonComponent_TextField_ServerID";
			this->server_RenewServerButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_RenewServerButtonComponent_TextField_ServerID->TabIndex = 96;
			this->server_RenewServerButtonComponent_TextField_ServerID->Text = L"";
			this->server_RenewServerButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_RenewServerButtonComponent_SendButton
			// 
			this->server_RenewServerButtonComponent_SendButton->Enabled = false;
			this->server_RenewServerButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_RenewServerButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_RenewServerButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_RenewServerButtonComponent_SendButton->Location = System::Drawing::Point(491, 177);
			this->server_RenewServerButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_RenewServerButtonComponent_SendButton->Name = L"server_RenewServerButtonComponent_SendButton";
			this->server_RenewServerButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_RenewServerButtonComponent_SendButton->TabIndex = 97;
			this->server_RenewServerButtonComponent_SendButton->Text = L"Send";
			this->server_RenewServerButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_RenewServerButtonComponent_SendButton->Visible = false;
			this->server_RenewServerButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_RenewServerButtonComponent_SendButton_Click);
			// 
			// server_GetVNCInfoButtonComponent_InstructionLabel_ServerID
			// 
			this->server_GetVNCInfoButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_GetVNCInfoButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetVNCInfoButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetVNCInfoButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_GetVNCInfoButtonComponent_InstructionLabel_ServerID->Name = L"server_GetVNCInfoButtonComponent_InstructionLabel_ServerID";
			this->server_GetVNCInfoButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_GetVNCInfoButtonComponent_InstructionLabel_ServerID->TabIndex = 98;
			this->server_GetVNCInfoButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_GetVNCInfoButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_GetVNCInfoButtonComponent_TextField_ServerID
			// 
			this->server_GetVNCInfoButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_GetVNCInfoButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_GetVNCInfoButtonComponent_TextField_ServerID->Enabled = false;
			this->server_GetVNCInfoButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetVNCInfoButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetVNCInfoButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_GetVNCInfoButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetVNCInfoButtonComponent_TextField_ServerID->Multiline = false;
			this->server_GetVNCInfoButtonComponent_TextField_ServerID->Name = L"server_GetVNCInfoButtonComponent_TextField_ServerID";
			this->server_GetVNCInfoButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_GetVNCInfoButtonComponent_TextField_ServerID->TabIndex = 99;
			this->server_GetVNCInfoButtonComponent_TextField_ServerID->Text = L"";
			this->server_GetVNCInfoButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_GetVNCinfoButtonComponent_SendButton
			// 
			this->server_GetVNCinfoButtonComponent_SendButton->Enabled = false;
			this->server_GetVNCinfoButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetVNCinfoButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetVNCinfoButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_GetVNCinfoButtonComponent_SendButton->Location = System::Drawing::Point(491, 177);
			this->server_GetVNCinfoButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetVNCinfoButtonComponent_SendButton->Name = L"server_GetVNCinfoButtonComponent_SendButton";
			this->server_GetVNCinfoButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_GetVNCinfoButtonComponent_SendButton->TabIndex = 100;
			this->server_GetVNCinfoButtonComponent_SendButton->Text = L"Send";
			this->server_GetVNCinfoButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_GetVNCinfoButtonComponent_SendButton->Visible = false;
			this->server_GetVNCinfoButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_GetVNCinfoButtonComponent_SendButton_Click);
			// 
			// server_GetBackupInfoButtonComponent_InstructionLabel_ServerID
			// 
			this->server_GetBackupInfoButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_GetBackupInfoButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetBackupInfoButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetBackupInfoButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(137, 116);
			this->server_GetBackupInfoButtonComponent_InstructionLabel_ServerID->Name = L"server_GetBackupInfoButtonComponent_InstructionLabel_ServerID";
			this->server_GetBackupInfoButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_GetBackupInfoButtonComponent_InstructionLabel_ServerID->TabIndex = 101;
			this->server_GetBackupInfoButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_GetBackupInfoButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_GetBackupInfoButtonComponent_TextField_ServerID
			// 
			this->server_GetBackupInfoButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_GetBackupInfoButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_GetBackupInfoButtonComponent_TextField_ServerID->Enabled = false;
			this->server_GetBackupInfoButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetBackupInfoButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetBackupInfoButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_GetBackupInfoButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetBackupInfoButtonComponent_TextField_ServerID->Multiline = false;
			this->server_GetBackupInfoButtonComponent_TextField_ServerID->Name = L"server_GetBackupInfoButtonComponent_TextField_ServerID";
			this->server_GetBackupInfoButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_GetBackupInfoButtonComponent_TextField_ServerID->TabIndex = 102;
			this->server_GetBackupInfoButtonComponent_TextField_ServerID->Text = L"";
			this->server_GetBackupInfoButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_GetBackupInfoButtonComponent_SendButton
			// 
			this->server_GetBackupInfoButtonComponent_SendButton->Enabled = false;
			this->server_GetBackupInfoButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetBackupInfoButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetBackupInfoButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_GetBackupInfoButtonComponent_SendButton->Location = System::Drawing::Point(491, 176);
			this->server_GetBackupInfoButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetBackupInfoButtonComponent_SendButton->Name = L"server_GetBackupInfoButtonComponent_SendButton";
			this->server_GetBackupInfoButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_GetBackupInfoButtonComponent_SendButton->TabIndex = 103;
			this->server_GetBackupInfoButtonComponent_SendButton->Text = L"Send";
			this->server_GetBackupInfoButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_GetBackupInfoButtonComponent_SendButton->Visible = false;
			this->server_GetBackupInfoButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_GetBackupInfoButtonComponent_SendButton_Click);
			// 
			// server_MakeBackupButtonComponent_InstructionLabel_ServerID
			// 
			this->server_MakeBackupButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_MakeBackupButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_MakeBackupButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_MakeBackupButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(137, 116);
			this->server_MakeBackupButtonComponent_InstructionLabel_ServerID->Name = L"server_MakeBackupButtonComponent_InstructionLabel_ServerID";
			this->server_MakeBackupButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_MakeBackupButtonComponent_InstructionLabel_ServerID->TabIndex = 104;
			this->server_MakeBackupButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_MakeBackupButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_MakeBackupButtonComponent_TextField_ServerID
			// 
			this->server_MakeBackupButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_MakeBackupButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_MakeBackupButtonComponent_TextField_ServerID->Enabled = false;
			this->server_MakeBackupButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_MakeBackupButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_MakeBackupButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_MakeBackupButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_MakeBackupButtonComponent_TextField_ServerID->Multiline = false;
			this->server_MakeBackupButtonComponent_TextField_ServerID->Name = L"server_MakeBackupButtonComponent_TextField_ServerID";
			this->server_MakeBackupButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_MakeBackupButtonComponent_TextField_ServerID->TabIndex = 105;
			this->server_MakeBackupButtonComponent_TextField_ServerID->Text = L"";
			this->server_MakeBackupButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_MakeBackupButtonComponent_InstructionLabel_Hostname
			// 
			this->server_MakeBackupButtonComponent_InstructionLabel_Hostname->Enabled = false;
			this->server_MakeBackupButtonComponent_InstructionLabel_Hostname->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_MakeBackupButtonComponent_InstructionLabel_Hostname->ForeColor = System::Drawing::Color::White;
			this->server_MakeBackupButtonComponent_InstructionLabel_Hostname->Location = System::Drawing::Point(139, 178);
			this->server_MakeBackupButtonComponent_InstructionLabel_Hostname->Name = L"server_MakeBackupButtonComponent_InstructionLabel_Hostname";
			this->server_MakeBackupButtonComponent_InstructionLabel_Hostname->Size = System::Drawing::Size(167, 23);
			this->server_MakeBackupButtonComponent_InstructionLabel_Hostname->TabIndex = 106;
			this->server_MakeBackupButtonComponent_InstructionLabel_Hostname->Text = L"FTP Hostname/IP:";
			this->server_MakeBackupButtonComponent_InstructionLabel_Hostname->Visible = false;
			// 
			// server_MakeBackupButtonComponent_TextField_Hostname
			// 
			this->server_MakeBackupButtonComponent_TextField_Hostname->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_MakeBackupButtonComponent_TextField_Hostname->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_MakeBackupButtonComponent_TextField_Hostname->Enabled = false;
			this->server_MakeBackupButtonComponent_TextField_Hostname->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_MakeBackupButtonComponent_TextField_Hostname->ForeColor = System::Drawing::Color::White;
			this->server_MakeBackupButtonComponent_TextField_Hostname->Location = System::Drawing::Point(137, 203);
			this->server_MakeBackupButtonComponent_TextField_Hostname->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_MakeBackupButtonComponent_TextField_Hostname->Multiline = false;
			this->server_MakeBackupButtonComponent_TextField_Hostname->Name = L"server_MakeBackupButtonComponent_TextField_Hostname";
			this->server_MakeBackupButtonComponent_TextField_Hostname->Size = System::Drawing::Size(429, 29);
			this->server_MakeBackupButtonComponent_TextField_Hostname->TabIndex = 107;
			this->server_MakeBackupButtonComponent_TextField_Hostname->Text = L"";
			this->server_MakeBackupButtonComponent_TextField_Hostname->Visible = false;
			// 
			// server_MakeBackupButtonComponent_InstructionLabel_Port
			// 
			this->server_MakeBackupButtonComponent_InstructionLabel_Port->Enabled = false;
			this->server_MakeBackupButtonComponent_InstructionLabel_Port->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_MakeBackupButtonComponent_InstructionLabel_Port->ForeColor = System::Drawing::Color::White;
			this->server_MakeBackupButtonComponent_InstructionLabel_Port->Location = System::Drawing::Point(139, 246);
			this->server_MakeBackupButtonComponent_InstructionLabel_Port->Name = L"server_MakeBackupButtonComponent_InstructionLabel_Port";
			this->server_MakeBackupButtonComponent_InstructionLabel_Port->Size = System::Drawing::Size(167, 23);
			this->server_MakeBackupButtonComponent_InstructionLabel_Port->TabIndex = 108;
			this->server_MakeBackupButtonComponent_InstructionLabel_Port->Text = L"FTP Port:";
			this->server_MakeBackupButtonComponent_InstructionLabel_Port->Visible = false;
			// 
			// server_MakeBackupButtonComponent_TextField_Port
			// 
			this->server_MakeBackupButtonComponent_TextField_Port->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_MakeBackupButtonComponent_TextField_Port->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_MakeBackupButtonComponent_TextField_Port->Enabled = false;
			this->server_MakeBackupButtonComponent_TextField_Port->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_MakeBackupButtonComponent_TextField_Port->ForeColor = System::Drawing::Color::White;
			this->server_MakeBackupButtonComponent_TextField_Port->Location = System::Drawing::Point(137, 272);
			this->server_MakeBackupButtonComponent_TextField_Port->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_MakeBackupButtonComponent_TextField_Port->Multiline = false;
			this->server_MakeBackupButtonComponent_TextField_Port->Name = L"server_MakeBackupButtonComponent_TextField_Port";
			this->server_MakeBackupButtonComponent_TextField_Port->Size = System::Drawing::Size(429, 29);
			this->server_MakeBackupButtonComponent_TextField_Port->TabIndex = 109;
			this->server_MakeBackupButtonComponent_TextField_Port->Text = L"";
			this->server_MakeBackupButtonComponent_TextField_Port->Visible = false;
			// 
			// server_MakeBackupButtonComponent_InstructionLabel_Password
			// 
			this->server_MakeBackupButtonComponent_InstructionLabel_Password->Enabled = false;
			this->server_MakeBackupButtonComponent_InstructionLabel_Password->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_MakeBackupButtonComponent_InstructionLabel_Password->ForeColor = System::Drawing::Color::White;
			this->server_MakeBackupButtonComponent_InstructionLabel_Password->Location = System::Drawing::Point(139, 321);
			this->server_MakeBackupButtonComponent_InstructionLabel_Password->Name = L"server_MakeBackupButtonComponent_InstructionLabel_Password";
			this->server_MakeBackupButtonComponent_InstructionLabel_Password->Size = System::Drawing::Size(167, 23);
			this->server_MakeBackupButtonComponent_InstructionLabel_Password->TabIndex = 110;
			this->server_MakeBackupButtonComponent_InstructionLabel_Password->Text = L"FTP Password:";
			this->server_MakeBackupButtonComponent_InstructionLabel_Password->Visible = false;
			// 
			// server_MakeBackupButtonComponent_TextField_Password
			// 
			this->server_MakeBackupButtonComponent_TextField_Password->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_MakeBackupButtonComponent_TextField_Password->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_MakeBackupButtonComponent_TextField_Password->Enabled = false;
			this->server_MakeBackupButtonComponent_TextField_Password->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_MakeBackupButtonComponent_TextField_Password->ForeColor = System::Drawing::Color::White;
			this->server_MakeBackupButtonComponent_TextField_Password->Location = System::Drawing::Point(137, 347);
			this->server_MakeBackupButtonComponent_TextField_Password->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_MakeBackupButtonComponent_TextField_Password->Multiline = false;
			this->server_MakeBackupButtonComponent_TextField_Password->Name = L"server_MakeBackupButtonComponent_TextField_Password";
			this->server_MakeBackupButtonComponent_TextField_Password->Size = System::Drawing::Size(429, 29);
			this->server_MakeBackupButtonComponent_TextField_Password->TabIndex = 111;
			this->server_MakeBackupButtonComponent_TextField_Password->Text = L"";
			this->server_MakeBackupButtonComponent_TextField_Password->Visible = false;
			// 
			// server_MakeBackupButtonComponent_InstructionLabel_Rotation
			// 
			this->server_MakeBackupButtonComponent_InstructionLabel_Rotation->Enabled = false;
			this->server_MakeBackupButtonComponent_InstructionLabel_Rotation->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_MakeBackupButtonComponent_InstructionLabel_Rotation->ForeColor = System::Drawing::Color::White;
			this->server_MakeBackupButtonComponent_InstructionLabel_Rotation->Location = System::Drawing::Point(139, 394);
			this->server_MakeBackupButtonComponent_InstructionLabel_Rotation->Name = L"server_MakeBackupButtonComponent_InstructionLabel_Rotation";
			this->server_MakeBackupButtonComponent_InstructionLabel_Rotation->Size = System::Drawing::Size(167, 23);
			this->server_MakeBackupButtonComponent_InstructionLabel_Rotation->TabIndex = 112;
			this->server_MakeBackupButtonComponent_InstructionLabel_Rotation->Text = L"Rotation:";
			this->server_MakeBackupButtonComponent_InstructionLabel_Rotation->Visible = false;
			// 
			// server_MakeBackupButtonComponent_TextField_Rotation
			// 
			this->server_MakeBackupButtonComponent_TextField_Rotation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_MakeBackupButtonComponent_TextField_Rotation->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_MakeBackupButtonComponent_TextField_Rotation->Enabled = false;
			this->server_MakeBackupButtonComponent_TextField_Rotation->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_MakeBackupButtonComponent_TextField_Rotation->ForeColor = System::Drawing::Color::White;
			this->server_MakeBackupButtonComponent_TextField_Rotation->Location = System::Drawing::Point(137, 420);
			this->server_MakeBackupButtonComponent_TextField_Rotation->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_MakeBackupButtonComponent_TextField_Rotation->Multiline = false;
			this->server_MakeBackupButtonComponent_TextField_Rotation->Name = L"server_MakeBackupButtonComponent_TextField_Rotation";
			this->server_MakeBackupButtonComponent_TextField_Rotation->Size = System::Drawing::Size(429, 29);
			this->server_MakeBackupButtonComponent_TextField_Rotation->TabIndex = 113;
			this->server_MakeBackupButtonComponent_TextField_Rotation->Text = L"";
			this->server_MakeBackupButtonComponent_TextField_Rotation->Visible = false;
			// 
			// server_MakeBackupButtonComponent_InstructionLabel_UseSSL
			// 
			this->server_MakeBackupButtonComponent_InstructionLabel_UseSSL->Enabled = false;
			this->server_MakeBackupButtonComponent_InstructionLabel_UseSSL->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_MakeBackupButtonComponent_InstructionLabel_UseSSL->ForeColor = System::Drawing::Color::White;
			this->server_MakeBackupButtonComponent_InstructionLabel_UseSSL->Location = System::Drawing::Point(139, 462);
			this->server_MakeBackupButtonComponent_InstructionLabel_UseSSL->Name = L"server_MakeBackupButtonComponent_InstructionLabel_UseSSL";
			this->server_MakeBackupButtonComponent_InstructionLabel_UseSSL->Size = System::Drawing::Size(167, 23);
			this->server_MakeBackupButtonComponent_InstructionLabel_UseSSL->TabIndex = 114;
			this->server_MakeBackupButtonComponent_InstructionLabel_UseSSL->Text = L"Use SSL:";
			this->server_MakeBackupButtonComponent_InstructionLabel_UseSSL->Visible = false;
			// 
			// server_MakeBackupButtonComponent_TextField_UseSSL
			// 
			this->server_MakeBackupButtonComponent_TextField_UseSSL->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_MakeBackupButtonComponent_TextField_UseSSL->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_MakeBackupButtonComponent_TextField_UseSSL->Enabled = false;
			this->server_MakeBackupButtonComponent_TextField_UseSSL->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_MakeBackupButtonComponent_TextField_UseSSL->ForeColor = System::Drawing::Color::White;
			this->server_MakeBackupButtonComponent_TextField_UseSSL->Location = System::Drawing::Point(137, 487);
			this->server_MakeBackupButtonComponent_TextField_UseSSL->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_MakeBackupButtonComponent_TextField_UseSSL->Multiline = false;
			this->server_MakeBackupButtonComponent_TextField_UseSSL->Name = L"server_MakeBackupButtonComponent_TextField_UseSSL";
			this->server_MakeBackupButtonComponent_TextField_UseSSL->Size = System::Drawing::Size(429, 29);
			this->server_MakeBackupButtonComponent_TextField_UseSSL->TabIndex = 115;
			this->server_MakeBackupButtonComponent_TextField_UseSSL->Text = L"true";
			this->server_MakeBackupButtonComponent_TextField_UseSSL->Visible = false;
			// 
			// server_MakeBackupButtonComponent_SendButton
			// 
			this->server_MakeBackupButtonComponent_SendButton->Enabled = false;
			this->server_MakeBackupButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_MakeBackupButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_MakeBackupButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_MakeBackupButtonComponent_SendButton->Location = System::Drawing::Point(491, 522);
			this->server_MakeBackupButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_MakeBackupButtonComponent_SendButton->Name = L"server_MakeBackupButtonComponent_SendButton";
			this->server_MakeBackupButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_MakeBackupButtonComponent_SendButton->TabIndex = 116;
			this->server_MakeBackupButtonComponent_SendButton->Text = L"Send";
			this->server_MakeBackupButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_MakeBackupButtonComponent_SendButton->Visible = false;
			this->server_MakeBackupButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_MakeBackupButtonComponent_SendButton_Click);
			// 
			// server_IndependentComponentShowIDs_RightPos
			// 
			this->server_IndependentComponentShowIDs_RightPos->Enabled = false;
			this->server_IndependentComponentShowIDs_RightPos->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_IndependentComponentShowIDs_RightPos->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_IndependentComponentShowIDs_RightPos->ForeColor = System::Drawing::Color::White;
			this->server_IndependentComponentShowIDs_RightPos->Location = System::Drawing::Point(455, 174);
			this->server_IndependentComponentShowIDs_RightPos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_IndependentComponentShowIDs_RightPos->Name = L"server_IndependentComponentShowIDs_RightPos";
			this->server_IndependentComponentShowIDs_RightPos->Size = System::Drawing::Size(111, 23);
			this->server_IndependentComponentShowIDs_RightPos->TabIndex = 117;
			this->server_IndependentComponentShowIDs_RightPos->Text = L"Show IDs";
			this->server_IndependentComponentShowIDs_RightPos->UseVisualStyleBackColor = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = false;
			this->server_IndependentComponentShowIDs_RightPos->Click += gcnew System::EventHandler(this, &main_form::server_IndependentComponentShowIDs_RightPos_Click);
			// 
			// server_DeleteBackupButtonComponent_InstructionLabel_ServerID
			// 
			this->server_DeleteBackupButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_DeleteBackupButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteBackupButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteBackupButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_DeleteBackupButtonComponent_InstructionLabel_ServerID->Name = L"server_DeleteBackupButtonComponent_InstructionLabel_ServerID";
			this->server_DeleteBackupButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_DeleteBackupButtonComponent_InstructionLabel_ServerID->TabIndex = 118;
			this->server_DeleteBackupButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_DeleteBackupButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_DeleteBackupButtonComponent_TextField_ServerID
			// 
			this->server_DeleteBackupButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_DeleteBackupButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_DeleteBackupButtonComponent_TextField_ServerID->Enabled = false;
			this->server_DeleteBackupButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteBackupButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteBackupButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_DeleteBackupButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteBackupButtonComponent_TextField_ServerID->Multiline = false;
			this->server_DeleteBackupButtonComponent_TextField_ServerID->Name = L"server_DeleteBackupButtonComponent_TextField_ServerID";
			this->server_DeleteBackupButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_DeleteBackupButtonComponent_TextField_ServerID->TabIndex = 119;
			this->server_DeleteBackupButtonComponent_TextField_ServerID->Text = L"";
			this->server_DeleteBackupButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_DeleteBackupButtonComponent_SendButton
			// 
			this->server_DeleteBackupButtonComponent_SendButton->Enabled = false;
			this->server_DeleteBackupButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_DeleteBackupButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteBackupButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_DeleteBackupButtonComponent_SendButton->Location = System::Drawing::Point(491, 177);
			this->server_DeleteBackupButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteBackupButtonComponent_SendButton->Name = L"server_DeleteBackupButtonComponent_SendButton";
			this->server_DeleteBackupButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_DeleteBackupButtonComponent_SendButton->TabIndex = 120;
			this->server_DeleteBackupButtonComponent_SendButton->Text = L"Send";
			this->server_DeleteBackupButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_DeleteBackupButtonComponent_SendButton->Visible = false;
			this->server_DeleteBackupButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_DeleteBackupButtonComponent_SendButton_Click);
			// 
			// server_GetBandwidthButtonComponent_InstructionLabel_ServerID
			// 
			this->server_GetBandwidthButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_GetBandwidthButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetBandwidthButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetBandwidthButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_GetBandwidthButtonComponent_InstructionLabel_ServerID->Name = L"server_GetBandwidthButtonComponent_InstructionLabel_ServerID";
			this->server_GetBandwidthButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_GetBandwidthButtonComponent_InstructionLabel_ServerID->TabIndex = 121;
			this->server_GetBandwidthButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_GetBandwidthButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_GetBandwidthButtonComponent_TextField_ServerID
			// 
			this->server_GetBandwidthButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_GetBandwidthButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_GetBandwidthButtonComponent_TextField_ServerID->Enabled = false;
			this->server_GetBandwidthButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetBandwidthButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetBandwidthButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_GetBandwidthButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetBandwidthButtonComponent_TextField_ServerID->Multiline = false;
			this->server_GetBandwidthButtonComponent_TextField_ServerID->Name = L"server_GetBandwidthButtonComponent_TextField_ServerID";
			this->server_GetBandwidthButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_GetBandwidthButtonComponent_TextField_ServerID->TabIndex = 122;
			this->server_GetBandwidthButtonComponent_TextField_ServerID->Text = L"";
			this->server_GetBandwidthButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_GetBandwidthButtonComponent_SendButton
			// 
			this->server_GetBandwidthButtonComponent_SendButton->Enabled = false;
			this->server_GetBandwidthButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetBandwidthButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetBandwidthButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_GetBandwidthButtonComponent_SendButton->Location = System::Drawing::Point(491, 174);
			this->server_GetBandwidthButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetBandwidthButtonComponent_SendButton->Name = L"server_GetBandwidthButtonComponent_SendButton";
			this->server_GetBandwidthButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_GetBandwidthButtonComponent_SendButton->TabIndex = 123;
			this->server_GetBandwidthButtonComponent_SendButton->Text = L"Send";
			this->server_GetBandwidthButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_GetBandwidthButtonComponent_SendButton->Visible = false;
			this->server_GetBandwidthButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_GetBandwidthButtonComponent_SendButton_Click);
			// 
			// server_SelectISOButtonComponent_InstructionLabel_ServerID
			// 
			this->server_SelectISOButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_SelectISOButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SelectISOButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_SelectISOButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_SelectISOButtonComponent_InstructionLabel_ServerID->Name = L"server_SelectISOButtonComponent_InstructionLabel_ServerID";
			this->server_SelectISOButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_SelectISOButtonComponent_InstructionLabel_ServerID->TabIndex = 124;
			this->server_SelectISOButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_SelectISOButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_SelectISOButtonComponent_InstructionLabel_FirstFile
			// 
			this->server_SelectISOButtonComponent_InstructionLabel_FirstFile->Enabled = false;
			this->server_SelectISOButtonComponent_InstructionLabel_FirstFile->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SelectISOButtonComponent_InstructionLabel_FirstFile->ForeColor = System::Drawing::Color::White;
			this->server_SelectISOButtonComponent_InstructionLabel_FirstFile->Location = System::Drawing::Point(139, 178);
			this->server_SelectISOButtonComponent_InstructionLabel_FirstFile->Name = L"server_SelectISOButtonComponent_InstructionLabel_FirstFile";
			this->server_SelectISOButtonComponent_InstructionLabel_FirstFile->Size = System::Drawing::Size(167, 23);
			this->server_SelectISOButtonComponent_InstructionLabel_FirstFile->TabIndex = 125;
			this->server_SelectISOButtonComponent_InstructionLabel_FirstFile->Text = L"First ISO File:";
			this->server_SelectISOButtonComponent_InstructionLabel_FirstFile->Visible = false;
			// 
			// server_SelectISOButtonComponent_TextField_ServerID
			// 
			this->server_SelectISOButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SelectISOButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SelectISOButtonComponent_TextField_ServerID->Enabled = false;
			this->server_SelectISOButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SelectISOButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_SelectISOButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_SelectISOButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SelectISOButtonComponent_TextField_ServerID->Multiline = false;
			this->server_SelectISOButtonComponent_TextField_ServerID->Name = L"server_SelectISOButtonComponent_TextField_ServerID";
			this->server_SelectISOButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_SelectISOButtonComponent_TextField_ServerID->TabIndex = 126;
			this->server_SelectISOButtonComponent_TextField_ServerID->Text = L"";
			this->server_SelectISOButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_SelectISOButtonComponent_TextField_FirstFile
			// 
			this->server_SelectISOButtonComponent_TextField_FirstFile->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SelectISOButtonComponent_TextField_FirstFile->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SelectISOButtonComponent_TextField_FirstFile->Enabled = false;
			this->server_SelectISOButtonComponent_TextField_FirstFile->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SelectISOButtonComponent_TextField_FirstFile->ForeColor = System::Drawing::Color::White;
			this->server_SelectISOButtonComponent_TextField_FirstFile->Location = System::Drawing::Point(137, 203);
			this->server_SelectISOButtonComponent_TextField_FirstFile->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SelectISOButtonComponent_TextField_FirstFile->Multiline = false;
			this->server_SelectISOButtonComponent_TextField_FirstFile->Name = L"server_SelectISOButtonComponent_TextField_FirstFile";
			this->server_SelectISOButtonComponent_TextField_FirstFile->Size = System::Drawing::Size(429, 29);
			this->server_SelectISOButtonComponent_TextField_FirstFile->TabIndex = 127;
			this->server_SelectISOButtonComponent_TextField_FirstFile->Text = L"";
			this->server_SelectISOButtonComponent_TextField_FirstFile->Visible = false;
			// 
			// server_SelectISOButtonComponent_InstructionLabel_SecondFile
			// 
			this->server_SelectISOButtonComponent_InstructionLabel_SecondFile->Enabled = false;
			this->server_SelectISOButtonComponent_InstructionLabel_SecondFile->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SelectISOButtonComponent_InstructionLabel_SecondFile->ForeColor = System::Drawing::Color::White;
			this->server_SelectISOButtonComponent_InstructionLabel_SecondFile->Location = System::Drawing::Point(139, 247);
			this->server_SelectISOButtonComponent_InstructionLabel_SecondFile->Name = L"server_SelectISOButtonComponent_InstructionLabel_SecondFile";
			this->server_SelectISOButtonComponent_InstructionLabel_SecondFile->Size = System::Drawing::Size(167, 23);
			this->server_SelectISOButtonComponent_InstructionLabel_SecondFile->TabIndex = 128;
			this->server_SelectISOButtonComponent_InstructionLabel_SecondFile->Text = L"Second ISO File:";
			this->server_SelectISOButtonComponent_InstructionLabel_SecondFile->Visible = false;
			// 
			// server_SelectISOButtonComponent_TextField_SecondFile
			// 
			this->server_SelectISOButtonComponent_TextField_SecondFile->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SelectISOButtonComponent_TextField_SecondFile->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SelectISOButtonComponent_TextField_SecondFile->Enabled = false;
			this->server_SelectISOButtonComponent_TextField_SecondFile->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SelectISOButtonComponent_TextField_SecondFile->ForeColor = System::Drawing::Color::White;
			this->server_SelectISOButtonComponent_TextField_SecondFile->Location = System::Drawing::Point(137, 272);
			this->server_SelectISOButtonComponent_TextField_SecondFile->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SelectISOButtonComponent_TextField_SecondFile->Multiline = false;
			this->server_SelectISOButtonComponent_TextField_SecondFile->Name = L"server_SelectISOButtonComponent_TextField_SecondFile";
			this->server_SelectISOButtonComponent_TextField_SecondFile->Size = System::Drawing::Size(429, 29);
			this->server_SelectISOButtonComponent_TextField_SecondFile->TabIndex = 129;
			this->server_SelectISOButtonComponent_TextField_SecondFile->Text = L"";
			this->server_SelectISOButtonComponent_TextField_SecondFile->Visible = false;
			// 
			// server_SelectISOButtonComponent_SendButton
			// 
			this->server_SelectISOButtonComponent_SendButton->Enabled = false;
			this->server_SelectISOButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_SelectISOButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SelectISOButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_SelectISOButtonComponent_SendButton->Location = System::Drawing::Point(491, 305);
			this->server_SelectISOButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SelectISOButtonComponent_SendButton->Name = L"server_SelectISOButtonComponent_SendButton";
			this->server_SelectISOButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_SelectISOButtonComponent_SendButton->TabIndex = 130;
			this->server_SelectISOButtonComponent_SendButton->Text = L"Send";
			this->server_SelectISOButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_SelectISOButtonComponent_SendButton->Visible = false;
			this->server_SelectISOButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_SelectISOButtonComponent_SendButton_Click);
			// 
			// server_ResetPasswordButtonComponent_InstructionLabel_ServerID
			// 
			this->server_ResetPasswordButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_ResetPasswordButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ResetPasswordButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_ResetPasswordButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_ResetPasswordButtonComponent_InstructionLabel_ServerID->Name = L"server_ResetPasswordButtonComponent_InstructionLabel_ServerID";
			this->server_ResetPasswordButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_ResetPasswordButtonComponent_InstructionLabel_ServerID->TabIndex = 131;
			this->server_ResetPasswordButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_ResetPasswordButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_ResetPasswordButtonComponent_TextField_ServerID
			// 
			this->server_ResetPasswordButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_ResetPasswordButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_ResetPasswordButtonComponent_TextField_ServerID->Enabled = false;
			this->server_ResetPasswordButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ResetPasswordButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_ResetPasswordButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_ResetPasswordButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ResetPasswordButtonComponent_TextField_ServerID->Multiline = false;
			this->server_ResetPasswordButtonComponent_TextField_ServerID->Name = L"server_ResetPasswordButtonComponent_TextField_ServerID";
			this->server_ResetPasswordButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_ResetPasswordButtonComponent_TextField_ServerID->TabIndex = 132;
			this->server_ResetPasswordButtonComponent_TextField_ServerID->Text = L"";
			this->server_ResetPasswordButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_ResetPasswordButtonComponent_SendButton
			// 
			this->server_ResetPasswordButtonComponent_SendButton->Enabled = false;
			this->server_ResetPasswordButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_ResetPasswordButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ResetPasswordButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_ResetPasswordButtonComponent_SendButton->Location = System::Drawing::Point(491, 176);
			this->server_ResetPasswordButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ResetPasswordButtonComponent_SendButton->Name = L"server_ResetPasswordButtonComponent_SendButton";
			this->server_ResetPasswordButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_ResetPasswordButtonComponent_SendButton->TabIndex = 133;
			this->server_ResetPasswordButtonComponent_SendButton->Text = L"Send";
			this->server_ResetPasswordButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_ResetPasswordButtonComponent_SendButton->Visible = false;
			this->server_ResetPasswordButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_ResetPasswordButtonComponent_SendButton_Click);
			// 
			// server_SetHostnameButtonComponent_InstructionLabel_ServerID
			// 
			this->server_SetHostnameButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_SetHostnameButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetHostnameButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_SetHostnameButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(137, 116);
			this->server_SetHostnameButtonComponent_InstructionLabel_ServerID->Name = L"server_SetHostnameButtonComponent_InstructionLabel_ServerID";
			this->server_SetHostnameButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_SetHostnameButtonComponent_InstructionLabel_ServerID->TabIndex = 134;
			this->server_SetHostnameButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_SetHostnameButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_SetHostnameButtonComponent_TextField_ServerID
			// 
			this->server_SetHostnameButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetHostnameButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetHostnameButtonComponent_TextField_ServerID->Enabled = false;
			this->server_SetHostnameButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetHostnameButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_SetHostnameButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_SetHostnameButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetHostnameButtonComponent_TextField_ServerID->Multiline = false;
			this->server_SetHostnameButtonComponent_TextField_ServerID->Name = L"server_SetHostnameButtonComponent_TextField_ServerID";
			this->server_SetHostnameButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_SetHostnameButtonComponent_TextField_ServerID->TabIndex = 135;
			this->server_SetHostnameButtonComponent_TextField_ServerID->Text = L"";
			this->server_SetHostnameButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_SetHostnameButtonComponent_SendButton
			// 
			this->server_SetHostnameButtonComponent_SendButton->Enabled = false;
			this->server_SetHostnameButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_SetHostnameButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetHostnameButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_SetHostnameButtonComponent_SendButton->Location = System::Drawing::Point(491, 238);
			this->server_SetHostnameButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetHostnameButtonComponent_SendButton->Name = L"server_SetHostnameButtonComponent_SendButton";
			this->server_SetHostnameButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_SetHostnameButtonComponent_SendButton->TabIndex = 136;
			this->server_SetHostnameButtonComponent_SendButton->Text = L"Send";
			this->server_SetHostnameButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_SetHostnameButtonComponent_SendButton->Visible = false;
			this->server_SetHostnameButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_SetHostnameButtonComponent_SendButton_Click);
			// 
			// server_SetHostnameButtonComponent_InstructionLabel_Hostname
			// 
			this->server_SetHostnameButtonComponent_InstructionLabel_Hostname->Enabled = false;
			this->server_SetHostnameButtonComponent_InstructionLabel_Hostname->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetHostnameButtonComponent_InstructionLabel_Hostname->ForeColor = System::Drawing::Color::White;
			this->server_SetHostnameButtonComponent_InstructionLabel_Hostname->Location = System::Drawing::Point(137, 178);
			this->server_SetHostnameButtonComponent_InstructionLabel_Hostname->Name = L"server_SetHostnameButtonComponent_InstructionLabel_Hostname";
			this->server_SetHostnameButtonComponent_InstructionLabel_Hostname->Size = System::Drawing::Size(167, 23);
			this->server_SetHostnameButtonComponent_InstructionLabel_Hostname->TabIndex = 137;
			this->server_SetHostnameButtonComponent_InstructionLabel_Hostname->Text = L"Hostname:";
			this->server_SetHostnameButtonComponent_InstructionLabel_Hostname->Visible = false;
			// 
			// server_SetHostnameButtonComponent_TextField_Hostname
			// 
			this->server_SetHostnameButtonComponent_TextField_Hostname->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetHostnameButtonComponent_TextField_Hostname->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetHostnameButtonComponent_TextField_Hostname->Enabled = false;
			this->server_SetHostnameButtonComponent_TextField_Hostname->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetHostnameButtonComponent_TextField_Hostname->ForeColor = System::Drawing::Color::White;
			this->server_SetHostnameButtonComponent_TextField_Hostname->Location = System::Drawing::Point(137, 203);
			this->server_SetHostnameButtonComponent_TextField_Hostname->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetHostnameButtonComponent_TextField_Hostname->Multiline = false;
			this->server_SetHostnameButtonComponent_TextField_Hostname->Name = L"server_SetHostnameButtonComponent_TextField_Hostname";
			this->server_SetHostnameButtonComponent_TextField_Hostname->Size = System::Drawing::Size(429, 29);
			this->server_SetHostnameButtonComponent_TextField_Hostname->TabIndex = 138;
			this->server_SetHostnameButtonComponent_TextField_Hostname->Text = L"";
			this->server_SetHostnameButtonComponent_TextField_Hostname->Visible = false;
			// 
			// server_RebuildButtonComponent_InstructionLabel_ServerID
			// 
			this->server_RebuildButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_RebuildButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_RebuildButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_RebuildButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(137, 116);
			this->server_RebuildButtonComponent_InstructionLabel_ServerID->Name = L"server_RebuildButtonComponent_InstructionLabel_ServerID";
			this->server_RebuildButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_RebuildButtonComponent_InstructionLabel_ServerID->TabIndex = 139;
			this->server_RebuildButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_RebuildButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_RebuildButtonComponent_TextField_ServerID
			// 
			this->server_RebuildButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_RebuildButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_RebuildButtonComponent_TextField_ServerID->Enabled = false;
			this->server_RebuildButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_RebuildButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_RebuildButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_RebuildButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_RebuildButtonComponent_TextField_ServerID->Multiline = false;
			this->server_RebuildButtonComponent_TextField_ServerID->Name = L"server_RebuildButtonComponent_TextField_ServerID";
			this->server_RebuildButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_RebuildButtonComponent_TextField_ServerID->TabIndex = 140;
			this->server_RebuildButtonComponent_TextField_ServerID->Text = L"";
			this->server_RebuildButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_RebuildButtonComponent_InstructionLabel_NewOS
			// 
			this->server_RebuildButtonComponent_InstructionLabel_NewOS->Enabled = false;
			this->server_RebuildButtonComponent_InstructionLabel_NewOS->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_RebuildButtonComponent_InstructionLabel_NewOS->ForeColor = System::Drawing::Color::White;
			this->server_RebuildButtonComponent_InstructionLabel_NewOS->Location = System::Drawing::Point(139, 178);
			this->server_RebuildButtonComponent_InstructionLabel_NewOS->Name = L"server_RebuildButtonComponent_InstructionLabel_NewOS";
			this->server_RebuildButtonComponent_InstructionLabel_NewOS->Size = System::Drawing::Size(167, 23);
			this->server_RebuildButtonComponent_InstructionLabel_NewOS->TabIndex = 141;
			this->server_RebuildButtonComponent_InstructionLabel_NewOS->Text = L"New OS:";
			this->server_RebuildButtonComponent_InstructionLabel_NewOS->Visible = false;
			// 
			// server_RebuildButtonComponent_TextField_NewOS
			// 
			this->server_RebuildButtonComponent_TextField_NewOS->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_RebuildButtonComponent_TextField_NewOS->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_RebuildButtonComponent_TextField_NewOS->Enabled = false;
			this->server_RebuildButtonComponent_TextField_NewOS->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_RebuildButtonComponent_TextField_NewOS->ForeColor = System::Drawing::Color::White;
			this->server_RebuildButtonComponent_TextField_NewOS->Location = System::Drawing::Point(137, 203);
			this->server_RebuildButtonComponent_TextField_NewOS->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_RebuildButtonComponent_TextField_NewOS->Multiline = false;
			this->server_RebuildButtonComponent_TextField_NewOS->Name = L"server_RebuildButtonComponent_TextField_NewOS";
			this->server_RebuildButtonComponent_TextField_NewOS->Size = System::Drawing::Size(429, 29);
			this->server_RebuildButtonComponent_TextField_NewOS->TabIndex = 142;
			this->server_RebuildButtonComponent_TextField_NewOS->Text = L"";
			this->server_RebuildButtonComponent_TextField_NewOS->Visible = false;
			// 
			// server_RebuildButtonComponent_SendButton
			// 
			this->server_RebuildButtonComponent_SendButton->Enabled = false;
			this->server_RebuildButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_RebuildButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_RebuildButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_RebuildButtonComponent_SendButton->Location = System::Drawing::Point(491, 240);
			this->server_RebuildButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_RebuildButtonComponent_SendButton->Name = L"server_RebuildButtonComponent_SendButton";
			this->server_RebuildButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_RebuildButtonComponent_SendButton->TabIndex = 143;
			this->server_RebuildButtonComponent_SendButton->Text = L"Send";
			this->server_RebuildButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_RebuildButtonComponent_SendButton->Visible = false;
			this->server_RebuildButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_RebuildButtonComponent_SendButton_Click);
			// 
			// server_GetIPInfoButtonComponent_Instructionlabel_ServerID
			// 
			this->server_GetIPInfoButtonComponent_Instructionlabel_ServerID->Enabled = false;
			this->server_GetIPInfoButtonComponent_Instructionlabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetIPInfoButtonComponent_Instructionlabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetIPInfoButtonComponent_Instructionlabel_ServerID->Location = System::Drawing::Point(137, 116);
			this->server_GetIPInfoButtonComponent_Instructionlabel_ServerID->Name = L"server_GetIPInfoButtonComponent_Instructionlabel_ServerID";
			this->server_GetIPInfoButtonComponent_Instructionlabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_GetIPInfoButtonComponent_Instructionlabel_ServerID->TabIndex = 144;
			this->server_GetIPInfoButtonComponent_Instructionlabel_ServerID->Text = L"Server ID:";
			this->server_GetIPInfoButtonComponent_Instructionlabel_ServerID->Visible = false;
			// 
			// server_GetIPInfoButtonComponent_TextField_ServerID
			// 
			this->server_GetIPInfoButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_GetIPInfoButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_GetIPInfoButtonComponent_TextField_ServerID->Enabled = false;
			this->server_GetIPInfoButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetIPInfoButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetIPInfoButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_GetIPInfoButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetIPInfoButtonComponent_TextField_ServerID->Multiline = false;
			this->server_GetIPInfoButtonComponent_TextField_ServerID->Name = L"server_GetIPInfoButtonComponent_TextField_ServerID";
			this->server_GetIPInfoButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_GetIPInfoButtonComponent_TextField_ServerID->TabIndex = 145;
			this->server_GetIPInfoButtonComponent_TextField_ServerID->Text = L"";
			this->server_GetIPInfoButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_GetIPInfoButtonComponent_SendButton
			// 
			this->server_GetIPInfoButtonComponent_SendButton->Enabled = false;
			this->server_GetIPInfoButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetIPInfoButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetIPInfoButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_GetIPInfoButtonComponent_SendButton->Location = System::Drawing::Point(495, 177);
			this->server_GetIPInfoButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetIPInfoButtonComponent_SendButton->Name = L"server_GetIPInfoButtonComponent_SendButton";
			this->server_GetIPInfoButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_GetIPInfoButtonComponent_SendButton->TabIndex = 146;
			this->server_GetIPInfoButtonComponent_SendButton->Text = L"Send";
			this->server_GetIPInfoButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_GetIPInfoButtonComponent_SendButton->Visible = false;
			this->server_GetIPInfoButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_GetIPInfoButtonComponent_SendButton_Click);
			// 
			// server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID
			// 
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID->Name = L"server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID";
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID->TabIndex = 147;
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_GetVNCInfoTFButtonComponent_TextField_ServerID
			// 
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->Enabled = false;
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->Multiline = false;
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->Name = L"server_GetVNCInfoTFButtonComponent_TextField_ServerID";
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->TabIndex = 148;
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->Text = L"";
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame
			// 
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame->Enabled = false;
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame->ForeColor = System::Drawing::Color::White;
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame->Location = System::Drawing::Point(139, 178);
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame->Name = L"server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame";
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame->Size = System::Drawing::Size(167, 23);
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame->TabIndex = 149;
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame->Text = L"Time Frame:";
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame->Visible = false;
			// 
			// server_GetVNCInfoTFButtonComponent_TextField_TimeFrame
			// 
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Enabled = false;
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->ForeColor = System::Drawing::Color::White;
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Location = System::Drawing::Point(137, 203);
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Multiline = false;
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Name = L"server_GetVNCInfoTFButtonComponent_TextField_TimeFrame";
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Size = System::Drawing::Size(429, 29);
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->TabIndex = 150;
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Text = L"";
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Visible = false;
			// 
			// server_GetVNCInfoTFButtonComponent_SendButton
			// 
			this->server_GetVNCInfoTFButtonComponent_SendButton->Enabled = false;
			this->server_GetVNCInfoTFButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetVNCInfoTFButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetVNCInfoTFButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_GetVNCInfoTFButtonComponent_SendButton->Location = System::Drawing::Point(491, 241);
			this->server_GetVNCInfoTFButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetVNCInfoTFButtonComponent_SendButton->Name = L"server_GetVNCInfoTFButtonComponent_SendButton";
			this->server_GetVNCInfoTFButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_GetVNCInfoTFButtonComponent_SendButton->TabIndex = 151;
			this->server_GetVNCInfoTFButtonComponent_SendButton->Text = L"Send";
			this->server_GetVNCInfoTFButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_GetVNCInfoTFButtonComponent_SendButton->Visible = false;
			this->server_GetVNCInfoTFButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_GetVNCInfoTFButtonComponent_SendButton_Click);
			// 
			// server_SetBootOrderButtonComponent_InstructionLabel_ServerID
			// 
			this->server_SetBootOrderButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_SetBootOrderButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetBootOrderButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_SetBootOrderButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_SetBootOrderButtonComponent_InstructionLabel_ServerID->Name = L"server_SetBootOrderButtonComponent_InstructionLabel_ServerID";
			this->server_SetBootOrderButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_SetBootOrderButtonComponent_InstructionLabel_ServerID->TabIndex = 152;
			this->server_SetBootOrderButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_SetBootOrderButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_SetBootOrderButtonComponent_TextField_ServerID
			// 
			this->server_SetBootOrderButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetBootOrderButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetBootOrderButtonComponent_TextField_ServerID->Enabled = false;
			this->server_SetBootOrderButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetBootOrderButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_SetBootOrderButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_SetBootOrderButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetBootOrderButtonComponent_TextField_ServerID->Multiline = false;
			this->server_SetBootOrderButtonComponent_TextField_ServerID->Name = L"server_SetBootOrderButtonComponent_TextField_ServerID";
			this->server_SetBootOrderButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_SetBootOrderButtonComponent_TextField_ServerID->TabIndex = 153;
			this->server_SetBootOrderButtonComponent_TextField_ServerID->Text = L"";
			this->server_SetBootOrderButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_SetBootOrderButtonComponent_InstructionLabel_BootOrder
			// 
			this->server_SetBootOrderButtonComponent_InstructionLabel_BootOrder->Enabled = false;
			this->server_SetBootOrderButtonComponent_InstructionLabel_BootOrder->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetBootOrderButtonComponent_InstructionLabel_BootOrder->ForeColor = System::Drawing::Color::White;
			this->server_SetBootOrderButtonComponent_InstructionLabel_BootOrder->Location = System::Drawing::Point(139, 177);
			this->server_SetBootOrderButtonComponent_InstructionLabel_BootOrder->Name = L"server_SetBootOrderButtonComponent_InstructionLabel_BootOrder";
			this->server_SetBootOrderButtonComponent_InstructionLabel_BootOrder->Size = System::Drawing::Size(167, 23);
			this->server_SetBootOrderButtonComponent_InstructionLabel_BootOrder->TabIndex = 154;
			this->server_SetBootOrderButtonComponent_InstructionLabel_BootOrder->Text = L"Boot Order:";
			this->server_SetBootOrderButtonComponent_InstructionLabel_BootOrder->Visible = false;
			// 
			// server_SetBootOrderButtonComponent_TextField_BootOrder
			// 
			this->server_SetBootOrderButtonComponent_TextField_BootOrder->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetBootOrderButtonComponent_TextField_BootOrder->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetBootOrderButtonComponent_TextField_BootOrder->Enabled = false;
			this->server_SetBootOrderButtonComponent_TextField_BootOrder->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetBootOrderButtonComponent_TextField_BootOrder->ForeColor = System::Drawing::Color::White;
			this->server_SetBootOrderButtonComponent_TextField_BootOrder->Location = System::Drawing::Point(137, 203);
			this->server_SetBootOrderButtonComponent_TextField_BootOrder->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetBootOrderButtonComponent_TextField_BootOrder->Multiline = false;
			this->server_SetBootOrderButtonComponent_TextField_BootOrder->Name = L"server_SetBootOrderButtonComponent_TextField_BootOrder";
			this->server_SetBootOrderButtonComponent_TextField_BootOrder->Size = System::Drawing::Size(429, 29);
			this->server_SetBootOrderButtonComponent_TextField_BootOrder->TabIndex = 155;
			this->server_SetBootOrderButtonComponent_TextField_BootOrder->Text = L"";
			this->server_SetBootOrderButtonComponent_TextField_BootOrder->Visible = false;
			// 
			// server_SetBootOrderButtonComponent_SendButton
			// 
			this->server_SetBootOrderButtonComponent_SendButton->Enabled = false;
			this->server_SetBootOrderButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_SetBootOrderButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetBootOrderButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_SetBootOrderButtonComponent_SendButton->Location = System::Drawing::Point(491, 242);
			this->server_SetBootOrderButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetBootOrderButtonComponent_SendButton->Name = L"server_SetBootOrderButtonComponent_SendButton";
			this->server_SetBootOrderButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_SetBootOrderButtonComponent_SendButton->TabIndex = 156;
			this->server_SetBootOrderButtonComponent_SendButton->Text = L"Send";
			this->server_SetBootOrderButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_SetBootOrderButtonComponent_SendButton->Visible = false;
			this->server_SetBootOrderButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_SetBootOrderButtonComponent_SendButton_Click);
			// 
			// server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID
			// 
			this->server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(137, 116);
			this->server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID->Name = L"server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID";
			this->server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID->TabIndex = 157;
			this->server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_GetFirewallRulesButtonComponent_TextField_ServerID
			// 
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID->Enabled = false;
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID->Multiline = false;
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID->Name = L"server_GetFirewallRulesButtonComponent_TextField_ServerID";
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID->TabIndex = 158;
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID->Text = L"";
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_GetFirewallRulesButtonComponent_SendButton
			// 
			this->server_GetFirewallRulesButtonComponent_SendButton->Enabled = false;
			this->server_GetFirewallRulesButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetFirewallRulesButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetFirewallRulesButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_GetFirewallRulesButtonComponent_SendButton->Location = System::Drawing::Point(491, 177);
			this->server_GetFirewallRulesButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetFirewallRulesButtonComponent_SendButton->Name = L"server_GetFirewallRulesButtonComponent_SendButton";
			this->server_GetFirewallRulesButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_GetFirewallRulesButtonComponent_SendButton->TabIndex = 159;
			this->server_GetFirewallRulesButtonComponent_SendButton->Text = L"Send";
			this->server_GetFirewallRulesButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_GetFirewallRulesButtonComponent_SendButton->Visible = false;
			this->server_GetFirewallRulesButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_GetFirewallRulesButtonComponent_SendButton_Click);
			// 
			// server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID
			// 
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(137, 116);
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID->Name = L"server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID";
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID->TabIndex = 160;
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_ToggleFirewallRuleButtonComponent_TextField_ServerID
			// 
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Enabled = false;
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Multiline = false;
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Name = L"server_ToggleFirewallRuleButtonComponent_TextField_ServerID";
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->TabIndex = 161;
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Text = L"";
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle
			// 
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle->Enabled = false;
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle->ForeColor = System::Drawing::Color::White;
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle->Location = System::Drawing::Point(139, 178);
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle->Name = L"server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle";
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle->Size = System::Drawing::Size(167, 23);
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle->TabIndex = 162;
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle->Text = L"Toggle:";
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle->Visible = false;
			// 
			// server_ToggleFirewallRuleButtonComponent_TextField_Toggle
			// 
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Enabled = false;
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->ForeColor = System::Drawing::Color::White;
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Location = System::Drawing::Point(137, 203);
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Multiline = false;
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Name = L"server_ToggleFirewallRuleButtonComponent_TextField_Toggle";
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Size = System::Drawing::Size(429, 29);
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->TabIndex = 163;
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Text = L"";
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Visible = false;
			// 
			// server_ToggleFirewallRuleButtonComponent_SendButton
			// 
			this->server_ToggleFirewallRuleButtonComponent_SendButton->Enabled = false;
			this->server_ToggleFirewallRuleButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_ToggleFirewallRuleButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ToggleFirewallRuleButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_ToggleFirewallRuleButtonComponent_SendButton->Location = System::Drawing::Point(491, 240);
			this->server_ToggleFirewallRuleButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ToggleFirewallRuleButtonComponent_SendButton->Name = L"server_ToggleFirewallRuleButtonComponent_SendButton";
			this->server_ToggleFirewallRuleButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_ToggleFirewallRuleButtonComponent_SendButton->TabIndex = 164;
			this->server_ToggleFirewallRuleButtonComponent_SendButton->Text = L"Send";
			this->server_ToggleFirewallRuleButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_ToggleFirewallRuleButtonComponent_SendButton->Visible = false;
			this->server_ToggleFirewallRuleButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_ToggleFirewallRuleButtonComponent_SendButton_Click);
			// 
			// server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID
			// 
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID->Name = L"server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID";
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID->TabIndex = 165;
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_AddFirewallRuleButtonComponent_TextField_ServerID
			// 
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID->Enabled = false;
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID->Multiline = false;
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID->Name = L"server_AddFirewallRuleButtonComponent_TextField_ServerID";
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID->TabIndex = 166;
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID->Text = L"";
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_AddFirewallRuleButtonComponent_InstructionLabel_Data
			// 
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_Data->Enabled = false;
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_Data->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_Data->ForeColor = System::Drawing::Color::White;
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_Data->Location = System::Drawing::Point(139, 178);
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_Data->Name = L"server_AddFirewallRuleButtonComponent_InstructionLabel_Data";
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_Data->Size = System::Drawing::Size(167, 23);
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_Data->TabIndex = 167;
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_Data->Text = L"Data:";
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_Data->Visible = false;
			// 
			// server_AddFirewallRuleButtonComponent_TextField_Data
			// 
			this->server_AddFirewallRuleButtonComponent_TextField_Data->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_AddFirewallRuleButtonComponent_TextField_Data->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_AddFirewallRuleButtonComponent_TextField_Data->Enabled = false;
			this->server_AddFirewallRuleButtonComponent_TextField_Data->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddFirewallRuleButtonComponent_TextField_Data->ForeColor = System::Drawing::Color::White;
			this->server_AddFirewallRuleButtonComponent_TextField_Data->Location = System::Drawing::Point(137, 203);
			this->server_AddFirewallRuleButtonComponent_TextField_Data->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_AddFirewallRuleButtonComponent_TextField_Data->Multiline = false;
			this->server_AddFirewallRuleButtonComponent_TextField_Data->Name = L"server_AddFirewallRuleButtonComponent_TextField_Data";
			this->server_AddFirewallRuleButtonComponent_TextField_Data->Size = System::Drawing::Size(429, 29);
			this->server_AddFirewallRuleButtonComponent_TextField_Data->TabIndex = 168;
			this->server_AddFirewallRuleButtonComponent_TextField_Data->Text = L"";
			this->server_AddFirewallRuleButtonComponent_TextField_Data->Visible = false;
			// 
			// server_AddFirewallRuleButtonComponent_SendButton
			// 
			this->server_AddFirewallRuleButtonComponent_SendButton->Enabled = false;
			this->server_AddFirewallRuleButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_AddFirewallRuleButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddFirewallRuleButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_AddFirewallRuleButtonComponent_SendButton->Location = System::Drawing::Point(491, 240);
			this->server_AddFirewallRuleButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_AddFirewallRuleButtonComponent_SendButton->Name = L"server_AddFirewallRuleButtonComponent_SendButton";
			this->server_AddFirewallRuleButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_AddFirewallRuleButtonComponent_SendButton->TabIndex = 169;
			this->server_AddFirewallRuleButtonComponent_SendButton->Text = L"Send";
			this->server_AddFirewallRuleButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_AddFirewallRuleButtonComponent_SendButton->Visible = false;
			this->server_AddFirewallRuleButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_AddFirewallRuleButtonComponent_SendButton_Click);
			// 
			// server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID
			// 
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID->Enabled = false;
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID->Location = System::Drawing::Point(139, 178);
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID->Name = L"server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID";
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID->Size = System::Drawing::Size(167, 23);
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID->TabIndex = 170;
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID->Text = L"Rule ID:";
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID->Visible = false;
			// 
			// server_DeleteFirewallRuleButtonComponent_TextField_RID
			// 
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID->Enabled = false;
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID->Location = System::Drawing::Point(137, 203);
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID->Multiline = false;
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID->Name = L"server_DeleteFirewallRuleButtonComponent_TextField_RID";
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID->Size = System::Drawing::Size(429, 29);
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID->TabIndex = 171;
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID->Text = L"";
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID->Visible = false;
			// 
			// server_DeleteFirewallRuleButtonComponent_SendButton
			// 
			this->server_DeleteFirewallRuleButtonComponent_SendButton->Enabled = false;
			this->server_DeleteFirewallRuleButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_DeleteFirewallRuleButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteFirewallRuleButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_DeleteFirewallRuleButtonComponent_SendButton->Location = System::Drawing::Point(491, 241);
			this->server_DeleteFirewallRuleButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteFirewallRuleButtonComponent_SendButton->Name = L"server_DeleteFirewallRuleButtonComponent_SendButton";
			this->server_DeleteFirewallRuleButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_DeleteFirewallRuleButtonComponent_SendButton->TabIndex = 172;
			this->server_DeleteFirewallRuleButtonComponent_SendButton->Text = L"Send";
			this->server_DeleteFirewallRuleButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_DeleteFirewallRuleButtonComponent_SendButton->Visible = false;
			this->server_DeleteFirewallRuleButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_DeleteFirewallRuleButtonComponent_SendButton_Click);
			// 
			// server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID
			// 
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(137, 116);
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID->Name = L"server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID";
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID->TabIndex = 173;
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_DeleteFirewallRuleButtonComponent_TextField_ServerID
			// 
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Enabled = false;
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Multiline = false;
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Name = L"server_DeleteFirewallRuleButtonComponent_TextField_ServerID";
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->TabIndex = 174;
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Text = L"";
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_SetIPrDNSButtonComponent_InstructionLabel_ServerID
			// 
			this->server_SetIPrDNSButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_SetIPrDNSButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetIPrDNSButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_SetIPrDNSButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_SetIPrDNSButtonComponent_InstructionLabel_ServerID->Name = L"server_SetIPrDNSButtonComponent_InstructionLabel_ServerID";
			this->server_SetIPrDNSButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_SetIPrDNSButtonComponent_InstructionLabel_ServerID->TabIndex = 175;
			this->server_SetIPrDNSButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_SetIPrDNSButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_SetIPrDNSButtonComponent_TextField_ServerID
			// 
			this->server_SetIPrDNSButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetIPrDNSButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetIPrDNSButtonComponent_TextField_ServerID->Enabled = false;
			this->server_SetIPrDNSButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetIPrDNSButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_SetIPrDNSButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_SetIPrDNSButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetIPrDNSButtonComponent_TextField_ServerID->Multiline = false;
			this->server_SetIPrDNSButtonComponent_TextField_ServerID->Name = L"server_SetIPrDNSButtonComponent_TextField_ServerID";
			this->server_SetIPrDNSButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_SetIPrDNSButtonComponent_TextField_ServerID->TabIndex = 176;
			this->server_SetIPrDNSButtonComponent_TextField_ServerID->Text = L"";
			this->server_SetIPrDNSButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_SetIPrDNSButtonComponent_InstructionLabel_IP
			// 
			this->server_SetIPrDNSButtonComponent_InstructionLabel_IP->Enabled = false;
			this->server_SetIPrDNSButtonComponent_InstructionLabel_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetIPrDNSButtonComponent_InstructionLabel_IP->ForeColor = System::Drawing::Color::White;
			this->server_SetIPrDNSButtonComponent_InstructionLabel_IP->Location = System::Drawing::Point(139, 178);
			this->server_SetIPrDNSButtonComponent_InstructionLabel_IP->Name = L"server_SetIPrDNSButtonComponent_InstructionLabel_IP";
			this->server_SetIPrDNSButtonComponent_InstructionLabel_IP->Size = System::Drawing::Size(167, 23);
			this->server_SetIPrDNSButtonComponent_InstructionLabel_IP->TabIndex = 177;
			this->server_SetIPrDNSButtonComponent_InstructionLabel_IP->Text = L"IP Address:";
			this->server_SetIPrDNSButtonComponent_InstructionLabel_IP->Visible = false;
			// 
			// server_SetIPrDNSButtonComponent_TextField_IP
			// 
			this->server_SetIPrDNSButtonComponent_TextField_IP->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetIPrDNSButtonComponent_TextField_IP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetIPrDNSButtonComponent_TextField_IP->Enabled = false;
			this->server_SetIPrDNSButtonComponent_TextField_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetIPrDNSButtonComponent_TextField_IP->ForeColor = System::Drawing::Color::White;
			this->server_SetIPrDNSButtonComponent_TextField_IP->Location = System::Drawing::Point(137, 203);
			this->server_SetIPrDNSButtonComponent_TextField_IP->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetIPrDNSButtonComponent_TextField_IP->Multiline = false;
			this->server_SetIPrDNSButtonComponent_TextField_IP->Name = L"server_SetIPrDNSButtonComponent_TextField_IP";
			this->server_SetIPrDNSButtonComponent_TextField_IP->Size = System::Drawing::Size(429, 29);
			this->server_SetIPrDNSButtonComponent_TextField_IP->TabIndex = 178;
			this->server_SetIPrDNSButtonComponent_TextField_IP->Text = L"";
			this->server_SetIPrDNSButtonComponent_TextField_IP->Visible = false;
			// 
			// server_SetIPrDNSButtonComponent_InstructionLabel_rDNS
			// 
			this->server_SetIPrDNSButtonComponent_InstructionLabel_rDNS->Enabled = false;
			this->server_SetIPrDNSButtonComponent_InstructionLabel_rDNS->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetIPrDNSButtonComponent_InstructionLabel_rDNS->ForeColor = System::Drawing::Color::White;
			this->server_SetIPrDNSButtonComponent_InstructionLabel_rDNS->Location = System::Drawing::Point(137, 247);
			this->server_SetIPrDNSButtonComponent_InstructionLabel_rDNS->Name = L"server_SetIPrDNSButtonComponent_InstructionLabel_rDNS";
			this->server_SetIPrDNSButtonComponent_InstructionLabel_rDNS->Size = System::Drawing::Size(167, 23);
			this->server_SetIPrDNSButtonComponent_InstructionLabel_rDNS->TabIndex = 179;
			this->server_SetIPrDNSButtonComponent_InstructionLabel_rDNS->Text = L"Reverse DNS:";
			this->server_SetIPrDNSButtonComponent_InstructionLabel_rDNS->Visible = false;
			// 
			// server_SetIPrDNSButtonComponent_TextField_rDNS
			// 
			this->server_SetIPrDNSButtonComponent_TextField_rDNS->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetIPrDNSButtonComponent_TextField_rDNS->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetIPrDNSButtonComponent_TextField_rDNS->Enabled = false;
			this->server_SetIPrDNSButtonComponent_TextField_rDNS->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetIPrDNSButtonComponent_TextField_rDNS->ForeColor = System::Drawing::Color::White;
			this->server_SetIPrDNSButtonComponent_TextField_rDNS->Location = System::Drawing::Point(137, 272);
			this->server_SetIPrDNSButtonComponent_TextField_rDNS->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetIPrDNSButtonComponent_TextField_rDNS->Multiline = false;
			this->server_SetIPrDNSButtonComponent_TextField_rDNS->Name = L"server_SetIPrDNSButtonComponent_TextField_rDNS";
			this->server_SetIPrDNSButtonComponent_TextField_rDNS->Size = System::Drawing::Size(429, 29);
			this->server_SetIPrDNSButtonComponent_TextField_rDNS->TabIndex = 180;
			this->server_SetIPrDNSButtonComponent_TextField_rDNS->Text = L"";
			this->server_SetIPrDNSButtonComponent_TextField_rDNS->Visible = false;
			// 
			// server_SetIPrDNSButtonComponent_SendButton
			// 
			this->server_SetIPrDNSButtonComponent_SendButton->Enabled = false;
			this->server_SetIPrDNSButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_SetIPrDNSButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetIPrDNSButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_SetIPrDNSButtonComponent_SendButton->Location = System::Drawing::Point(491, 305);
			this->server_SetIPrDNSButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetIPrDNSButtonComponent_SendButton->Name = L"server_SetIPrDNSButtonComponent_SendButton";
			this->server_SetIPrDNSButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_SetIPrDNSButtonComponent_SendButton->TabIndex = 181;
			this->server_SetIPrDNSButtonComponent_SendButton->Text = L"Send";
			this->server_SetIPrDNSButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_SetIPrDNSButtonComponent_SendButton->Visible = false;
			this->server_SetIPrDNSButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_SetIPrDNSButtonComponent_SendButton_Click);
			// 
			// server_IndependentComponentShowIPs_RightPos
			// 
			this->server_IndependentComponentShowIPs_RightPos->Enabled = false;
			this->server_IndependentComponentShowIPs_RightPos->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_IndependentComponentShowIPs_RightPos->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_IndependentComponentShowIPs_RightPos->ForeColor = System::Drawing::Color::White;
			this->server_IndependentComponentShowIPs_RightPos->Location = System::Drawing::Point(455, 236);
			this->server_IndependentComponentShowIPs_RightPos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_IndependentComponentShowIPs_RightPos->Name = L"server_IndependentComponentShowIPs_RightPos";
			this->server_IndependentComponentShowIPs_RightPos->Size = System::Drawing::Size(111, 23);
			this->server_IndependentComponentShowIPs_RightPos->TabIndex = 182;
			this->server_IndependentComponentShowIPs_RightPos->Text = L"Show IPs";
			this->server_IndependentComponentShowIPs_RightPos->UseVisualStyleBackColor = true;
			this->server_IndependentComponentShowIPs_RightPos->Visible = false;
			this->server_IndependentComponentShowIPs_RightPos->Click += gcnew System::EventHandler(this, &main_form::server_IndependentComponentShowIPs_RightPos_Click);
			// 
			// server_GetIPRulesButtonComponent_TextField_ServerID
			// 
			this->server_GetIPRulesButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_GetIPRulesButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_GetIPRulesButtonComponent_TextField_ServerID->Enabled = false;
			this->server_GetIPRulesButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetIPRulesButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetIPRulesButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_GetIPRulesButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetIPRulesButtonComponent_TextField_ServerID->Multiline = false;
			this->server_GetIPRulesButtonComponent_TextField_ServerID->Name = L"server_GetIPRulesButtonComponent_TextField_ServerID";
			this->server_GetIPRulesButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_GetIPRulesButtonComponent_TextField_ServerID->TabIndex = 184;
			this->server_GetIPRulesButtonComponent_TextField_ServerID->Text = L"";
			this->server_GetIPRulesButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_GetIPRulesButtonComponent_InstructionLabel_IP
			// 
			this->server_GetIPRulesButtonComponent_InstructionLabel_IP->Enabled = false;
			this->server_GetIPRulesButtonComponent_InstructionLabel_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetIPRulesButtonComponent_InstructionLabel_IP->ForeColor = System::Drawing::Color::White;
			this->server_GetIPRulesButtonComponent_InstructionLabel_IP->Location = System::Drawing::Point(139, 178);
			this->server_GetIPRulesButtonComponent_InstructionLabel_IP->Name = L"server_GetIPRulesButtonComponent_InstructionLabel_IP";
			this->server_GetIPRulesButtonComponent_InstructionLabel_IP->Size = System::Drawing::Size(167, 23);
			this->server_GetIPRulesButtonComponent_InstructionLabel_IP->TabIndex = 185;
			this->server_GetIPRulesButtonComponent_InstructionLabel_IP->Text = L"IP Address:";
			this->server_GetIPRulesButtonComponent_InstructionLabel_IP->Visible = false;
			// 
			// server_GetIPRulesButtonComponent_TextField_IP
			// 
			this->server_GetIPRulesButtonComponent_TextField_IP->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_GetIPRulesButtonComponent_TextField_IP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_GetIPRulesButtonComponent_TextField_IP->Enabled = false;
			this->server_GetIPRulesButtonComponent_TextField_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetIPRulesButtonComponent_TextField_IP->ForeColor = System::Drawing::Color::White;
			this->server_GetIPRulesButtonComponent_TextField_IP->Location = System::Drawing::Point(137, 203);
			this->server_GetIPRulesButtonComponent_TextField_IP->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetIPRulesButtonComponent_TextField_IP->Multiline = false;
			this->server_GetIPRulesButtonComponent_TextField_IP->Name = L"server_GetIPRulesButtonComponent_TextField_IP";
			this->server_GetIPRulesButtonComponent_TextField_IP->Size = System::Drawing::Size(429, 29);
			this->server_GetIPRulesButtonComponent_TextField_IP->TabIndex = 186;
			this->server_GetIPRulesButtonComponent_TextField_IP->Text = L"";
			this->server_GetIPRulesButtonComponent_TextField_IP->Visible = false;
			// 
			// server_GetIPRulesButtonComponent_SendButton
			// 
			this->server_GetIPRulesButtonComponent_SendButton->Enabled = false;
			this->server_GetIPRulesButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetIPRulesButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetIPRulesButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_GetIPRulesButtonComponent_SendButton->Location = System::Drawing::Point(491, 240);
			this->server_GetIPRulesButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetIPRulesButtonComponent_SendButton->Name = L"server_GetIPRulesButtonComponent_SendButton";
			this->server_GetIPRulesButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_GetIPRulesButtonComponent_SendButton->TabIndex = 187;
			this->server_GetIPRulesButtonComponent_SendButton->Text = L"Send";
			this->server_GetIPRulesButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_GetIPRulesButtonComponent_SendButton->Visible = false;
			this->server_GetIPRulesButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_GetIPRulesButtonComponent_SendButton_Click);
			// 
			// server_IndependentComponentShowIPs
			// 
			this->server_IndependentComponentShowIPs->Enabled = false;
			this->server_IndependentComponentShowIPs->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_IndependentComponentShowIPs->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_IndependentComponentShowIPs->ForeColor = System::Drawing::Color::White;
			this->server_IndependentComponentShowIPs->Location = System::Drawing::Point(137, 238);
			this->server_IndependentComponentShowIPs->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_IndependentComponentShowIPs->Name = L"server_IndependentComponentShowIPs";
			this->server_IndependentComponentShowIPs->Size = System::Drawing::Size(111, 23);
			this->server_IndependentComponentShowIPs->TabIndex = 188;
			this->server_IndependentComponentShowIPs->Text = L"Show IPs";
			this->server_IndependentComponentShowIPs->UseVisualStyleBackColor = true;
			this->server_IndependentComponentShowIPs->Visible = false;
			this->server_IndependentComponentShowIPs->Click += gcnew System::EventHandler(this, &main_form::server_IndependentComponentShowIPs_Click);
			// 
			// server_GetIPRulesButtonComponent_InstructionLabel_ServerID
			// 
			this->server_GetIPRulesButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_GetIPRulesButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetIPRulesButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetIPRulesButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_GetIPRulesButtonComponent_InstructionLabel_ServerID->Name = L"server_GetIPRulesButtonComponent_InstructionLabel_ServerID";
			this->server_GetIPRulesButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_GetIPRulesButtonComponent_InstructionLabel_ServerID->TabIndex = 189;
			this->server_GetIPRulesButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_GetIPRulesButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID
			// 
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID->Name = L"server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID";
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID->TabIndex = 190;
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_GetMitigationStatusButtonComponent_TextField_ServerID
			// 
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID->Enabled = false;
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID->Multiline = false;
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID->Name = L"server_GetMitigationStatusButtonComponent_TextField_ServerID";
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID->TabIndex = 191;
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID->Text = L"";
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_GetMitigationStatusButtonComponent_InstructionLabel_IP
			// 
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_IP->Enabled = false;
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_IP->ForeColor = System::Drawing::Color::White;
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_IP->Location = System::Drawing::Point(137, 178);
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_IP->Name = L"server_GetMitigationStatusButtonComponent_InstructionLabel_IP";
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_IP->Size = System::Drawing::Size(167, 23);
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_IP->TabIndex = 192;
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_IP->Text = L"IP Address:";
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_IP->Visible = false;
			// 
			// server_GetMitigationStatusButtonComponent_TextField_IP
			// 
			this->server_GetMitigationStatusButtonComponent_TextField_IP->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_GetMitigationStatusButtonComponent_TextField_IP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_GetMitigationStatusButtonComponent_TextField_IP->Enabled = false;
			this->server_GetMitigationStatusButtonComponent_TextField_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetMitigationStatusButtonComponent_TextField_IP->ForeColor = System::Drawing::Color::White;
			this->server_GetMitigationStatusButtonComponent_TextField_IP->Location = System::Drawing::Point(137, 206);
			this->server_GetMitigationStatusButtonComponent_TextField_IP->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetMitigationStatusButtonComponent_TextField_IP->Multiline = false;
			this->server_GetMitigationStatusButtonComponent_TextField_IP->Name = L"server_GetMitigationStatusButtonComponent_TextField_IP";
			this->server_GetMitigationStatusButtonComponent_TextField_IP->Size = System::Drawing::Size(429, 29);
			this->server_GetMitigationStatusButtonComponent_TextField_IP->TabIndex = 193;
			this->server_GetMitigationStatusButtonComponent_TextField_IP->Text = L"";
			this->server_GetMitigationStatusButtonComponent_TextField_IP->Visible = false;
			// 
			// server_GetMitigationStatusButtonComponent_SendButton
			// 
			this->server_GetMitigationStatusButtonComponent_SendButton->Enabled = false;
			this->server_GetMitigationStatusButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_GetMitigationStatusButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_GetMitigationStatusButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_GetMitigationStatusButtonComponent_SendButton->Location = System::Drawing::Point(491, 241);
			this->server_GetMitigationStatusButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_GetMitigationStatusButtonComponent_SendButton->Name = L"server_GetMitigationStatusButtonComponent_SendButton";
			this->server_GetMitigationStatusButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_GetMitigationStatusButtonComponent_SendButton->TabIndex = 194;
			this->server_GetMitigationStatusButtonComponent_SendButton->Text = L"Send";
			this->server_GetMitigationStatusButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_GetMitigationStatusButtonComponent_SendButton->Visible = false;
			this->server_GetMitigationStatusButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_GetMitigationStatusButtonComponent_SendButton_Click);
			// 
			// server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID
			// 
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(137, 116);
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID->Name = L"server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID";
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID->TabIndex = 195;
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_SetMitigationStatusButtonComponent_TextField_ServerID
			// 
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID->Enabled = false;
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID->Multiline = false;
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID->Name = L"server_SetMitigationStatusButtonComponent_TextField_ServerID";
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID->TabIndex = 196;
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID->Text = L"";
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_SetMitigationStatusButtonComponent_InstructionLabel_IP
			// 
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_IP->Enabled = false;
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_IP->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_IP->Location = System::Drawing::Point(139, 178);
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_IP->Name = L"server_SetMitigationStatusButtonComponent_InstructionLabel_IP";
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_IP->Size = System::Drawing::Size(167, 23);
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_IP->TabIndex = 197;
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_IP->Text = L"IP Address:";
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_IP->Visible = false;
			// 
			// server_SetMitigationStatusButtonComponent_TextField_IP
			// 
			this->server_SetMitigationStatusButtonComponent_TextField_IP->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetMitigationStatusButtonComponent_TextField_IP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetMitigationStatusButtonComponent_TextField_IP->Enabled = false;
			this->server_SetMitigationStatusButtonComponent_TextField_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationStatusButtonComponent_TextField_IP->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationStatusButtonComponent_TextField_IP->Location = System::Drawing::Point(137, 206);
			this->server_SetMitigationStatusButtonComponent_TextField_IP->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetMitigationStatusButtonComponent_TextField_IP->Multiline = false;
			this->server_SetMitigationStatusButtonComponent_TextField_IP->Name = L"server_SetMitigationStatusButtonComponent_TextField_IP";
			this->server_SetMitigationStatusButtonComponent_TextField_IP->Size = System::Drawing::Size(429, 29);
			this->server_SetMitigationStatusButtonComponent_TextField_IP->TabIndex = 198;
			this->server_SetMitigationStatusButtonComponent_TextField_IP->Text = L"";
			this->server_SetMitigationStatusButtonComponent_TextField_IP->Visible = false;
			// 
			// server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle
			// 
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle->Enabled = false;
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle->Location = System::Drawing::Point(137, 246);
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle->Name = L"server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle";
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle->Size = System::Drawing::Size(167, 23);
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle->TabIndex = 199;
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle->Text = L"Toggle:";
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle->Visible = false;
			// 
			// server_SetMitigationStatusButtonComponent_TextField_Toggle
			// 
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle->Enabled = false;
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle->Location = System::Drawing::Point(137, 274);
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle->Multiline = false;
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle->Name = L"server_SetMitigationStatusButtonComponent_TextField_Toggle";
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle->Size = System::Drawing::Size(429, 29);
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle->TabIndex = 200;
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle->Text = L"";
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle->Visible = false;
			// 
			// server_SetMitigationStatusButtonComponent_SendButton
			// 
			this->server_SetMitigationStatusButtonComponent_SendButton->Enabled = false;
			this->server_SetMitigationStatusButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_SetMitigationStatusButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationStatusButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationStatusButtonComponent_SendButton->Location = System::Drawing::Point(491, 305);
			this->server_SetMitigationStatusButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetMitigationStatusButtonComponent_SendButton->Name = L"server_SetMitigationStatusButtonComponent_SendButton";
			this->server_SetMitigationStatusButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_SetMitigationStatusButtonComponent_SendButton->TabIndex = 201;
			this->server_SetMitigationStatusButtonComponent_SendButton->Text = L"Send";
			this->server_SetMitigationStatusButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_SetMitigationStatusButtonComponent_SendButton->Visible = false;
			this->server_SetMitigationStatusButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_SetMitigationStatusButtonComponent_SendButton_Click);
			// 
			// server_AddGAMERuleButtonComponent_InstructionLabel_ServerID
			// 
			this->server_AddGAMERuleButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddGAMERuleButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_AddGAMERuleButtonComponent_InstructionLabel_ServerID->Name = L"server_AddGAMERuleButtonComponent_InstructionLabel_ServerID";
			this->server_AddGAMERuleButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_AddGAMERuleButtonComponent_InstructionLabel_ServerID->TabIndex = 202;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_AddGAMERuleButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_AddGAMERuleButtonComponent_TextField_ServerID
			// 
			this->server_AddGAMERuleButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_AddGAMERuleButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_AddGAMERuleButtonComponent_TextField_ServerID->Enabled = false;
			this->server_AddGAMERuleButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddGAMERuleButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_AddGAMERuleButtonComponent_TextField_ServerID->Location = System::Drawing::Point(141, 142);
			this->server_AddGAMERuleButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_AddGAMERuleButtonComponent_TextField_ServerID->Multiline = false;
			this->server_AddGAMERuleButtonComponent_TextField_ServerID->Name = L"server_AddGAMERuleButtonComponent_TextField_ServerID";
			this->server_AddGAMERuleButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_AddGAMERuleButtonComponent_TextField_ServerID->TabIndex = 203;
			this->server_AddGAMERuleButtonComponent_TextField_ServerID->Text = L"";
			this->server_AddGAMERuleButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_AddGAMERuleButtonComponent_InstructionLabel_IP
			// 
			this->server_AddGAMERuleButtonComponent_InstructionLabel_IP->Enabled = false;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddGAMERuleButtonComponent_InstructionLabel_IP->ForeColor = System::Drawing::Color::White;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_IP->Location = System::Drawing::Point(139, 180);
			this->server_AddGAMERuleButtonComponent_InstructionLabel_IP->Name = L"server_AddGAMERuleButtonComponent_InstructionLabel_IP";
			this->server_AddGAMERuleButtonComponent_InstructionLabel_IP->Size = System::Drawing::Size(167, 23);
			this->server_AddGAMERuleButtonComponent_InstructionLabel_IP->TabIndex = 204;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_IP->Text = L"IP Address:";
			this->server_AddGAMERuleButtonComponent_InstructionLabel_IP->Visible = false;
			// 
			// server_AddGAMERuleButtonComponent_TextField_IP
			// 
			this->server_AddGAMERuleButtonComponent_TextField_IP->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_AddGAMERuleButtonComponent_TextField_IP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_AddGAMERuleButtonComponent_TextField_IP->Enabled = false;
			this->server_AddGAMERuleButtonComponent_TextField_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddGAMERuleButtonComponent_TextField_IP->ForeColor = System::Drawing::Color::White;
			this->server_AddGAMERuleButtonComponent_TextField_IP->Location = System::Drawing::Point(137, 206);
			this->server_AddGAMERuleButtonComponent_TextField_IP->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_AddGAMERuleButtonComponent_TextField_IP->Multiline = false;
			this->server_AddGAMERuleButtonComponent_TextField_IP->Name = L"server_AddGAMERuleButtonComponent_TextField_IP";
			this->server_AddGAMERuleButtonComponent_TextField_IP->Size = System::Drawing::Size(429, 29);
			this->server_AddGAMERuleButtonComponent_TextField_IP->TabIndex = 205;
			this->server_AddGAMERuleButtonComponent_TextField_IP->Text = L"";
			this->server_AddGAMERuleButtonComponent_TextField_IP->Visible = false;
			// 
			// server_AddGAMERuleButtonComponent_InstructionLabel_Proto
			// 
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Proto->Enabled = false;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Proto->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Proto->ForeColor = System::Drawing::Color::White;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Proto->Location = System::Drawing::Point(139, 246);
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Proto->Name = L"server_AddGAMERuleButtonComponent_InstructionLabel_Proto";
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Proto->Size = System::Drawing::Size(167, 23);
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Proto->TabIndex = 206;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Proto->Text = L"Protocol:";
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Proto->Visible = false;
			// 
			// server_AddGAMERuleButtonComponent_TextField_Proto
			// 
			this->server_AddGAMERuleButtonComponent_TextField_Proto->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_AddGAMERuleButtonComponent_TextField_Proto->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_AddGAMERuleButtonComponent_TextField_Proto->Enabled = false;
			this->server_AddGAMERuleButtonComponent_TextField_Proto->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddGAMERuleButtonComponent_TextField_Proto->ForeColor = System::Drawing::Color::White;
			this->server_AddGAMERuleButtonComponent_TextField_Proto->Location = System::Drawing::Point(139, 273);
			this->server_AddGAMERuleButtonComponent_TextField_Proto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_AddGAMERuleButtonComponent_TextField_Proto->Multiline = false;
			this->server_AddGAMERuleButtonComponent_TextField_Proto->Name = L"server_AddGAMERuleButtonComponent_TextField_Proto";
			this->server_AddGAMERuleButtonComponent_TextField_Proto->Size = System::Drawing::Size(429, 29);
			this->server_AddGAMERuleButtonComponent_TextField_Proto->TabIndex = 207;
			this->server_AddGAMERuleButtonComponent_TextField_Proto->Text = L"";
			this->server_AddGAMERuleButtonComponent_TextField_Proto->Visible = false;
			// 
			// server_AddGAMERuleButtonComponent_InstructionLabel_Port
			// 
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Port->Enabled = false;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Port->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Port->ForeColor = System::Drawing::Color::White;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Port->Location = System::Drawing::Point(139, 321);
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Port->Name = L"server_AddGAMERuleButtonComponent_InstructionLabel_Port";
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Port->Size = System::Drawing::Size(167, 23);
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Port->TabIndex = 208;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Port->Text = L"Port:";
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Port->Visible = false;
			// 
			// server_AddGAMERuleButtonComponent_TextField_Port
			// 
			this->server_AddGAMERuleButtonComponent_TextField_Port->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_AddGAMERuleButtonComponent_TextField_Port->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_AddGAMERuleButtonComponent_TextField_Port->Enabled = false;
			this->server_AddGAMERuleButtonComponent_TextField_Port->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddGAMERuleButtonComponent_TextField_Port->ForeColor = System::Drawing::Color::White;
			this->server_AddGAMERuleButtonComponent_TextField_Port->Location = System::Drawing::Point(137, 347);
			this->server_AddGAMERuleButtonComponent_TextField_Port->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_AddGAMERuleButtonComponent_TextField_Port->Multiline = false;
			this->server_AddGAMERuleButtonComponent_TextField_Port->Name = L"server_AddGAMERuleButtonComponent_TextField_Port";
			this->server_AddGAMERuleButtonComponent_TextField_Port->Size = System::Drawing::Size(429, 29);
			this->server_AddGAMERuleButtonComponent_TextField_Port->TabIndex = 209;
			this->server_AddGAMERuleButtonComponent_TextField_Port->Text = L"";
			this->server_AddGAMERuleButtonComponent_TextField_Port->Visible = false;
			// 
			// server_AddGAMERuleButtonComponent_SendButton
			// 
			this->server_AddGAMERuleButtonComponent_SendButton->Enabled = false;
			this->server_AddGAMERuleButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_AddGAMERuleButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddGAMERuleButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_AddGAMERuleButtonComponent_SendButton->Location = System::Drawing::Point(491, 382);
			this->server_AddGAMERuleButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_AddGAMERuleButtonComponent_SendButton->Name = L"server_AddGAMERuleButtonComponent_SendButton";
			this->server_AddGAMERuleButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_AddGAMERuleButtonComponent_SendButton->TabIndex = 210;
			this->server_AddGAMERuleButtonComponent_SendButton->Text = L"Send";
			this->server_AddGAMERuleButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_AddGAMERuleButtonComponent_SendButton->Visible = false;
			this->server_AddGAMERuleButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::Server_AddGAMERuleButtonComponent_SendButton_Click);
			// 
			// server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID
			// 
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID->Name = L"server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID";
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID->TabIndex = 211;
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP
			// 
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP->Enabled = false;
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP->ForeColor = System::Drawing::Color::White;
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP->Location = System::Drawing::Point(139, 180);
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP->Name = L"server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP";
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP->Size = System::Drawing::Size(167, 23);
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP->TabIndex = 212;
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP->Text = L"IP Address:";
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP->Visible = false;
			// 
			// server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle
			// 
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle->Enabled = false;
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle->ForeColor = System::Drawing::Color::White;
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle->Location = System::Drawing::Point(139, 246);
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle->Name = L"server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle";
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle->Size = System::Drawing::Size(167, 23);
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle->TabIndex = 213;
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle->Text = L"Toggle:";
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle->Visible = false;
			// 
			// server_ToggleGAMEFirewallButtonComponent_TextField_ServerID
			// 
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Enabled = false;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 142);
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Multiline = false;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Name = L"server_ToggleGAMEFirewallButtonComponent_TextField_ServerID";
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->TabIndex = 214;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Text = L"";
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_ToggleGAMEFirewallButtonComponent_TextField_IP
			// 
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Enabled = false;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->ForeColor = System::Drawing::Color::White;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Location = System::Drawing::Point(137, 204);
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Multiline = false;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Name = L"server_ToggleGAMEFirewallButtonComponent_TextField_IP";
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Size = System::Drawing::Size(429, 29);
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->TabIndex = 215;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Text = L"";
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Visible = false;
			// 
			// server_ToggleGAMEFirewallButtonComponent_TextField_Toggle
			// 
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Enabled = false;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->ForeColor = System::Drawing::Color::White;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Location = System::Drawing::Point(137, 272);
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Multiline = false;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Name = L"server_ToggleGAMEFirewallButtonComponent_TextField_Toggle";
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Size = System::Drawing::Size(429, 29);
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->TabIndex = 216;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Text = L"";
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Visible = false;
			// 
			// server_ToggleGAMEFirewallButtonComponent_SendButton
			// 
			this->server_ToggleGAMEFirewallButtonComponent_SendButton->Enabled = false;
			this->server_ToggleGAMEFirewallButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_ToggleGAMEFirewallButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_ToggleGAMEFirewallButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_ToggleGAMEFirewallButtonComponent_SendButton->Location = System::Drawing::Point(495, 305);
			this->server_ToggleGAMEFirewallButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_ToggleGAMEFirewallButtonComponent_SendButton->Name = L"server_ToggleGAMEFirewallButtonComponent_SendButton";
			this->server_ToggleGAMEFirewallButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_ToggleGAMEFirewallButtonComponent_SendButton->TabIndex = 217;
			this->server_ToggleGAMEFirewallButtonComponent_SendButton->Text = L"Send";
			this->server_ToggleGAMEFirewallButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_ToggleGAMEFirewallButtonComponent_SendButton->Visible = false;
			this->server_ToggleGAMEFirewallButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::Server_ToggleGAMEFirewallButtonComponent_SendButton_Click);
			// 
			// server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID
			// 
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(137, 116);
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID->Name = L"server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID";
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID->TabIndex = 218;
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_DeleteGAMERuleButtonComponent_TextField_ServerID
			// 
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Enabled = false;
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Location = System::Drawing::Point(137, 143);
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Multiline = false;
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Name = L"server_DeleteGAMERuleButtonComponent_TextField_ServerID";
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->TabIndex = 219;
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Text = L"";
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_DeleteGAMERuleButtonComponent_InstructionLabel_IP
			// 
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_IP->Enabled = false;
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_IP->ForeColor = System::Drawing::Color::White;
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_IP->Location = System::Drawing::Point(139, 180);
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_IP->Name = L"server_DeleteGAMERuleButtonComponent_InstructionLabel_IP";
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_IP->Size = System::Drawing::Size(167, 23);
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_IP->TabIndex = 220;
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_IP->Text = L"IP Address:";
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_IP->Visible = false;
			// 
			// server_DeleteGAMERuleButtonComponent_TextField_IP
			// 
			this->server_DeleteGAMERuleButtonComponent_TextField_IP->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_DeleteGAMERuleButtonComponent_TextField_IP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_DeleteGAMERuleButtonComponent_TextField_IP->Enabled = false;
			this->server_DeleteGAMERuleButtonComponent_TextField_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteGAMERuleButtonComponent_TextField_IP->ForeColor = System::Drawing::Color::White;
			this->server_DeleteGAMERuleButtonComponent_TextField_IP->Location = System::Drawing::Point(139, 203);
			this->server_DeleteGAMERuleButtonComponent_TextField_IP->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteGAMERuleButtonComponent_TextField_IP->Multiline = false;
			this->server_DeleteGAMERuleButtonComponent_TextField_IP->Name = L"server_DeleteGAMERuleButtonComponent_TextField_IP";
			this->server_DeleteGAMERuleButtonComponent_TextField_IP->Size = System::Drawing::Size(429, 29);
			this->server_DeleteGAMERuleButtonComponent_TextField_IP->TabIndex = 221;
			this->server_DeleteGAMERuleButtonComponent_TextField_IP->Text = L"";
			this->server_DeleteGAMERuleButtonComponent_TextField_IP->Visible = false;
			// 
			// server_DeleteGAMERuleButtonComponent_InstructionLabel_RID
			// 
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_RID->Enabled = false;
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_RID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_RID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_RID->Location = System::Drawing::Point(139, 246);
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_RID->Name = L"server_DeleteGAMERuleButtonComponent_InstructionLabel_RID";
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_RID->Size = System::Drawing::Size(167, 23);
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_RID->TabIndex = 222;
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_RID->Text = L"Rule ID:";
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_RID->Visible = false;
			// 
			// server_DeleteGAMERuleButtonComponent_TextField_RID
			// 
			this->server_DeleteGAMERuleButtonComponent_TextField_RID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_DeleteGAMERuleButtonComponent_TextField_RID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_DeleteGAMERuleButtonComponent_TextField_RID->Enabled = false;
			this->server_DeleteGAMERuleButtonComponent_TextField_RID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteGAMERuleButtonComponent_TextField_RID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteGAMERuleButtonComponent_TextField_RID->Location = System::Drawing::Point(139, 273);
			this->server_DeleteGAMERuleButtonComponent_TextField_RID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteGAMERuleButtonComponent_TextField_RID->Multiline = false;
			this->server_DeleteGAMERuleButtonComponent_TextField_RID->Name = L"server_DeleteGAMERuleButtonComponent_TextField_RID";
			this->server_DeleteGAMERuleButtonComponent_TextField_RID->Size = System::Drawing::Size(429, 29);
			this->server_DeleteGAMERuleButtonComponent_TextField_RID->TabIndex = 223;
			this->server_DeleteGAMERuleButtonComponent_TextField_RID->Text = L"";
			this->server_DeleteGAMERuleButtonComponent_TextField_RID->Visible = false;
			// 
			// server_DeleteGAMERuleButtonComponent_SendButton
			// 
			this->server_DeleteGAMERuleButtonComponent_SendButton->Enabled = false;
			this->server_DeleteGAMERuleButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_DeleteGAMERuleButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteGAMERuleButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_DeleteGAMERuleButtonComponent_SendButton->Location = System::Drawing::Point(495, 304);
			this->server_DeleteGAMERuleButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteGAMERuleButtonComponent_SendButton->Name = L"server_DeleteGAMERuleButtonComponent_SendButton";
			this->server_DeleteGAMERuleButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_DeleteGAMERuleButtonComponent_SendButton->TabIndex = 224;
			this->server_DeleteGAMERuleButtonComponent_SendButton->Text = L"Send";
			this->server_DeleteGAMERuleButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_DeleteGAMERuleButtonComponent_SendButton->Visible = false;
			this->server_DeleteGAMERuleButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::Server_DeleteGAMERuleButtonComponent_SendButton_Click);
			// 
			// server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID
			// 
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID->Name = L"server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID";
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID->TabIndex = 225;
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_SetFirewallTemplateButtonComponent_InstructionLabel_IP
			// 
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_IP->Enabled = false;
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_IP->ForeColor = System::Drawing::Color::White;
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_IP->Location = System::Drawing::Point(139, 180);
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_IP->Name = L"server_SetFirewallTemplateButtonComponent_InstructionLabel_IP";
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_IP->Size = System::Drawing::Size(167, 23);
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_IP->TabIndex = 226;
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_IP->Text = L"IP Address:";
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_IP->Visible = false;
			// 
			// server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName
			// 
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName->Enabled = false;
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName->ForeColor = System::Drawing::Color::White;
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName->Location = System::Drawing::Point(139, 247);
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName->Name = L"server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName";
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName->Size = System::Drawing::Size(167, 23);
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName->TabIndex = 227;
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName->Text = L"Template Name:";
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName->Visible = false;
			// 
			// server_SetFirewallTemplateButtonComponent_TextField_TemplateName
			// 
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Enabled = false;
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->ForeColor = System::Drawing::Color::White;
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Location = System::Drawing::Point(137, 272);
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Multiline = false;
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Name = L"server_SetFirewallTemplateButtonComponent_TextField_TemplateName";
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Size = System::Drawing::Size(429, 29);
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->TabIndex = 228;
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Text = L"";
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Visible = false;
			// 
			// server_SetFirewallTemplateButtonComponent_TextField_IP
			// 
			this->server_SetFirewallTemplateButtonComponent_TextField_IP->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetFirewallTemplateButtonComponent_TextField_IP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetFirewallTemplateButtonComponent_TextField_IP->Enabled = false;
			this->server_SetFirewallTemplateButtonComponent_TextField_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetFirewallTemplateButtonComponent_TextField_IP->ForeColor = System::Drawing::Color::White;
			this->server_SetFirewallTemplateButtonComponent_TextField_IP->Location = System::Drawing::Point(139, 204);
			this->server_SetFirewallTemplateButtonComponent_TextField_IP->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetFirewallTemplateButtonComponent_TextField_IP->Multiline = false;
			this->server_SetFirewallTemplateButtonComponent_TextField_IP->Name = L"server_SetFirewallTemplateButtonComponent_TextField_IP";
			this->server_SetFirewallTemplateButtonComponent_TextField_IP->Size = System::Drawing::Size(429, 29);
			this->server_SetFirewallTemplateButtonComponent_TextField_IP->TabIndex = 229;
			this->server_SetFirewallTemplateButtonComponent_TextField_IP->Text = L"";
			this->server_SetFirewallTemplateButtonComponent_TextField_IP->Visible = false;
			// 
			// server_SetFirewallTemplateButtonComponent_TextField_ServerID
			// 
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Enabled = false;
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Location = System::Drawing::Point(139, 143);
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Multiline = false;
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Name = L"server_SetFirewallTemplateButtonComponent_TextField_ServerID";
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->TabIndex = 230;
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Text = L"";
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_SetFirewallTemplateButtonComponent_SendButton
			// 
			this->server_SetFirewallTemplateButtonComponent_SendButton->Enabled = false;
			this->server_SetFirewallTemplateButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_SetFirewallTemplateButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetFirewallTemplateButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_SetFirewallTemplateButtonComponent_SendButton->Location = System::Drawing::Point(491, 304);
			this->server_SetFirewallTemplateButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetFirewallTemplateButtonComponent_SendButton->Name = L"server_SetFirewallTemplateButtonComponent_SendButton";
			this->server_SetFirewallTemplateButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_SetFirewallTemplateButtonComponent_SendButton->TabIndex = 231;
			this->server_SetFirewallTemplateButtonComponent_SendButton->Text = L"Send";
			this->server_SetFirewallTemplateButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_SetFirewallTemplateButtonComponent_SendButton->Visible = false;
			this->server_SetFirewallTemplateButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::server_SetFirewallTemplateButtonComponent_SendButton_Click);
			// 
			// server_AddFirewallButtonComponent_InstructionLabel_ServerID
			// 
			this->server_AddFirewallButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_AddFirewallButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddFirewallButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_AddFirewallButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 117);
			this->server_AddFirewallButtonComponent_InstructionLabel_ServerID->Name = L"server_AddFirewallButtonComponent_InstructionLabel_ServerID";
			this->server_AddFirewallButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_AddFirewallButtonComponent_InstructionLabel_ServerID->TabIndex = 232;
			this->server_AddFirewallButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_AddFirewallButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_AddFirewallButtonComponent_TextField_ServerID
			// 
			this->server_AddFirewallButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_AddFirewallButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_AddFirewallButtonComponent_TextField_ServerID->Enabled = false;
			this->server_AddFirewallButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddFirewallButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_AddFirewallButtonComponent_TextField_ServerID->Location = System::Drawing::Point(139, 143);
			this->server_AddFirewallButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_AddFirewallButtonComponent_TextField_ServerID->Multiline = false;
			this->server_AddFirewallButtonComponent_TextField_ServerID->Name = L"server_AddFirewallButtonComponent_TextField_ServerID";
			this->server_AddFirewallButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_AddFirewallButtonComponent_TextField_ServerID->TabIndex = 233;
			this->server_AddFirewallButtonComponent_TextField_ServerID->Text = L"";
			this->server_AddFirewallButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_AddFirewallButtonComponent_TextField_IP
			// 
			this->server_AddFirewallButtonComponent_TextField_IP->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_AddFirewallButtonComponent_TextField_IP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_AddFirewallButtonComponent_TextField_IP->Enabled = false;
			this->server_AddFirewallButtonComponent_TextField_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddFirewallButtonComponent_TextField_IP->ForeColor = System::Drawing::Color::White;
			this->server_AddFirewallButtonComponent_TextField_IP->Location = System::Drawing::Point(137, 206);
			this->server_AddFirewallButtonComponent_TextField_IP->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_AddFirewallButtonComponent_TextField_IP->Multiline = false;
			this->server_AddFirewallButtonComponent_TextField_IP->Name = L"server_AddFirewallButtonComponent_TextField_IP";
			this->server_AddFirewallButtonComponent_TextField_IP->Size = System::Drawing::Size(429, 29);
			this->server_AddFirewallButtonComponent_TextField_IP->TabIndex = 234;
			this->server_AddFirewallButtonComponent_TextField_IP->Text = L"";
			this->server_AddFirewallButtonComponent_TextField_IP->Visible = false;
			// 
			// server_AddFirewallButtonComponent_InstructionLabel_IP
			// 
			this->server_AddFirewallButtonComponent_InstructionLabel_IP->Enabled = false;
			this->server_AddFirewallButtonComponent_InstructionLabel_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddFirewallButtonComponent_InstructionLabel_IP->ForeColor = System::Drawing::Color::White;
			this->server_AddFirewallButtonComponent_InstructionLabel_IP->Location = System::Drawing::Point(139, 180);
			this->server_AddFirewallButtonComponent_InstructionLabel_IP->Name = L"server_AddFirewallButtonComponent_InstructionLabel_IP";
			this->server_AddFirewallButtonComponent_InstructionLabel_IP->Size = System::Drawing::Size(167, 23);
			this->server_AddFirewallButtonComponent_InstructionLabel_IP->TabIndex = 235;
			this->server_AddFirewallButtonComponent_InstructionLabel_IP->Text = L"IP Address:";
			this->server_AddFirewallButtonComponent_InstructionLabel_IP->Visible = false;
			// 
			// server_AddFirewallButtonComponent_InstructionLabel_Data
			// 
			this->server_AddFirewallButtonComponent_InstructionLabel_Data->Enabled = false;
			this->server_AddFirewallButtonComponent_InstructionLabel_Data->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddFirewallButtonComponent_InstructionLabel_Data->ForeColor = System::Drawing::Color::White;
			this->server_AddFirewallButtonComponent_InstructionLabel_Data->Location = System::Drawing::Point(139, 246);
			this->server_AddFirewallButtonComponent_InstructionLabel_Data->Name = L"server_AddFirewallButtonComponent_InstructionLabel_Data";
			this->server_AddFirewallButtonComponent_InstructionLabel_Data->Size = System::Drawing::Size(167, 23);
			this->server_AddFirewallButtonComponent_InstructionLabel_Data->TabIndex = 236;
			this->server_AddFirewallButtonComponent_InstructionLabel_Data->Text = L"Firewall Data:";
			this->server_AddFirewallButtonComponent_InstructionLabel_Data->Visible = false;
			// 
			// server_AddFirewallButtonComponent_TextField_Data
			// 
			this->server_AddFirewallButtonComponent_TextField_Data->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_AddFirewallButtonComponent_TextField_Data->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_AddFirewallButtonComponent_TextField_Data->Enabled = false;
			this->server_AddFirewallButtonComponent_TextField_Data->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddFirewallButtonComponent_TextField_Data->ForeColor = System::Drawing::Color::White;
			this->server_AddFirewallButtonComponent_TextField_Data->Location = System::Drawing::Point(135, 273);
			this->server_AddFirewallButtonComponent_TextField_Data->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_AddFirewallButtonComponent_TextField_Data->Multiline = false;
			this->server_AddFirewallButtonComponent_TextField_Data->Name = L"server_AddFirewallButtonComponent_TextField_Data";
			this->server_AddFirewallButtonComponent_TextField_Data->Size = System::Drawing::Size(429, 29);
			this->server_AddFirewallButtonComponent_TextField_Data->TabIndex = 237;
			this->server_AddFirewallButtonComponent_TextField_Data->Text = L"";
			this->server_AddFirewallButtonComponent_TextField_Data->Visible = false;
			// 
			// server_AddFirewallButtonComponent_SendButton
			// 
			this->server_AddFirewallButtonComponent_SendButton->Enabled = false;
			this->server_AddFirewallButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_AddFirewallButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_AddFirewallButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_AddFirewallButtonComponent_SendButton->Location = System::Drawing::Point(491, 304);
			this->server_AddFirewallButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_AddFirewallButtonComponent_SendButton->Name = L"server_AddFirewallButtonComponent_SendButton";
			this->server_AddFirewallButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_AddFirewallButtonComponent_SendButton->TabIndex = 238;
			this->server_AddFirewallButtonComponent_SendButton->Text = L"Send";
			this->server_AddFirewallButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_AddFirewallButtonComponent_SendButton->Visible = false;
			this->server_AddFirewallButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::Server_AddFirewallButtonComponent_SendButton_Click);
			// 
			// server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID
			// 
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 117);
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID->Name = L"server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID";
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID->TabIndex = 239;
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID
			// 
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Enabled = false;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Location = System::Drawing::Point(136, 143);
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Multiline = false;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Name = L"server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID";
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->TabIndex = 240;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Text = L"";
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP
			// 
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP->Enabled = false;
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP->ForeColor = System::Drawing::Color::White;
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP->Location = System::Drawing::Point(139, 180);
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP->Name = L"server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP";
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP->Size = System::Drawing::Size(167, 23);
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP->TabIndex = 241;
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP->Text = L"IP Address:";
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP->Visible = false;
			// 
			// server_DeleteFirewallIPRuleButtonComponent_TextField_IP
			// 
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Enabled = false;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->ForeColor = System::Drawing::Color::White;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Location = System::Drawing::Point(139, 203);
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Multiline = false;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Name = L"server_DeleteFirewallIPRuleButtonComponent_TextField_IP";
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Size = System::Drawing::Size(429, 29);
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->TabIndex = 242;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Text = L"";
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Visible = false;
			// 
			// server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID
			// 
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID->Enabled = false;
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID->Location = System::Drawing::Point(139, 246);
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID->Name = L"server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID";
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID->Size = System::Drawing::Size(167, 23);
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID->TabIndex = 243;
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID->Text = L"Rule ID:";
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID->Visible = false;
			// 
			// server_DeleteFirewallIPRuleButtonComponent_TextField_RID
			// 
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Enabled = false;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->ForeColor = System::Drawing::Color::White;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Location = System::Drawing::Point(135, 273);
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Multiline = false;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Name = L"server_DeleteFirewallIPRuleButtonComponent_TextField_RID";
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Size = System::Drawing::Size(429, 29);
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->TabIndex = 244;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Text = L"";
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Visible = false;
			// 
			// server_DeleteFirewallIPRuleButtonComponent_SendButton
			// 
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton->Enabled = false;
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton->Location = System::Drawing::Point(492, 309);
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton->Name = L"server_DeleteFirewallIPRuleButtonComponent_SendButton";
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton->TabIndex = 245;
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton->Text = L"Send";
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton->Visible = false;
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::Server_DeleteFirewallIPRuleButtonComponent_SendButton_Click);
			// 
			// server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID
			// 
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID->Enabled = false;
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID->Location = System::Drawing::Point(139, 116);
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID->Name = L"server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID";
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID->Size = System::Drawing::Size(167, 23);
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID->TabIndex = 246;
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID->Text = L"Server ID:";
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID->Visible = false;
			// 
			// server_SetMitigationTimeoutButtonComponent_TextField_ServerID
			// 
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Enabled = false;
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Location = System::Drawing::Point(135, 143);
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Multiline = false;
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Name = L"server_SetMitigationTimeoutButtonComponent_TextField_ServerID";
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Size = System::Drawing::Size(429, 29);
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->TabIndex = 247;
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Text = L"";
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Visible = false;
			// 
			// server_SetMitigationTimeoutButtonComponent_TextField_IP
			// 
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP->Enabled = false;
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP->Location = System::Drawing::Point(135, 204);
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP->Multiline = false;
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP->Name = L"server_SetMitigationTimeoutButtonComponent_TextField_IP";
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP->Size = System::Drawing::Size(429, 29);
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP->TabIndex = 249;
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP->Text = L"";
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP->Visible = false;
			// 
			// server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout
			// 
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout->Enabled = false;
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout->Location = System::Drawing::Point(139, 247);
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout->Name = L"server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout";
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout->Size = System::Drawing::Size(167, 23);
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout->TabIndex = 250;
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout->Text = L"Timeout:";
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout->Visible = false;
			// 
			// server_SetMitigationTimeoutButtonComponent_TextField_Timeout
			// 
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Enabled = false;
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Location = System::Drawing::Point(135, 272);
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Multiline = false;
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Name = L"server_SetMitigationTimeoutButtonComponent_TextField_Timeout";
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Size = System::Drawing::Size(429, 29);
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->TabIndex = 251;
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Text = L"";
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Visible = false;
			// 
			// server_SetMitigationTimeoutButtonComponent_SendButton
			// 
			this->server_SetMitigationTimeoutButtonComponent_SendButton->Enabled = false;
			this->server_SetMitigationTimeoutButtonComponent_SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->server_SetMitigationTimeoutButtonComponent_SendButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationTimeoutButtonComponent_SendButton->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationTimeoutButtonComponent_SendButton->Location = System::Drawing::Point(491, 309);
			this->server_SetMitigationTimeoutButtonComponent_SendButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->server_SetMitigationTimeoutButtonComponent_SendButton->Name = L"server_SetMitigationTimeoutButtonComponent_SendButton";
			this->server_SetMitigationTimeoutButtonComponent_SendButton->Size = System::Drawing::Size(75, 23);
			this->server_SetMitigationTimeoutButtonComponent_SendButton->TabIndex = 252;
			this->server_SetMitigationTimeoutButtonComponent_SendButton->Text = L"Send";
			this->server_SetMitigationTimeoutButtonComponent_SendButton->UseVisualStyleBackColor = true;
			this->server_SetMitigationTimeoutButtonComponent_SendButton->Visible = false;
			this->server_SetMitigationTimeoutButtonComponent_SendButton->Click += gcnew System::EventHandler(this, &main_form::Server_SetMitigationTimeoutButtonComponent_SendButton_Click);
			// 
			// server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP
			// 
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP->Enabled = false;
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP->Font = (gcnew System::Drawing::Font(L"Calibri", 11));
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP->ForeColor = System::Drawing::Color::White;
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP->Location = System::Drawing::Point(139, 180);
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP->Name = L"server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP";
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP->Size = System::Drawing::Size(167, 23);
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP->TabIndex = 248;
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP->Text = L"IP Address:";
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP->Visible = false;
			// 
			// main_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->ClientSize = System::Drawing::Size(1084, 556);
			this->Controls->Add(this->server_SetMitigationTimeoutButtonComponent_SendButton);
			this->Controls->Add(this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout);
			this->Controls->Add(this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout);
			this->Controls->Add(this->server_SetMitigationTimeoutButtonComponent_TextField_IP);
			this->Controls->Add(this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP);
			this->Controls->Add(this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_DeleteFirewallIPRuleButtonComponent_SendButton);
			this->Controls->Add(this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID);
			this->Controls->Add(this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID);
			this->Controls->Add(this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP);
			this->Controls->Add(this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP);
			this->Controls->Add(this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_AddFirewallButtonComponent_SendButton);
			this->Controls->Add(this->server_AddFirewallButtonComponent_TextField_Data);
			this->Controls->Add(this->server_AddFirewallButtonComponent_InstructionLabel_Data);
			this->Controls->Add(this->server_AddFirewallButtonComponent_InstructionLabel_IP);
			this->Controls->Add(this->server_AddFirewallButtonComponent_TextField_IP);
			this->Controls->Add(this->server_AddFirewallButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_AddFirewallButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_SetFirewallTemplateButtonComponent_SendButton);
			this->Controls->Add(this->server_SetFirewallTemplateButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_SetFirewallTemplateButtonComponent_TextField_IP);
			this->Controls->Add(this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName);
			this->Controls->Add(this->server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName);
			this->Controls->Add(this->server_SetFirewallTemplateButtonComponent_InstructionLabel_IP);
			this->Controls->Add(this->server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_DeleteGAMERuleButtonComponent_SendButton);
			this->Controls->Add(this->server_DeleteGAMERuleButtonComponent_TextField_RID);
			this->Controls->Add(this->server_DeleteGAMERuleButtonComponent_InstructionLabel_RID);
			this->Controls->Add(this->server_DeleteGAMERuleButtonComponent_TextField_IP);
			this->Controls->Add(this->server_DeleteGAMERuleButtonComponent_InstructionLabel_IP);
			this->Controls->Add(this->server_DeleteGAMERuleButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_ToggleGAMEFirewallButtonComponent_SendButton);
			this->Controls->Add(this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle);
			this->Controls->Add(this->server_ToggleGAMEFirewallButtonComponent_TextField_IP);
			this->Controls->Add(this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle);
			this->Controls->Add(this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP);
			this->Controls->Add(this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_AddGAMERuleButtonComponent_SendButton);
			this->Controls->Add(this->server_AddGAMERuleButtonComponent_TextField_Port);
			this->Controls->Add(this->server_AddGAMERuleButtonComponent_InstructionLabel_Port);
			this->Controls->Add(this->server_AddGAMERuleButtonComponent_TextField_Proto);
			this->Controls->Add(this->server_AddGAMERuleButtonComponent_InstructionLabel_Proto);
			this->Controls->Add(this->server_AddGAMERuleButtonComponent_TextField_IP);
			this->Controls->Add(this->server_AddGAMERuleButtonComponent_InstructionLabel_IP);
			this->Controls->Add(this->server_AddGAMERuleButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_AddGAMERuleButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_SetMitigationStatusButtonComponent_SendButton);
			this->Controls->Add(this->server_SetMitigationStatusButtonComponent_TextField_Toggle);
			this->Controls->Add(this->server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle);
			this->Controls->Add(this->server_SetMitigationStatusButtonComponent_TextField_IP);
			this->Controls->Add(this->server_SetMitigationStatusButtonComponent_InstructionLabel_IP);
			this->Controls->Add(this->server_SetMitigationStatusButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_GetMitigationStatusButtonComponent_SendButton);
			this->Controls->Add(this->server_GetMitigationStatusButtonComponent_TextField_IP);
			this->Controls->Add(this->server_GetMitigationStatusButtonComponent_InstructionLabel_IP);
			this->Controls->Add(this->server_GetMitigationStatusButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_GetIPRulesButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_GetIPInfoButtonComponent_Instructionlabel_ServerID);
			this->Controls->Add(this->server_IndependentComponentShowIPs);
			this->Controls->Add(this->server_GetIPRulesButtonComponent_SendButton);
			this->Controls->Add(this->server_GetIPRulesButtonComponent_TextField_IP);
			this->Controls->Add(this->server_GetIPRulesButtonComponent_InstructionLabel_IP);
			this->Controls->Add(this->server_GetIPRulesButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_IndependentComponentShowIPs_RightPos);
			this->Controls->Add(this->server_SetIPrDNSButtonComponent_SendButton);
			this->Controls->Add(this->server_SetIPrDNSButtonComponent_TextField_rDNS);
			this->Controls->Add(this->server_SetIPrDNSButtonComponent_InstructionLabel_rDNS);
			this->Controls->Add(this->server_SetIPrDNSButtonComponent_TextField_IP);
			this->Controls->Add(this->server_SetIPrDNSButtonComponent_InstructionLabel_IP);
			this->Controls->Add(this->server_SetIPrDNSButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_SetIPrDNSButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_DeleteFirewallRuleButtonComponent_SendButton);
			this->Controls->Add(this->server_DeleteFirewallRuleButtonComponent_TextField_RID);
			this->Controls->Add(this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID);
			this->Controls->Add(this->server_AddFirewallRuleButtonComponent_SendButton);
			this->Controls->Add(this->server_AddFirewallRuleButtonComponent_TextField_Data);
			this->Controls->Add(this->server_AddFirewallRuleButtonComponent_InstructionLabel_Data);
			this->Controls->Add(this->server_AddFirewallRuleButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_ToggleFirewallRuleButtonComponent_SendButton);
			this->Controls->Add(this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle);
			this->Controls->Add(this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle);
			this->Controls->Add(this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_GetFirewallRulesButtonComponent_SendButton);
			this->Controls->Add(this->server_GetFirewallRulesButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_SetBootOrderButtonComponent_SendButton);
			this->Controls->Add(this->server_SetBootOrderButtonComponent_TextField_BootOrder);
			this->Controls->Add(this->server_SetBootOrderButtonComponent_InstructionLabel_BootOrder);
			this->Controls->Add(this->server_SetBootOrderButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_SetBootOrderButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_GetVNCInfoTFButtonComponent_SendButton);
			this->Controls->Add(this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame);
			this->Controls->Add(this->server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame);
			this->Controls->Add(this->server_GetVNCInfoTFButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_GetIPInfoButtonComponent_SendButton);
			this->Controls->Add(this->server_GetIPInfoButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_RebuildButtonComponent_SendButton);
			this->Controls->Add(this->server_RebuildButtonComponent_TextField_NewOS);
			this->Controls->Add(this->server_RebuildButtonComponent_InstructionLabel_NewOS);
			this->Controls->Add(this->server_RebuildButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_RebuildButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_SetHostnameButtonComponent_TextField_Hostname);
			this->Controls->Add(this->server_SetHostnameButtonComponent_InstructionLabel_Hostname);
			this->Controls->Add(this->server_SetHostnameButtonComponent_SendButton);
			this->Controls->Add(this->server_SetHostnameButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_SetHostnameButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_ResetPasswordButtonComponent_SendButton);
			this->Controls->Add(this->server_ResetPasswordButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_ResetPasswordButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_SelectISOButtonComponent_SendButton);
			this->Controls->Add(this->server_SelectISOButtonComponent_TextField_SecondFile);
			this->Controls->Add(this->server_SelectISOButtonComponent_InstructionLabel_SecondFile);
			this->Controls->Add(this->server_SelectISOButtonComponent_TextField_FirstFile);
			this->Controls->Add(this->server_SelectISOButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_SelectISOButtonComponent_InstructionLabel_FirstFile);
			this->Controls->Add(this->server_SelectISOButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_GetBandwidthButtonComponent_SendButton);
			this->Controls->Add(this->server_GetBandwidthButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_GetBandwidthButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_DeleteBackupButtonComponent_SendButton);
			this->Controls->Add(this->server_DeleteBackupButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_DeleteBackupButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_IndependentComponentShowIDs_RightPos);
			this->Controls->Add(this->server_MakeBackupButtonComponent_SendButton);
			this->Controls->Add(this->server_MakeBackupButtonComponent_TextField_UseSSL);
			this->Controls->Add(this->server_MakeBackupButtonComponent_InstructionLabel_UseSSL);
			this->Controls->Add(this->server_MakeBackupButtonComponent_TextField_Rotation);
			this->Controls->Add(this->server_MakeBackupButtonComponent_InstructionLabel_Rotation);
			this->Controls->Add(this->server_MakeBackupButtonComponent_TextField_Password);
			this->Controls->Add(this->server_MakeBackupButtonComponent_InstructionLabel_Password);
			this->Controls->Add(this->server_MakeBackupButtonComponent_TextField_Port);
			this->Controls->Add(this->server_MakeBackupButtonComponent_InstructionLabel_Port);
			this->Controls->Add(this->server_MakeBackupButtonComponent_TextField_Hostname);
			this->Controls->Add(this->server_MakeBackupButtonComponent_InstructionLabel_Hostname);
			this->Controls->Add(this->server_MakeBackupButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_MakeBackupButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_GetBackupInfoButtonComponent_SendButton);
			this->Controls->Add(this->server_GetBackupInfoButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_GetBackupInfoButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_GetVNCinfoButtonComponent_SendButton);
			this->Controls->Add(this->server_GetVNCInfoButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_GetVNCInfoButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_RenewServerButtonComponent_SendButton);
			this->Controls->Add(this->server_RenewServerButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_RenewServerButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_ForceStopServerButtonComponent_SendButton);
			this->Controls->Add(this->server_ForceStopServerButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_ForceStopServerButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_ShutdownServerButtonComponent_SendButton);
			this->Controls->Add(this->server_ShutdownServerButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_ShutdownServerButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_RestartServerButtonComponent_SendButton);
			this->Controls->Add(this->server_RestartServerButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_RestartServerButtonComponent_Instructionlabel_ServerID);
			this->Controls->Add(this->server_PowerOnServerButtonComponent_SendButton);
			this->Controls->Add(this->server_PowerOnServerButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_PowerOnServerButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_GetMediaInfoButtonComponent_SendButton);
			this->Controls->Add(this->server_GetMediaInfoButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_GetMediaInfoButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_GetExpireInfoButtonComponent_SendButton);
			this->Controls->Add(this->server_GetExpireInfoButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_GetExpireInfoButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_DeleteByIDButtonComponent_SendButton);
			this->Controls->Add(this->server_DeleteByIDButtonComponent_TextField_ServerID);
			this->Controls->Add(this->server_DeleteByIDButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_IndependentComponentShowIDs);
			this->Controls->Add(this->server_GetInfoButtonComponent_SendButton);
			this->Controls->Add(this->server_GetInfoButtonComponent_InstructionLabel_ServerID);
			this->Controls->Add(this->server_GetInfoButtonComponent_TextField_ServerID);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_SaveButton);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_InstructionLabel_Password);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_TextField_Password);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_TextField_Email);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_InstructionLabel_Email);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_InstructionLabel_City);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_TextField_City);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_TextField_Address);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_InstructionLabel_Address);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_TextField_State);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_InstructionLabel_State);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_TextField_Country);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_InstructionLabel_Country);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_InstructionLabel_LastName);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_TextField_LastName);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_TextField_FirstName);
			this->Controls->Add(this->billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName);
			this->Controls->Add(this->billing_ReplyToTicketButtonComponent_InstructionLabel_Message);
			this->Controls->Add(this->billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID);
			this->Controls->Add(this->billing_ReplyToTicketButtonComponent_SendButton);
			this->Controls->Add(this->billing_ReplyToTicketButtonComponent_TextField_Message);
			this->Controls->Add(this->billing_ReplyToTicketButtonComponent_TextField_TicketID);
			this->Controls->Add(this->billing_OpenNewTicketButtonComponent_InstructionLabel_Department);
			this->Controls->Add(this->billing_OpenNewTicketButtonComponent_InstructionLabel_Priority);
			this->Controls->Add(this->billing_OpenNewTicketButtonComponent_InstructionLabel_Subject);
			this->Controls->Add(this->billing_OpenNewTicketButtonComponent_InstructionLabel_Message);
			this->Controls->Add(this->billing_OpenNewTicketButtonComponent_SendButton);
			this->Controls->Add(this->billing_OpenNewTicketButtonComponent_TextField_Message);
			this->Controls->Add(this->billing_OpenNewTicketButtonComponent_TextField_Department);
			this->Controls->Add(this->billing_OpenNewTicketButtonComponent_TextField_Priority);
			this->Controls->Add(this->billing_OpenNewTicketButtonComponent_TextField_Subject);
			this->Controls->Add(this->billing_CloseTicketByIDButtonComponent_TextField);
			this->Controls->Add(this->billing_CloseTicketByIDButtonComponent_SendButton);
			this->Controls->Add(this->billing_CloseTicketByIDButtonComponent_InstructionLabel);
			this->Controls->Add(this->billing_GetPromoInfoButtonComponent_InstructionLabel);
			this->Controls->Add(this->billing_GetPromoInfoButtonComponent_SendButton);
			this->Controls->Add(this->billing_GetPromoInfoButtonComponent_TextField);
			this->Controls->Add(this->billing_GetTicketByIDButtonComponent_SendButton);
			this->Controls->Add(this->billing_GetTicketByIDButtonComponent_InstructionLabel);
			this->Controls->Add(this->billing_GetTicketByIDButtonComponent_TextField);
			this->Controls->Add(this->billing_GetInvoiceByIDComponent_InstructionLabel);
			this->Controls->Add(this->billing_GetInvoiceByIDComponent_SendButton);
			this->Controls->Add(this->billing_GetInvoiceByIDButtonComponent_TextField);
			this->Controls->Add(this->settings_ServerIPResetButton);
			this->Controls->Add(this->settings_ServerIPSaveButton);
			this->Controls->Add(this->settings_ServerIPInputField);
			this->Controls->Add(this->settings_ServerIPInstructionLabel);
			this->Controls->Add(this->settings_ServerIDResetButton);
			this->Controls->Add(this->settings_ServerIDSaveButton);
			this->Controls->Add(this->settings_ServerIDInputField);
			this->Controls->Add(this->settings_ServerIDInstructionlabel);
			this->Controls->Add(this->settings_SaveChangedKeyButton);
			this->Controls->Add(this->settings_ApiInstructionLabel);
			this->Controls->Add(this->settings_ChangeApiKeyInputField);
			this->Controls->Add(this->fthApiInputExtendedBanner);
			this->Controls->Add(this->apiKeySaveButton);
			this->Controls->Add(this->apiInstructionLabel);
			this->Controls->Add(this->apiKeyInputField);
			this->Controls->Add(this->ribbonHoriPanel);
			this->Controls->Add(this->ribbonVertPanel);
			this->Controls->Add(this->responseOutputField);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"main_form";
			this->Text = L"FTH Manager";
			this->Load += gcnew System::EventHandler(this, &main_form::main_form_Load);
			this->ribbonHoriPanel->ResumeLayout(false);
			this->ribbonVertPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
		public: System::Void main_form_Load(System::Object^ sender, System::EventArgs^ e) { // check for API Key upon init
			if (configuration::keyFileCheck() == FILE_OK) {
				configuration::getAPIKey(apiKey);
				this->serverButton_Click(this, EventArgs::Empty); // open with Server tab open by default
			}
			else if (configuration::keyFileCheck() == FILE_EMPTY) {
				initApiKeyGUI();
			}
		}
		public: System::Void apiKeySaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
			if (System::String::IsNullOrEmpty(this->apiKeyInputField->Text)) {
				MessageBox::Show("Please enter your given FTH API key!", "Notice");
			}
			else {
				File::WriteAllText(KEYFILEPATH, this->apiKeyInputField->Text);
				configuration::getAPIKey(apiKey);
				deinitApiKeyGUI();
			}
		}










		// SERVER oriented functions below - this whole section is gonna take up at least 2000 lines
		public: System::Void serverButton_Click(System::Object^ sender, System::EventArgs^ e) {
			if (configuration::keyFileCheck() == FILE_EMPTY) {
				MessageBox::Show("API key not detected. Be sure to submit your FTH supplied API key before attempting to use other sections of the application.", "Notice");
			}
			else {
				functionDeinitHandler(selectedFunction, this);
				apiDeinitHandler(this->selectedGUI, this);
				this->selectedGUI = GUI_SERVER;
				this->selectedPage = 1;
				initServerTabGUI();
			}
		}
		public: System::Void server_NextPageButton_Click(System::Object^ sender, System::EventArgs^ e) {			
			if (selectedPage == 3) { // no overflowing past max. page
				// do nothing
			}
			else {
				this->selectedPage += 1;
				this->responseOutputField->Text = "";
				functionDeinitHandler(selectedFunction, this);
				pageSwitchHandler(selectedPage, this);
			}
		}
		public: System::Void server_PrevPageButton_Click(System::Object^ sender, System::EventArgs^ e) {
			if (selectedPage == 1) { // no overflowing past min. page
				// do nothing
			}
			else {
				this->selectedPage -= 1;
				this->responseOutputField->Text = "";
				functionDeinitHandler(selectedFunction, this);
				pageSwitchHandler(selectedPage, this);
			}
		}
		public: System::Void server_IndependentComponentShowIDs_Click(System::Object^ sender, System::EventArgs^ e) {
			configuration::printServerIDs();
		}
		public: System::Void server_IndependentComponentShowIDs_RightPos_Click(System::Object^ sender, System::EventArgs^ e) { // same as above, but right-aligned
			configuration::printServerIDs();
		}
		public: System::Void server_IndependentComponentShowIPs_Click(System::Object^ sender, System::EventArgs^ e) {
			configuration::printServerIPs();
		}
		public: System::Void server_IndependentComponentShowIPs_RightPos_Click(System::Object^ sender, System::EventArgs^ e) { // same as above, but right-aligned
			configuration::printServerIPs();
		}
		public: System::Void server_GetInfoButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_INFO_REQUEST;
			this->server_GetInfoButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_GetInfoButtonComponent_TextField_ServerID->Visible = true;
			this->server_GetInfoButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_GetInfoButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_GetInfoButtonComponent_TextField_ServerID->Enabled = true;
			this->server_GetInfoButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs->Enabled = true;
		} 	public: System::Void server_GetInfoButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				this->responseOutputField->Text = "";
				this->responseOutputField->Text = request::performRequest(GET, apiKey, "server/" + this->server_GetInfoButtonComponent_TextField_ServerID->Text);
				this->server_GetInfoButtonComponent_TextField_ServerID->Text = "";
				functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
			}
		public: System::Void server_DeleteByIDButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_DELETE_REQUEST;
			this->server_DeleteByIDButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_DeleteByIDButtonComponent_TextField_ServerID->Visible = true;
			this->server_DeleteByIDButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_DeleteByIDButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_DeleteByIDButtonComponent_TextField_ServerID->Enabled = true;
			this->server_DeleteByIDButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs->Enabled = true;
		} 	public: System::Void server_DeleteByIDButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_DeleteByIDButtonComponent_TextField_ServerID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(DELETE, apiKey, "server/" + this->server_DeleteByIDButtonComponent_TextField_ServerID->Text);
					this->server_DeleteByIDButtonComponent_TextField_ServerID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void server_GetExpireInfoButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_EXPIREINFO_REQUEST;
			this->server_GetExpireInfoButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_GetExpireInfoButtonComponent_TextField_ServerID->Visible = true;
			this->server_GetExpireInfoButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_GetExpireInfoButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_GetExpireInfoButtonComponent_TextField_ServerID->Enabled = true;
			this->server_GetExpireInfoButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs->Enabled = true;
		} 	public: System::Void server_GetExpireInfoButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_GetExpireInfoButtonComponent_TextField_ServerID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(GET, apiKey, "server/" + this->server_GetExpireInfoButtonComponent_TextField_ServerID->Text + "/expiration");
					this->server_GetExpireInfoButtonComponent_TextField_ServerID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void server_GetMediaInfoButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_MEDIAINFO_REQUEST;
			this->server_GetMediaInfoButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_GetMediaInfoButtonComponent_TextField_ServerID->Visible = true;
			this->server_GetMediaInfoButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_IndependentComponentShowIDs->Enabled = true;
			this->server_GetMediaInfoButtonComponent_TextField_ServerID->Enabled = true;
			this->server_GetMediaInfoButtonComponent_SendButton->Enabled = true;
			this->server_GetMediaInfoButtonComponent_InstructionLabel_ServerID->Enabled = true;
		} 	public: System::Void server_GetMediaInfoButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_GetMediaInfoButtonComponent_TextField_ServerID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(GET, apiKey, "server/" + this->server_GetMediaInfoButtonComponent_TextField_ServerID->Text + "/media");
					this->server_GetMediaInfoButtonComponent_TextField_ServerID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void server_PowerOnServerButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_POWERON_REQUEST;
			this->server_PowerOnServerButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_PowerOnServerButtonComponent_TextField_ServerID->Visible = true;
			this->server_PowerOnServerButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_PowerOnServerButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_PowerOnServerButtonComponent_TextField_ServerID->Enabled = true;
			this->server_PowerOnServerButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs->Enabled = true;
		}	public: System::Void server_PowerOnServerButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_PowerOnServerButtonComponent_TextField_ServerID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(POST, apiKey, "server/" + this->server_PowerOnServerButtonComponent_TextField_ServerID->Text + "/start");
					this->server_PowerOnServerButtonComponent_TextField_ServerID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void server_RestartServerButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_REBOOT_REQUEST;
			this->server_RestartServerButtonComponent_Instructionlabel_ServerID->Visible = true;
			this->server_RestartServerButtonComponent_TextField_ServerID->Visible = true;
			this->server_RestartServerButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_RestartServerButtonComponent_Instructionlabel_ServerID->Enabled = true;
			this->server_RestartServerButtonComponent_TextField_ServerID->Enabled = true;
			this->server_RestartServerButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs->Enabled = true;
		}	public: System::Void server_RestartServerButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_RestartServerButtonComponent_TextField_ServerID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(POST, apiKey, "server/" + this->server_RestartServerButtonComponent_TextField_ServerID->Text + "/restart");
					this->server_RestartServerButtonComponent_TextField_ServerID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void server_ShutdownServerButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_SHUTDOWN_REQUEST;
			this->server_ShutdownServerButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_ShutdownServerButtonComponent_TextField_ServerID->Visible = true;
			this->server_ShutdownServerButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_ShutdownServerButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_ShutdownServerButtonComponent_TextField_ServerID->Enabled = true;
			this->server_ShutdownServerButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs->Enabled = true;
		}	public: System::Void server_ShutdownServerButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_ShutdownServerButtonComponent_TextField_ServerID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(POST, apiKey, "server/" + this->server_ShutdownServerButtonComponent_TextField_ServerID->Text + "/shutdown");
					this->server_ShutdownServerButtonComponent_TextField_ServerID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void server_ForceStopServerButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_FORCESTOP_REQUEST;
			this->server_ForceStopServerButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_ForceStopServerButtonComponent_TextField_ServerID->Visible = true;
			this->server_ForceStopServerButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_ForceStopServerButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_ForceStopServerButtonComponent_TextField_ServerID->Enabled = true;
			this->server_ForceStopServerButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs->Enabled = true;
		}	public: System::Void server_ForceStopServerButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_ForceStopServerButtonComponent_TextField_ServerID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(POST, apiKey, "server/" + this->server_ForceStopServerButtonComponent_TextField_ServerID->Text + "/stop");
					this->server_ForceStopServerButtonComponent_TextField_ServerID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void server_RenewServerButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_RENEW_REQUEST;
			this->server_RenewServerButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_RenewServerButtonComponent_TextField_ServerID->Visible = true;
			this->server_RenewServerButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_RenewServerButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_RenewServerButtonComponent_TextField_ServerID->Enabled = true;
			this->server_RenewServerButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs->Enabled = true;
		}	public: System::Void server_RenewServerButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_RenewServerButtonComponent_TextField_ServerID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(POST, apiKey, "server/" + this->server_RenewServerButtonComponent_TextField_ServerID->Text + "/renew");
					this->server_RenewServerButtonComponent_TextField_ServerID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send	
				}
			}
		public: System::Void server_GetVNCInfoButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_VNCINFO_REQUEST;
			this->server_GetVNCInfoButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_GetVNCInfoButtonComponent_TextField_ServerID->Visible = true;
			this->server_GetVNCinfoButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_GetVNCInfoButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_GetVNCInfoButtonComponent_TextField_ServerID->Enabled = true;
			this->server_GetVNCinfoButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs->Enabled = true;
		}	public: System::Void server_GetVNCinfoButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_GetVNCInfoButtonComponent_TextField_ServerID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(GET, apiKey, "server/" + this->server_GetVNCInfoButtonComponent_TextField_ServerID->Text + "/vnc");
					this->server_GetVNCInfoButtonComponent_TextField_ServerID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send	
				}
			}
		public: System::Void server_GetBackupInfoButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_BACKUPINFO_REQUEST;
			this->server_GetBackupInfoButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_GetBackupInfoButtonComponent_TextField_ServerID->Visible = true;
			this->server_GetBackupInfoButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_GetBackupInfoButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_GetBackupInfoButtonComponent_TextField_ServerID->Enabled = true;
			this->server_GetBackupInfoButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs->Enabled = true;
		}	public: System::Void server_GetBackupInfoButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_GetBackupInfoButtonComponent_TextField_ServerID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(GET, apiKey, "server/" + this->server_GetBackupInfoButtonComponent_TextField_ServerID->Text + "/backup");
					this->server_GetBackupInfoButtonComponent_TextField_ServerID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send	
				}				
			}
		public: System::Void server_MakeBackupButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_BACKUP_REQUEST;
			this->server_MakeBackupButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_MakeBackupButtonComponent_TextField_ServerID->Visible = true;
			this->server_MakeBackupButtonComponent_InstructionLabel_Hostname->Visible = true;
			this->server_MakeBackupButtonComponent_TextField_Hostname->Visible = true;
			this->server_MakeBackupButtonComponent_InstructionLabel_Port->Visible = true;
			this->server_MakeBackupButtonComponent_TextField_Port->Visible = true;
			this->server_MakeBackupButtonComponent_InstructionLabel_Password->Visible = true;
			this->server_MakeBackupButtonComponent_TextField_Password->Visible = true;
			this->server_MakeBackupButtonComponent_InstructionLabel_Rotation->Visible = true;
			this->server_MakeBackupButtonComponent_TextField_Rotation->Visible = true;
			this->server_MakeBackupButtonComponent_InstructionLabel_UseSSL->Visible = true;
			this->server_MakeBackupButtonComponent_TextField_UseSSL->Visible = true;
			this->server_MakeBackupButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;

			this->server_MakeBackupButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_MakeBackupButtonComponent_TextField_ServerID->Enabled = true;
			this->server_MakeBackupButtonComponent_InstructionLabel_Hostname->Enabled = true;
			this->server_MakeBackupButtonComponent_TextField_Hostname->Enabled = true;
			this->server_MakeBackupButtonComponent_InstructionLabel_Port->Enabled = true;
			this->server_MakeBackupButtonComponent_TextField_Port->Enabled = true;
			this->server_MakeBackupButtonComponent_InstructionLabel_Password->Enabled = true;
			this->server_MakeBackupButtonComponent_TextField_Password->Enabled = true;
			this->server_MakeBackupButtonComponent_InstructionLabel_Rotation->Enabled = true;
			this->server_MakeBackupButtonComponent_TextField_Rotation->Enabled = true;
			this->server_MakeBackupButtonComponent_InstructionLabel_UseSSL->Enabled = true;
			this->server_MakeBackupButtonComponent_TextField_UseSSL->Enabled = true;
			this->server_MakeBackupButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
		} 	public: System::Void server_MakeBackupButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_MakeBackupButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_MakeBackupButtonComponent_TextField_Hostname->Text)
					|| String::IsNullOrEmpty(this->server_MakeBackupButtonComponent_TextField_Port->Text) || String::IsNullOrEmpty(this->server_MakeBackupButtonComponent_TextField_Password->Text)
					|| String::IsNullOrEmpty(this->server_MakeBackupButtonComponent_TextField_Rotation->Text) || String::IsNullOrEmpty(this->server_MakeBackupButtonComponent_TextField_UseSSL->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(PUT, apiKey, "server/" + this->server_MakeBackupButtonComponent_TextField_ServerID->Text + "/backup", "host=" + this->server_MakeBackupButtonComponent_TextField_Hostname->Text
						+ "&port=" + this->server_MakeBackupButtonComponent_TextField_Port->Text
						+ "&pass=" + this->server_MakeBackupButtonComponent_TextField_Password->Text
						+ "&rotation=" + this->server_MakeBackupButtonComponent_TextField_Rotation->Text
						+ "&ssl=" + this->server_MakeBackupButtonComponent_TextField_UseSSL->Text);
					this->server_MakeBackupButtonComponent_TextField_ServerID->Text = "";
					this->server_MakeBackupButtonComponent_TextField_Hostname->Text = "";
					this->server_MakeBackupButtonComponent_TextField_Port->Text = "";
					this->server_MakeBackupButtonComponent_TextField_Password->Text = "";
					this->server_MakeBackupButtonComponent_TextField_Rotation->Text = "";
					this->server_MakeBackupButtonComponent_TextField_UseSSL->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send	
				}				
			}
		public: System::Void server_DeleteBackupButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_DELETEBACKUP_REQUEST;
			this->server_DeleteBackupButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_DeleteBackupButtonComponent_TextField_ServerID->Visible = true;
			this->server_DeleteBackupButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_DeleteBackupButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_DeleteBackupButtonComponent_TextField_ServerID->Enabled = true;
			this->server_DeleteBackupButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs->Enabled = true;
		}	public: System::Void server_DeleteBackupButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_DeleteBackupButtonComponent_TextField_ServerID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(DELETE, apiKey, "server/" + this->server_DeleteBackupButtonComponent_TextField_ServerID->Text + "/backup");
					this->server_DeleteBackupButtonComponent_TextField_ServerID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send	
				}				
			}
		public: System::Void serverGetBandwidthButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_BANDWIDTHINFO_REQUEST;
			this->server_GetBandwidthButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_GetBandwidthButtonComponent_TextField_ServerID->Visible = true;
			this->server_GetBandwidthButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_GetBandwidthButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_GetBandwidthButtonComponent_TextField_ServerID->Enabled = true;
			this->server_GetBandwidthButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs->Enabled = true;
		} 	public: System::Void server_GetBandwidthButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_GetBandwidthButtonComponent_TextField_ServerID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(GET, apiKey, "server/" + this->server_GetBandwidthButtonComponent_TextField_ServerID->Text + "/bandwidthusage");
					this->server_GetBandwidthButtonComponent_TextField_ServerID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send	
				}				
			}
		public: System::Void server_SelectISOButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_NEWISO_REQUEST;
			this->server_SelectISOButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_SelectISOButtonComponent_TextField_ServerID->Visible = true;
			this->server_SelectISOButtonComponent_InstructionLabel_FirstFile->Visible = true;
			this->server_SelectISOButtonComponent_TextField_FirstFile->Visible = true;
			this->server_SelectISOButtonComponent_InstructionLabel_SecondFile->Visible = true;
			this->server_SelectISOButtonComponent_TextField_SecondFile->Visible = true;
			this->server_SelectISOButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;

			this->server_SelectISOButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_SelectISOButtonComponent_TextField_ServerID->Enabled = true;
			this->server_SelectISOButtonComponent_InstructionLabel_FirstFile->Enabled = true;
			this->server_SelectISOButtonComponent_TextField_FirstFile->Enabled = true;
			this->server_SelectISOButtonComponent_InstructionLabel_SecondFile->Enabled = true;
			this->server_SelectISOButtonComponent_TextField_SecondFile->Enabled = true;
			this->server_SelectISOButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
		} 	public: System::Void server_SelectISOButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_SelectISOButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_SelectISOButtonComponent_TextField_FirstFile->Text)
					|| String::IsNullOrEmpty(this->server_SelectISOButtonComponent_TextField_SecondFile->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(PUT, apiKey, "server/" + this->server_SelectISOButtonComponent_TextField_ServerID->Text + "/iso", "iso=" + this->server_SelectISOButtonComponent_TextField_FirstFile->Text
						+ "&iso2=" + this->server_SelectISOButtonComponent_TextField_SecondFile->Text);
					this->server_SelectISOButtonComponent_TextField_ServerID->Text = "";
					this->server_SelectISOButtonComponent_TextField_FirstFile->Text = "";
					this->server_SelectISOButtonComponent_TextField_SecondFile->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send	
				}
			}
		public: System::Void server_ResetPasswordButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_RESETPASSWORD_REQUEST;
			this->server_ResetPasswordButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_ResetPasswordButtonComponent_TextField_ServerID->Visible = true;
			this->server_ResetPasswordButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_ResetPasswordButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_ResetPasswordButtonComponent_TextField_ServerID->Enabled = true;
			this->server_ResetPasswordButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs->Enabled = true;
		} 	public: System::Void server_ResetPasswordButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_ResetPasswordButtonComponent_TextField_ServerID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(POST, apiKey, "server/" + this->server_ResetPasswordButtonComponent_TextField_ServerID->Text + "/resetPassword");
					this->server_ResetPasswordButtonComponent_TextField_ServerID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send			
				}
			}
		public: System::Void server_SetHostnameButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_SETHOSTNAME_REQUEST;
			this->server_SetHostnameButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_SetHostnameButtonComponent_TextField_ServerID->Visible = true;
			this->server_SetHostnameButtonComponent_InstructionLabel_Hostname->Visible = true;
			this->server_SetHostnameButtonComponent_TextField_Hostname->Visible = true;
			this->server_SetHostnameButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;

			this->server_SetHostnameButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_SetHostnameButtonComponent_TextField_ServerID->Enabled = true;
			this->server_SetHostnameButtonComponent_InstructionLabel_Hostname->Enabled = true;
			this->server_SetHostnameButtonComponent_TextField_Hostname->Enabled = true;
			this->server_SetHostnameButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
		} 	public: System::Void server_SetHostnameButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_SetHostnameButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_SetHostnameButtonComponent_TextField_Hostname->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(PUT, apiKey, "server/" + this->server_SetHostnameButtonComponent_TextField_ServerID->Text + "/hostname", "hostname=" + this->server_SetHostnameButtonComponent_TextField_Hostname->Text);
					this->server_SetHostnameButtonComponent_TextField_ServerID->Text = "";
					this->server_SetHostnameButtonComponent_TextField_Hostname->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send			
				}
			}
		public: System::Void server_RebuildButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_REBUILD_REQUEST;
			this->server_RebuildButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_RebuildButtonComponent_TextField_ServerID->Visible = true;
			this->server_RebuildButtonComponent_InstructionLabel_NewOS->Visible = true;
			this->server_RebuildButtonComponent_TextField_NewOS->Visible = true;
			this->server_RebuildButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;

			this->server_RebuildButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_RebuildButtonComponent_TextField_ServerID->Enabled = true;
			this->server_RebuildButtonComponent_InstructionLabel_NewOS->Enabled = true;
			this->server_RebuildButtonComponent_TextField_NewOS->Enabled = true;
			this->server_RebuildButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
		} 	public: System::Void server_RebuildButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_RebuildButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_RebuildButtonComponent_TextField_NewOS->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(POST, apiKey, "server/" + this->server_RebuildButtonComponent_TextField_ServerID->Text + "/rebuild", "newos=" + this->server_RebuildButtonComponent_TextField_NewOS->Text);
					this->server_RebuildButtonComponent_TextField_ServerID->Text = "";
					this->server_RebuildButtonComponent_TextField_NewOS->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void server_GetIPInfoButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_IPINFO_REQUEST;
			this->server_GetIPInfoButtonComponent_Instructionlabel_ServerID->Visible = true;
			this->server_GetIPInfoButtonComponent_TextField_ServerID->Visible = true;
			this->server_GetIPInfoButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_GetIPInfoButtonComponent_Instructionlabel_ServerID->Enabled = true;
			this->server_GetIPInfoButtonComponent_TextField_ServerID->Enabled = true;
			this->server_GetIPInfoButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs->Enabled = true;
		} 	public: System::Void server_GetIPInfoButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_GetIPInfoButtonComponent_TextField_ServerID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(GET, apiKey, "server/" + this->server_GetIPInfoButtonComponent_TextField_ServerID->Text + "/ip");
					this->server_GetIPInfoButtonComponent_TextField_ServerID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void server_GetVNCInfoTFButton_Click(System::Object^ sender, System::EventArgs^ e) { // TF -> timeFrame
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_VNCSCOPEDINFO_REQUEST;
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->Visible = true;
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame->Visible = true;
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Visible = true;
			this->server_GetVNCInfoTFButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;

			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->Enabled = true;
			this->server_GetVNCInfoTFButtonComponent_InstructionLabel_TimeFrame->Enabled = true;
			this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Enabled = true;
			this->server_GetVNCInfoTFButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
		}	public: System::Void server_GetVNCInfoTFButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(GET, apiKey, "server/" + this->server_GetIPInfoButtonComponent_TextField_ServerID->Text + "/statistics/" + this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Text);
					this->server_GetVNCInfoTFButtonComponent_TextField_ServerID->Text = "";
					this->server_GetVNCInfoTFButtonComponent_TextField_TimeFrame->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void server_SetBootOrderButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_BOOTORDER_REQUEST;
			this->server_SetBootOrderButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_SetBootOrderButtonComponent_TextField_ServerID->Visible = true;
			this->server_SetBootOrderButtonComponent_InstructionLabel_BootOrder->Visible = true;
			this->server_SetBootOrderButtonComponent_TextField_BootOrder->Visible = true;
			this->server_SetBootOrderButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;

			this->server_SetBootOrderButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_SetBootOrderButtonComponent_TextField_ServerID->Enabled = true;
			this->server_SetBootOrderButtonComponent_InstructionLabel_BootOrder->Enabled = true;
			this->server_SetBootOrderButtonComponent_TextField_BootOrder->Enabled = true;
			this->server_SetBootOrderButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
		}	public: System::Void server_SetBootOrderButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_SetBootOrderButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_SetBootOrderButtonComponent_TextField_BootOrder->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(PUT, apiKey, "server/" + this->server_SetBootOrderButtonComponent_TextField_ServerID->Text + "/media", "order=" + this->server_SetBootOrderButtonComponent_TextField_BootOrder->Text);
					this->server_SetBootOrderButtonComponent_TextField_ServerID->Text = "";
					this->server_SetBootOrderButtonComponent_TextField_BootOrder->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void server_GetFirewallRulesButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_GETFIREWALLRULES_REQUEST;
			this->server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID->Visible = true;
			this->server_GetFirewallRulesButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs->Visible = true;

			this->server_GetFirewallRulesButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_GetFirewallRulesButtonComponent_TextField_ServerID->Enabled = true;
			this->server_GetFirewallRulesButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs->Enabled = true;
		} 	public: System::Void server_GetFirewallRulesButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_GetFirewallRulesButtonComponent_TextField_ServerID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(GET, apiKey, "server/" + this->server_GetFirewallRulesButtonComponent_TextField_ServerID->Text + "/firewall");
					this->server_GetFirewallRulesButtonComponent_TextField_ServerID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void server_ToggleFirewallRuleButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_TOGGLEFIREWALLRULE_REQUEST;
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Visible = true;
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle->Visible = true;
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Visible = true;
			this->server_ToggleFirewallRuleButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;

			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Enabled = true;
			this->server_ToggleFirewallRuleButtonComponent_InstructionLabel_Toggle->Enabled = true;
			this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Enabled = true;
			this->server_ToggleFirewallRuleButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
		}	public: System::Void server_ToggleFirewallRuleButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(PUT, apiKey, "server/" + this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Text + "/firewall", "toggle=" + this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Text);
					this->server_ToggleFirewallRuleButtonComponent_TextField_ServerID->Text = "";
					this->server_ToggleFirewallRuleButtonComponent_TextField_Toggle->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}				
			}
		public: System::Void server_AddFirewallRuleButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_ADDFIREWALLRULE_REQUEST;
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID->Visible = true;
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_Data->Visible = true;
			this->server_AddFirewallRuleButtonComponent_TextField_Data->Visible = true;
			this->server_AddFirewallRuleButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;

			this->server_AddFirewallRuleButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_AddFirewallRuleButtonComponent_TextField_ServerID->Enabled = true;
			this->server_AddFirewallRuleButtonComponent_InstructionLabel_Data->Enabled = true;
			this->server_AddFirewallRuleButtonComponent_TextField_Data->Enabled = true;
			this->server_AddFirewallRuleButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
		} 	public: System::Void server_AddFirewallRuleButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_AddFirewallRuleButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_AddFirewallRuleButtonComponent_TextField_Data->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(POST, apiKey, "server/" + this->server_AddFirewallRuleButtonComponent_TextField_ServerID->Text + "/firewall", "data=" + this->server_AddFirewallRuleButtonComponent_TextField_Data->Text);
					this->server_AddFirewallRuleButtonComponent_TextField_ServerID->Text = "";
					this->server_AddFirewallRuleButtonComponent_TextField_Data->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}						
			}
		public: System::Void server_DeleteFirewallRuleButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_DELETEFIREWALLRULE_REQUEST;
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Visible = true;
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID->Visible = true;
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID->Visible = true;
			this->server_DeleteFirewallRuleButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;

			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Enabled = true;
			this->server_DeleteFirewallRuleButtonComponent_InstructionLabel_RID->Enabled = true;
			this->server_DeleteFirewallRuleButtonComponent_TextField_RID->Enabled = true;
			this->server_DeleteFirewallRuleButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
		}	public: System::Void server_DeleteFirewallRuleButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_DeleteFirewallRuleButtonComponent_TextField_RID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(DELETE, apiKey, "server/" + this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Text + "/firewall", "rid=" + this->server_DeleteFirewallRuleButtonComponent_TextField_RID->Text);
					this->server_DeleteFirewallRuleButtonComponent_TextField_ServerID->Text = "";
					this->server_DeleteFirewallRuleButtonComponent_TextField_RID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}						
			}
		public: System::Void server_SetIPrDNSButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_SETRDNS_REQUEST;
			this->server_SetIPrDNSButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_SetIPrDNSButtonComponent_TextField_ServerID->Visible = true;
			this->server_SetIPrDNSButtonComponent_InstructionLabel_IP->Visible = true;
			this->server_SetIPrDNSButtonComponent_TextField_IP->Visible = true;
			this->server_SetIPrDNSButtonComponent_InstructionLabel_rDNS->Visible = true;
			this->server_SetIPrDNSButtonComponent_TextField_rDNS->Visible = true;
			this->server_SetIPrDNSButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;
			this->server_IndependentComponentShowIPs_RightPos->Visible = true;

			this->server_SetIPrDNSButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_SetIPrDNSButtonComponent_TextField_ServerID->Enabled = true;
			this->server_SetIPrDNSButtonComponent_InstructionLabel_IP->Enabled = true;
			this->server_SetIPrDNSButtonComponent_TextField_IP->Enabled = true;
			this->server_SetIPrDNSButtonComponent_InstructionLabel_rDNS->Enabled = true;
			this->server_SetIPrDNSButtonComponent_TextField_rDNS->Enabled = true;
			this->server_SetIPrDNSButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
			this->server_IndependentComponentShowIPs_RightPos->Enabled = true;
		}	public: System::Void server_SetIPrDNSButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_SetIPrDNSButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_SetIPrDNSButtonComponent_TextField_IP->Text)
					|| String::IsNullOrEmpty(this->server_SetIPrDNSButtonComponent_TextField_rDNS->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(PUT, apiKey, "server/" + this->server_SetIPrDNSButtonComponent_TextField_ServerID->Text + "/ip/" + this->server_SetIPrDNSButtonComponent_TextField_IP->Text + "/rdns", "target=" + this->server_SetIPrDNSButtonComponent_TextField_rDNS->Text);
					this->server_SetIPrDNSButtonComponent_TextField_ServerID->Text = "";
					this->server_SetIPrDNSButtonComponent_TextField_IP->Text = "";
					this->server_SetIPrDNSButtonComponent_TextField_rDNS->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}						
			}
		public: System::Void server_GetIPRulesButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_GETIPRULES_REQUEST;
			this->server_GetIPRulesButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_GetIPRulesButtonComponent_TextField_ServerID->Visible = true;
			this->server_GetIPRulesButtonComponent_InstructionLabel_IP->Visible = true;
			this->server_GetIPRulesButtonComponent_TextField_IP->Visible = true;
			this->server_GetIPRulesButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;
			this->server_IndependentComponentShowIPs->Visible = true;

			this->server_GetIPRulesButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_GetIPRulesButtonComponent_TextField_ServerID->Enabled = true;
			this->server_GetIPRulesButtonComponent_InstructionLabel_IP->Enabled = true;
			this->server_GetIPRulesButtonComponent_TextField_IP->Enabled = true;
			this->server_GetIPRulesButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
			this->server_IndependentComponentShowIPs->Enabled = true;
		}	public: System::Void server_GetIPRulesButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_GetIPRulesButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_GetIPRulesButtonComponent_TextField_IP->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(GET, apiKey, "server/" + this->server_GetIPRulesButtonComponent_TextField_ServerID->Text + "/ip/" + this->server_GetIPRulesButtonComponent_TextField_IP->Text);
					this->server_GetIPRulesButtonComponent_TextField_ServerID->Text = "";
					this->server_GetIPRulesButtonComponent_TextField_IP->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void server_GetMitigationStatusButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_GETMITIGATION_REQUEST;
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID->Visible = true;
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_IP->Visible = true;
			this->server_GetMitigationStatusButtonComponent_TextField_IP->Visible = true;
			this->server_GetMitigationStatusButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;
			this->server_IndependentComponentShowIPs->Visible = true;

			this->server_GetMitigationStatusButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_GetMitigationStatusButtonComponent_TextField_ServerID->Enabled = true;
			this->server_GetMitigationStatusButtonComponent_InstructionLabel_IP->Enabled = true;
			this->server_GetMitigationStatusButtonComponent_TextField_IP->Enabled = true;
			this->server_GetMitigationStatusButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
			this->server_IndependentComponentShowIPs->Enabled = true;
		}	public: System::Void server_GetMitigationStatusButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_GetMitigationStatusButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_GetMitigationStatusButtonComponent_TextField_IP->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(GET, apiKey, "server/" + this->server_GetMitigationStatusButtonComponent_TextField_ServerID->Text + "/ip/" + this->server_GetMitigationStatusButtonComponent_TextField_IP->Text + "/mitigation");
					this->server_GetMitigationStatusButtonComponent_TextField_ServerID->Text = "";
					this->server_GetMitigationStatusButtonComponent_TextField_IP->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void server_SetMitigationStatusButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_TOGGLEMITIGATION_REQUEST;
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID->Visible = true;
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_IP->Visible = true;
			this->server_SetMitigationStatusButtonComponent_TextField_IP->Visible = true;
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle->Visible = true;
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle->Visible = true;
			this->server_SetMitigationStatusButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;
			this->server_IndependentComponentShowIPs_RightPos->Visible = true;

			this->server_SetMitigationStatusButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_SetMitigationStatusButtonComponent_TextField_ServerID->Enabled = true;
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_IP->Enabled = true;
			this->server_SetMitigationStatusButtonComponent_TextField_IP->Enabled = true;
			this->server_SetMitigationStatusButtonComponent_InstructionLabel_Toggle->Enabled = true;
			this->server_SetMitigationStatusButtonComponent_TextField_Toggle->Enabled = true;
			this->server_SetMitigationStatusButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
			this->server_IndependentComponentShowIPs_RightPos->Enabled = true;
		}	public: System::Void server_SetMitigationStatusButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_SetMitigationStatusButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_SetMitigationStatusButtonComponent_TextField_IP->Text)
					|| String::IsNullOrEmpty(this->server_SetMitigationStatusButtonComponent_TextField_Toggle->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(PUT, apiKey, "server/" + this->server_SetMitigationStatusButtonComponent_TextField_ServerID->Text + "/ip/" + this->server_SetMitigationStatusButtonComponent_TextField_IP->Text + "/mitigation", "toggle=" + this->server_SetMitigationStatusButtonComponent_TextField_Toggle->Text);
					this->server_SetMitigationStatusButtonComponent_TextField_ServerID->Text = "";
					this->server_SetMitigationStatusButtonComponent_TextField_IP->Text = "";
					this->server_SetMitigationStatusButtonComponent_TextField_Toggle->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void Server_AddGAMERuleButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_ADDGAMERULE_REQUEST;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_AddGAMERuleButtonComponent_TextField_ServerID->Visible = true;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_IP->Visible = true;
			this->server_AddGAMERuleButtonComponent_TextField_IP->Visible = true;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Proto->Visible = true;
			this->server_AddGAMERuleButtonComponent_TextField_Proto->Visible = true;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Port->Visible = true;
			this->server_AddGAMERuleButtonComponent_TextField_Port->Visible = true;
			this->server_AddGAMERuleButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;
			this->server_IndependentComponentShowIPs_RightPos->Visible = true;

			this->server_AddGAMERuleButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_AddGAMERuleButtonComponent_TextField_ServerID->Enabled = true;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_IP->Enabled = true;
			this->server_AddGAMERuleButtonComponent_TextField_IP->Enabled = true;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Proto->Enabled = true;
			this->server_AddGAMERuleButtonComponent_TextField_Proto->Enabled = true;
			this->server_AddGAMERuleButtonComponent_InstructionLabel_Port->Enabled = true;
			this->server_AddGAMERuleButtonComponent_TextField_Port->Enabled = true;
			this->server_AddGAMERuleButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
			this->server_IndependentComponentShowIPs_RightPos->Enabled = true;
		}	public: System::Void Server_AddGAMERuleButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_AddGAMERuleButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_AddGAMERuleButtonComponent_TextField_IP->Text)
					|| String::IsNullOrEmpty(this->server_AddGAMERuleButtonComponent_TextField_Proto->Text) || String::IsNullOrEmpty(this->server_AddGAMERuleButtonComponent_TextField_Port->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(POST, apiKey, "server/" + this->server_AddGAMERuleButtonComponent_TextField_ServerID->Text + "/ip/" + this->server_AddGAMERuleButtonComponent_TextField_IP->Text + "/game", "protocol=" + this->server_AddGAMERuleButtonComponent_TextField_Proto->Text + "&port=" + this->server_AddGAMERuleButtonComponent_TextField_Port->Text);
					this->server_AddGAMERuleButtonComponent_TextField_ServerID->Text = "";
					this->server_AddGAMERuleButtonComponent_TextField_IP->Text = "";
					this->server_AddGAMERuleButtonComponent_TextField_Proto->Text = "";
					this->server_AddGAMERuleButtonComponent_TextField_Port->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}
		public: System::Void Server_ToggleGAMEFirewallButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_TOGGLEGAMEFIREWALL_REQUEST;
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Visible = true;
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP->Visible = true;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Visible = true;
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle->Visible = true;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Visible = true;
			this->server_ToggleGAMEFirewallButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;
			this->server_IndependentComponentShowIPs_RightPos->Visible = true;

			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Enabled = true;
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_IP->Enabled = true;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Enabled = true;
			this->server_ToggleGAMEFirewallButtonComponent_InstructionLabel_Toggle->Enabled = true;
			this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Enabled = true;
			this->server_ToggleGAMEFirewallButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
			this->server_IndependentComponentShowIPs_RightPos->Enabled = true;
		} 	public: System::Void Server_ToggleGAMEFirewallButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Text)
					|| String::IsNullOrEmpty(this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(PUT, apiKey, "server/" + this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Text + "/ip/" + this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Text + "/game", "toggle=" + this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Text);
					this->server_ToggleGAMEFirewallButtonComponent_TextField_ServerID->Text = "";
					this->server_ToggleGAMEFirewallButtonComponent_TextField_IP->Text = "";
					this->server_ToggleGAMEFirewallButtonComponent_TextField_Toggle->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}				
			}
		public: System::Void Server_DeleteGAMERuleButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_DELETEGAMEFIREWALLRULE_REQUEST;
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Visible = true;
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_IP->Visible = true;
			this->server_DeleteGAMERuleButtonComponent_TextField_IP->Visible = true;
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_RID->Visible = true;
			this->server_DeleteGAMERuleButtonComponent_TextField_RID->Visible = true;
			this->server_DeleteGAMERuleButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;
			this->server_IndependentComponentShowIPs_RightPos->Visible = true;

			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Enabled = true;
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_IP->Enabled = true;
			this->server_DeleteGAMERuleButtonComponent_TextField_IP->Enabled = true;
			this->server_DeleteGAMERuleButtonComponent_InstructionLabel_RID->Enabled = true;
			this->server_DeleteGAMERuleButtonComponent_TextField_RID->Enabled = true;
			this->server_DeleteGAMERuleButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
			this->server_IndependentComponentShowIPs_RightPos->Enabled = true;
		} 	public: System::Void Server_DeleteGAMERuleButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_DeleteGAMERuleButtonComponent_TextField_IP->Text)
					|| String::IsNullOrEmpty(this->server_DeleteGAMERuleButtonComponent_TextField_RID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(DELETE, apiKey, "server/" + this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Text + "/ip/" + this->server_DeleteGAMERuleButtonComponent_TextField_IP->Text + "/game/" + this->server_DeleteGAMERuleButtonComponent_TextField_RID->Text);
					this->server_DeleteGAMERuleButtonComponent_TextField_ServerID->Text = "";
					this->server_DeleteGAMERuleButtonComponent_TextField_IP->Text = "";
					this->server_DeleteGAMERuleButtonComponent_TextField_RID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}			
			}
		public: System::Void server_SetFirewallTemplateButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_SETFIREWALLTEMPLATE_REQUEST;
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Visible = true;
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_IP->Visible = true;
			this->server_SetFirewallTemplateButtonComponent_TextField_IP->Visible = true;
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName->Visible = true;
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Visible = true;
			this->server_SetFirewallTemplateButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;
			this->server_IndependentComponentShowIPs_RightPos->Visible = true;

			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Enabled = true;
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_IP->Enabled = true;
			this->server_SetFirewallTemplateButtonComponent_TextField_IP->Enabled = true;
			this->server_SetFirewallTemplateButtonComponent_InstructionLabel_TemplateName->Enabled = true;
			this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Enabled = true;
			this->server_SetFirewallTemplateButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
			this->server_IndependentComponentShowIPs_RightPos->Enabled = true;
		} 	public: System::Void server_SetFirewallTemplateButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_SetFirewallTemplateButtonComponent_TextField_IP->Text)
					|| String::IsNullOrEmpty(this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(PUT, apiKey, "server/" + this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Text + "/ip/" + this->server_SetFirewallTemplateButtonComponent_TextField_IP->Text + "/firewall/template", "template=" + this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Text);
					this->server_SetFirewallTemplateButtonComponent_TextField_ServerID->Text = "";
					this->server_SetFirewallTemplateButtonComponent_TextField_IP->Text = "";
					this->server_SetFirewallTemplateButtonComponent_TextField_TemplateName->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}		
			}
		public: System::Void Server_AddFirewallButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_ADDFIREWALL_REQUEST;
			this->server_AddFirewallButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_AddFirewallButtonComponent_TextField_ServerID->Visible = true;
			this->server_AddFirewallButtonComponent_InstructionLabel_IP->Visible = true;
			this->server_AddFirewallButtonComponent_TextField_IP->Visible = true;
			this->server_AddFirewallButtonComponent_InstructionLabel_Data->Visible = true;
			this->server_AddFirewallButtonComponent_TextField_Data->Visible = true;
			this->server_AddFirewallButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;
			this->server_IndependentComponentShowIPs_RightPos->Visible = true;

			this->server_AddFirewallButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_AddFirewallButtonComponent_TextField_ServerID->Enabled = true;
			this->server_AddFirewallButtonComponent_InstructionLabel_IP->Enabled = true;
			this->server_AddFirewallButtonComponent_TextField_IP->Enabled = true;
			this->server_AddFirewallButtonComponent_InstructionLabel_Data->Enabled = true;
			this->server_AddFirewallButtonComponent_TextField_Data->Enabled = true;
			this->server_AddFirewallButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
			this->server_IndependentComponentShowIPs_RightPos->Enabled = true;
		} 	public: System::Void Server_AddFirewallButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_AddFirewallButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_AddFirewallButtonComponent_TextField_IP->Text)
					|| String::IsNullOrEmpty(this->server_AddFirewallButtonComponent_TextField_Data->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(POST, apiKey, "server/" + this->server_AddFirewallButtonComponent_TextField_ServerID->Text + "/ip/" + this->server_AddFirewallButtonComponent_TextField_IP->Text + "/firewall", "data=" + this->server_AddFirewallButtonComponent_TextField_Data->Text);
					this->server_AddFirewallButtonComponent_TextField_ServerID->Text = "";
					this->server_AddFirewallButtonComponent_TextField_IP->Text = "";
					this->server_AddFirewallButtonComponent_TextField_Data->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}		
			}

		public: System::Void server_DeleteFirewallIPRuleButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_DELETEIPFIREWALLRULE_REQUEST;
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Visible = true;
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP->Visible = true;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Visible = true;
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID->Visible = true;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Visible = true;
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;
			this->server_IndependentComponentShowIPs_RightPos->Visible = true;

			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Enabled = true;
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_IP->Enabled = true;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Enabled = true;
			this->server_DeleteFirewallIPRuleButtonComponent_InstructionLabel_RID->Enabled = true;
			this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Enabled = true;
			this->server_DeleteFirewallIPRuleButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
			this->server_IndependentComponentShowIPs_RightPos->Enabled = true;
		} 	public: System::Void Server_DeleteFirewallIPRuleButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Text)
					|| String::IsNullOrEmpty(this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(DELETE, apiKey, "server/" + this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Text + "/ip/" + this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Text + "/firewall/" + this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Text);
					this->server_DeleteFirewallIPRuleButtonComponent_TextField_ServerID->Text = "";
					this->server_DeleteFirewallIPRuleButtonComponent_TextField_IP->Text = "";
					this->server_DeleteFirewallIPRuleButtonComponent_TextField_RID->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}

		public: System::Void server_SetMitigationTimeoutButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = SERVER_SETMITIGATIONTIMEOUT_REQUEST;
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID->Visible = true;
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Visible = true;
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP->Visible = true;
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP->Visible = true;
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout->Visible = true;
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Visible = true;
			this->server_SetMitigationTimeoutButtonComponent_SendButton->Visible = true;
			this->server_IndependentComponentShowIDs_RightPos->Visible = true;
			this->server_IndependentComponentShowIPs_RightPos->Visible = true;

			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_ServerID->Enabled = true;
			this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Enabled = true;
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_IP->Enabled = true;
			this->server_SetMitigationTimeoutButtonComponent_TextField_IP->Enabled = true;
			this->server_SetMitigationTimeoutButtonComponent_InstructionLabel_Timeout->Enabled = true;
			this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Enabled = true;
			this->server_SetMitigationTimeoutButtonComponent_SendButton->Enabled = true;
			this->server_IndependentComponentShowIDs_RightPos->Enabled = true;
			this->server_IndependentComponentShowIPs_RightPos->Enabled = true;
		} 	public: System::Void Server_SetMitigationTimeoutButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (String::IsNullOrEmpty(this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Text) || String::IsNullOrEmpty(this->server_SetMitigationTimeoutButtonComponent_TextField_IP->Text)
					|| String::IsNullOrEmpty(this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = "";
					this->responseOutputField->Text = request::performRequest(PUT, apiKey, "server/" + this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Text + "/ip/" + this->server_SetMitigationTimeoutButtonComponent_TextField_IP->Text + "/mitigationtimeout", "timeout=" + this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Text);
					this->server_SetMitigationTimeoutButtonComponent_TextField_ServerID->Text = "";
					this->server_SetMitigationTimeoutButtonComponent_TextField_IP->Text = "";
					this->server_SetMitigationTimeoutButtonComponent_TextField_Timeout->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send		
				}
			}






		// FIREWALL oriented functions below - mainly logs
		public: System::Void firewallButton_Click(System::Object^ sender, System::EventArgs^ e) {
			if (configuration::keyFileCheck() == FILE_EMPTY) {
				MessageBox::Show("API key not detected. Be sure to submit your FTH supplied API key before attempting to use other sections of the application.", "Notice");
			}
			else {
				functionDeinitHandler(selectedFunction, this);
				apiDeinitHandler(this->selectedGUI, this);
				this->selectedGUI = GUI_FIREWALL;
				initFirewallTabGUI();
			}
		}
		public: System::Void firewall_GetFirewallLogsButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = request::performRequest(GET, apiKey, "firewall_log");
		}
		public: System::Void firewall_GetUnreadFirewallLogsButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = request::performRequest(GET, apiKey, "firewall_log/unseen");
		}
		public: System::Void firewall_DeleteFirewallLogsButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = request::performRequest(DELETE, apiKey, "firewall_log");
		}



			   
			   
			   

			   
			   
			   
		// BILLING oriented functions below
		public: System::Void billingButton_Click(System::Object^ sender, System::EventArgs^ e) {
			if (configuration::keyFileCheck() == FILE_EMPTY) {
				MessageBox::Show("API key not detected. Be sure to submit your FTH supplied API key before attempting to use other sections of the application.", "Notice");
			}
			else {
				functionDeinitHandler(selectedFunction, this);
				apiDeinitHandler(this->selectedGUI, this);
				this->selectedGUI = GUI_BILLING;
				initBillingTabGUI();
			}
		}
		public: System::Void billing_GetAccountInfoButton_Click(System::Object^ sender, System::EventArgs^ e) {
			functionDeinitHandler(selectedFunction, this);
			this->responseOutputField->Text = request::performRequest(GET, apiKey, "me");
		}
		public: System::Void billing_GetAllInvoicesButton_Click(System::Object^ sender, System::EventArgs^ e) {
			functionDeinitHandler(selectedFunction, this);
			this->responseOutputField->Text = request::performRequest(GET, apiKey, "me/invoice");
		}
		public: System::Void billing_GetActiveServicesButton_Click(System::Object^ sender, System::EventArgs^ e) {
			functionDeinitHandler(selectedFunction, this);
			this->responseOutputField->Text = request::performRequest(GET, apiKey, "server");
		}
		public: System::Void billing_GetProductsButton_Click(System::Object^ sender, System::EventArgs^ e) {
			functionDeinitHandler(selectedFunction, this);
			this->responseOutputField->Text = request::performRequest(GET, apiKey, "products");
		}
		public: System::Void billing_GetAllTickets_Click(System::Object^ sender, System::EventArgs^ e) {
			functionDeinitHandler(selectedFunction, this);
			this->responseOutputField->Text = request::performRequest(GET, apiKey, "me/ticket");
		}
		public: System::Void billing_GetInvoiceByIDButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = BILLING_INVOICEINFO_REQUEST;
			this->billing_GetInvoiceByIDButtonComponent_TextField->Visible = true;
			this->billing_GetInvoiceByIDComponent_SendButton->Visible = true;
			this->billing_GetInvoiceByIDComponent_InstructionLabel->Visible = true;

			this->billing_GetInvoiceByIDButtonComponent_TextField->Enabled = true;
			this->billing_GetInvoiceByIDComponent_SendButton->Enabled = true;
			this->billing_GetInvoiceByIDComponent_InstructionLabel->Enabled = true;
		} // any function indented is only used when the function above it is called - as well as its components only being shown when the above is called
			public: System::Void billing_GetInvoiceByIDComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				this->responseOutputField->Text = "";
				this->responseOutputField->Text = request::performRequest(GET, apiKey, "me/invoice/" + this->billing_GetInvoiceByIDButtonComponent_TextField->Text);
				this->billing_GetInvoiceByIDButtonComponent_TextField->Text = "";
				functionDeinitHandler(selectedFunction, this); // to clear after hitting Send
			}
		public: System::Void billing_GetTicketByIDButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = BILLING_GETTICKET_REQUEST;
			this->billing_GetTicketByIDButtonComponent_TextField->Visible = true;
			this->billing_GetTicketByIDButtonComponent_SendButton->Visible = true;
			this->billing_GetTicketByIDButtonComponent_InstructionLabel->Visible = true;

			this->billing_GetTicketByIDButtonComponent_TextField->Enabled = true;
			this->billing_GetTicketByIDButtonComponent_SendButton->Enabled = true;
			this->billing_GetTicketByIDButtonComponent_InstructionLabel->Enabled = true;
		}	public: System::Void billing_GetTicketByIDButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				this->responseOutputField->Text = "";
				this->responseOutputField->Text = request::performRequest(GET, apiKey, "me/ticket/" + this->billing_GetTicketByIDButtonComponent_TextField->Text);
				this->billing_GetTicketByIDButtonComponent_TextField->Text = "";
				functionDeinitHandler(selectedFunction, this); // to clear after hitting Send
			}
		public: System::Void billing_GetPromoInfoButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = BILLING_PROMOINFO_REQUEST;
			this->billing_GetPromoInfoButtonComponent_TextField->Visible = true;
			this->billing_GetPromoInfoButtonComponent_SendButton->Visible = true;
			this->billing_GetPromoInfoButtonComponent_InstructionLabel->Visible = true;

			this->billing_GetPromoInfoButtonComponent_TextField->Enabled = true;
			this->billing_GetPromoInfoButtonComponent_SendButton->Enabled = true;
			this->billing_GetPromoInfoButtonComponent_InstructionLabel->Enabled = true;
		}	public: System::Void billing_GetPromoInfoButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				this->responseOutputField->Text = "";
				this->responseOutputField->Text = request::performRequest(GET, apiKey, "order/promotion/" + this->billing_GetPromoInfoButtonComponent_TextField->Text);
				this->billing_GetPromoInfoButtonComponent_TextField->Text = "";
				functionDeinitHandler(selectedFunction, this); // to clear after hitting Send			
			}
		public: System::Void billing_CloseTicketByIDButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = BILLING_CLOSETICKET_REQUEST;
			this->billing_CloseTicketByIDButtonComponent_TextField->Visible = true;
			this->billing_CloseTicketByIDButtonComponent_SendButton->Visible = true;
			this->billing_CloseTicketByIDButtonComponent_InstructionLabel->Visible = true;

			this->billing_CloseTicketByIDButtonComponent_TextField->Enabled = true;
			this->billing_CloseTicketByIDButtonComponent_SendButton->Enabled = true;
			this->billing_CloseTicketByIDButtonComponent_InstructionLabel->Enabled = true;
		} 	public: System::Void billing_CloseTicketByIDButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				this->responseOutputField->Text = "";
				this->responseOutputField->Text = request::performRequest(POST, apiKey, "me/ticket/" + this->billing_CloseTicketByIDButtonComponent_TextField->Text + "/close");
				this->billing_CloseTicketByIDButtonComponent_TextField->Text = "";
				functionDeinitHandler(selectedFunction, this); // to clear after hitting Send
			}
		public: System::Void billing_OpenNewTicketButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = BILLING_SENDTICKET_REQUEST;
			this->billing_OpenNewTicketButtonComponent_TextField_Subject->Visible = true;
			this->billing_OpenNewTicketButtonComponent_TextField_Priority->Visible = true;
			this->billing_OpenNewTicketButtonComponent_TextField_Department->Visible = true;
			this->billing_OpenNewTicketButtonComponent_TextField_Message->Visible = true;
			this->billing_OpenNewTicketButtonComponent_SendButton->Visible = true;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Subject->Visible = true;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Priority->Visible = true;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Department->Visible = true;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Message->Visible = true;

			this->billing_OpenNewTicketButtonComponent_TextField_Subject->Enabled = true;
			this->billing_OpenNewTicketButtonComponent_TextField_Priority->Enabled = true;
			this->billing_OpenNewTicketButtonComponent_TextField_Department->Enabled = true;
			this->billing_OpenNewTicketButtonComponent_TextField_Message->Enabled = true;
			this->billing_OpenNewTicketButtonComponent_SendButton->Enabled = true;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Subject->Enabled = true;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Priority->Enabled = true;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Department->Enabled = true;
			this->billing_OpenNewTicketButtonComponent_InstructionLabel_Message->Enabled = true;
		}	public: System::Void billing_OpenNewTicketButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				this->responseOutputField->Text = "";
				if (String::IsNullOrEmpty(this->billing_OpenNewTicketButtonComponent_TextField_Subject->Text) || String::IsNullOrEmpty(this->billing_OpenNewTicketButtonComponent_TextField_Priority->Text) || String::IsNullOrEmpty(this->billing_OpenNewTicketButtonComponent_TextField_Department->Text) || String::IsNullOrEmpty(this->billing_OpenNewTicketButtonComponent_TextField_Message->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = request::performRequest(POST, apiKey, "me/ticket", "subject=" + this->billing_OpenNewTicketButtonComponent_TextField_Subject->Text
						+ "&priority=" + this->billing_OpenNewTicketButtonComponent_TextField_Priority->Text
						+ "&deptid=" + this->billing_OpenNewTicketButtonComponent_TextField_Department->Text
						+ "&message=" + this->billing_OpenNewTicketButtonComponent_TextField_Message->Text);
					this->billing_OpenNewTicketButtonComponent_TextField_Subject->Text = "";
					this->billing_OpenNewTicketButtonComponent_TextField_Priority->Text = "";
					this->billing_OpenNewTicketButtonComponent_TextField_Department->Text = "";
					this->billing_OpenNewTicketButtonComponent_TextField_Message->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send
				}
			}
		public: System::Void billing_ReplyToTicketButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = BILLING_REPLYTICKET_REQUEST;
			this->billing_ReplyToTicketButtonComponent_TextField_TicketID->Visible = true;
			this->billing_ReplyToTicketButtonComponent_TextField_Message->Visible = true;
			this->billing_ReplyToTicketButtonComponent_SendButton->Visible = true;
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID->Visible = true;
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_Message->Visible = true;

			this->billing_ReplyToTicketButtonComponent_TextField_TicketID->Enabled = true;
			this->billing_ReplyToTicketButtonComponent_TextField_Message->Enabled = true;
			this->billing_ReplyToTicketButtonComponent_SendButton->Enabled = true;
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_TicketID->Enabled = true;
			this->billing_ReplyToTicketButtonComponent_InstructionLabel_Message->Enabled = true;
		}	public: System::Void billing_ReplyToTicketButtonComponent_SendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				this->responseOutputField->Text = "";
				if (String::IsNullOrEmpty(this->billing_ReplyToTicketButtonComponent_TextField_TicketID->Text) || String::IsNullOrEmpty(this->billing_ReplyToTicketButtonComponent_TextField_Message->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = request::performRequest(PUT, apiKey, "me/ticket/" + this->billing_ReplyToTicketButtonComponent_TextField_TicketID->Text, "message=" + this->billing_ReplyToTicketButtonComponent_TextField_Message->Text);
					this->billing_ReplyToTicketButtonComponent_TextField_TicketID->Text = "";
					this->billing_ReplyToTicketButtonComponent_TextField_Message->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send
				}
			}
		public: System::Void billing_SetAccountInfoButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->responseOutputField->Text = "";
			functionDeinitHandler(selectedFunction, this);
			this->selectedFunction = BILLING_SETINFO_REQUEST;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName->Visible = true;
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName->Visible = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_LastName->Visible = true;
			this->billing_SetAccountInfoButtonComponent_TextField_LastName->Visible = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Country->Visible = true;
			this->billing_SetAccountInfoButtonComponent_TextField_Country->Visible = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_State->Visible = true;
			this->billing_SetAccountInfoButtonComponent_TextField_State->Visible = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Address->Visible = true;
			this->billing_SetAccountInfoButtonComponent_TextField_Address->Visible = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_City->Visible = true;
			this->billing_SetAccountInfoButtonComponent_TextField_City->Visible = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode->Visible = true;
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Visible = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber->Visible = true;
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Visible = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Email->Visible = true;
			this->billing_SetAccountInfoButtonComponent_TextField_Email->Visible = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Password->Visible = true;
			this->billing_SetAccountInfoButtonComponent_TextField_Password->Visible = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword->Visible = true;
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Visible = true;
			this->billing_SetAccountInfoButtonComponent_SaveButton->Visible = true;

			this->billing_SetAccountInfoButtonComponent_InstructionLabel_FirstName->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_TextField_FirstName->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_LastName->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_TextField_LastName->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Country->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_TextField_Country->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_State->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_TextField_State->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Address->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_TextField_Address->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_City->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_TextField_City->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ZIPCode->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_PhoneNumber->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Email->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_TextField_Email->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_Password->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_TextField_Password->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_InstructionLabel_ConfirmPassword->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Enabled = true;
			this->billing_SetAccountInfoButtonComponent_SaveButton->Enabled = true;
		}	public: System::Void billing_SetAccountInfoButtonComponent_SaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
				this->responseOutputField->Text = "";
				if (String::IsNullOrEmpty(this->billing_SetAccountInfoButtonComponent_TextField_FirstName->Text) || String::IsNullOrEmpty(this->billing_SetAccountInfoButtonComponent_TextField_LastName->Text)
					|| String::IsNullOrEmpty(this->billing_SetAccountInfoButtonComponent_TextField_Country->Text) || String::IsNullOrEmpty(this->billing_SetAccountInfoButtonComponent_TextField_State->Text)
					|| String::IsNullOrEmpty(this->billing_SetAccountInfoButtonComponent_TextField_Address->Text) || String::IsNullOrEmpty(this->billing_SetAccountInfoButtonComponent_TextField_City->Text)
					|| String::IsNullOrEmpty(this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Text) || String::IsNullOrEmpty(this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Text)
					|| String::IsNullOrEmpty(this->billing_SetAccountInfoButtonComponent_TextField_Email->Text) || String::IsNullOrEmpty(this->billing_SetAccountInfoButtonComponent_TextField_Password->Text)
					|| String::IsNullOrEmpty(this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Text)) {
					MessageBox::Show("Make sure no input fields are empty!", "Notice");
				}
				else {
					this->responseOutputField->Text = request::performRequest(PUT, apiKey, "me", "firstname=" + this->billing_SetAccountInfoButtonComponent_TextField_FirstName->Text
						+ "&lastname=" + this->billing_SetAccountInfoButtonComponent_TextField_LastName->Text
						+ "&country=" + this->billing_SetAccountInfoButtonComponent_TextField_Country->Text
						+ "&state=" + this->billing_SetAccountInfoButtonComponent_TextField_State->Text
						+ "&address1=" + this->billing_SetAccountInfoButtonComponent_TextField_Address->Text
						+ "&city=" + this->billing_SetAccountInfoButtonComponent_TextField_City->Text
						+ "&postcode=" + this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Text
						+ "&phonenumber=" + this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Text
						+ "&email=" + this->billing_SetAccountInfoButtonComponent_TextField_Email->Text
						+ "&password2=" + this->billing_SetAccountInfoButtonComponent_TextField_Password->Text
						+ "&confirmpass=" + this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Text);
					this->billing_SetAccountInfoButtonComponent_TextField_FirstName->Text = "";
					this->billing_SetAccountInfoButtonComponent_TextField_LastName->Text = "";
					this->billing_SetAccountInfoButtonComponent_TextField_Country->Text = "";
					this->billing_SetAccountInfoButtonComponent_TextField_State->Text = "";
					this->billing_SetAccountInfoButtonComponent_TextField_Address->Text = "";
					this->billing_SetAccountInfoButtonComponent_TextField_City->Text = "";
					this->billing_SetAccountInfoButtonComponent_TextField_ZIPCode->Text = "";
					this->billing_SetAccountInfoButtonComponent_TextField_PhoneNumber->Text = "";
					this->billing_SetAccountInfoButtonComponent_TextField_Email->Text = "";
					this->billing_SetAccountInfoButtonComponent_TextField_Password->Text = "";
					this->billing_SetAccountInfoButtonComponent_TextField_ConfirmPassword->Text = "";
					functionDeinitHandler(selectedFunction, this); // to clear after hitting Send
				}
			}










		// SETTINGS oriented functions below
		public: System::Void settingsButton_Click(System::Object^ sender, System::EventArgs^ e) {
			if (configuration::keyFileCheck() == FILE_EMPTY) {
				MessageBox::Show("API key not detected. Be sure to submit your FTH supplied API key before attempting to use other sections of the application.", "Notice");
			}
			else {
				functionDeinitHandler(selectedFunction, this);
				apiDeinitHandler(this->selectedGUI, this);
				this->selectedGUI = GUI_SETTINGS;
				initSettingsTabGUI();
			}
		}
		public: System::Void settings_SaveChangedKeyButton_Click(System::Object^ sender, System::EventArgs^ e) {
			if (System::String::IsNullOrEmpty(this->settings_ChangeApiKeyInputField->Text)) {
				MessageBox::Show("Please enter your new FTH API key!", "Notice");
			}
			else {
				configuration::changeAPIKey(this->settings_ChangeApiKeyInputField->Text, apiKey);
				this->settings_ChangeApiKeyInputField->Text = "";
				MessageBox::Show("Key updated!", "Notice");
			}
		}
		public: System::Void settings_ServerIDSaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
			if (System::String::IsNullOrEmpty(this->settings_ServerIDInputField->Text)) {
				MessageBox::Show("Please enter your Server ID!", "Notice");
			}
			else {
				configuration::addServerID(this->settings_ServerIDInputField->Text);
				this->settings_ServerIDInputField->Text = "";
			}
		}
		public: System::Void settings_ServerIDResetButton_Click(System::Object^ sender, System::EventArgs^ e) {
			configuration::removeServerIDs();
			MessageBox::Show("ID(s) reset successfully!", "Notice");
		}
		public: System::Void settings_ServerIPSaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
			if (System::String::IsNullOrEmpty(this->settings_ServerIPInputField->Text)) {
				MessageBox::Show("Please enter your Server IP!", "Notice");
			}
			else {
				configuration::addServerIP(this->settings_ServerIPInputField->Text);
				this->settings_ServerIPInputField->Text = "";
			}
		}
		public: System::Void settings_ServerIPResetButton_Click(System::Object^ sender, System::EventArgs^ e) {
			configuration::removeServerIPs();
			MessageBox::Show("IP(s) reset successfully!", "Notice");
		}
	};
}