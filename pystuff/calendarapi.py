import httplib2
import sys
import datetime
import json

from googleapiclient.discovery import build
from oauth2client import tools
from oauth2client.file import Storage
from oauth2client.client import AccessTokenRefreshError
from oauth2client.client import OAuth2WebServerFlow
from oauth2client.client import flow_from_clientsecrets


# Create a flow object. This object holds the client_id, client_secret, and
# scope. It assists with OAuth 2.0 steps to get user authorization and
# credentials.
flow = flow_from_clientsecrets('./pystuff/client_secrets.json',
                               scope='https://www.googleapis.com/auth/calendar.readonly',
                               redirect_uri='urn:ietf:wg:oauth:2.0:oob')

def main():

  # Create a Storage object. This object holds the credentials that your
  # application needs to authorize access to the user's data. The name of the
  # credentials file is provided. If the file does not exist, it is
  # created. This object can only hold credentials for a single user, so
  # as-written, this script can only handle a single user.
  storage = Storage('pystuff/credentials.dat')

  # The get() function returns the credentials for the Storage object. If no
  # credentials were found, None is returned.
  credentials = storage.get()

  # If no credentials are found or the credentials are invalid due to
  # expiration, new credentials need to be obtained from the authorization
  # server. The oauth2client.tools.run_flow() function attempts to open an
  # authorization server page in your default web browser. The server
  # asks the user to grant your application access to the user's data.
  # If the user grants access, the run_flow() function returns new credentials.
  # The new credentials are also stored in the supplied Storage object,
  # which updates the credentials.dat file.
  if credentials is None or credentials.invalid:
    credentials = tools.run_flow(flow, storage, tools.argparser.parse_args())

  # Create an httplib2.Http object to handle our HTTP requests, and authorize it
  # using the credentials.authorize() function.
  http = httplib2.Http()
  http = credentials.authorize(http)

  # The apiclient.discovery.build() function returns an instance of an API service
  # object can be used to make API calls. The object is constructed with
  # methods specific to the calendar API. The arguments provided are:
  #   name of the API ('calendar')
  #   version of the API you are using ('v3')
  #   authorized httplib2.Http() object that can be used for API calls
  service = build('calendar', 'v3', http=http)

  try:

    # The Calendar API's events().list method returns paginated results, so we
    # have to execute the request in a paging loop. First, build the
    # request object. The arguments provided are:
    #   primary calendar for user

    start = datetime.datetime.now()
    end = (start + datetime.timedelta(days=1)).replace(hour=0, minute=0, second=0, microsecond=0)
    start = start.isoformat() + 'Z'
    end = end.isoformat() + 'Z'

    print str(start)
    print str(end)


    response = service.events().list(calendarId='primary',orderBy = "startTime",singleEvents = True, timeMin = start, timeMax = end).execute()

    # Accessing the response like a dict object with an 'items' key
    # returns a list of item objects (events).
    for event in response.get('items', []):
        # The event object is a dict object with a 'summary' key.
        print repr(event.get('summary', 'NO SUMMARY')) + '\n'
        # Get the next request object by passing the previous request object to
        # the list_next method.

    #take response and write to json file

    with open('pystuff/caldata.json', 'w') as outfile:
        json.dump(response, outfile)


  except AccessTokenRefreshError:
    # The AccessTokenRefreshError exception is raised if the credentials
    # have been revoked by the user or they have expired.
    print ('The credentials have been revoked or expired, please re-run'
           'the application to re-authorize')

if __name__ == '__main__':
  main()
