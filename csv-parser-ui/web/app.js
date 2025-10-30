(function(){
  var fileInput = document.getElementById('file-input');
  var fileName = document.getElementById('file-name');
  var filterSection = document.getElementById('filter-section');
  var resultsSection = document.getElementById('results-section');
  var colSel = document.getElementById('col');
  var opSel = document.getElementById('op');
  var valInput = document.getElementById('val');
  var applyBtn = document.getElementById('apply');
  var exportBtn = document.getElementById('export');
  var resultsPre = document.getElementById('results');
  var errorMeta = document.getElementById('error');

  var data = []; // array of arrays (CSV rows)

  function parseCSV(text) {
    var rows = [];
    var lines = text.split(/\r?\n/);
    for (var i=0; i<lines.length; i++) {
      var line = lines[i];
      if (!line) continue;
      rows.push(parseLine(line));
    }
    return rows;
  }

  // Quote-aware CSV line parse using simple state toggle, mirrors style from C++ impl
  function parseLine(line) {
    var fields = [];
    var field = '';
    var inQuotes = false;
    for (var i=0; i<line.length; i++) {
      var c = line[i];
      if (c === '"') {
        inQuotes = !inQuotes;
      } else if (c === ',' && !inQuotes) {
        fields.push(field);
        field = '';
      } else {
        field += c;
      }
    }
    fields.push(field);
    return fields;
  }

  function toCSV(rows) {
    return rows.map(function(r){ return r.join(','); }).join('\n');
  }

  function compare(op, a, b) {
    if (op === 'contains') return String(a).indexOf(String(b)) !== -1;
    var an = Number(a), bn = Number(b);
    switch(op) {
      case '==': return String(a) === String(b);
      case '!=': return String(a) !== String(b);
      case '>': return an > bn;
      case '<': return an < bn;
      case '>=': return an >= bn;
      case '<=': return an <= bn;
      default: return false;
    }
  }

  function applyFilter() {
    errorMeta.textContent = '';
    if (!data.length) return;
    var idx = Number(colSel.value);
    var header = data[0] || [];
    if (idx < 0 || idx >= header.length) {
      errorMeta.textContent = 'Error: Column index ' + idx + ' exceeds available columns (' + header.length + ')';
      resultsPre.textContent = header.join(',');
      resultsSection.style.display = 'grid';
      return;
    }
    var op = opSel.value;
    var val = valInput.value;
    var matches = [];
    for (var r=1; r<data.length; r++) {
      var row = data[r];
      if (row && compare(op, row[idx], val)) matches.push(r);
    }
    var out = [];
    out.push(header);
    for (var m=0; m<matches.length; m++) {
      out.push(data[matches[m]]);
    }
    resultsPre.textContent = toCSV(out);
    resultsSection.style.display = 'grid';
  }

  fileInput.addEventListener('change', function(ev){
    var f = ev.target.files && ev.target.files[0];
    if (!f) return;
    fileName.textContent = f.name;
    var reader = new FileReader();
    reader.onload = function(){
      var csvText = String(reader.result || '');
      if (!csvText.trim()) {
        errorMeta.textContent = 'Error: CSV file is empty';
        filterSection.style.display = 'none';
        resultsSection.style.display = 'none';
        return;
      }
      data = parseCSV(csvText);
      if (!data.length || !data[0].length) {
        errorMeta.textContent = 'Error: Failed to parse CSV file';
        filterSection.style.display = 'none';
        resultsSection.style.display = 'none';
        return;
      }
      var header = data[0] || [];
      colSel.innerHTML = '';
      for (var i=0; i<header.length; i++) {
        var opt = document.createElement('option');
        opt.value = String(i);
        opt.textContent = String(i) + (header[i] ? (' - ' + header[i]) : '');
        colSel.appendChild(opt);
      }
      filterSection.style.display = 'grid';
      resultsSection.style.display = 'none';
      resultsPre.textContent = '';
      errorMeta.textContent = '';
    };
    reader.onerror = function() {
      errorMeta.textContent = 'Error: Failed to read CSV file';
      filterSection.style.display = 'none';
      resultsSection.style.display = 'none';
    };
    reader.readAsText(f);
  });

  applyBtn.addEventListener('click', function(ev){
    ev.preventDefault();
    applyFilter();
  });

  // Keyboard support: Enter key to apply filter
  valInput.addEventListener('keydown', function(ev){
    if (ev.key === 'Enter') {
      ev.preventDefault();
      applyFilter();
    }
  });

  exportBtn.addEventListener('click', function(ev){
    ev.preventDefault();
    var blob = new Blob([resultsPre.textContent || ''], {type: 'text/csv'});
    var a = document.createElement('a');
    a.href = URL.createObjectURL(blob);
    a.download = 'results.csv';
    document.body.appendChild(a);
    a.click();
    a.remove();
  });
})();


