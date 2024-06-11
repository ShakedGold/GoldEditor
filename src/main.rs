use components::{sidebar, Component};
use eframe::egui;

mod components;

// Main function to run the app
fn main() -> eframe::Result<(), eframe::Error> {
    let native_options = eframe::NativeOptions::default();
    return eframe::run_native(
        "Gold Editor",
        native_options,
        Box::new(|_| Box::new(MainApp::new())),
    );
}

struct MainApp {
    sidebar: components::sidebar::Sidebar,
}
impl MainApp {
    fn new() -> Self {
        let mut this = Self {
            sidebar: components::sidebar::Sidebar::new(),
        };

        // get all files in current folder
        let files = std::fs::read_dir(".").unwrap();
        for file in files {
            let file = file.unwrap();
            let file_path = file.path();
            this.sidebar
                .add_item(components::item::Item::new(file_path.display().to_string()));
        }

        return this;
    }
}

impl eframe::App for MainApp {
    fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
        egui::CentralPanel::default().show(ctx, |ui| {
            self.sidebar.render(ctx, ui);
        });
    }
}
