#!/bin/bash
# Git Push Commands for CSV Parser with Web UI
# Run this script from the CSV-PARSER directory

cd "/run/media/jb/8539-EC27/dev/C++ Projects/CSV-PARSER"

# Check if git is initialized
if [ ! -d .git ]; then
    echo "Initializing git repository..."
    git init
fi

# Add all files
echo "Adding all files..."
git add .

# Check git status
echo "Current git status:"
git status --short

# Commit with comprehensive message
echo "Creating commit..."
git commit -m "Add complete Web UI and UI/UX documentation

Features Added:
- Complete web-based UI (HTML, CSS, JavaScript)
- All 7 filter operators fully functional
- Real-time CSV filtering and results display
- Export filtered results as CSV
- Responsive design (mobile and desktop support)
- WCAG 2.2 AA accessibility compliance
- Full keyboard navigation support

Documentation Added:
- Complete UI/UX specification (11 documentation files)
- Executive summary and information architecture
- Screen-by-screen specifications
- Interactive component library
- Function-to-UI mapping
- Navigation and routing model
- Accessibility checklist (WCAG 2.2 AA)
- Style compliance matrix
- Style decisions log
- Developer handoff artifacts
- Browser test report
- Final sanity check report

Technical:
- Bosk8 Dark Minimal Mono design system compliance
- 100% feature parity with C++ CLI
- Browser-tested and verified
- Production-ready implementation"

# Show commit
echo "Commit created:"
git log -1 --oneline

echo ""
echo "To push to GitHub, run:"
echo "  git remote add origin https://github.com/YOUR_USERNAME/csv-parser.git"
echo "  git push -u origin main"
echo ""
echo "Or if remote already exists:"
echo "  git push origin main"

