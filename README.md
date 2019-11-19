# FullTime Manager
<p align="center">
  <img src="https://hostadvice.com/wp-content/uploads/2018/02/logo-8.png" width="400" height="250"></img>
</p>
<p align="center">
  < Created for <a href="https://fulltimehosting.net">Full Time Hosting</a> and their clients >
</p>

<br/>

# Description
A client whose main purpose is to be used for functions that are originally found on the FTH control panel. It interacts with their JSON API--via the use of an authorization key--and performs billing, firewall, and server-oriented functions. This is the earliest release, and some of the functions outlined in the FTH API are incompletely/haphazardly documented. This results in some of these functions--only a few--being unstable until there is improved documentation.

<br/>

# Functions
Some functions that can be found within the client are as follows:
  - Firewall:
    - Get All/Unread Logs
    - Delete Logs
  - Billing:
    - Retrieve Product List
    - Retrieve Active Servers
    - Set/Get Account Info
    - Get/Open/Reply/Close Ticket(s)
    - Get Invoices
    - Get Promotional Code Info
  - Server:
    - Get Server Info
    - Power/Restart/Crash/Renew Server
    - Get Expiration Info
    - Get Backup Info/Make Backup/Delete Backup
    - Get Media Info
    - Get VNC Info
    - Get Bandwidth Info
    - Set ISO
    - Manipulate Firewall Rules (GAME, Hardware, etc)
    - Set Boot Order
    - Manipulate Mitigation
    - Manipulate rDNS Settings
    - ...and more!

<br/>

# Screenshots
Image of the pre-API key phase. This is the screen shown before a user supplies their FTH API key. Access to all other sections of the application are blocked until an API key--valid or not--is supplied.
<p align="center">
  <img src="https://github.com/defec1iv3/FullTime-Manager/blob/master/Screenshots/ss4.PNG" width="400" height="250"></img>
</p>

Image of the client's Server Tab--first page. Functions oriented around server control and information are located here.
<p align="center">
  <img src="https://github.com/defec1iv3/FullTime-Manager/blob/master/Screenshots/ss0.PNG" width="400" height="250"></img>
</p>

Image of the client's Firewall Tab. Functions regarding generic firewall data retrieval are located here. Not many functions, but useful nonetheless. Might eventually relocate some Firewall functions found in the Server Tab to here instead.
<p align="center">
  <img src="https://github.com/defec1iv3/FullTime-Manager/blob/master/Screenshots/ss1.PNG" width="400" height="250"></img>
</p>

Image of the client's Billing Tab. Functions regarding billing-oriented information are located here. 
<p align="center">
  <img src="https://github.com/defec1iv3/FullTime-Manager/blob/master/Screenshots/ss2.PNG" width="400" height="250"></img>
</p>

Image of the client's Settings tab. Functions regarding general client settings are here, such as the ability to refresh an API key.
<p align="center">
  <img src="https://github.com/defec1iv3/FullTime-Manager/blob/master/Screenshots/ss3.PNG" width="400" height="250"></img>
</p>

<br/>

# Credits
Programming, GUI Design: Defect (defec1iv3)

Quality Assurance Testers: none yet!

Version: 1.0.0

Notes: I'm colorblind, so if the GUI looks weird to you, well... ( ͡ಠ ͜ʖ ͡ಠ)
