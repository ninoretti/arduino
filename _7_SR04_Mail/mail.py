#!/usr/bin/python

import smtplib
nome = 'Antonino'
sender = ['py_mail@miur.gov.it']
receivers = ['a51.oretti@gmail.com']

intestazione = """From: ninoretti <ninoretti@miur.gov.it>
To: Oretti KN <pesca@miur.gov.it>
"""
subject = "Subject: Rilevata presenza - Ciao " + nome
corpo = "\n\nCiao " + nome + """
Ti ho visto in giro al Marchi
come mai? ci vedremo alla prossima lezione\n
"""
firma = """
Cordiali saluti

ninoretti

"""
message = intestazione + subject + corpo + firma
#message = message + corpo
#message = message + firma
try:
	smtpObj = smtplib.SMTP('smtp.miur.gov.it', 25)
#	smtpObj.set_debuglevel(1)
	smtpObj.login('py_mail@miur.gov.it','9Ax-27By.33K+')
	smtpObj.sendmail(sender, receivers, message)
	smtpObj.quit()         
	print "Successfully sent email"
except smtplib.SMTPException:
	print "Error: unable to send email"
