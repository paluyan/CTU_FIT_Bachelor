function sendMail() {
  for (var i = 1; i < 30; i++) {
    var spam = "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
    MailApp.sendEmail("josef.polasek@themama.ai", "SPAM " + "#" + i, spam)
  }
}

function getColor() {
  var colVar = SpreadsheetApp.getActive().getRange("D19").getBackground();
  console.log(colVar);
}

function download_json() {
  const html = HtmlService.createHtmlOutputFromFile("index");
  SpreadsheetApp.getUi().showModalDialog(html, "Downloading only green cables as JSON");
}

function downloadFile() {
  const sheet = SpreadsheetApp.getActiveSpreadsheet().getActiveSheet();
  const [header, ...values] = sheet.getDataRange().getValues();
  const obj = values.map(r => r.reduce((o, c, j) => Object.assign(o, { [header[j]]: c }), {}));
  const filename = `${sheet.getSheetName()}.json`;
  const blob = Utilities.newBlob(JSON.stringify(obj), MimeType.PLAIN_TEXT, filename);
  return { data: `data:${MimeType.PLAIN_TEXT};base64,${Utilities.base64Encode(blob.getBytes())}`, filename: filename };
}