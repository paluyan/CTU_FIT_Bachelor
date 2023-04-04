// runned when the spredsheet is open
function onOpen() {
  SpreadsheetApp.getUi()
    .createMenu("Update")
    .addItem("UPDATE Right Side", "fill_righ_side")
    .addItem("CLEAR Right Side Cells", "clear_righ_side")
    /* .addItem('Export to JSON', 'download_json') */.addToUi();
}

function clear_righ_side() {
  var activeSheet = SpreadsheetApp.getActive();
  var newVar = activeSheet.getRangeByName("rightSide").clearContent();
}

// fills right side
function fill_righ_side() {
  var activeSheet = SpreadsheetApp.getActive();

  var cables = activeSheet.getRangeByName("cabel").getValues(); // named range "cabel"
  var leftSide = activeSheet.getRangeByName("leftSide").getValues(); //  -//-

  var rightIndex = 2;
  for (var i = 1; i < cables.length; i++) {
    // if (String(SpreadsheetApp.getActive().getRange(`D${i+1}`).getBackground()) != "#d9ead3") {
    //   rightIndex++;
    //   continue;
    // }

    var leftIndex = is_there(cables[i], i);

    if (leftIndex === -1) {
    } else if (leftIndex) {
      activeSheet.getRange(`E${rightIndex}`).setValue(leftSide[leftIndex][2]);
      activeSheet.getRange(`F${rightIndex}`).setValue(leftSide[leftIndex][1]);
      activeSheet.getRange(`G${rightIndex}`).setValue(leftSide[leftIndex][0]);
    } else {
      activeSheet.getRange(`E${rightIndex}:G${rightIndex}`).setValue("no pair"); // right side
    }

    rightIndex++;
  }
}

// check whether the cabel appears more than once
function is_there(item, index) {
  var cables = SpreadsheetApp.getActive().getRangeByName("cabel").getValues();

  if (String(item) === "x") return -1;
  else if (String(item) === "tp") return -1;

  for (var i = 1; i < cables.length; i++) {

    if (String(cables[i]) === String(item) && i != index) return i;
  }
  return null;
}
